#ifndef GESTIONE_H
#define GESTIONE_H
#include "lista.h"

void aggiornaStatus(lista lista1, int id);
void filtraPerStatus(lista lista1, char* status);
lista rimuoviSegnalazione(lista lista1, int id);
void reportSegnalazioni(lista lista1);

#endif