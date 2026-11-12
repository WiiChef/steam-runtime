# SteamTest Android (arm64-v8a) — ships the repo shim and a separate Valve API library.
cmake_minimum_required(VERSION 3.21)
project(steamtest C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEAM_RUNTIME_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

add_library(steam_api SHARED
    ${STEAM_RUNTIME_ROOT}/client/shim.c
    ${STEAM_RUNTIME_ROOT}/client/trampolines.c)
set_target_properties(steam_api PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
target_include_directories(steam_api PRIVATE ${STEAM_RUNTIME_ROOT}/client)
target_link_libraries(steam_api log dl)
set_target_properties(steam_api PROPERTIES OUTPUT_NAME steam_api)

add_library(steamtest SHARED jni/jni_bridge.cpp jni/sns_test.cpp)
target_include_directories(steamtest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../client
    $ENV{STEAMWORKS_HEADERS})
# Link through our shim -> DT_NEEDED libsteam_api.so; the shim forwards to
# libsteam_api_real.so from the installed port's Valve library set.
target_link_libraries(steamtest steam_api log dl)
