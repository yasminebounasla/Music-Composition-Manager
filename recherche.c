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

list_composition recherche_composition(int ID, list_composition l) {
    list_composition result;
    initStack(&result);

    if (isEmpty(&l)) {
        printf("Stack is empty! No compositions to search.\n");
        return result;
    }

    for (int i = 0; i <= l.top; i++) {
        if (l.stack[i].year == ID) {  // Assuming ID corresponds to the year for example
            printf("Composition with ID %d found.\n", ID);
            push(&result, l.stack[i]);
        }
    }

    if (isEmpty(&result)) {
        printf("Composition with ID %d not found.\n", ID);
    }
    
    return result;
}
