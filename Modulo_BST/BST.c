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

//funzioni Helper

static BST creaFoglia(segnalazione s){
    struct nodo* T;
    T = malloc(sizeof(struct nodo));
    if(T == NULL) return NULL;
    T->s = s;
    T->dx = NULL;
    T->sx = NULL;
    return T;
}

static int minore(int x, int y){
    if(x < y) return 1;
    return 0;
}

static BST minvalue(BST Albero){
    BST current = Albero;

    while(current->sx != NULL){
        current = current->sx;
    }
    return current;

}

//FUNZIONI PRINCIPALI

BST newBST(){
    return NULL;
}

int emptyBST(BST Albero){
    return Albero == NULL;
}

void outputBST(BST Albero){

    if(Albero == NULL) return;

    outputBST(Albero->sx);

    stampaSegnalazione(Albero->s);

    outputBST(Albero->dx);
}

//FUNZIONI DI MODIFICA

BST insert(BST Albero, segnalazione s){

    if(Albero == NULL) return creaFoglia(s);
    else if(minore(getChiave(s), getChiave(Albero->s))){
        Albero->sx = insert(Albero->sx, s);
    } else if(minore(getChiave(Albero->s), getChiave(s))){
        Albero->dx = insert(Albero->dx, s);
    }
    return Albero;
}

BST CancellaSegnalazione(BST root, int chiave){
    
    if(root == NULL) return NULL;

    if(minore(chiave, getChiave(root->s))){
        root->sx = CancellaSegnalazione(root->sx, chiave);
    } else if(minore(getChiave(root->s), chiave)){
        root->dx = CancellaSegnalazione(root->dx, chiave);
    } 
    
    
    else{
        //caso con nessuno o un figlio
        if(figlioSX(root) == NULL){
            BST temp = root->dx;
            free(root);
            return temp;
        } else if(root->dx == NULL){
            BST temp = root->sx;
            free(root);
            return temp;
        }
        
        //caso con 2 figli
        BST temp = minvalue(root->dx);
        root->s = getSegnalazione(temp);
        root->dx = CancellaSegnalazione(root->dx, getChiave(root->s));
    }
    return root;
}

//FUNZIONI DI RICERCA

segnalazione ricercaPerId(BST Albero, char* id){
    if(Albero == NULL) return NULL;
    
    //cerco nel nodo attuale
    if(strcmp(getID(Albero->s), id) == 0){
        return Albero->s;
    }
    
    //cerco nel nodo di sinistra
    segnalazione tmp = ricercaPerId(Albero->sx, id);
    if(tmp != NULL) return tmp;

    //cerca nel nodo di destra
    return ricercaPerId(Albero->dx, id);
}

int ricercaPerCategoria(BST Albero, char* categoria){ //intero temporaneo

    int cont = 0;

    if(Albero == NULL) return 0;
    
    if(strcmp (getCategoria(Albero->s), categoria) == 0){
        stampaSegnalazione(Albero->s);
        cont = 1;
    }  

    cont += ricercaPerCategoria(Albero->sx, categoria);
    cont += ricercaPerCategoria(Albero->dx, categoria);

    return cont;
}

int esisteUrgenza(BST Albero, int livello){
    if(Albero == NULL) return 0;
   
    if(getUrgenza(Albero->s) == livello){
        return 1;
    }

    return esisteUrgenza(Albero->sx, livello) || esisteUrgenza(Albero->dx, livello);
}

//FUNZIONI DI STAMPA

void stampaPerStatus(BST Albero, char* status){
    if(Albero == NULL) return;

   stampaPerStatus(Albero->sx, status);
   
    if(strcmp(getStatus(Albero->s), status) == 0){
        stampaSegnalazione(Albero->s);
    }

    stampaPerStatus(Albero->dx, status);
}

void stampaPerUrgenza(BST Albero, int livello){
    if(Albero == NULL) return;


    if(getUrgenza(Albero->s) == livello){
        stampaSegnalazione(Albero->s);
    }

    stampaPerUrgenza(Albero->sx, livello);
    stampaPerUrgenza(Albero->dx, livello);
}

//GETTER
BST figlioSX(BST Albero){
    return Albero->sx;
}

BST figlioDX(BST Albero){
    return Albero->dx;
}

segnalazione getSegnalazione(BST T){
    return T->s;
}

//SETTER
void setSegnalazione(BST T, segnalazione s){
    T->s = s;
}