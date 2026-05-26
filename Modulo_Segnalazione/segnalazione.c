#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "segnalazione.h"

/*
FILE: segnalazione.c
AUTORE: Francesco Pio Siano

Questo modulo si occupa della gestione della struttura astratta
segnalazione e di tutte le operazioni legate ad essa.

Il file si occupa nello specifico della creazione e della stampa
della segnalazione.

Sono implementate funzioni helper per permettere la corretta
suddivisioni delle operazioni per una migliore manutenibilità.

Sono state implementate funzioni di getter e setter
per poter concedere l'accesso ai dati della struttura
anche a moduli più alti
*/

/*
La struttura rappresenta una segnalazione.

Contiene i dati anagrafici relativi al segnalatore ed
informazioni aggiuntive utili per organizzare, ricercare 
ed ordinare.
*/

typedef struct Segnalazione{
    char id[9];
    char nome[50];
    char categoria[50];
    char descrizione[100];
    /* timestamp della data */
    time_t data;
    int urgenza;
    char status[20];
    /* chiave per ordinare BST */
    int chiave;
}Segnalazione;

/* Prototipi di funzioni helper: */
static int incrementaChiave(void);
static time_t generaData(void);

/*
NOTE IMPLEMENTATIVE:
La funzione crea dinamicamente una nuova segnalazione
e inizializza tutti i suoi campi.

I campi ID, chiave e data vengono invece generati
automaticamente tramite funzioni helper.

In caso di fallimento dell'allocazione dinamica,
la funzione restituisce NULL.
*/
segnalazione creaSegnalazione(char* nome, char* categoria, char* descrizione, int urgenza, int stato){

    segnalazione s = malloc(sizeof(Segnalazione));

    if(s == NULL){
        return NULL;
    }

    generaID(s->id);

    s->chiave = incrementaChiave();

    s->data = generaData();

    strcpy(s->nome, nome);

    strcpy(s->categoria, categoria);

    strcpy(s->descrizione, descrizione);

    s->urgenza = urgenza;

    switch(stato){

        case 1:
            strcpy(s->status, "aperta");
            break;

        case 2:
            strcpy(s->status, "in lavorazione");
            break;

        case 3:
            strcpy(s->status, "chiusa");
            break;

        default:
            strcpy(s->status, "aperta");
    }

    return s;
}

void stampaSegnalazione(segnalazione s){
    
    /* Caso in cui la segnalazione sia vuota */
    if(s == NULL){
        printf("\nSegnalazione non valida\n");
        return;
    }

    printf("\nCodice Identificativo: %s\n", s->id);
    printf("-----------------------------\n");

    printf("Nome Segnalatore: %s\n", s->nome);
    printf("-----------------------------\n");

    printf("Categoria della segnalazione: %s\n", s->categoria);
    printf("-----------------------------\n");

    printf("Descrizione: %s\n", s->descrizione);
    printf("-----------------------------\n");

    stampaData(s->data);
    printf("-----------------------------\n");
 
    printf("Livello di Urgenza: %d (1= elevato, 2= intermedio, 3= lieve)\n", s->urgenza);
    printf("-----------------------------\n");

    printf("Stato della segnalazione: %s\n", s->status);
    printf("-----------------------------\n");

    printf("\n===STAMPA COMPLETATA===\n");
}

void generaID(char* id){
    const char set[] = "ABCDEFGHIJKLMNOPQRSTUVWYZ0123456789";
    int i;
    for(i = 0; i < 8; i++){
        /* esclude il terminatore '\0' dalla selezione casuale */
        int indice = rand() % (sizeof(set)-1);
        id[i] = set[indice];
    }
    id[8] = '\0';
}

static int incrementaChiave(void){
    /* variabile che conserva il valore */
    static int contatore = 1;
    return contatore++;
}

/*
Funzione generaData
    La funzione mediante la chiamata alla funzione time
    chiede al sistema operativo la data e l'orario attuale.

    Note: 
        - nella funzione time(NULL), passo il parametro NULL perchè non mi serve
        salvare la data attuale in alcuna variabile, ma necessito solo del timestamp

    Parametri:
        - Nessun input
    
    Restituito il tipo time_t
*/
static time_t generaData(void){
    return time(NULL);
}

/*
Funzione stampaData(time_t data)
    La procedura attuata prevede l'assegnamento dell'ora locale alla variabile 
    di tipo time_t, essa è una struct tm che contiene giorno, mese ed anno.
    
    Note:
        - tm_mon è un array che parte da 0. dunque aggiungo 1
        - tm_ year inizia il conto dal 1900, aggiungo il valore per farlo corrispondere 
        al nostro calendario
    
    Parametri:
        - data: tipo di variabile time_t
    
    Nessun valore di ritorno
 */ 

void stampaData(time_t data){
    struct tm tm = *localtime(&data);

    printf("Data di inserimento: %02d/%02d/%d\n", 
        tm.tm_mday, 
        tm.tm_mon + 1, 
        tm.tm_year + 1900);
}

/*
Funzione liberaSegnalazione(s)
    La funzione libera la memoria allocata
    dinamicamente per una segnalazione.

    Parametri:
        - s -> puntatore alla struttura segnalazione

    Return:
        - Nessun valore restituito
*/

void liberaSegnalazione(segnalazione s){
    if(s != NULL) free(s);
}


/* Getter */
char* getID(segnalazione s){
    return s->id;
}

char* getCategoria(segnalazione s){
    return s->categoria;
}

char* getStatus(segnalazione s){
    return s->status;
}

int getUrgenza(segnalazione s){
    return s->urgenza;
}

int getChiave(segnalazione s){
    return s->chiave;
}

time_t getData(segnalazione s){
    return s->data;
}

/* Setter */
void setStatus(segnalazione s, char* status){
    strcpy(s->status, status);
}
