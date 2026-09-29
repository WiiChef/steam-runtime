// sns_test.cpp - SNS_TEST_PROTOCOL.md implementation for Android (host=0, client=1)
// Direct linking against libsteam_api.so; SteamAPI_RunCallbacks pumped by Java nativeRunFrame.
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

#ifdef SNS_SELFTEST_MAIN
#define SNSLOG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#else
#include <android/log.h>
#ifndef __COUNTER__
#define __COUNTER__ 0
#endif
#include "steam/steam_api.h"
#include <jni.h>
#define SNSLOG(fmt, ...) __android_log_print(ANDROID_LOG_INFO, "SNSTEST", fmt, ##__VA_ARGS__)
#endif

namespace {

const int kVirtualPort = 7;
const uint32_t kPayloadSize = 4096;
const char *kLobbyKeyTest = "sns_test";
const char *kLobbyKeyHost = "sns_host";
const char *kLobbyKeyNonce = "sns_nonce";

std::string make_payload(uint8_t seed) {
    std::string s;
    s.reserve(kPayloadSize);
    for (uint32_t i = 0; i < kPayloadSize; ++i)
        s.push_back(static_cast<char>(static_cast<int>(i) * 31 + static_cast<int>(seed) & 0xFF));
    return s;
}

struct Sha256Ctx {
    uint32_t h[8];
    uint64_t len;
    uint8_t buf[64];
    size_t buflen;
};

static inline uint32_t rotr(uint32_t x, uint32_t n) { return (x >> n) | (x << (32 - n)); }

static void sha256_block(Sha256Ctx *c, const uint8_t *p) {
    static const uint32_t K[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };
    uint32_t w[64];
    for (int i = 0; i < 16; ++i)
        w[i] = (uint32_t(p[i * 4]) << 24) | (uint32_t(p[i * 4 + 1]) << 16) |
               (uint32_t(p[i * 4 + 2]) << 8) | uint32_t(p[i * 4 + 3]);
    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ (w[i - 15] >> 3);
        uint32_t s1 = rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }
    uint32_t a = c->h[0], b = c->h[1], cc = c->h[2], d = c->h[3];
    uint32_t e = c->h[4], f = c->h[5], g = c->h[6], h = c->h[7];
    for (int i = 0; i < 64; ++i) {
        uint32_t S1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t t1 = h + S1 + ch + K[i] + w[i];
        uint32_t S0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
        uint32_t maj = (a & b) ^ (a & cc) ^ (b & cc);
        uint32_t t2 = S0 + maj;
        h = g; g = f; f = e; e = d + t1; d = cc; cc = b; b = a; a = t1 + t2;
    }
    c->h[0] += a; c->h[1] += b; c->h[2] += cc; c->h[3] += d;
    c->h[4] += e; c->h[5] += f; c->h[6] += g; c->h[7] += h;
}

void sha256(const uint8_t *data, size_t len, uint8_t out[32]) {
    Sha256Ctx c;
    static const uint32_t H0[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
    for (int i = 0; i < 8; ++i) c.h[i] = H0[i];
    c.len = 0; c.buflen = 0;
    size_t consumed = 0;
    while (len >= 64) {
        sha256_block(&c, data);
        data += 64; len -= 64;
        consumed += 64;
    }
    c.buflen = len;
    memcpy(c.buf, data, len);
    uint64_t bitlen = (consumed + len) * 8;
    c.buf[len] = 0x80;
    if (len >= 56) {
        memset(c.buf + len + 1, 0, 63 - len);
        sha256_block(&c, c.buf);
        memset(c.buf, 0, 56);
    } else {
        memset(c.buf + len + 1, 0, 55 - len);
    }
    for (int i = 0; i < 8; ++i)
        c.buf[56 + i] = uint8_t(bitlen >> (56 - i * 8));
    sha256_block(&c, c.buf);
    for (int i = 0; i < 8; ++i) {
        out[i * 4] = uint8_t(c.h[i] >> 24);
        out[i * 4 + 1] = uint8_t(c.h[i] >> 16);
        out[i * 4 + 2] = uint8_t(c.h[i] >> 8);
        out[i * 4 + 3] = uint8_t(c.h[i]);
    }
}

std::string to_hex(const uint8_t *d, size_t n) {
    static const char *hex = "0123456789abcdef";
    std::string s;
    s.reserve(n * 2);
    for (size_t i = 0; i < n; ++i) {
        s.push_back(hex[d[i] >> 4]);
        s.push_back(hex[d[i] & 0xF]);
    }
    return s;
}

std::string hash_of(const std::string &s) {
    uint8_t out[32];
    sha256(reinterpret_cast<const uint8_t *>(s.data()), s.size(), out);
    return to_hex(out, 32);
}

} // namespace
#ifndef SNS_SELFTEST_MAIN

class SnsTest {
public:
    enum State {
        St_Init = 0,
        St_WaitLobbyCreated,   // host
        St_WaitLobbyMatch,     // client
        St_WaitJoined,         // client
        St_Listening,          // host, waiting for incoming connection
        St_Connecting,         // client, ConnectP2P issued
        St_Connected,          // payload phase
        St_Done,               // PASS
        St_Failed              // FAIL
    };

    SnsTest() : m_role(0), m_state(St_Init), m_listenSocket(k_HSteamListenSocket_Invalid),
                m_conn(k_HSteamNetConnection_Invalid), m_hostSteamId64(0),
                m_connectDeadline(), m_payloadDeadline(), m_resultSent(false) {}
    ~SnsTest() { Stop(); }

    void Start(int role);
    void StartDirect(uint64_t hostSteamId64);   // client role, skip lobby search
    int Tick();   // 0 running, 1 pass, 2 fail
    void Stop();

    // STEAM_CALLBACK target
    STEAM_CALLBACK(SnsTest, OnConnStatus, SteamNetConnectionStatusChangedCallback_t);

    // CCallResult targets
    void OnLobbyCreated(LobbyCreated_t *p, bool bApplicable);
    void OnLobbyMatchList(LobbyMatchList_t *p, bool bApplicable);
    void OnLobbyEnter(LobbyEnter_t *p, bool bApplicable);

private:
    void LogEvent(const char *event, const std::string &kv);
    void Fail(const char *detail);
    void Pass(const char *detail);
    void SendPayload(uint8_t seed, const char *dir);
    void PumpReceive();
    void BeginConnectToHost(uint64_t hostSteamId64);  // shared client connect path
    void OnConnected();
    void CloseConn(int reason, const char *debug);
    static std::string RandomNonceHex();

    int m_role;                    // 0 = host, 1 = client
    State m_state;
    uint64_t m_lobbyId;            // lobby SteamID64
    uint64_t m_hostSteamId64;      // host identity read from lobby data (client side)
    HSteamListenSocket m_listenSocket;
    HSteamNetConnection m_conn;
    std::string m_recvBuf;         // reassembly buffer
    bool m_payloadSent;
    bool m_payloadReceived;
    bool m_doneReceived;           // host: got DONE
    bool m_doneSent;               // client: sent DONE
    bool m_resultSent;
    std::chrono::steady_clock::time_point m_connectDeadline;
    std::chrono::steady_clock::time_point m_payloadDeadline;

    CCallResult<SnsTest, LobbyCreated_t> m_callLobbyCreated;
    CCallResult<SnsTest, LobbyMatchList_t> m_callLobbyMatchList;
    CCallResult<SnsTest, LobbyEnter_t> m_callLobbyEnter;
};

namespace {

std::unique_ptr<SnsTest> g_sns;

const char *RoleName(int role) { return role == 0 ? "host" : "client"; }

static void Stop() {
    if (g_sns) {
        g_sns->Stop();
        g_sns.reset();
    }
}

} // namespace

#endif

#ifndef SNS_SELFTEST_MAIN
std::string SnsTest::RandomNonceHex() {
    static const char *hex = "0123456789abcdef";
    std::string s;
    for (int i = 0; i < 8; ++i)
        s.push_back(hex[arc4random_uniform(16)]);
    return s;
}

void SnsTest::LogEvent(const char *event, const std::string &kv) {
    SNSLOG("SNSTEST role=%s event=%s %s", RoleName(m_role), event, kv.c_str());
}

void SnsTest::Fail(const char *detail) {
    if (m_resultSent) return;
    m_resultSent = true;
    m_state = St_Failed;
    LogEvent("RESULT", std::string("status=FAIL detail=") + detail);
}

void SnsTest::Pass(const char *detail) {
    if (m_resultSent) return;
    m_resultSent = true;
    m_state = St_Done;
    LogEvent("RESULT", std::string("status=PASS detail=") + detail);
}

void SnsTest::Start(int role) {
    m_role = role;
    m_state = St_Init;
    m_listenSocket = k_HSteamListenSocket_Invalid;
    m_conn = k_HSteamNetConnection_Invalid;
    m_recvBuf.clear();
    m_payloadSent = false;
    m_payloadReceived = false;
    m_doneReceived = false;
    m_doneSent = false;
    m_resultSent = false;
    m_hostSteamId64 = 0;

    uint64_t myId = SteamUser()->GetSteamID().ConvertToUint64();
    int appid = SteamUtils()->GetAppID();
    SNSLOG("SNSTEST role=%s event=init steamid=%llu appid=%d",
           RoleName(role), (unsigned long long)myId, appid);

    if (role == 0) {
        // HOST: create lobby
        SteamAPICall_t call = SteamMatchmaking()->CreateLobby(k_ELobbyTypePublic, 2);
        m_callLobbyCreated.Set(call, this, &SnsTest::OnLobbyCreated);
        m_state = St_WaitLobbyCreated;
    } else {
        // CLIENT: ensure relay network access is initialized before any P2P connect
        SteamNetworkingUtils()->InitRelayNetworkAccess();
        // CLIENT: filter and request lobby list
        SteamMatchmaking()->AddRequestLobbyListStringFilter(kLobbyKeyTest, "1", k_ELobbyComparisonEqual);
        SteamAPICall_t call = SteamMatchmaking()->RequestLobbyList();
        m_callLobbyMatchList.Set(call, this, &SnsTest::OnLobbyMatchList);
        m_state = St_WaitLobbyMatch;
    }
}

void SnsTest::StartDirect(uint64_t hostSteamId64) {
    Start(1);   // client role: also calls InitRelayNetworkAccess; lobby request is harmless/unused
    m_callLobbyMatchList.Cancel();  // drop the pending lobby search so its result can't fail the run
    m_state = St_Init;  // cancel lobby-list path, go straight to P2P connect
    BeginConnectToHost(hostSteamId64);
}

void SnsTest::BeginConnectToHost(uint64_t hostSteamId64) {
    m_hostSteamId64 = hostSteamId64;
    LogEvent("direct_target", "host=" + std::to_string(m_hostSteamId64));
    SteamNetworkingIdentity identity;
    identity.SetSteamID64(m_hostSteamId64);
    m_conn = SteamNetworkingSockets()->ConnectP2P(identity, kVirtualPort, 0, nullptr);
    LogEvent("connect_start", "conn=" + std::to_string((uint64_t)m_conn));
    m_connectDeadline = std::chrono::steady_clock::now() + std::chrono::seconds(60);
    m_state = St_Connecting;
}

void SnsTest::Stop() {
    if (m_conn != k_HSteamNetConnection_Invalid) {
        SteamNetworkingSockets()->CloseConnection(m_conn, 1001, "sns_test_stop", true);
        m_conn = k_HSteamNetConnection_Invalid;
    }
    if (m_listenSocket != k_HSteamListenSocket_Invalid) {
        SteamNetworkingSockets()->CloseListenSocket(m_listenSocket);
        m_listenSocket = k_HSteamListenSocket_Invalid;
    }
}

void SnsTest::OnLobbyCreated(LobbyCreated_t *p, bool bApplicable) {
    if (!bApplicable || p->m_eResult != EResult::k_EResultOK) {
        Fail("lobby_create_failed");
        return;
    }
    m_lobbyId = p->m_ulSteamIDLobby;
    CSteamID lobby((uint64)m_lobbyId);
    SteamMatchmaking()->SetLobbyData(lobby, kLobbyKeyTest, "1");
    uint64_t myId = SteamUser()->GetSteamID().ConvertToUint64();
    SteamMatchmaking()->SetLobbyData(lobby, kLobbyKeyHost, std::to_string(myId).c_str());
    SteamMatchmaking()->SetLobbyData(lobby, kLobbyKeyNonce, RandomNonceHex().c_str());
    LogEvent("lobby_created", "lobby=" + std::to_string(m_lobbyId));

    m_listenSocket = SteamNetworkingSockets()->CreateListenSocketP2P(kVirtualPort, 0, nullptr);
    LogEvent("listen_socket", "handle=" + std::to_string((uint64_t)m_listenSocket));
    m_connectDeadline = std::chrono::steady_clock::now() + std::chrono::seconds(60);
    m_state = St_Listening;
}

void SnsTest::OnLobbyMatchList(LobbyMatchList_t *p, bool bApplicable) {
    if (!bApplicable || p->m_nLobbiesMatching < 1) {
        Fail("no_lobby_found");
        return;
    }
    CSteamID lobby = SteamMatchmaking()->GetLobbyByIndex(0);
    m_lobbyId = lobby.ConvertToUint64();
    const char *hostStr = SteamMatchmaking()->GetLobbyData(lobby, kLobbyKeyHost);
    if (!hostStr) {
        Fail("missing_sns_host");
        return;
    }
    m_hostSteamId64 = strtoull(hostStr, nullptr, 10);
    LogEvent("lobby_found", "lobby=" + std::to_string(m_lobbyId));
    SteamAPICall_t call = SteamMatchmaking()->JoinLobby(lobby);
    m_callLobbyEnter.Set(call, this, &SnsTest::OnLobbyEnter);
    m_state = St_WaitJoined;
}

void SnsTest::OnLobbyEnter(LobbyEnter_t *p, bool bApplicable) {
    if (!bApplicable) {
        Fail("lobby_enter_failed");
        return;
    }
    BeginConnectToHost(m_hostSteamId64);
}

void SnsTest::OnConnStatus(SteamNetConnectionStatusChangedCallback_t *p) {
    std::string debug = p->m_info.m_szEndDebug ? p->m_info.m_szEndDebug : "";
    LogEvent("state", "conn=" + std::to_string((uint64_t)p->m_hConn) +
                      " old=" + std::to_string((int)p->m_eOldState) +
                      " new=" + std::to_string((int)p->m_info.m_eState) +
                      " end_reason=" + std::to_string(p->m_info.m_eEndReason) +
                      " debug=" + debug);
    switch (p->m_info.m_eState) {
        case k_ESteamNetworkingConnectionState_Connecting:
            if (m_role == 0 && p->m_hConn != k_HSteamNetConnection_Invalid) {
                if (m_listenSocket != k_HSteamListenSocket_Invalid &&
                    p->m_info.m_hListenSocket == m_listenSocket &&
                    p->m_info.m_identityRemote.GetSteamID64() != 0) {
                    SteamNetworkingSockets()->AcceptConnection(p->m_hConn);
                    LogEvent("accepted", "conn=" + std::to_string((uint64_t)p->m_hConn));
                    m_conn = p->m_hConn;
                }
            }
            break;
        case k_ESteamNetworkingConnectionState_Connected:
            if (m_role == 0 && p->m_hConn != m_conn) {
                // A different accepted connection reached Connected; track it.
                m_conn = p->m_hConn;
            }
            OnConnected();
            break;
        default:
            if (p->m_hConn == m_conn &&
                (p->m_info.m_eState == k_ESteamNetworkingConnectionState_ClosedByPeer ||
                 p->m_info.m_eState == k_ESteamNetworkingConnectionState_ProblemDetectedLocally)) {
                if (!m_resultSent)
                    Fail("connection_closed");
            }
            break;
    }
}

void SnsTest::OnConnected() {
    if (m_state >= St_Connected) return;
    m_state = St_Connected;
    m_payloadDeadline = std::chrono::steady_clock::now() + std::chrono::seconds(30);
    SendPayload(m_role == 0 ? 7 : 13, m_role == 0 ? "host_to_client" : "client_to_host");
}

void SnsTest::SendPayload(uint8_t seed, const char *dir) {
    std::string payload = make_payload(seed);
    EResult r = SteamNetworkingSockets()->SendMessageToConnection(
        m_conn, payload.data(), (uint32_t)payload.size(), k_nSteamNetworkingSend_Reliable, nullptr);
    m_payloadSent = (r == k_EResultOK);
    LogEvent("sent", std::string("dir=") + dir +
                     " bytes=" + std::to_string(payload.size()) +
                     " sha256=" + hash_of(payload) +
                     " result=" + std::to_string((int)r));
    if (!m_payloadSent)
        Fail("send_failed");
}

void SnsTest::PumpReceive() {
    if (m_conn == k_HSteamNetConnection_Invalid) return;
    SteamNetworkingMessage_t *msgs[8];
    int n = SteamNetworkingSockets()->ReceiveMessagesOnConnection(m_conn, msgs, 8);
    for (int i = 0; i < n; ++i) {
        SteamNetworkingMessage_t &msg = *msgs[i];
        if (msg.m_cbSize == 4 && memcmp(msg.m_pData, "DONE", 4) == 0) {
            msg.Release();
            if (m_role == 0) {
                m_doneReceived = true;
                CloseConn(1000, "sns_test_ok");
                Pass("round_trip_complete");
            }
            continue;
        }
        m_recvBuf.append(static_cast<char *>(msg.m_pData), msg.m_cbSize);
        msg.Release();
        if (m_recvBuf.size() == kPayloadSize) {
            std::string got = std::move(m_recvBuf);
            m_recvBuf.clear();
            std::string expected = make_payload(m_role == 0 ? 13 : 7);
            std::string gotHash = hash_of(got);
            std::string expHash = hash_of(expected);
            int match = (gotHash == expHash) ? 1 : 0;
            const char *dir = m_role == 0 ? "host_to_client" : "client_to_host";
            LogEvent("received", std::string("dir=") + dir +
                                 " bytes=4096 sha256=" + gotHash +
                                 " expected_sha256=" + expHash +
                                 " match=" + std::to_string(match));
            if (match == 1) {
                m_payloadReceived = true;
                if (m_role == 1 && m_payloadSent && !m_doneSent) {
                    const char *done = "DONE";
                    SteamNetworkingSockets()->SendMessageToConnection(
                        m_conn, done, 4, k_nSteamNetworkingSend_Reliable, nullptr);
                    m_doneSent = true;
                    Pass("round_trip_complete");
                }
            } else {
                Fail("hash_mismatch");
            }
        }
    }
}

void SnsTest::CloseConn(int reason, const char *debug) {
    if (m_conn != k_HSteamNetConnection_Invalid) {
        SteamNetworkingSockets()->CloseConnection(m_conn, reason, debug, true);
        m_conn = k_HSteamNetConnection_Invalid;
    }
    LogEvent("closed", "reason=" + std::to_string(reason));
}

int SnsTest::Tick() {
    PumpReceive();
    auto now = std::chrono::steady_clock::now();
    if (m_resultSent)
        return m_state == St_Done ? 1 : 2;
    if ((m_state == St_Listening || m_state == St_Connecting) &&
        now > m_connectDeadline) {
        Fail("connect_timeout");
        return 2;
    }
    if (m_state == St_Connected && !m_payloadReceived && now > m_payloadDeadline) {
        Fail("payload_timeout");
        return 2;
    }
    return 0;
}

extern "C" {

JNIEXPORT void JNICALL Java_com_sts2_steamtest_SteamTest_nativeSnsStart(JNIEnv *env, jobject obj, jint role) {
    (void)env; (void)obj;
    if (g_sns) Stop();
    g_sns.reset(new SnsTest());
    g_sns->Start(role == 0 ? 0 : 1);
}

JNIEXPORT void JNICALL Java_com_sts2_steamtest_SteamTest_nativeSnsStartDirect(JNIEnv *env, jobject obj, jlong hostSteamId) {
    (void)env; (void)obj;
    if (g_sns) Stop();
    g_sns.reset(new SnsTest());
    g_sns->StartDirect((uint64_t)hostSteamId);
}

JNIEXPORT jint JNICALL Java_com_sts2_steamtest_SteamTest_nativeSnsTick(JNIEnv *env, jobject obj) {
    (void)env; (void)obj;
    if (!g_sns) return 0;
    return g_sns->Tick();
}

JNIEXPORT void JNICALL Java_com_sts2_steamtest_SteamTest_nativeSnsStop(JNIEnv *env, jobject obj) {
    (void)env; (void)obj;
    Stop();
}

// Read-only friend lobby discovery for AppID 2868840 (does NOT join anything).
static std::vector<uint64> g_friendLobbies;

// Flat API entry points used by the game's Steamworks.NET (for FRIENDDIAG comparison).
extern "C" uint64 SteamAPI_ISteamFriends_GetFriendByIndex(ISteamFriends *, int, int);
extern "C" int SteamAPI_ISteamFriends_GetFriendCount(ISteamFriends *, int);

JNIEXPORT jint JNICALL Java_com_sts2_steamtest_SteamTest_nativeFriendLobbies(JNIEnv *env, jobject obj) {
    (void)env; (void)obj;
    g_friendLobbies.clear();
    int count = 0;
    int nFriends = SteamFriends()->GetFriendCount(k_EFriendFlagImmediate);
    // Diagnostic: compare the C++ path with the flat API the game's Steamworks.NET uses.
    {
        int flatCount = SteamAPI_ISteamFriends_GetFriendCount(SteamFriends(), k_EFriendFlagImmediate);
        uint64 flat0 = flatCount > 0 ? SteamAPI_ISteamFriends_GetFriendByIndex(SteamFriends(), 0, k_EFriendFlagImmediate) : 0;
        uint64 cpp0 = nFriends > 0 ? SteamFriends()->GetFriendByIndex(0, k_EFriendFlagImmediate).ConvertToUint64() : 0;
        SNSLOG("FRIENDDIAG cpp_count=%d flat_count=%d cpp0_valid=%d flat0_valid=%d same=%d",
               nFriends, flatCount, cpp0 != 0, flat0 != 0, cpp0 == flat0);
    }
    for (int i = 0; i < nFriends; ++i) {
        CSteamID id = SteamFriends()->GetFriendByIndex(i, k_EFriendFlagImmediate);
        FriendGameInfo_t info;
        if (!SteamFriends()->GetFriendGamePlayed(id, &info)) continue;
        if (info.m_gameID.AppID() != 2868840) continue;
        const char *name = SteamFriends()->GetFriendPersonaName(id);
        uint64_t lobbyId = info.m_steamIDLobby.ConvertToUint64();
        bool valid = info.m_steamIDLobby.IsValid();
        SNSLOG("FRIENDLOBBY friend=%s app=2868840 lobby=%llu valid=%d",
               name ? name : "?", (unsigned long long)lobbyId, valid ? 1 : 0);
        if (valid) {
            CSteamID lobbyCid((uint64)lobbyId);
            SteamMatchmaking()->RequestLobbyData(lobbyCid);
            g_friendLobbies.push_back(lobbyId);
            ++count;
        }
    }
    SNSLOG("FRIENDLOBBY total_found=%d", count);
    return count;
}

JNIEXPORT void JNICALL Java_com_sts2_steamtest_SteamTest_nativeFriendLobbyDump(JNIEnv *env, jobject obj) {
    (void)env; (void)obj;
    for (size_t li = 0; li < g_friendLobbies.size(); ++li) {
        CSteamID lobby((uint64)g_friendLobbies[li]);
        int members = SteamMatchmaking()->GetNumLobbyMembers(lobby);   // may be 0 when not joined
        int limit = SteamMatchmaking()->GetLobbyMemberLimit(lobby);
        int n = SteamMatchmaking()->GetLobbyDataCount(lobby);
        SNSLOG("FRIENDLOBBY_DATA lobby=%llu limit=%d datacount=%d",
               (unsigned long long)g_friendLobbies[li], limit, n);
        for (int k = 0; k < n; ++k) {
            char key[256] = {0};
            char value[1024] = {0};
            if (!SteamMatchmaking()->GetLobbyDataByIndex(lobby, k, key, (int)sizeof(key),
                                                         value, (int)sizeof(value))) {
                continue;
            }
            if (strlen(value) > 120) value[120] = '\0';   // truncate value in log
            SNSLOG("FRIENDLOBBY_DATA lobby=%llu key=%s value=%s",
                   (unsigned long long)g_friendLobbies[li], key, value);
        }
    }
}

} // extern "C"
#endif // !SNS_SELFTEST_MAIN
#ifdef SNS_SELFTEST_MAIN
int main() {
    std::string p7 = make_payload(7);
    std::string p13 = make_payload(13);
    printf("seed7 %s\n", hash_of(p7).c_str());
    printf("seed13 %s\n", hash_of(p13).c_str());
    const std::string abc = "abc";
    printf("abc %s\n", hash_of(abc).c_str());
    int ok = (hash_of(p7) == "d41d438c379110c7f7b2c561b1f04f26c1b4549110791f8e022f48974280c13e") &&
             (hash_of(p13) == "f8d749036d5f1bc689a03838e7bfec01c538b386f787e832b3c799169b1d0f07") &&
             (hash_of(abc) == "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
    printf(ok ? "SELFTEST PASS\n" : "SELFTEST FAIL\n");
    return ok ? 0 : 1;
}
#endif // SNS_SELFTEST_MAIN
