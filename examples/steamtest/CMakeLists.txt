# SteamTest Android (arm64-v8a) — links against real Valve androidarm64 libsteam_api.so
cmake_minimum_required(VERSION 3.21)
project(steamtest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# STEAMWORKS_LIB = full path to redistributable_bin/androidarm64/libsteam_api.so
if(NOT DEFINED STEAMWORKS_LIB)
    message(FATAL_ERROR "Define -DSTEAMWORKS_LIB=/path/to/libsteam_api.so")
endif()
get_filename_component(STEAMWORKS_DIR ${STEAMWORKS_LIB} DIRECTORY)

add_library(steamtest SHARED jni/jni_bridge.cpp jni/sns_test.cpp)
target_include_directories(steamtest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../client
    $ENV{STEAMWORKS_HEADERS})
# Link directly against the shared object -> DT_NEEDED libsteam_api.so
target_link_libraries(steamtest ${STEAMWORKS_LIB} log)
