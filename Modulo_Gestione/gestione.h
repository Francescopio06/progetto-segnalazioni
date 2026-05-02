#ifndef GESTIONE_H
#define GESTIONE_H
#include "BST.h"

void inserisciSegnalazione(BST* Albero);

void visualizzaSegnalazione(BST Albero);

void ricercaSegnalazione(BST Albero);

void aggiornaStato(BST Albero);

void filtraSegnalazioni(BST Albero);

void mostraUrgenza(BST Albero);

void eliminaSegnalazione(BST Albero);

void generaReport(BST Albero);

#endif