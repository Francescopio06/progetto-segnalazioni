#ifndef LISTA_H
#define LISTA_H

//ADT Lista come puntatore alla struttura nodo
typedef struct nodo *lista;

//operazioni su lista
lista newList();
int emptyList(lista list1);
lista consList(lista lista1, segnalazione* s);
void outputList(lista lista1);

//operazioni di ricerca
segnalazione* ricercaPerId(lista lista1, int id);
void ricercaPerCategoria(lista lista1, char* categoria);

//operazioni di stampa
void stampaPerStatus(lista lista1, char* status);
void stampaPerUrgenza(lista lista1);

//operazione di modifica
lista rimuoviSegnalazione(lista lista1, int id);
//void stampaListaConIndice(lista lista1);

#endif