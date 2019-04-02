#include "list.h"

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

void *srealloc(void *ptr, size_t size)
{
    if (!size)
        return NULL;

    void *mem;
    mem = realloc(ptr, size);

    if (!mem) {
        fprintf(stderr, "Fatal: Erro na alocação (realloc de %zu bytes)\n", size);
        exit(EXIT_FAILURE);
    }

    return mem;
}

void instanciate_list(struct list_t *list, size_t size)
{
    list->list = (char **)smalloc(sizeof(char *) * size);

    for (unsigned int i = 0;i < size;i++) {
        list->list[i] = (char *)smalloc(MAX_LINE_CHARACTERS * sizeof(char *));
    }

    list->used_space = 0;
    list->size = size;
}

void insert_into_list(struct list_t *list, char *value, unsigned int index)
{
    if (index >= list->size) {
        fprintf(stderr, "Não é possivel alocar '%s' na posição %d.\n",
                value, index);
        exit(EXIT_FAILURE);
    }

    strcpy(list->list[index], value);
    list->used_space++;
}

void append_into_list(struct list_t *list, char *value)
{
    list->used_space++;
    list->size++;

    list->list = (char **)srealloc(list->list, list->size);
    list->list[list->size-1] = (char *)smalloc(MAX_LINE_CHARACTERS * sizeof(char *));

    strcpy(list->list[list->size], value);
}

int main()
{
    struct list_t my_list;

    instanciate_list(&my_list, 10);
    insert_into_list(&my_list, "pizza0", 0);
    insert_into_list(&my_list, "pizza1", 1);
    insert_into_list(&my_list, "pizza2", 2);
    insert_into_list(&my_list, "pizza3", 3);
    insert_into_list(&my_list, "pizza4", 4);
    insert_into_list(&my_list, "pizza5", 5);
    insert_into_list(&my_list, "pizza6", 6);
    insert_into_list(&my_list, "pizza7", 7);
    insert_into_list(&my_list, "pizza8", 8);
    insert_into_list(&my_list, "pizza9", 9);
    append_into_list(&my_list, "pizza10");

    printf("%lu\n", my_list.size);

    for (unsigned int i = 0;i < my_list.used_space;i++)
        printf("%s\n", my_list.list[i]);
}
