#include <stdio.h>
#include <string.h>
#include "composition.h"
#include "listcomposition.h"

composition edit_composition(list_composition *list , int ID) {
    list_composition current = *list;
    composition compo_modifier = {0};

    while (current != NULL){
        if (current->info.ID == ID) {

            compo_modifier = current->info;
            printf ("Modification de la composition avec ID= %d\n",ID);
            printf ("Entrez le nouveau nom: ");
            scanf ("%s",current->info.name );

            printf ("Entrez le nouveau compositeur: ");
            scanf ("%s",current->info.composer);

            printf ("Entrez le nouveau statut: ");
            scanf ("%s",current->info.statu);

            printf ("Entrez la nouvelle priorité: ");
            scanf ("%d",&current->info.property);

            printf ("Entrez la nouvelle date de création(jour mois année): ");
            scanf ("%d %d %d",&current->info.date_cretion.jour,
                              &current->info.date_cretion.mois,
                              &current->info.date_cretion.annee);

            printf ("Composition modifiée avec succès.\n");                 
        }
        current=current->next;
    }
    printf("Composition avec ID= %d non trouvée.\n", ID);

    return compo_modifier;
}
