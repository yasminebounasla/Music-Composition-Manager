#ifndef COMPOSITION_H  
#define COMPOSITION_H
#include <string.h> 

typedef struct date
{
  int jour ;
  int mois ;
  int annee ;
}date;
// struct for the composition 
typedef struct {

    int ID;
    char name[20];
    char composer[20];
    char statu[10];
    int property;
    date date_cretion;
    date modification; 

} composition;

#endif