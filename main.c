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
#define _GNU_SOURCE

#include "args.h"
#include "dotconfig.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "config.h"

int 
main(int argc, char **argv) {
    args_t args;

    args_parse(&args, argc, argv);

    if (args.version) {
        fprintf(stdout, "dotconfig %s\n", VERSION);
        return 0;
    }

    if (args.help) {
        fprintf(stdout, "Usage:\n");
        fprintf(stdout, "-h Prints this help message\n");
        fprintf(stdout, "-V Print version information\n");
        fprintf(stdout, "-i Install dotfiles\n");
        fprintf(stdout, "-u Uninstall dotfiles\n");
        fprintf(stdout, "-C <dir> Specify dotfiles directory\n");
        return 0;
    }

    if (args.install) {
        if (args.dir) {
            config_install(args.dir);
        } else {
            char path[PATH_MAX];
            if (getcwd(path, sizeof(path)) != NULL) {
                config_install(path);
            } else {
                fprintf(stderr, "Failed to get current directory\n");
                return 1;
            }
        }
        
    }
}
