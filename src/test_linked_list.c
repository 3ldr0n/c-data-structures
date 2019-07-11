#include <stdbool.h>

#include "doubly_linked_list.h"

int number_of_tests_passed = 0;

void assert(bool expr, char* error)
{
    if (!expr) {
        printf("Assertion error on:\n");
        printf("%s\n", error);
        exit(-1);
    }
    number_of_tests_passed++;
}

int main()
{
    struct list_t list;

    instanciate_list(&list);
    assert(list.size == (size_t) 0, "size == 0");

    append(&list, 10);
    append(&list, 1);
    append(&list, 2);

    assert(list.size == 3, "size == 3");

    remove_first(&list);

    assert(list.size == 2, "size == 2");

    remove_last(&list);

    assert(list.tail->value == list.head->value, "value == value");
    assert(list.size == 1, "size == 1");

    printf("%d tests passed\n", number_of_tests_passed);
    print_list(&list);

    return 0;
}
