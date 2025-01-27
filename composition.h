#ifndef COMPOSITION_H  
#define COMPOSITION_H
#include <string.h> 

// struct for the date

typedef struct {
    int jour;
    int mois;
    int annee;
} date ;

//struct for composition
typedef struct {

    int ID;
    char name[20];
    char composer[20];
    char statu[10];
    int property;
    date date_cretion;

} composition;

#endif
