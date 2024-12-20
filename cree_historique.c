#include "historique.h"
#include "composition.h"
#include <stdio.h>
#include <string.h>

list_histo cree_historique(list_histo l, composition compo, char action[10], char field[50], char befor[50], char after[50], date D){
    list_histo new, p;

    new =(list_histo)malloc(sizeof(cell));

    
    new->info.composition_id = compo.ID;
    strcpy(new->info.action, action);
    strcpy(new->info.modified_field ,field);
    strcpy(new->info.before_modification ,befor);
    strcpy(new->info.after_modification ,after);
    new->info.modification_date.jour = D.jour;
    new->info.modification_date.mois = D.mois;
    new->info.modification_date.annee = D.annee;
    new->next = NULL;

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
