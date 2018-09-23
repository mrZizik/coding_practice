#include <stdio.h>
#include "stack.h"

int main() {
    Stack *stack = create_stack(3);
    push(stack, 10);
    pip(stack);
    push(stack, 14);
    pip(stack);
    push(stack, 25);
    push(stack, -3);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    printf("Size: %d\n", stack->size);
    printf("Is empty: %d", stack_is_empty(stack));

    run_all_tests();
    return 0;
}

