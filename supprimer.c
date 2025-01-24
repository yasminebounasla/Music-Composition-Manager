#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "composition.h"
#include "listComposition.h"


list_composition supprimer_composition(int ID, list_composition l) {
list_composition prec;
list_composition p;

    if (l == NULL) {
        printf("la list de composition est vide ! \n");
        return l;
    } else {
        if( l->info.ID == ID ){
            p = l;
            l = l->next;
            free(p);
        } else {
            prec = l;
            p = l->next;

            while( p != NULL){
                if( p->info.ID == ID){
                    prc->next = p->next;
                    free(p);
                    p = prc->next;
                }
            }
        }
    }

    return l;
}
