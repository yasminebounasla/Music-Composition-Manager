#ifndef HISTORIQUE_H  
#define HISTORIQUE_H
#include <time.h>

typedef struct {

    time_t modification_date;
    int composition_id;
    char action[10]; // delete, add, edit
    char modified_field[50]; // name, status,....
    char before_modification[50];
    char after_modification[50];
    
} historique;

typedef struct cell {
    historique info;
    struct cell *next;
} cell;

typedef cell* list_histo; 

#endif 
