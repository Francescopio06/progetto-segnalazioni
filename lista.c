#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "segnalazione.h"

// struct nodo
struct nodo{
    //item
    segnalazione* s;
    //puntatore al nodo successivo
    struct nodo* next;
};

//creo una lista vuota
lista newList(){
    return NULL;
}

//verifico se la lista è vuota
int emptyList(lista lista1){
    return lista1 == NULL;
}

//inserisco un nuovo nodo nella lista
lista consList(lista lista1, segnalazione* s){
    lista new_node = (lista)malloc(sizeof(struct nodo));
    if(new_node == NULL){
        fprintf(stderr, "ERRORE: impossibile allocare memoria per il nuovo nodo");
        exit(EXIT_FAILURE);
    }
    
    new_node->s = s;
    new_node->next = NULL;
    return new_node;
}

//stampo tutta la lista
void outputList(lista lista1){
    while(lista1 != NULL){
        stampaSegnalazione(lista1->s); //funzione presente in segnalazione.c
        lista1 = lista1->next;
    }
    printf("\n");
}

segnalazione* ricercaPerId(lista lista1, int id){
    lista tmp = lista1;

        while(tmp != NULL){
            if(tmp->s->id == id){
                return tmp->s;
            } 
            tmp = tmp->next;
        }
    return NULL;
}

void ricercaPerCategoria(lista lista1, char* categoria){
    lista tmp = lista1;
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

void stampaPerStatus(lista lista1, char* status){
    lista tmp = lista1;
    int found = 0;
    while(tmp != NULL){
        if(strcmp(tmp->s->status, status) == 0){
            stampaSegnalazione(tmp->s);
            found++;
        }
        tmp = tmp->next;
    }

    if(found == 0){
        printf("nessuna segnalazione per lo stato %s\n", status);
    }
}

void stampaPerUrgenza(lista lista1){
    if(lista1 == NULL){
        printf("Nessuna Segnalazione Registrata\n");
        return;
    }

    lista tmp = lista1;
    int trovato = 0;

    //livello 1
    printf("\n--- Urgenza 1 (massima) ---\n");
    while(tmp != NULL){
        if(tmp->s->urgenza == 1){
            stampaSegnalazione(tmp->s);
            trovato = 1;
        }
        tmp = tmp->next;
    }
    
    //livello 2
    if(trovato == 0){
        printf("\nNessuna segnalazione di livello 1, mostro livello 2:\n");
        tmp = lista1;
        while(tmp != NULL){
            if(tmp->s->urgenza == 2){
                stampaSegnalazione(tmp->s);
                trovato = 1;
            }
            tmp = tmp->next;
        }
    }
    
    //livello 3
    if(trovato == 0){
        printf("\nNessuna segnalazione di livello 1 o 2, mostro livello 3:\n");
        tmp = lista1;
        while(tmp != NULL){
            if(tmp->s->urgenza == 3){
                stampaSegnalazione(tmp->s);
            }
            tmp = tmp->next;
        }
    }

}
