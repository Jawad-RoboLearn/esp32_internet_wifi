# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/jawad/esp32/esp-idf/components/bootloader/subproject"
  "/home/jawad/esp_projects/wifi_connect/build/bootloader"
  "/home/jawad/esp_projects/wifi_connect/build/bootloader-prefix"
  "/home/jawad/esp_projects/wifi_connect/build/bootloader-prefix/tmp"
  "/home/jawad/esp_projects/wifi_connect/build/bootloader-prefix/src/bootloader-stamp"
  "/home/jawad/esp_projects/wifi_connect/build/bootloader-prefix/src"
  "/home/jawad/esp_projects/wifi_connect/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/jawad/esp_projects/wifi_connect/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/jawad/esp_projects/wifi_connect/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
