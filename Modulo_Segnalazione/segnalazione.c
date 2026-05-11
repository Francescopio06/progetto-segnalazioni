#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "segnalazione.h"

/*
FILE: segnalazione.c

Questo modulo si occupa della gestione della struttura astratta
segnalazione e di tutte le operazioni legate ad essa.

Il file si occupa nello specifica della creazione e della stampa
della segnalazione.

Sono implementati funzioni helper per permettere la corretta
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
    //timestamp della data
    time_t data;
    int urgenza;
    char status[20];
    // chiave per ordinare BST
    int chiave;
}Segnalazione;

/* Prototipi di funzioni helper: */
static void stampaData(time_t data);
void generaID(char* id);
static int incrementaChiave();
static time_t generaData();

/*
NOTE IMPLEMENTATIVE:
La funzione crea dinamicamente una nuova segnalazione
e inizializza tutti i suoi campi.
 
I dati testuali vengono acquisiti da tastiera con
controlli per evitare stringhe vuote.

I campi ID, chiave e data vengono invece generati
automaticamente tramite funzioni helper.

In caso di fallimento dell'allocazione dinamica,
la funzione restituisce NULL.
*/
segnalazione creaSegnalazione(){
    segnalazione s;

    s = malloc(sizeof(Segnalazione));
    if(s == NULL) return NULL;

    generaID(s->id);
    printf("\nID generato Automaticamente: %s\n", s->id);
    printf("-----------------------------\n");

    s->chiave = incrementaChiave();

    do{
    printf("Inserire Nome del Segnalatore:\n");
    fgets(s->nome, 50, stdin);
    s->nome[strcspn(s->nome, "\n")] = '\0';
    }while(strlen(s->nome) == 0);

    printf("-----------------------------\n");
    
    do{
    printf("Inserire Categoria della segnalazione:\n");
    fgets(s->categoria, 50, stdin);
    s->categoria[strcspn(s->categoria, "\n")] = '\0';
    }while(strlen(s->categoria) == 0);

    printf("-----------------------------\n");

    do{
    printf("Inserire informazioni aggiuntive della segnalazione:\n");
    fgets(s->descrizione, 100, stdin);
    s->descrizione[strcspn(s->descrizione, "\n")] = '\0';
    }while(strlen(s->descrizione) == 0);

    printf("-----------------------------\n");

    s->data = generaData();
    stampaData(s->data);
    printf("-----------------------------\n");

    do{
    printf("Inserire livello di urgenza (1 = Alta, 2 = Media, 3 = Bassa):\n");
    scanf("%d", &s->urgenza);
    getchar();
    }while(s->urgenza < 1 || s->urgenza > 3);
    
    printf("-----------------------------\n");

    int choice = 0;
    do{
    printf("Inserisci stato:");
    printf("\n1. Aperta");
    printf("\n2. In lavorazione");
    printf("\n3. Chiusa");
    printf("\nScelta:\n");
    
    scanf("%d", &choice);
    getchar();

   } while(choice < 1 || choice > 3);
    
    switch(choice){
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
        printf("\nScelta non valida");
    }
    printf("-----------------------------\n");

    printf("\n=== Segnalazione Inserita! ===\n");

    return s;
}

void stampaSegnalazione(segnalazione s){
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

    for(int i = 0; i < 8; i++){
        //esclude il terminatore '\0' dalla selezione casuale
        int indice = rand() % (sizeof(set)-1);
        id[i] = set[indice];
    }
    id[8] = '\0';
}

static int incrementaChiave(){
    // variabile che conserva il valore 
    static int contatore = 0;
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
static time_t generaData(){
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
static void stampaData(time_t data){
    struct tm tm = *localtime(&data);

    printf("Data di inserimento: %02d/%02d/%d\n", 
        tm.tm_mday, 
        tm.tm_mon + 1, 
        tm.tm_year + 1900);
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

/* Setter */
void setStatus(segnalazione s, char* status){
    strcpy(s->status, status);
}
