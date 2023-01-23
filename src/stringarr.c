#include "stringarr.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

stringarr_t *
stringarr_new(void) {
    stringarr_t *arr = malloc(sizeof(stringarr_t));
    assert(arr);

    arr->capacity = 4;
    arr->total = 0;
    arr->items = malloc(sizeof(void *) * arr->capacity);
    assert(arr->items);

    return arr;
}

void
stringarr__resize(stringarr_t *arr, int capacity) {
    char **items = realloc(arr->items, sizeof(char *) * capacity);
    assert(items);

    arr->items = items;
    arr->capacity = capacity;
}

void
stringarr_add(stringarr_t *arr, const char *item) {
    assert(arr);
    
    if (arr->total == arr->capacity) {
        stringarr__resize(arr, arr->capacity * 2);
    }

    arr->items[arr->total] = malloc(sizeof(char *) + strlen(item));
    assert(arr->items[arr->total]);
    strcpy(arr->items[arr->total], item);

    arr->total++;
}
