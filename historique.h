#ifndef HISTORIQUE_H  
#define HISTORIQUE_H

typedef struct date{
    int jour;
    int mois;
    int annee;
}date;

typedef struct {

    date modification_date;
    int composition_id;
    char composition_name[20];
    char action[10]; // deleting, adding, editing 
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
