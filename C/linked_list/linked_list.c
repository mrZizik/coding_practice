//
// Created by mrzizik on 3/24/18.

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

LinkedList *create_linked_list() {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    checkAddress(linkedList);
    linkedList->head = NULL;
    linkedList->tail = NULL;
}

bool linked_list_empty(LinkedList *linkedList) {
    return linkedList->head == NULL && linkedList->tail == NULL;
}

void linked_list_print(LinkedList *linkedList) {
    if (linked_list_empty(linkedList)) {
        printf("List is empty");
        return;
    }

    Node *item = linkedList->head;
    int index = 0;
    do {
        printf("\n\t%d: %d", index, item->data);
        index++;
        item = item->next;
    } while(item != NULL);
}

void linked_list_push_start(LinkedList *linkedList, int item) {
    Node *node = malloc(sizeof(Node));
    node->data = item;
    node->next = linkedList->head;
    if (linked_list_empty(linkedList)) {
        linkedList->tail = node;
    }
    linkedList->head = node;
}

int linked_list_get_start(LinkedList *linkedList) {
    if (linked_list_empty(linkedList)) {
        printf("List is empty");
        return NULL;
    }
    return linkedList->head->data;
}

int linked_list_pop_start(LinkedList *linkedList) {
    if (linked_list_empty(linkedList)) {
        printf("List is empty");
        return NULL;
    }
    Node *node = linkedList->head;
    int tmp = node->data;
    linkedList->head = node->next;
    if (linkedList->head == NULL) {
        linkedList->tail = NULL;
    }
    free(node);
    return tmp;
}

void linked_list_push_back(LinkedList *linkedList, int item) {
    Node *node = malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;

    if (linked_list_empty(linkedList)) {
        linkedList->head = node;
    } else {
        Node *tmpTail = linkedList->tail;
        tmpTail->next = node;
    }
    linkedList->tail = node;
}

int linked_list_get_back(LinkedList *linkedList) {
    if (linked_list_empty(linkedList)) {
        printf("List is empty");
        return NULL;
    }
    return linkedList->tail->data;
}

int linked_list_pop_back(LinkedList *linkedList) {
    if (linked_list_empty(linkedList)) {
        printf("List is empty");
        return NULL;
    }
    Node *node = linkedList->tail;
    Node *tmpPreLast = linkedList->head;
    int tmp = node->data;

    do {
        tmpPreLast = tmpPreLast->next;
    } while(tmpPreLast->next != node);

    tmpPreLast->next = NULL;
    linkedList->tail = tmpPreLast;
    free(node);
    return tmp;
}

Node* linked_list_find(LinkedList *linkedList, int item) {
    Node *tmpNode = linkedList->head;
    while(tmpNode->data != item) {
        tmpNode = tmpNode->next;
    }

    return tmpNode;
}

void linked_list_add_before(LinkedList *linkedList, int elementBefore, int item) {
    Node *nodeBefore = linked_list_find(linkedList, elementBefore);

    if (nodeBefore == linkedList->head) {
        linked_list_push_start(linkedList, item);
        return;
    }

    Node *node = malloc(sizeof(Node));
    node->data = item;
    node->next = nodeBefore;

    Node *tmpNode = linkedList->head;
    while(tmpNode->next != nodeBefore) {
        tmpNode = tmpNode->next;
        break;
    }
//    printf("\n\n%d\n\n\n", tmpNode->next->data);

//
    tmpNode->next = node;
    return;
}

void checkAddress(void *ptr) {
    if (ptr == NULL) {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}
//

