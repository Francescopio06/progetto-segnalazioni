#ifndef BST_H
#define BST_H
#include "segnalazione.h"

//ADT Lista come puntatore alla struttura nodo
typedef struct nodo *BST;

//operazioni su lista
BST newBST();
int emptyBST(BST Albero);
void outputBST(BST Albero);

//operazione di modifica
BST insert(BST Albero, segnalazione s);
BST CancellaSegnalazione(BST root, int chiave);

//operazioni di ricerca
segnalazione ricercaPerId(BST Albero, char* id);
int ricercaPerCategoria(BST Albero, char* categoria); //void + stampa
int esisteUrgenza(BST Albero, int livello);

//operazioni di stampa
void stampaPerStatus(BST Albero, char* status, int* trovato);
void stampaPerUrgenza(BST Albero, int livello);

//getter
BST figlioDX(BST Albero);
BST figlioSX(BST Albero);
segnalazione getSegnalazione(BST T);

//setter
void setSegnalazione(BST T, segnalazione s);


#endif