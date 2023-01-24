#define _GNU_SOURCE
#include "ini.h"
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_PATH 256

char g_path[MAX_PATH];

char *get_ini(const char *str) {
    const char *pattern1 = "[";
    const char *pattern2 = "]";

    char *target = NULL;
    char *start, *end;

    if ((start = strstr(str, pattern1))) {
        start += strlen(pattern1);
        if ((end = strstr(start, pattern2))) {
            target = (char *)malloc(end - start + 1);
            memcpy(target, start, end - start);
            target[end - start] = '\0';
        }

    }

    return target;
}

config_t *
ini_load_config(const char *path) {
    config_t *config = config_new();

    if (path) {
        strcpy(g_path, path);
    } else {
        getcwd(g_path, MAX_PATH);
    }
    
    strcat(g_path, "/dotconfig");

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(g_path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file\n");
        config_free(config);
        return NULL;
    }

    stringarr_t *config_current = NULL;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '\n') { /* Skip empty lines */
            continue;
        }

        char *p;
        if ((p = get_ini(line)) != NULL) {
            printf("%s\n", p);
            if (strcmp(p, "config") == 0) {
                config_current = config->config;
            }
            if (strcmp(p, "local") == 0) {
                config_current = config->local;
            }
            if (strcmp(p, "home") == 0) {
                config_current = config->home;
            }
            continue;
        } else {
            stringarr_add(config_current, line);
        }
        printf("Line: %s", line);
    }

    fclose(fp);

    if (line) {
        free(line);
    }

    return config;
}
