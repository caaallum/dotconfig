#ifndef __DOTCONFIG_CONFIG_H
#define __DOTCONFIG_CONFIG_H 

typedef struct {
    char *method;

    char **config;
    char **local;
    char **home;
} config_t;

config_t *config_new(void);

void config_set_method(config_t *config, const char *method);

void config_add(char ***list, const char *data);

void config_free(config_t *config);

#endif /* __DOTCONFIG_CONFIG_H */
