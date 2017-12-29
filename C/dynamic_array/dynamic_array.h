//
// Created by mrzizik on 12/29/17.
//

#ifndef DYNAMIC_ARRAY_DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_DYNAMIC_ARRAY_H

#include <stdbool.h>

int minCapacity = 4;
int growthFactor = 2;

typedef struct DynamicArrayImpl {
    int size; //number of elements in array
    int capacity; //number of elements, that can be stored in our array
    int *data; //array data
} DynamicArray;

//functions

//Creates a new DynamicArray instance
DynamicArray *create_dynamic_array(int capacity);
//Destroys array
void dynamic_array_destroy(DynamicArray *arrtr);
//Turns user entered capacity to capacity in x^growthFactor
int calculate_capacity(int capacity);
//Print array info and data
void dynamic_array_print(DynamicArray *arrtr);
//Push element to end of array
void dynamic_array_push(DynamicArray *arrtr, int item);
//Make size of array bigger to power of growthFactor
void dynamic_array_upsize(DynamicArray *arrtr);
//Check if resize is needed
void dynamic_array_resize_if_needed(DynamicArray *arrayPtr, int new_size);
//Get element at index
int dynamic_array_get_element(DynamicArray *arrayPtr, int index);
//Set element at index
void dynamic_array_set_element(DynamicArray *arrayPtr, int index, int value);
//Get size of array
int dynamic_array_get_size(DynamicArray *arrayPtr);
//Get capacity of array
int dynamic_array_get_capacity(DynamicArray *arrayPtr);
//Remove element from array and shift elements left
void dynamic_array_remove_element(DynamicArray *arrayPtr, int index);
// is array empty
bool dynamic_array_is_empty(DynamicArray *arrayPtr);

void run_all_tests();

void test_append();
void test_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();
void test_resize();
void test_get();
void test_set();
void test_remove();
#endif //DYNAMIC_ARRAY_DYNAMIC_ARRAY_H
