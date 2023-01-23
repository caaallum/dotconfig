#include "config.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

config_t *
config_new(void) {
    config_t *config = malloc(sizeof(config_t));
    assert(config);

    config->method = NULL;
    
    config->config = malloc(sizeof(char *));
    config->config[0] = NULL;
    config->local = malloc(sizeof(char *));
    config->local[0] = NULL;
    config->home = malloc(sizeof(char *));
    config->home[0] = NULL;

    return config;
}

void config_add(char ***list, const char *data) {
    int size = 0;
    char **l = *list;

    while(l[size]) {
        size++;
    }

        l = realloc(l, sizeof(char *) * (size + 1));
        l[size] = malloc(sizeof(char) + strlen(data));
        assert(l[size]);
        strcpy(l[size], data);
        l[size++] = NULL;
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
