#include <stdio.h>
#include <string.h> 
#include "historique.h"
#include "composition.h"
#include "listComposition.h"

composition compositionID(list_composition l, int ID){
    list_composition p;

    p = l;

    while( p != NULL){
        if( p->info.ID == ID){
            return p->info;
        } else {
            p = p->next;
        }
    }
}

date date_modification(){
    date date_modif;

    printf("l'anneé: ");
    scanf("%d", &date_modif.annee);

    printf("le mois :");
    scanf("%d", &date_modif.mois);

    if( date_modif.mois <= 0 || date_modif.mois > 12){
        printf("le mois doit etre entre [1, 12]");
        scanf("%d",&date_modif.mois);
    }

    printf("entrer la date d'aujourdhui ( la date doit eter que des nombre) :\n");
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

    int num_compo,i,x, ID_compo, ID_to_edit, ID_to_delet, ID_ajouter;
    list_composition l, l_after_delet;
    char name_compo[20];
    char name_composer[20];
    composition compo_chercher, compo_modifier, compo_avant_modifier, compo_ajouter, compo_delete;
    list_histo listH;
    date D_modif;
    

    printf("Musique Composition Manager\n\n");

    printf("Entrez le nombre de compositions que vous souhaitez créer :\n");
    scanf("%d",&num_compo);

    for( i=1; i<=num_compo; i++){
        ID_ajouter = ajouteComposition(l);

        compo_ajouter = compositionID(l, ID_ajouter);

        listH =  cree_historique(l, compo_ajouter, "ajouter", "", "","",  compo_ajouter.date_cretion);
        
    }
    
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
        afficherComposition(l);
        break;
    case 2:
        printf("Entrez le nom de la composition :\n");
        scanf("%s", name_compo);
        printf("Entrez le nom du compositeur :\n");
        scanf("%s", name_composer);

        compo_chercher = recherche_composition(name_compo, name_composer, l);
        break;

    case 3:
       printf("Entrez l'ID de la composition à modifier :\n");
       scanf("%d", &ID_to_edit);

       while (exist(l, ID_to_edit) == 0){
            printf("ce ID n'exist pas! entrer le ID correct");
            scanf("%d", &ID_to_edit);
        }

      // trouver la composition que on va modifier
       compo_avant_modifier = compositionID(l, ID_to_edit);
       compo_modifier = edit_composition(ID_to_edit, l); 
       D_modif = date_modification();



        // cree l'historique de modification

        if(strcmp(compo_avant_modifier.composer, compo_modifier.composer) != 0 ) {
            listH = cree_historique(l, compo_modifier, "modifier", "composer", compo_avant_modifier.composer, compo_modifier.composer, D_modif);

        } else {
            if( strcmp(compo_avant_modifier.name, compo_modifier.name) != 0 ) {
                listH = cree_historique(l, compo_modifier, "modifier", "name", compo_avant_modifier.name, compo_modifier.name, D_modif);

            } else {
                if( strcmp(compo_avant_modifier.statu, compo_modifier.statu) != 0) {
                    listH = cree_historique(l, compo_modifier, "modifier", "statu", compo_avant_modifier.statu, compo_modifier.statu, D_modif);

                } else {
                    if(compo_avant_modifier.property != compo_modifier.property) {
                        listH = cree_historique(l, compo_modifier, "modifier", "property", compo_avant_modifier.property, compo_modifier.property, D_modif);
                    }
                }
            }
        }

        break;



    case 4:
       printf("Entrez l'ID de la composition à supprimer :\n");
       scanf("%d", &ID_to_delet);

       while(exist(l, ID_to_delet) == 0) {
            printf("ce ID n'exist pas! entrer le ID correct");
            scanf("%d", &ID_to_delet);
        }

       compo_delete = compositionID(l, ID_to_delet);

       l_after_delet = supprimer_composition(ID_to_delet, l);

       D_modif = date_modification();
       listH = cree_historique(l, compo_delete, "suprrimer", "", "",  "", D_modif);

       break;
    case 5:
       printf("Voici l'historique des modifications :\n");
       afficher_historique(listH);
       break;
    case 6:
       printf("Voici les compositions en cours :\n");
       afficher_composition_en_cour(l);
       break;

    case 0:
       printf("Au revoir !\n");
       break;

    default:
        printf("Option invalide. Veuillez réessayer.\n");
        break;
    }

    return 0;
}