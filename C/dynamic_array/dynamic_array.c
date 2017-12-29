//
// Created by mrzizik on 12/29/17.
//


#include <assert.h>
#include <stdlib.h>
#include "dynamic_array.h"


DynamicArray *create_dynamic_array(int capacity) {
    int array_capacity = calculate_capacity(capacity);

    DynamicArray *dynamicArray = malloc(sizeof(DynamicArray));
    checkAddress(dynamicArray);

    dynamicArray->capacity = array_capacity;
    dynamicArray->size = 0;
    dynamicArray->data = (int *)malloc(sizeof(int) * array_capacity);
    checkAddress(dynamicArray->data);

    return dynamicArray;
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

void checkAddress(void *ptr) {
    if (ptr == NULL) {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

void dynamic_array_destroy(DynamicArray *arrayPtr) {
    free(arrayPtr->data);
    free(arrayPtr);
}

void dynamic_array_print(DynamicArray *arrayPtr) {
    printf("Size: %d\n", arrayPtr->size);
    printf("Capacity: %d\n", arrayPtr->capacity);

    printf("Items: \n\tIndex: Value\n");
    for (int i=0; i<arrayPtr->size; i++) {
        printf("\t%d: %d\n", i, *(arrayPtr->data+i));
    }
}

void dynamic_array_push(DynamicArray *arrayPtr, int item) {
    dynamic_array_resize_if_needed(arrayPtr, arrayPtr->size + 1);

    *(arrayPtr->data + arrayPtr->size) = item;
    ++(arrayPtr->size);
}

void dynamic_array_upsize(DynamicArray* arrayPtr) {
    int oldCapacity = arrayPtr->capacity;
    int newCapacity = calculate_capacity(oldCapacity);

    int *newData = (int *)malloc(sizeof(int)*newCapacity);
    checkAddress(newData);

    for (int i = 0; i < oldCapacity; i++) {
        *(newData + i) = *(arrayPtr->data+i);
    }

    free(arrayPtr->data);
    arrayPtr->data = newData;
    arrayPtr->capacity = newCapacity;
}

void dynamic_array_resize_if_needed(DynamicArray *dynamicArray, int new_size) {
    if (dynamicArray->capacity <= new_size) {
        dynamic_array_upsize(dynamicArray);
    }
}

int dynamic_array_get_element(DynamicArray *arrayPtr, int index) {
    if (arrayPtr->size < index || index < 0) {
        exit(EXIT_FAILURE);
    }
    return *(arrayPtr->data+index);
}

void dynamic_array_set_element(DynamicArray *arrayPtr, int index, int value) {
    if (arrayPtr->size < index || index < 0) {
        exit(EXIT_FAILURE);
    }
    *(arrayPtr->data+index) = value;
}

void dynamic_array_remove_element(DynamicArray *arrayPtr, int index) {
    if (arrayPtr->size < index || index < 0) {
        exit(EXIT_FAILURE);
    }

    for (int i = index+1; i < arrayPtr->size; i++) {
        *(arrayPtr->data+i-1) = *(arrayPtr->data+i);
    }

    dynamic_array_set_element(arrayPtr, arrayPtr->size-1, NULL);
    --arrayPtr->size;

}

int dynamic_array_size(DynamicArray *arrayPtr) {
    return arrayPtr->size;
}

int dynamic_array_capacity(DynamicArray *arrayPtr) {
    return arrayPtr->capacity;
}

bool dynamic_array_is_empty(DynamicArray *arrayPtr) {
    return dynamic_array_size(arrayPtr) == 0;
}


//Tests

void run_all_tests() {
    test_init();
    test_append();
    test_append_past_capacity();
    test_capacity();
    test_empty();
    test_get();
    test_set();
    test_remove();
}

void test_init() {
    DynamicArray *dynamicArray = create_dynamic_array(3);
    assert(dynamic_array_size(dynamicArray) == 0);
    dynamic_array_destroy(dynamicArray);
}

void test_append() {
    DynamicArray *dynamicArray = create_dynamic_array(3);
    dynamic_array_push(dynamicArray, 15);
    dynamic_array_push(dynamicArray, 35);
    assert(dynamic_array_size(dynamicArray) == 2);
    dynamic_array_destroy(dynamicArray);
}

void test_append_past_capacity() {
    DynamicArray *dynamicArray = create_dynamic_array(1);
    dynamic_array_push(dynamicArray, 15);
    dynamic_array_push(dynamicArray, 35);
    dynamic_array_push(dynamicArray, 52);
    int oldCapacity = dynamic_array_capacity(dynamicArray);
    dynamic_array_push(dynamicArray, 23);
    assert(dynamic_array_capacity(dynamicArray) == oldCapacity*2);
    dynamic_array_destroy(dynamicArray);
}

void test_capacity() {
    DynamicArray *dynamicArray = create_dynamic_array(1);
    dynamic_array_push(dynamicArray, 15);
    dynamic_array_push(dynamicArray, 35);
    dynamic_array_push(dynamicArray, 52);
    assert(dynamic_array_capacity(dynamicArray) == 4);
    dynamic_array_destroy(dynamicArray);
}

void test_empty() {
    DynamicArray *dynamicArray = create_dynamic_array(1);
    assert(dynamic_array_is_empty(dynamicArray) == 1);
    dynamic_array_push(dynamicArray, 15);
    assert(dynamic_array_is_empty(dynamicArray) == 0);
    dynamic_array_destroy(dynamicArray);
}

void test_get() {
    DynamicArray *dynamicArray = create_dynamic_array(1);
    dynamic_array_push(dynamicArray, 15);
    assert(dynamic_array_get_element(dynamicArray, 0) == 15);
    dynamic_array_destroy(dynamicArray);
}

void test_set() {
    DynamicArray *dynamicArray = create_dynamic_array(1);
    dynamic_array_push(dynamicArray, 15);
    dynamic_array_set_element(dynamicArray, 0, 250);
    assert(dynamic_array_get_element(dynamicArray, 0) == 250);
    dynamic_array_destroy(dynamicArray);
}

void test_remove() {
    DynamicArray *dynamicArray = create_dynamic_array(1);
    dynamic_array_push(dynamicArray, 1);
    dynamic_array_push(dynamicArray, 2);
    dynamic_array_push(dynamicArray, 3);
    dynamic_array_push(dynamicArray, 4);
    dynamic_array_push(dynamicArray, 5);
    dynamic_array_remove_element(dynamicArray, 2);
    assert(dynamic_array_size(dynamicArray) == 4);
    assert(dynamic_array_get_element(dynamicArray, 2) == 4);
    dynamic_array_destroy(dynamicArray);
}