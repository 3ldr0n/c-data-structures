#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_CHARACTERS 200

struct list_t {
    char **list;
    size_t used_space;
    size_t size;
};

void *smalloc(size_t size);
void *srealloc(void *ptr, size_t size);
void instanciate_list(struct list_t *list, size_t size);
void insert_into_list(struct list_t *list, char *value, unsigned int index);
void append_into_list(struct list_t *list, char *value);

#endif
