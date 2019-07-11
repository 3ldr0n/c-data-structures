#include "singly_linked_list.h"

#include <stdbool.h>

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
    assert(list.size == 0, "size == 0");

    append(&list, 10);
    append(&list, 1);
    append(&list, 2);
    append(&list, 9);

    assert(list.size == 4, "size == 4");

    return 0;
}
