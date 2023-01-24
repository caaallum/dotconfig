#define _GNU_SOURCE
#include "ini.h"
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_PATH 256

char g_path[MAX_PATH];

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

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Line: %s\n", line);
    }

    fclose(fp);

    if (line) {
        free(line);
    }

    return config;
}
