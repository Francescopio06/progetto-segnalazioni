#ifndef BST_H
#define BST_H
#include "segnalazione.h"

//ADT Lista come puntatore alla struttura nodo
typedef struct nodo *BST;

//operazioni su lista
BST newBST();
int emptyBST(BST Albero);
BST insert(BST Albero, segnalazione s);
void outputBST(BST Albero);

//operazioni di ricerca
segnalazione ricercaPerId(BST Albero, int id);
void ricercaPerCategoria(BST Albero, char* categoria);

//operazioni di stampa
void stampaPerStatus(BST Albero, char* status);
void stampaPerUrgenza(BST Albero);

//operazione di modifica
BST deleteNodo(BST Albero, int id);
//void stampaListaConIndice(lista lista1);

#endif