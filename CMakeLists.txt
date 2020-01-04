cmake_minimum_required(VERSION 3.16)
project(EPGrab)
add_definitions("-Wall -O2 -g")
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBDVBV5  libdvbv5>=1.18.0)
pkg_check_modules(LIBV4L2   libv4l2>=1.18.0)

execute_process(COMMAND awk -f iso_639.awk iso_639.tab
                OUTPUT_VARIABLE langidents.c)

file(WRITE langidents.c "${langidents.c}")

add_executable(epgrab crc32.c lookup.c dvb_info_tables.c dvb_text_iconv.c langidents.c tv_grab_dvb.c)
