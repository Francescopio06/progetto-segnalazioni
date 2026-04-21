#ifndef LISTA_H
#define LISTA_H

//ADT Lista come puntatore alla struttura nodo
typedef struct nodo *lista;

lista newList();
int emptyList(lista list1);
lista consList(lista lista1, segnalazione* s);
void outputList(lista lista1);
segnalazione* ricercaPerId(lista lista1, int id);
void ricercaPerCategoria(lista lista1, char* categoria);
void stampaPerStatus(lista lista1, char* status);
void stampaPerUrgenza(lista lista1, int urgenza);

#endif