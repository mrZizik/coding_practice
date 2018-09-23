//
// Created by mrzizik on 23.09.18.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int minCapacity = 4;
int growthFactor = 2;

int calculate_capacity(int capacity);
void check_address(void *ptr);
void dynamic_array_upsize(Stack *stackPtr);
void dynamic_array_resize_if_needed(Stack *stackPtr, int new_size);

Stack *create_stack(int capacity) {
    int array_capacity = calculate_capacity(capacity);

    Stack *stack = malloc(sizeof(Stack));
    check_address(stack);

    stack->capacity = array_capacity;
    stack->size = 0;
    stack->data = (int *)malloc(sizeof(int) * array_capacity);
    check_address(stack->data);

    return stack;
}

void push(Stack *stackPtr, int element) {
    dynamic_array_resize_if_needed(stackPtr, stackPtr->size + 1);
    *(stackPtr->data + stackPtr->size) = element;
    ++(stackPtr->size);
}

int pop(Stack *stackPtr) {
    int element = *(stackPtr->data+stackPtr->size-1);
    dynamic_array_remove_last_element(stackPtr);
    return element;
}

void pip(Stack *stackPtr) {
    printf("Size: %d\n", stackPtr->size);

    printf("Items: \n\tIndex: Value\n");
    for (int i=0; i<stackPtr->size; i++) {
        printf("\t%d: %d\n", i, *(stackPtr->data+i));
    }
}

bool stack_is_empty(Stack *stackPtr) {
    return stackPtr->size == 0;
}

void destroy_stack(Stack *stack) {
    free(stack->data);
    free(stack);
}

int calculate_capacity(int capacity) {
    if (capacity < 1) {
        exit(EXIT_FAILURE);
    }

    int true_capacity = minCapacity;

    while (capacity > true_capacity/growthFactor) {
        true_capacity *= growthFactor;
    }

    return true_capacity;
}

void check_address(void *ptr) {
    if (ptr == NULL) {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

void dynamic_array_upsize(Stack* arrayPtr) {
    int oldCapacity = arrayPtr->capacity;
    int newCapacity = calculate_capacity(oldCapacity);

    int *newData = (int *)malloc(sizeof(int)*newCapacity);
    check_address(newData);

    for (int i = 0; i < oldCapacity; i++) {
        *(newData + i) = *(arrayPtr->data+i);
    }

    free(arrayPtr->data);
    arrayPtr->data = newData;
    arrayPtr->capacity = newCapacity;
}

void dynamic_array_resize_if_needed(Stack *stackPtr, int new_size) {
    if (stackPtr->capacity <= new_size) {
        dynamic_array_upsize(stackPtr);
    }
}

void dynamic_array_remove_last_element(Stack *stackPtr) {
    *(stackPtr->data+stackPtr->size-1) = NULL;
    --stackPtr->size;
}


void run_all_tests() {
    test_create();
    test_is_empty();
    test_push_pop();
}

void test_create() {
    Stack *stack = create_stack(3);
    assert(stack->size == 0);
    destroy_stack(stack);
}

void test_push_pop() {
    Stack *stack = create_stack(3);
    push(stack, 10);
    assert(pop(stack) == 10);
    destroy_stack(stack);
}

void test_is_empty() {
    Stack *stack = create_stack(3);
    assert(stack_is_empty(stack));
    destroy_stack(stack);
}

