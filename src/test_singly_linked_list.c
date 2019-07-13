#include "singly_linked_list.h"

#include <stdbool.h>

int tests_run = 0;
int tests_passed = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do {  \
        tests_run++;        \
        if (!(test)) {      \
            FAIL();         \
            return 1;       \
        } else {            \
            tests_passed++; \
        }                   \
    } while(0)

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
