cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(heli_controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(heli_controller
    src/main.c
    src/axis.c
    src/calibration.c
    src/cli.c
    src/hid_report.c
    src/inputs.c
    src/mcp3208.c
    src/usb_descriptors.c
)

target_include_directories(heli_controller PRIVATE src)

target_link_libraries(heli_controller
    pico_stdlib
    pico_unique_id
    hardware_flash
    hardware_spi
    hardware_sync
    tinyusb_device
    tinyusb_board
)

pico_enable_stdio_usb(heli_controller 0)
pico_enable_stdio_uart(heli_controller 0)
pico_add_extra_outputs(heli_controller)
