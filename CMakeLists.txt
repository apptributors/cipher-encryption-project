cmake_minimum_required(VERSION 3.0.0)
project(Cipher-Encryption-Project VERSION 1.2.2)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

file(GLOB MY_PROJECT_FILES "src/*.cpp")

if ( CMAKE_COMPILER_IS_GNUCC )
    add_definitions("-Werror")
endif()
if ( MSVC )
    add_definitions("/WX")
endif()

add_executable(${PROJECT_NAME} ${MY_PROJECT_FILES})
