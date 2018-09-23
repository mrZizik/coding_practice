#include <stdio.h>
#include "dynamic_array.c"

int main() {
    run_all_tests();

    DynamicArray *dynamicArray = create_dynamic_array(5);

    dynamic_array_push(dynamicArray, 1);
    dynamic_array_push(dynamicArray, 2);
    dynamic_array_push(dynamicArray, 3);
    dynamic_array_push(dynamicArray, 4);
    dynamic_array_push(dynamicArray, 5);

    dynamic_array_print(dynamicArray);

    dynamic_array_push(dynamicArray, 6);

    dynamic_array_print(dynamicArray);

    dynamic_array_set_element(dynamicArray, 0, 42);

    printf("First element is: %d \n", dynamic_array_get_element(dynamicArray, 0));

    dynamic_array_remove_element(dynamicArray, 0);

    dynamic_array_print(dynamicArray);



    return 0;
}