#include <stdio.h>
#include <string.h>
#include "composition.h"

#define MAX_COMPOSITIONS 10

typedef struct {
    char title[50];
    char composer[50];
    int year;
} Composition;

typedef struct {
    Composition stack[MAX_COMPOSITIONS];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_COMPOSITIONS - 1;
}

void push(Stack *stack, Composition composition) {
    if (isFull(stack)) {
        printf("Stack is full! Cannot add more compositions.\n");
    } else {
        stack->stack[++stack->top] = composition;
    }
}

void pop(Stack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
    }
}

void deleteComposition(Stack *stack, const char *titleToDelete) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No compositions to delete.\n");
        return;
    }

    Stack tempStack;
    initStack(&tempStack);

    int found = 0;

    while (!isEmpty(stack)) {
        Composition current = stack->stack[stack->top];
        pop(stack);

        if (strcmp(current.title, titleToDelete) == 0) {
            found = 1;
            printf("Composition '%s' deleted successfully.\n", titleToDelete);
            continue;
        }
        push(&tempStack, current);
    }

    while (!isEmpty(&tempStack)) {
        push(stack, tempStack.stack[tempStack.top]);
        pop(&tempStack);
    }

    if (!found) {
        printf("Composition '%s' not found.\n", titleToDelete);
    }
}
