#ifndef BST_H
#define BST_H
#include "segnalazione.h"

//ADT BST come puntatore alla struttura nodo
typedef struct nodo *BST;

//operazioni su lista

/*
Funzione newBST()
    La funzione crea e restituisce un albero vuoto.

    Parametri:
        - Nessun input
    
    Return:
        - puntatore vuoto alla struttura dati BST
*/
BST newBST();
int emptyBST(BST Albero);
void outputBST(BST Albero);

//operazione di modifica
/*
Funzione insert(Albero, s)
    La funzione inserisce all'interno dell'Albero
    la segnalazione fornita in input.

    Parametri:
        - Albero -> puntatore alla struttura dati BST
        - s -> puntatore alla struttura dati segnalazione

    Return:
        - puntatore alla struttura dati BST
*/
BST insert(BST Albero, segnalazione s);

/*
Funzione CancellaSegnalazione(root, chiave)
    La funzione cancella un nodo e gestisce i principali casi di cancellazione
    nel BST in cui il nodo sia la radice, in cui sia una foglia o che abbia un figlio.

    Parametri:
        - root -> puntatore alla struttura dati BST
        - chiave -> intero per ordinare il BST

    Return:
        - puntatore alla struttura dati BST con il nodo rimosso
*/
BST CancellaSegnalazione(BST root, int chiave);

//operazioni di ricerca
/*
Funzione ricercaPerId(Albero, id)
    Usa la ricorsione per scorrere il BST e ricercare la 
    segnalazione richiesta

    Parametri:
        - Albero -> puntatore alla struttura dati BST 
        - id -> puntatore all'array di caratteri 

    Return:
        - segnalazione richiesta
*/
segnalazione ricercaPerId(BST Albero, char* id);
int ricercaPerCategoria(BST Albero, char* categoria);
int esisteUrgenza(BST Albero, int livello);

//operazioni di stampa
void stampaPerStatus(BST Albero, char* status, int* trovato);
void stampaPerUrgenza(BST Albero, int livello);

/*
Funzione generaReport(Albero)
    La funzione attraversa il BST
    e genera statistiche relative a:

    - numero totale di segnalazioni
    - stato delle segnalazioni
    - categorie presenti
    - categoria più frequente

    Parametri:
        - Albero -> puntatore alla struttura dati BST

    Return:
        - Nessun valore restituito
*/
void generaReport(BST Albero);

//getter
BST figlioDX(BST Albero);
BST figlioSX(BST Albero);
segnalazione getSegnalazione(BST T);

//setter
void setSegnalazione(BST T, segnalazione s);


#endif