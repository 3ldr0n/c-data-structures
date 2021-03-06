#include <stdbool.h>

#include "singly_linked_list.h"
#include "test.h"

int test_instanciate_list(struct list_t *list)
{
    instanciate_list(list);
    _assert(list->size == 0);
    return 1;
}

int test_is_empty_list(struct list_t *list)
{
    _assert(is_list_empty(list));
    return 1;
}

int test_append(struct list_t *list)
{
    append(list, 10);
    append(list, 1);
    append(list, 2);
    append(list, 9);

    _assert(list->size == 4);
    _assert(list->head->value == 10);
    return 1;
}

int main()
{
    struct list_t list;

    test_instanciate_list(&list);

    test_is_empty_list(&list);

    test_append(&list);

    printf("%d/%d tests passed\n", tests_passed, tests_run);

    return 0;
}
