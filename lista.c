#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

nodo* creaNodo(Segnalazione* x){
    if(x == NULL) return NULL;

    nodo* p = malloc(sizeof(nodo)); 
    if(p == NULL) return NULL;

    p->s = x;
    p->next = NULL;
    return p;
}

void InserisciSegnalazione(nodo** testa, Segnalazione* s){
    nodo* nuovo = creaNodo(s);
    nuovo->next = *testa;
    *testa = nuovo;
}


void StampaLista(nodo* testa){
    while(testa != NULL){
        stampaSegnalazione(testa->s);
        testa = testa->next;
    }
}

Segnalazione* ricercaPerId(nodo* testa, int id){
    nodo* tmp = testa;

    while(tmp != NULL){
        if(tmp->s->id == id){
            return tmp->s;
        } else {
            tmp = tmp->next;
        }
    }
    printf("Segnalazione non trovata\n");
    return NULL;
}

void ricercaPerCategoria(nodo** testa, char* categoria){
    nodo* tmp = *testa;
    int count = 0;

    while(tmp != NULL){
        if(strcmp(tmp->s->categoria, categoria) == 0){
            stampaSegnalazione(tmp->s);
            count++;
        } 
        tmp = tmp->next;
    }
    if(count == 0){
        printf("Nessuna segnalazione per tale categoria %s\n", categoria);
    } else {
        printf("Totale segnalazioni per la categoria %s = %d", categoria, count);
    }
}

void aggiornaStatus(nodo* testa, int id){
    Segnalazione* s = ricercaPerId(testa, id);
    if(s == NULL) return;

    printf("Inserisci nuovo status: \n");
    getchar();
    fgets(s->status, 20, stdin);
    s->status[strcspn(s->status, "\n")] = '0';

    printf("Status Aggiornato!\n");
}

void stampaPerStatus(nodo* testa, char* status){ //da usare nel main per filtrare tutte le segnalazioni
    int found = 0;
    while(testa != NULL){
        if(strcmp(testa->s->status, status) == 0){
            stampaSegnalazione(testa->s);
            printf("-----------------------------\n");
            found++;
        }
        testa = testa->next;
    }
    if(found == 0){
        printf("Nessuna segnalazione trovata per status: %s\n", status);
    }
}