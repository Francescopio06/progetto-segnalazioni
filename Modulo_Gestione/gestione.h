#ifndef GESTIONE_H
#define GESTIONE_H
#include "BST.h"
/*
FILE: gestione.h
AUTORE: Francesco Pio Siano

Questo header definisce l'interfaccia pubblica
del modulo 'Gestione'.

Il modulo espone le principali operazioni
applicative disponibili per la gestione delle
segnalazioni, consentendo l'interazione tra
l'utente ed i moduli sottostanti.

Le funzionalità disponibili includono:
- inserimento di una nuova segnalazione
- visualizzazione delle segnalazioni presenti
- ricerca per ID o categoria
- aggiornamento dello stato
- filtraggio per stato
- visualizzazione per urgenza
- eliminazione di una segnalazione
- generazione del report

L'implementazione interna delle funzioni helper
rimane nascosta all'interno del file sorgente
secondo il principio di information hiding.
*/
void inserisciSegnalazione(BST* Albero);

void visualizzaSegnalazione(BST Albero);

void ricercaSegnalazione(BST Albero);

void aggiornaStato(BST Albero);

void filtraSegnalazioni(BST Albero);

void mostraUrgenza(BST Albero);

void eliminaSegnalazione(BST* Albero);

void visualizzaReport(BST Albero);

void pulisciSchermo(void);

#endif
