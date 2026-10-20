cmake_minimum_required(VERSION 3.21)

set(PICO_BOARD pol_deck)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pol-deck-project C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

pico_sdk_init()

add_subdirectory(
    $ENV{PICO_ILI9488}
    ${CMAKE_BINARY_DIR}/pico-ili9488
)

add_executable(pol-deck-project
    src/main.cpp
)

target_include_directories(pol-deck-project PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(pol-deck-project
    pico_stdlib
    pico_ili9488
)

pico_enable_stdio_usb(pol-deck-project 1)
pico_enable_stdio_uart(pol-deck-project 0)

pico_add_extra_outputs(pol-deck-project)

# --------------------------------------------------
# Tests
# --------------------------------------------------

include(CTest)

if(BUILD_TESTING)
    message(STATUS "Testing enabled")
    
endif()
