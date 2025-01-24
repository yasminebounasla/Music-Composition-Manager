#ifndef LISTCOMPOSITION_H
#define LISTCOMPOSITION_H
#include "composition.h"
typedef struct cell {
    composition info;
    struct cell *next;
} cell;
typedef cell* list_composition; 
#endif
