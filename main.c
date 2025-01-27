#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "historique.h"
#include "composition.h"
#include "listComposition.h"

list_histo cree_historique(list_histo l, composition compo, char action[10], char field[50], char before[50], char after[50], date d);
composition edit_composition(list_composition *list , int ID);
list_composition recherche_composition(char name_compo[20], char  name_composer[20] , list_composition l);
list_composition supprimer_composition(int ID, list_composition l);
int ajoutComposition(list_composition* liste);
int exist(list_composition liste, int id);
void afficher_historique(list_histo l);
void afficheComposition(list_composition liste);
void statutmus(char statut[]);
void afficher_composition_en_cours (list_composition list);



composition compositionID(list_composition l, int ID){
    list_composition p;
    composition empty = {0};

    p = l;

    while( p != NULL){
        if( p->info.ID == ID){
            return p->info;
        } else {
            p = p->next;
        }
    }

    return empty;
}

date date_modification(){
    date date_modif;

    printf("entrer la date d'aujourdhui :\n");
    printf("l'anneé: ");
    scanf("%d", &date_modif.annee);

    printf("le mois :");
    scanf("%d", &date_modif.mois);

    if( date_modif.mois <= 0 || date_modif.mois > 12){
        printf("le mois doit etre entre [1, 12]");
        scanf("%d",&date_modif.mois);
    }
    printf("le jour :");
    scanf("%d", &date_modif.jour);

    switch (date_modif.mois){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        while (date_modif.jour <= 0 || date_modif.jour > 31) {
            printf("le jour doit etre entre [1, 31]");
            scanf("%d", &date_modif.jour);
        }
        break;

    case 2:
        while( date_modif.jour <= 0 || date_modif.jour > 29){
            printf("le jour doit etre entre [1, 29]");
            scanf("%d", &date_modif.jour);
        }
        break;

    default:
         while( date_modif.jour <= 0 || date_modif.jour >30){
            printf("le jour doit etre entre [1, 30]");
            scanf("%d", &date_modif.jour);
        }
        break;
    }

    return date_modif;
}


int main() {

    int num_compo,i,x, ID_to_edit, ID_to_delet, ID_ajouter;
    list_composition l, l_after_delet, compo_chercher;
    char name_compo[20];
    char name_composer[20];
    composition compo_modifier, compo_avant_modifier, compo_ajouter, compo_delete;
    list_histo listH;
    date D_modif;


    printf("Musique Composition Manager\n\n");

    printf("Entrez le nombre de compositions que vous souhaitez creer :");
    scanf("%d",&num_compo);
    l = NULL;
    listH =NULL;

    printf("\n");

    for( i=0; i<num_compo; i++){

        printf("composition %d :\n", i+1);
        ID_ajouter = ajoutComposition(&l);

        compo_ajouter = compositionID(l, ID_ajouter);

        listH =  cree_historique(listH, compo_ajouter, "ajouter", "", "","", compo_ajouter.date_cretion);

         printf("\n");
    }

do{

    printf("\nChoisissez une option : \n");
    printf("1. Afficher toutes les compositions\n");
    printf("2. Rechercher une composition\n");
    printf("3. Modifier une composition\n");
    printf("4. Supprimer une composition\n");
    printf("5. Afficher l'historique des modifications\n");
    printf("6. Afficher les compositions en cours\n");
    printf("0. Quitter\n");

    scanf("%d", &x);


    switch (x)
    {
    case 1:
        afficheComposition(l);
        break;
    case 2:

        if( l == NULL){
            printf("Aucune composition disponible.\n");

        } else {
            printf("Entrez le nom de la composition :\n");
            scanf("%19s", name_compo);
            printf("Entrez le nom du compositeur :\n");
            scanf("%19s", name_composer);

            compo_chercher = recherche_composition(name_compo, name_composer, l);

            if( compo_chercher == NULL){
                printf("cette composition n'exist pas !");

            } else {
                printf("le nom de la composition : %s\n" , compo_chercher->info.name );
                printf("le ID : %d" , compo_chercher->info.ID );
                printf("le nom de composer :%s\n" , compo_chercher->info.composer);
                printf("the property :%d\n" , compo_chercher->info.property);
                printf("le statu :%s\n" , compo_chercher->info.statu);
                printf("la date de creation : %d/%d/%d\n" , compo_chercher->info.date_cretion.jour , compo_chercher->info.date_cretion.mois , compo_chercher->info.date_cretion.annee);
            }
        }
        break;

    case 3:

       if( l == NULL){
           printf("Aucune composition disponible.\n");

        } else {
            printf("Entrez l'ID de la composition à modifier :\n");
            scanf("%d", &ID_to_edit);

            while (exist(l, ID_to_edit) == 0){
                printf("ce ID n'exist pas! entrer le ID correct :");
                scanf("%d", &ID_to_edit);
            }


            // trouver la composition que on va modifier
            compo_avant_modifier = compositionID(l, ID_to_edit);
            compo_modifier = edit_composition(&l, ID_to_edit);
            D_modif.annee = compo_modifier.date_cretion.annee;

            if( compo_modifier.ID == 0){
                printf("Composition avec ID = %d non trouvée.\n", ID_to_edit);

            } else {

                D_modif.mois = compo_modifier.date_cretion.mois;
                D_modif.jour = compo_modifier.date_cretion.jour;
            }



            // cree l'historique de modification

            if(strcmp(compo_avant_modifier.composer, compo_modifier.composer) != 0 ) {
                listH = cree_historique(listH, compo_modifier, "modifier", "composer", compo_avant_modifier.composer, compo_modifier.composer, D_modif);

            } else {
                if( strcmp(compo_avant_modifier.name, compo_modifier.name) != 0 ) {
                    listH = cree_historique(listH, compo_modifier, "modifier", "name", compo_avant_modifier.name, compo_modifier.name, D_modif);

                } else {
                    if( strcmp(compo_avant_modifier.statu, compo_modifier.statu) != 0) {
                        listH = cree_historique(listH, compo_modifier, "modifier", "statu", compo_avant_modifier.statu, compo_modifier.statu, D_modif);

                    } else {
                        if(compo_avant_modifier.property != compo_modifier.property) {
                            listH = cree_historique(listH, compo_modifier, "modifier", "property", compo_avant_modifier.property, compo_modifier.property, D_modif);
                        }
                    }
                }
            }

        }

        break;



    case 4:

       if( l == NULL){
           printf("Aucune composition disponible.\n");

        } else {
            printf("Entrez l'ID de la composition à supprimer :\n");
            scanf("%d", &ID_to_delet);

            while(exist(l, ID_to_delet) == 0) {
                printf("ce ID n'exist pas! entrer le ID correct");
                scanf("%d", &ID_to_delet);
            }

            compo_delete = compositionID(l, ID_to_delet);

            l_after_delet = supprimer_composition(ID_to_delet, l);
            l = l_after_delet;

            D_modif = date_modification();
            listH = cree_historique(listH, compo_delete, "supprimer", "", "",  "", D_modif);
        }

        break;

    case 5:
        if( listH == NULL){
            printf("l'historique est vide !");

        } else {
            printf("Voici l'historique des modifications :\n");
            afficher_historique(listH);
        }

       break;

    case 6:

       if( l == NULL){
            printf("Aucune composition disponible.\n");

        } else {
            printf("Voici les compositions en cours :\n");
            afficher_composition_en_cours(l);
        }

       break;

    case 0:
       printf("Au revoir !\n");
       break;

    default:
        printf("Option invalide. Veuillez réessayer.\n");
        break;
    }

} while( x != 0);

    return 0;
}

