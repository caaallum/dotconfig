#include "config.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

config_t *
config_new(void) {
    config_t *config = malloc(sizeof(config_t));
    assert(config);

    config->method = NULL;

    config->config = stringarr_new();
    config->local = stringarr_new();
    config->home = stringarr_new();

    return config;
}

void 
config_set_method(config_t *config, const char *method) {
    assert(config);
    config->method = malloc(sizeof(char) + strlen(method));
    assert(config->method);
    strcpy(config->method, method);
}

void
config_free(config_t *config) {
    free(config->method);

    free(config);
}
