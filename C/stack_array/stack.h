//
// Created by mrzizik on 23.09.18.
//

#ifndef STACK_ARRAY_STACK_H
#define STACK_ARRAY_STACK_H

#include <stdbool.h>

typedef struct {
    int size; //number of elements in array
    int capacity; //number of elements, that can be stored in our array
    int *data; //array data
} Stack;

//Create stack
Stack *create_stack(int capacity);
//Push stack
void push(Stack *stackPtr, int element);
//Pop stack
int pop(Stack *stackPtr);
//Destroy
void destroy_stack(Stack *stackPtr);
//Print stack
void pip(Stack *stackPtr);
//Is stack empty
bool stack_is_empty(Stack *stackPtr);



//Tests
void run_all_tests();

void test_create();
void test_push_pop();
void test_is_empty();

#endif //STACK_ARRAY_STACK_H
