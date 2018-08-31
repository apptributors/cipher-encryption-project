cmake_minimum_required(VERSION 3.0.0)
project(Cipher-Encryption-Project VERSION 1.2.2)

include_directories(include)

set(UNIX_EXE_NAME "${PROJECT_NAME}.out")
set(WIN_EXE_NAME "${PROJECT_NAME}.exe")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

file(GLOB MY_PROJECT_FILES "src/*.cpp")

if (WIN32)
    add_executable(${WIN_EXE_NAME} ${MY_PROJECT_FILES})
else()
    add_executable(${UNIX_EXE_NAME} ${MY_PROJECT_FILES})
endif()