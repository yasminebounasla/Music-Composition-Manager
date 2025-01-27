#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listComposition.h"

 void statutmus(char statut[]){
   bool s = false ;
   while (!s){

     printf("enter statut de la composition : ");

     int c;
     while ((c = getchar()) != '\n' && c != EOF);
     fgets(statut, 100, stdin);


     size_t len = strlen(statut);
        if (len > 0 && statut[len - 1] == '\n') {
            statut[len - 1] = '\0';
        }

     if (strcmp(statut, "en cours") == 0 || strcmp(statut, "termine") == 0 ||
        strcmp(statut, "planifie") == 0 || strcmp(statut, "en attente") == 0 ||
        strcmp(statut, "abandonne") == 0){
        s = true ;

      }else{
      printf("le statut doit etre soit 'en cours', 'termine', 'planifie', 'en attente', ou 'abandonne'.\n ");
     }
    }

  }

int exist(list_composition liste, int id){
    //parcourire p pour check if ID already exist
    list_composition p = liste ;
    while (p != NULL)
    {
       if(p->info.ID == id){
        return 1 ;//ID exist
       }
       p = p->next;
    }
    return 0;// ID doesn't exist
}



int ajoutComposition(list_composition* liste){
   // creation of new node that countain les donnee de l'utilisateur pour ce node
   list_composition new = (list_composition)malloc(sizeof(cell));

   printf("enter le nom de la composition : ");
   scanf("%s",new->info.name);

   printf("enter the composer de la composition : ");
   scanf("%s",new->info.composer);

   printf("enter la date de creation de la composition : \n");
   printf("le jour :");
   scanf("%d",&new->info.date_cretion.jour );
   printf("le mois :");
   scanf("%d", &new->info.date_cretion.mois);
   printf("l' annee :");
   scanf("%d", &new->info.date_cretion.annee);

   // Call statutmus to get a valid status and store it in new
   statutmus(new->info.statu);
   // ID
   int n ;
   do
   {
     printf("enter l'identifiant de la composition :");
     scanf("%d",&n);
     if (n <= 0){
     printf("id doit être un entier positif.\n ");
     }else if (exist(*liste,n)){
     printf("id exist déjà.enter un id unique.\n");
     }
    } while (n<=0 || exist(*liste,n));
   new->info.ID = n;
   // property
   int pr ;
   do
   {
     printf("enter la priorite de la composition :");
    scanf("%d",&pr);
      if (pr<1 || pr>10)
      {
      printf("la priorite doit être un nombre entre 1 et 10.\n ");
      }
   } while (pr<1 || pr>10);
    new->info.property = pr ;

    new->next = NULL ;




    // add the node on the list
    if (*liste == NULL)// empty list
    {
      *liste = new ;
    }else
    {
     list_composition temp = *liste ;// pointer dans head of the list
     list_composition prev = NULL;
     // parcourir la list pour find the correct position a travere id
     while (temp != NULL && temp->info.ID < n)
        {
         prev = temp;
         temp =temp->next;
        }
        if (prev == NULL)// inserer au debut de la list
        {
         new->next = *liste;
         *liste = new ;
        }else
        { // inserer au milieu ou a la fin
         prev->next = new ;
         new->next = temp ;
        }
    }
    // return the ID of new that added in the composition
    return new->info.ID;
  }
