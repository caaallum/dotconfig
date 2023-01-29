/*
 * This file is part of dotconfig.
 *
 * dotconfig is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dotconfig is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dotconfig.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2023 callum speirs
 * https://github.com/caaallum/dotconfig
 */

#include "args.h"
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

void 
default_args(args_t *args) {
    args->version = 0;
    args->install = 0;
    args->uninstall = 0;
    args->help = 0;
    args->dir = NULL;
}

void
args_parse(args_t *args, int argc, char **argv) {
    opterr = 0;
    int c;
    default_args(args);

    while ((c = getopt(argc, argv, "ViuhC:")) != -1) {
        switch(c) {
            case 'V':
                args->version = 1; 
                break;
            case 'i':
                args->install = 1;
                break;
            case 'u':
                args->uninstall = 1;
                break;
            case 'h':
                args->help = 1;
                break;
            case 'C':
                args->dir = optarg;
                break;
            case '?':
                if (optopt == 'C') {
                    fprintf(stderr, "Option -%c required an argument.\n", optopt);
                } else {
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                }
                exit(1);
        }
    }
}
