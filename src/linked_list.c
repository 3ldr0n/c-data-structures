#include "linked_list.h"

void *smalloc(size_t size)
{
    if (!size)
        return NULL;

    void *mem;
    mem = malloc(size);

    if (!mem) {
        fprintf(stderr, "Fatal: Erro na alocação (malloc de %zu bytes)\n", size);
        exit(EXIT_FAILURE);
    }

    return mem;
}

void instanciate_list(struct list_t *list)
{
    list->head = NULL;

    list->size = 0;
}

bool is_list_empty(struct list_t *list)
{
    return list->head == NULL;
}

void append(struct list_t *list, int value)
{
    if (is_list_empty(list)) {
        list->head = (struct node *)smalloc(sizeof(struct node *));
        list->head->value = value;
        list->head->next = NULL;
        return;
    }

    struct node *item = list->head;
    for (;item->next != NULL;item = item->next) {}

    struct node *node = (struct node *)smalloc(sizeof(struct node *));
    node->value = value;
    node->next = NULL;
    item->next = node;

    list->size++;
}

void print_list(struct list_t *list)
{
    for (struct node *item = list->head;item != NULL;item = item->next) {
        printf("%d ", item->value);
    }
    printf("\n");
}

int main()
{
    struct list_t list;

    instanciate_list(&list);
    append(&list, 10);
    append(&list, 1);
    append(&list, 2);
    append(&list, 9);

    print_list(&list);

    return 0;
}
