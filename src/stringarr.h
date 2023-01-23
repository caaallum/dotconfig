#ifndef __DOTCONFIG_STRINGARR_H
#define __DOTCONFIG_STRINGARR_H

typedef struct {
    char **items;
    int total;
    int capacity;
} stringarr_t;

stringarr_t *stringarr_new(void);

void stringarr_add(stringarr_t *arr, const char *item);

void stringarr_free(stringarr_t *arr);

#endif /* __DOTCONFIG_VECTOR_H */
