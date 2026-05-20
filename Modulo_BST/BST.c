#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "segnalazione.h"
/*
FILE: BST.c
AUTORE: Francesco Pio Siano

Il compito di questo modulo rirguarda la gestione 
di tutto ciò che è relativo alla struttura dati BST.

Sono presenti funzioni relative la creazione, la stampa
e la midifica del BST.

Sono state implementate funzioni helper per consentire
una più facile gestione del codice in caso di necessarie modifiche.

Sono stati adottate funzioni di getter e setter per permettere a moduli
più alti di poter accedere ai campi della struttura BST in modo protetto.
*/

/*
Nodo interno del BST.

Ogni nodo contiene:
- una segnalazione
- il puntatore al sottoalbero sinistro
- il puntatore al sottoalbero destro
*/
struct nodo{
    segnalazione s;
    struct nodo* sx;
    struct nodo* dx;
};

/*
Struttura di supporto utilizzata durante
la generazione del report per memorizzare
il numero di occorrenze di ogni categoria.
*/
typedef struct {
    char categoria[50];
    int count;
} ContaCategoria;

//funzioni Helper
static void visitaReport(BST Albero, int* tot, int* aperte, int* chiuse,int* inLavorazione, ContaCategoria stats[], int* nCategorie);

/*
Funzione creaFoglia(s)
    crea un nodo e ne inserisce la 
    segnalazione dato come parametri.

    Parametri:
        - s -> puntatore alla struttura segnalazione

    Return:
        - restituisce il BST contenente la segnalazione data
*/
static BST creaFoglia(segnalazione s){
    struct nodo* T;
    T = malloc(sizeof(struct nodo));
    if(T == NULL) return NULL;
    T->s = s;
    T->dx = NULL;
    T->sx = NULL;
    return T;
}

/*
Funzione helper che confronta due chiavi
e restituisce 1 se la prima è minore
della seconda, 0 altrimenti.
*/
static int minore(int x, int y){
    if(x < y) return 1;
    return 0;
}

/*
Funzione helper utilizzata durante la cancellazione.
Scorre il sottoalbero sinistro fino a raggiungere
il nodo con chiave minima.
*/
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
/*
NOTE IMPLEMENTATIVE:
La funzione confronta la chiave della segnalazione attuale con
tutte le altre segnalazioni scorrendo l'albero 
fino a trovare il nodo giusto in cui inserirlo.
*/
BST insert(BST Albero, segnalazione s){

    if(Albero == NULL) return creaFoglia(s);
    else if(minore(getChiave(s), getChiave(Albero->s))){
        Albero->sx = insert(Albero->sx, s);
    } else if(minore(getChiave(Albero->s), getChiave(s))){
        Albero->dx = insert(Albero->dx, s);
    }
    return Albero;
}

BST CancellaSegnalazione(BST Albero, int chiave){
    
    if(Albero == NULL) return NULL;

    //controlla che il nodo interessato sia la radice
    if(minore(chiave, getChiave(Albero->s))){
        Albero->sx = CancellaSegnalazione(Albero->sx, chiave);
    } else if(minore(getChiave(Albero->s), chiave)){
        Albero->dx = CancellaSegnalazione(Albero->dx, chiave);
    } 

    
    else{
        //caso con nessuno o un figlio
        if(Albero->sx == NULL){
            BST temp = Albero->dx;
            liberaSegnalazione(Albero->s);
            free(Albero); 
            return temp;
        } else if(Albero->dx == NULL){
            BST temp = Albero->sx;
            liberaSegnalazione(Albero->s);
            free(Albero);
            return temp;
        }
        
        //caso con 2 figli
        BST temp = minvalue(Albero->dx);

        segnalazione tmp = Albero->s;
        Albero->s = temp->s;
        temp->s = tmp;

        Albero->dx = CancellaSegnalazione(Albero->dx, getChiave(temp->s));
    }
    return Albero;
}

//FUNZIONI DI RICERCA

segnalazione ricercaPerId(BST Albero, char* id){
    if(Albero == NULL) return NULL;
    
    if(strcmp(getID(Albero->s), id) == 0){
        return Albero->s;
    }
    
    segnalazione tmp = ricercaPerId(Albero->sx, id);
    if(tmp != NULL) return tmp;

    return ricercaPerId(Albero->dx, id);
}

int ricercaPerCategoria(BST Albero, char* categoria){ 

    // Contatore delle segnalazioni con la categoria richiesta
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
void stampaPerStatus(BST Albero, char* status, int* trovato){

    if(Albero == NULL) return;

   stampaPerStatus(Albero->sx, status, trovato);
   
    if(strcmp(getStatus(Albero->s), status) == 0){
        stampaSegnalazione(Albero->s);
        *trovato = 1;
    }

    stampaPerStatus(Albero->dx, status, trovato);
}

void stampaPerUrgenza(BST Albero, int livello){
    if(Albero == NULL) return;


    if(getUrgenza(Albero->s) == livello){
        stampaSegnalazione(Albero->s);
    }

    stampaPerUrgenza(Albero->sx, livello);
    stampaPerUrgenza(Albero->dx, livello);
}

void generaReport(BST Albero){

    if(Albero == NULL){
        printf("\n---------------------------------\n");
        printf("=== Nessuna Segnalazione presente! ===\n");
        printf("---------------------------------\n");
        return;
    }

    int tot = 0;
    int aperte = 0;
    int chiuse = 0;
    int inLavorazione = 0;

    ContaCategoria stats[100];
    int nCategorie = 0;

    visitaReport(Albero, &tot, &aperte, &chiuse, &inLavorazione, stats, &nCategorie);

    // stampa base
    printf("\n--- REPORT ---\n");
    printf("Totale segnalazioni: %d\n", tot);
    printf("Aperte: %d\n", aperte);
    printf("Chiuse: %d\n", chiuse);
    printf("In lavorazione: %d\n", inLavorazione);

    // per categoria
    printf("\nSegnalazioni per categoria:\n");
    for(int i = 0; i < nCategorie; i++){
        printf("%s: %d\n", stats[i].categoria, stats[i].count);
    }

    // categoria più frequente
    int max = 0;
    int indice = -1;

    for(int i = 0; i < nCategorie; i++){
        if(stats[i].count > max){
            max = stats[i].count;
            indice = i;
        }
    }

    if(indice != -1){
        printf("\nCategoria più frequente: %s (%d)\n",
               stats[indice].categoria,
               stats[indice].count);
    }
}

/*
Funzione helper utilizzata da generaReport().

Attraversa ricorsivamente il BST e aggiorna:
- numero totale di segnalazioni
- conteggio per stato
- conteggio per categoria
*/
static void visitaReport(BST Albero, int* tot, int* aperte, int* chiuse,int* inLavorazione, ContaCategoria stats[], int* nCategorie){

    if(Albero == NULL) return;

    visitaReport(figlioSX(Albero), tot, aperte, chiuse, inLavorazione, stats, nCategorie);

    segnalazione s = getSegnalazione(Albero);

    (*tot)++;

    // stato
    if(strcmp(getStatus(s), "aperta") == 0)
        (*aperte)++;
    else if(strcmp(getStatus(s), "chiusa") == 0)
        (*chiuse)++;
    else if(strcmp(getStatus(s), "in lavorazione") == 0)
        (*inLavorazione)++;

    // categoria
    char* cat = getCategoria(s);
    int trovato = 0;

    for(int i = 0; i < *nCategorie; i++){
        if(strcmp(stats[i].categoria, cat) == 0){
            stats[i].count++;
            trovato = 1;
            break;
        }
    }

    if(!trovato){
        strcpy(stats[*nCategorie].categoria, cat);
        stats[*nCategorie].count = 1;
        (*nCategorie)++;
    }

    visitaReport(figlioDX(Albero), tot, aperte, chiuse, inLavorazione, stats, nCategorie);
}

//GETTER
BST figlioSX(BST Albero){
    return Albero->sx;
}

BST figlioDX(BST Albero){
    return Albero->dx;
}

segnalazione getSegnalazione(BST Albero){
    return Albero->s;
}

//SETTER
void setSegnalazione(BST Albero, segnalazione s){
    Albero->s = s;
}