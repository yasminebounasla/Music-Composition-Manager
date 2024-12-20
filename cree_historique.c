#include "historique.h"
#include "composition.h"
#include <stdio.h>
#include <string.h>


list_histo cree_historique(list_histo l, composition compo, char action[10], char field[50], char before[50], char after[50], date d){
    list_histo new, p;

    new =(list_histo)malloc(sizeof(cell));

    
    if (new != NULL){
        new->info.composition_id = compo.ID;
        strcpy(new->info.action, action);
        strcpy(new->info.composition_name, compo.name);
        strcpy(new->info.modified_field ,field);
        strcpy(new->info.before_modification ,before);
        strcpy(new->info.after_modification ,after);
        new->info.modification_date.jour = d.jour;
        new->info.modification_date.mois = d.mois;
        new->info.modification_date.annee = d.annee;

        new->next = NULL;
    }

    if( l == NULL){
        l = new;

    } else {

        p = l;
        while ( p->next != NULL){
            p = p->next;
        }
        p->next = new;
    }

    return l;
    
}
