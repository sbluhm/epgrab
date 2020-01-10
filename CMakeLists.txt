cmake_minimum_required(VERSION 3.16)
project(epgrab)
set(PACKAGE ${PROJECT_NAME})

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBDVBV5  libdvbv5>=1.18.0)
pkg_check_modules(LIBV4L2   libv4l2>=1.18.0)
pkg_check_modules(LIBDVBPSI libdvbpsi>=1.3.2)
pkg_check_modules(MXML      mxml>=3.1)


set(CMAKE_C_FLAGS "-Wall -O2 -g -ldvbv5 -lmxml")

execute_process(COMMAND awk -f iso_639.awk iso_639.tab
                OUTPUT_VARIABLE langidents.c)

file(WRITE langidents.c "${langidents.c}")

add_executable(tv_grab_dvb crc32.c lookup.c dvb_info_tables.c dvb_text_iconv.c langidents.c tv_grab_dvb.c)

set(PROGRAM_NAME "epgrab")
set(${PROGRAM_NAME}_MAJOR "2")
set(${PROGRAM_NAME}_MINOR "0")
set(${PROGRAM_NAME}_PATCH "0")
set(PROGRAM_VERSION "${${PROGRAM_NAME}_MAJOR}.${${PROGRAM_NAME}_MINOR}.${${PROGRAM_NAME}_PATCH}")
configure_file(config.h.in config.h)
add_executable(epgrab epgrab.c)