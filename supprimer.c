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
} list_composition;

void initStack(list_composition *stack) {
    stack->top = -1;
}

int isEmpty(list_composition *stack) {
    return stack->top == -1;
}

int isFull(list_composition *stack) {
    return stack->top == MAX_COMPOSITIONS - 1;
}

void push(list_composition *stack, Composition composition) {
    if (isFull(stack)) {
        printf("Stack is full! Cannot add more compositions.\n");
    } else {
        stack->stack[++stack->top] = composition;
    }
}

void pop(list_composition *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
    }
}

list_composition supprimer_composition(int ID, list_composition l) {
    if (isEmpty(&l)) {
        printf("Stack is empty! No compositions to delete.\n");
        return l;
    }

    list_composition tempStack;
    initStack(&tempStack);
    int found = 0;

    while (!isEmpty(&l)) {
        Composition current = l.stack[l.top];
        pop(&l);

        if (current.year == ID) {  // Assuming ID corresponds to the year for example
            found = 1;
            printf("Composition with ID %d deleted successfully.\n", ID);
            continue;
        }
        push(&tempStack, current);
    }

    while (!isEmpty(&tempStack)) {
        push(&l, tempStack.stack[tempStack.top]);
        pop(&tempStack);
    }

    if (!found) {
        printf("Composition with ID %d not found.\n", ID);
    }

    return l;
}
