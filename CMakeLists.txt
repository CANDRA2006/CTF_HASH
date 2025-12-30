cmake_minimum_required(VERSION 3.16)
project(ctf_hash_cracker)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

include_directories(include)

add_executable(ctf-cracker
    src/main.cpp
    src/hash_detector.cpp
    src/hasher.cpp
    src/dictionary_attack.cpp
)

target_link_libraries(ctf-cracker OpenSSL::Crypto)
