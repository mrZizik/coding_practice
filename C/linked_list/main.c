#include <stdio.h>
#include "linked_list.c"

int main() {
    LinkedList *linkedList = create_linked_list();
//    printf(linked_list_empty(linkedList) ? "true" : "false");
    linked_list_push_back(linkedList, 10);
    linked_list_push_start(linkedList, 1);
    linked_list_push_start(linkedList, 5);
    linked_list_print(linkedList);
//    linked_list_add_before(linkedList, 1, 13);
//    linked_list_print(linkedList);
//    linked_list_add_before(linkedList, 5, 87);
//    linked_list_print(linkedList);
    return 0;
}