#include "composition.h"
#include "listComposition.h"
#include <stdio.h>

void afficheComposition(composition* liste){
   list_composition p = liste ;
   if (p == NULL)
   {
      printf("la liste des composition est vide.\n");
   }else
   {
     while (p != NULL)
     {//affiche the details pour chaque composition
       printf("id : %d\n",p->info.ID);

       printf("nom : %s\n",p->info.name);

       printf("auteur : %s\n",p->info.composer);
  
       printf("date de creation : %02d/%02d/%04d\n",p->info.date_cretion.jour,p->info.date_cretion.mois,p->info.date_cretion.annee);
       
       printf("date de modification : %02d/%02d/%04d\n",p->info.modification.jour,p->info.modification.mois,p->info.modification.annee);
       
       printf("statut : %s\n",p->info.statu);

       printf("priorité : %d\n",p->info.property);

       p = p->next;// Move to the next element in the list
      }
    }
  }