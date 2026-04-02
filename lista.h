#ifndef LISTA_H
#define LISTA_H
#include "segnalazione.h"

typedef struct{
    Segnalazione * s;
   struct nodo* next;
} nodo;

nodo* creaNodo(Segnalazione* x);
void InserisciSegnalazione(nodo** testa, Segnalazione* s);
void StampaLista(nodo* testa);
Segnalazione* ricercaPerId(nodo* testa, int id);
void ricercaPerCategoria(nodo** testa, char* categoria);
void aggiornaStatus(nodo* testa, int id);
void stampaPerStatus(nodo* testa, char* status);

#endif