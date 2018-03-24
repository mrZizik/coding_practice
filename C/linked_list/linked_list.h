//
// Created by mrzizik on 3/24/18.
//

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include <stdbool.h>

typedef struct NodeImpl{
    struct NodeImpl *next; // pointer to next node
    int data; // data
} Node;

typedef struct {
    Node *head; // pointer to head
    Node *tail; // pointer to tail
} LinkedList;

//functions

//Creates a new DynamicArray instance
LinkedList *create_linked_list();
//Destroys array
void linked_list_destroy(LinkedList *arrayPtr);
//Print array info and data
void linked_list_print(LinkedList *arrayPtr);
//Push element to start of array
void linked_list_push_start(LinkedList *arrayPtr, int item);
//Get first element
int linked_list_get_start(LinkedList *arrayPtr);
//Push element to back
void linked_list_push_back(LinkedList *arrayPtr, int item);
//Get element from back
int linked_list_get_back(LinkedList *arrayPtr);
//Delete last element
int linked_list_pop_back(LinkedList *arrayPtr);
//Find element
Node* linked_list_find(LinkedList *arrayPtr, int item);
//Empty
bool linked_list_empty(LinkedList *arrayPtr);
//Add before
void linked_list_add_before(LinkedList *arrayPtr, int elementBefore, int item);
#endif //LINKED_LIST_LINKED_LIST_H
