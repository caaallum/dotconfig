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
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

char home[PATH_MAX];

int
config__dir_exists(const char *path) {
    struct stat sb;
    return stat(path, &sb) != 0 && S_ISDIR(sb.st_mode);
}

int
config_install(const char *path) {
    char config[PATH_MAX];
    struct passwd *pw = getpwuid(getuid());
    strcpy(home, pw->pw_dir);

    sprintf(config, "%s/config", path);
    
    if (!config__dir_exists(config)) {
        fprintf(stderr, "config not found in %s\n", path);
        return 0;
    }

    if (config__dir_exists(config)) {
        printf(".config exists\n");
    } else {
        printf(".config doesnt exist\n");
        mkdir(path, 0600);
    }

    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
            char from[PATH_MAX], to[PATH_MAX];
            sprintf(from, "%s/%s", path, dir->d_name);
            sprintf(to, "%s/.config/%s", home, dir->d_name);
            printf("Creating link from: %s to: %s\n", from, to);
            //symlink(from, to);
        }
        closedir(d); 
    }

    return 0;
}

int
config_uninstall(void) {
    return 0;
}
