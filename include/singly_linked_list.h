#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_CHARACTERS 200

struct node {
    int value;
    struct node *next;
};

struct list_t {
    struct node *head;
    size_t size;
};

void *smalloc(size_t size);
void instanciate_list(struct list_t *list);
bool is_list_empty(struct list_t *list);
void append(struct list_t *list, int value);

#endif
