#include "doubly_linked_list.h"

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
    list->tail = NULL;

    list->size = 0;
}

bool is_list_empty(struct list_t *list)
{
    return list->head == NULL;
}

void append(struct list_t *list, int value)
{
    struct node *new_node = (struct node *)smalloc(sizeof(struct node *));
    new_node->value = value;
    new_node->next = NULL;

    if (is_list_empty(list)) {
        new_node->prev = NULL;
        list->tail = list->head = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void print_list(struct list_t *list)
{
    for (struct node *item = list->head;item != NULL;item = item->next)
        printf("%d ", item->value);

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
