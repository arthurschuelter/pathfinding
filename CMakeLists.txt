cmake_minimum_required(VERSION 3.16)
project(game LANGUAGES CXX)

# Compiler and flags (-std=c++17, no GNU extensions)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Target and sources (output: bin/game.out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(SOURCES src/main.cpp src/character.cpp src/character.hpp)

add_executable(game ${SOURCES})
set_target_properties(game PROPERTIES
    OUTPUT_NAME game
    SUFFIX ".out"
)

# OS detection + Raylib
if(APPLE)
    # Mirror the Makefile: locate raylib through Homebrew
    execute_process(
        COMMAND brew --prefix raylib
        OUTPUT_VARIABLE RAYLIB_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    if(RAYLIB_PREFIX)
        list(APPEND CMAKE_PREFIX_PATH "${RAYLIB_PREFIX}")
    endif()
elseif(NOT UNIX)
    message(FATAL_ERROR "Unsupported OS: ${CMAKE_SYSTEM_NAME}")
endif()

# Prefer raylib's CMake package; fall back to plain linking like the Makefile
find_package(raylib QUIET)

if(raylib_FOUND)
    target_link_libraries(game PRIVATE raylib)
elseif(APPLE)
    target_include_directories(game PRIVATE "${RAYLIB_PREFIX}/include")
    target_link_directories(game PRIVATE "${RAYLIB_PREFIX}/lib")
    target_link_libraries(game PRIVATE raylib)
else()
    target_link_libraries(game PRIVATE raylib GL m pthread dl rt X11)
endif()

# Frameworks raylib needs on macOS
if(APPLE)
    target_link_libraries(game PRIVATE
        "-framework IOKit"
        "-framework Cocoa"
        "-framework OpenGL"
    )
endif()

# `make run` / `cmake --build build --target run`
add_custom_target(run
    COMMAND $<TARGET_FILE:game>
    DEPENDS game
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    USES_TERMINAL
)