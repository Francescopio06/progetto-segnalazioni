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
    struct nodo* new_node = (lista)malloc(sizeof(struct nodo));
    if(new_node == NULL){
        fprintf(stderr, "ERRORE: impossibile allocare memoria per il nuovo nodo");
        exit(EXIT_FAILURE);
    }
    
    new_node->s = s;
    new_node->next = lista1;
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
            if(getID(tmp->s) == id){
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
        if(strcmp(getCategoria(tmp->s), categoria) == 0){
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
        if(strcmp(getStatus(tmp->s), status) == 0){
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
        if(getUrgenza(tmp->s) == 1){
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
            if(getUrgenza(tmp->s) == 2){
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
            if(tmp->s== 3){
                stampaSegnalazione(tmp->s);
            }
            tmp = tmp->next;
        }
    }

}

lista rimuoviSegnalazione(lista lista1, int id){
    lista curr = lista1;
    lista prec = NULL;

    while(curr != NULL){
        if(getID(curr->s) == id){
            if(prec == NULL){
                lista1 = curr->next;
            } else {
                prec->next = curr->next;
            }
            free(curr);
            printf("segnalazione rimossa con successo\n");
            return lista1;
        }
        prec = curr;
        curr = curr->next;
    }

    printf("Segnalazione non trovata");
    return lista1;
}

/*void stampaListaConIndice(lista lista1){
    int i = 1;
    while(lista1 != NULL){
        printf("%d) ID: %d - Categoria: %s", i, getID(lista1->s), getCategoria(lista1->s));
        lista1 = lista1->next;
        i++;
    }
}*/

int prendiID(lista lista1, int scelta){
    int i = 1;
    while(lista1 != NULL){
        if(i == scelta){
            return getID(lista1->s);
        }
        lista1 = lista1->next;
        i++;
    }
    return -1; 
}
