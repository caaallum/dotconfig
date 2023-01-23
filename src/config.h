#ifndef __DOTCONFIG_CONFIG_H
#define __DOTCONFIG_CONFIG_H 

#include "stringarr.h"

typedef struct {
    char *method;

    stringarr_t *config;
    stringarr_t *local;
    stringarr_t *home;
} config_t;

config_t *config_new(void);

void config_set_method(config_t *config, const char *method);

void config_free(config_t *config);

#endif /* __DOTCONFIG_CONFIG_H */
