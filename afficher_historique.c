#include <stdio.h>
#include "historique.h"

void afficher_historique(list_histo l){
    list_histo p;

    p = l;

    while( p != NULL){
        printf("Composition %s :\n", p->info.composition_name);
        printf("ID : %d\n", p->info.composition_id);
        printf("Date of modification : %d / %d / %d \n", p->info.modification_date.jour , p->info.modification_date.mois, p->info.modification_date.annee);
        printf("Modification : %s %s\n", p->info.action, p->info.modified_field);
        printf("%s before modification : %s\n", p->info.modified_field, p->info.before_modification);
        printf("%s after modification : %s\n", p->info.modified_field ,p->info.after_modification);
        printf("\n");

        p = p->next;
    }
}