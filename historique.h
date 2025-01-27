#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include"composition.h"



typedef struct historique {

    date modification_date;
    int composition_id;
    char composition_name[20];
    char action[10]; // deleting, adding, editing
    char modified_field[50]; // name, status,....
    char before_modification[50];
    char after_modification[50];

} historique;

typedef struct cell_histo {
    historique info;
    struct cell_histo *next;
} cell_histo;

typedef cell_histo* list_histo;

#endif
