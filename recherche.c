#include <stdio.h>
#include <string.h>
#include "composition.h"
#include "listComposition.h"


list_composition recherche_composition(int ID, list_composition l) {
    list_composition result;

    if (l == NULL) {
        return l;
    } else {
        result = l;
        while( result != NULL){
            if((strcmp(result->info.composer, name_composer) == 0) && ( strcmp(result->info.name, name_compo))) {
                 return result;
            } else {
                result = result->next;
             } 
        }
    
    return result;
}
