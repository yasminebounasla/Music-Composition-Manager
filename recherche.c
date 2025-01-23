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

int searchComposition(Stack *stack, const char *titleToSearch) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No compositions to search.\n");
        return 0;
    }

    for (int i = 0; i <= stack->top; i++) {
        if (strcmp(stack->stack[i].title, titleToSearch) == 0) {
            printf("Composition '%s' found.\n", titleToSearch);
            return 1;
        }
    }

    printf("Composition '%s' not found.\n", titleToSearch);
    return 0;
}
