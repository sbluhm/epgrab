/*
    EPGrab, an utility which decodes DVB EPG data
    Copyright (C) 2020  YOU Hui-Hong <hiroshi@ghostsinthelab.org>

    This file is part of EPGrab.

    EPGrab is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    EPGrab is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with EPGrab.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <argp.h>

#include "config.h"

#include <linux/dvb/dmx.h>
#include "libdvbv5/dvb-file.h"
#include "libdvbv5/dvb-demux.h"
#include "libdvbv5/dvb-dev.h"
#include "libdvbv5/dvb-v5-std.h"
#include "libdvbv5/dvb-scan.h"
#include "libdvbv5/countries.h"

char doc[] = "EPGrab, an utility which decodes DVB EPG data";
struct argp argp = { NULL, NULL, NULL, doc };

int main( int argc, char *argv[] ) {
    printf("Hello! This is EPGrab.\n");
    argp_parse( &argp, argc, argv, 0, 0, NULL );
    return 0;
}