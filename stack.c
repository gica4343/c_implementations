#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->collection = malloc(sizeof(int) * capacity);
    if(stack->collection == NULL) {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}
void destroy_stack(Stack *stack) {
    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack) {
    return stack->capacity == stack->size;
}
bool is_empty(Stack *stack) {
    return stack->size == 0;
}

bool pop(Stack *stack, int *item) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return false;
    }
    *item = 0;
    stack->size--;
    return true;
}

bool push(Stack *stack, int item) {
    if(is_full(stack)) {
        printf("Stack is full\n");
        return false;
    }

    stack->collection[stack->size] = item;
    stack->size++;

    return true;
}
bool peek(Stack *stack, int *item) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return false;
    }

    *item = stack->collection[stack->size - 1];
    return true;
}

int main() {
    Stack *stack = create_stack(5);
    if (stack == NULL) {
        printf("Error creating stack.\n");
        return 1;
    }
    push(stack, 2);
    printf("%d", stack->collection[stack->size]);
    //peek(stack, stack->collection);

    // for (int i = 0; i < stack->capacity; i++) {
    //     printf("%d\n", stack->collection[i]); 
    // }
    destroy_stack(stack);
    return 0;
}