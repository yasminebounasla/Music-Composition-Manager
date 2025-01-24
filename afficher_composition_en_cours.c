#include <stdio.h>
#include <string.h>
#include "composition.h"
#include "listcomposition.h"

void afficher_composition_en_cours (list_composition list){
    list_composition current = list;

    printf ("Composition en cours: \n");

    while (current != NULL){
        if(strcmp(current->info.statu,"en cours") ==0) {
            printf ("ID: %d\n",current->info.ID);
            printf ("Nom: %s\n",current->info.name);
            printf ("compositeur: %s\n", current->info.composer);
            printf ("Statut: %s\n", current->info.statu);
            printf ("Priorité: %d\n", current->info.property);
            printf ("Date de création: %02d/%02d/%d\n",
                     current->info.date_cretion.jour,
                     current->info.date_cretion.mois,
                     current->info.date_cretion.annee );
            printf ("----------------------------\n");

        }
        current = current->next;
    }
}

