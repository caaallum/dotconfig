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
#include "config.h"
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

int
config__dir_exists(const char *path) {
    struct stat sb;
    return stat(path, &sb) == 0 && S_ISDIR(sb.st_mode);
}

int
config_install(const char *path) {
    char config[PATH_MAX];

    sprintf(config, "%s/.config", path);

    if (config__dir_exists(config)) {
        printf(".config exists\n");
    } else {
        printf(".config doesnt exist\n");
    }

    return 0;
}

int
config_uninstall(void) {
    return 0;
}
