#ifndef COMPOSITION_H  
#define COMPOSITION_H
#include <string.h> 
#include <time.h>

// struct for the composition 

typedef struct {

    int ID;
    char name[20];
    char composer[20];
    char statu[10];
    char property[10];
    time_t date_cretion;
    time_t modification; 

} composition;

#endif