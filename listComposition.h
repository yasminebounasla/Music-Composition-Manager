#ifndef LISTCOMPOSITION_H
#define LISTCOMPOSITION_H

#include "composition.h"

// Structure for linked list node
typedef struct Node {
    composition info;
    struct Node *next;
} Node;

// Define list_composition as a pointer to Node
typedef Node* list_composition;

// Function prototypes

// Initialize an empty list
void init_list(list_composition *l);

// Add a new composition to the list and return its ID
int ajouteComposition(list_composition *l);

// Search for a composition by name and composer
composition recherche_composition(const char *name, const char *composer, list_composition l);

// Check if a composition with a given ID exists in the list
int exist(list_composition l, int ID);

// Edit a composition and return the modified version
composition edit_composition(int ID, list_composition l);

// Remove a composition by ID and return the updated list
list_composition supprimer_composition(int ID, list_composition l);

// Display all compositions in the list
void afficherComposition(list_composition l);

// Display compositions that are still in progress
void afficher_composition_en_cour(list_composition l);

#endif // LISTCOMPOSITION_H
