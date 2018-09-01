cmake_minimum_required(VERSION 3.0.0)
project(Cipher-Encryption-Project VERSION 1.2.2)

include_directories(include)

set(LINUX_EXE_NAME "${PROJECT_NAME}.out")
set(WIN_EXE_NAME "${PROJECT_NAME}.exe")
set(MAC_EXE_NAME "${PROJECT_NAME}.app")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

file(GLOB MY_PROJECT_FILES "src/*.cpp")

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /WX")
endif()

if ( WIN32 )
    set(EXECUTABLE_NAME ${WIN_EXE_NAME})
elseif ( APPLE )
    set (EXECUTABLE_NAME ${MAC_EXE_NAME})
else ()
    set(EXECUTABLE_NAME ${LINUX_EXE_NAME})
endif ()

add_executable(${EXECUTABLE_NAME} ${MY_PROJECT_FILES})