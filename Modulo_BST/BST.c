#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "segnalazione.h"

// struct nodo
struct nodo{
    //item
    segnalazione s;
    struct nodo* sx;
    struct nodo* dx;
};

//funzioni ausiliari
segnalazione getSegnalazione(struct nodo* N){
    return N->s;
}

void setSegnalazione(struct nodo* N, segnalazione s){
    N->s = s;
}

BST creaFoglia(segnalazione s){
    struct nodo* N;
    N = malloc(sizeof(struct nodo));
    if(N == NULL) return NULL;
    setSegnalazione(N,s);
    N->dx = NULL;
    N->sx = NULL;
    return N;
}

BST figlioSX(BST Albero){
    return Albero->sx;
}

BST figlioDX(BST Albero){
    return Albero->dx;
}

int minore(int x, int y){
    if(x < y) return 1;
    return 0;
}

//funzioni principali
BST newBST(){
    return NULL;
}

int emptyBST(BST Albero){
    return Albero == NULL;
}

void outputBST(BST Albero){

    if(Albero == NULL) return;

    outputBST(figlioSX(Albero));

    stampaSegnalazione(getSegnalazione(Albero));

    outputBST(figlioDX(Albero));
}

BST minvalue(BST Albero){
    BST current = Albero;
    while(current != NULL){
        current = figlioSX(current);
    }
    return current;

}

//funzioni di modifica
BST insert(BST Albero, segnalazione s){
    segnalazione x = getSegnalazione(Albero); //nodo attuale
    
    if(Albero == NULL) return creaFoglia(s);
    else if(minore(getChiave(s), getChiave(x))){
        Albero->sx = insert(figlioSX(Albero), s);
    } else if(minore(getChiave(x), getChiave(s))){
        Albero->dx = insert(figlioDX(Albero), s);
    }
    return Albero;
}

BST deleteNodo(BST root, int chiave){
    if(root == NULL) return NULL;
    segnalazione s = getSegnalazione(root);
   
    if(minore(chiave, getChiave(s))){
        root->sx = deleteNodo(figlioSX(root), chiave);
    } else if(minore(getChiave(s), chiave)){
        root->dx = deleteNodo(figlioDX(root), chiave);
    } 
    
    
    else{
        //caso con nessuno o un figlio
        if(figlioSX(root) == NULL){
            BST temp = figlioDX(root);
            free(root);
            return temp;
        } else if(figlioDX(root) == NULL){
            BST temp = figlioSX(root);
            free(root);
            return temp;
        }
        
        //caso con 2 figli
        BST temp = minvalue(figlioDX(root));
        s = getSegnalazione(temp);
        root->dx = deleteNodo(figlioDX(root), getChiave(s));
    }
    return root;
}


//funzioni di ricerca
segnalazione ricercaPerId(BST Albero, char* id){
    if(Albero == NULL) return NULL;

    segnalazione s = getSegnalazione(Albero);
    //cerco nel nodo attuale
    if(strcmp(getID(s), id) == 0){
        return s;
    }
    
    //cerco nel nodo di sinistra
    segnalazione tmp = ricercaPerId(figlioSX(Albero), id);
    if(tmp != NULL) return tmp;

    //cerca nel nodo di destra
    return ricercaPerId(figlioDX(Albero), id);
}

int esisteUrgenza(BST Albero, int livello){
    segnalazione s = getSegnalazione(Albero);
    
    if(getUrgenza(s) == livello){
        return 1;
    }

    return esisteUrgenza(figlioSX(Albero), livello) || esisteUrgenza(figlioDX(Albero), livello);
}


//funzioni di stampa
void stampaPerStatus(BST Albero, char* status){
    if(Albero == NULL) return;

    segnalazione s = getSegnalazione(Albero);

   stampaPerStatus(figlioSX(Albero), status);
   
    if(strcmp(getStatus(s), status) == 0){
        stampaSegnalazione(s);
    }

    stampaPerStatus(figlioDX(Albero), status);
}

void stampaPerUrgenza(BST Albero, int livello){
    if(Albero == NULL) return;
    segnalazione s = getSegnalazione(Albero);

    if(getUrgenza(s) == livello){
        stampaSegnalazione(s);
    }

    stampaPerUrgenza(figlioSX(Albero), livello);
    stampaPerUrgenza(figlioDX(Albero), livello);
}

