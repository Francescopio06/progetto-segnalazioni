#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "segnalazione.h"

/*
FILE: gestione.c
AUTORE: Francesco Pio Siano

Questo modulo si occupa della gestione delle principali
operazioni applicative sulle segnalazioni.

Il file funge da livello intermedio tra l'interfaccia utente
ed i moduli che implementano le strutture dati, coordinando
l'acquisizione degli input, la validazione dei dati e
l'esecuzione delle operazioni richieste.

Le funzionalità implementate includono:
- inserimento di una nuova segnalazione
- visualizzazione delle segnalazioni presenti
- ricerca per ID o categoria
- aggiornamento dello stato
- filtraggio per stato
- visualizzazione per urgenza
- eliminazione di una segnalazione
- generazione del report statistico

Sono inoltre presenti funzioni helper utilizzate
per separare la logica di interazione con l'utente
dalla gestione dei dati.
*/

static void controlloID(BST Albero, char* ID);
static segnalazione acquisisciSegnalazione();

//funzioni principali
void inserisciSegnalazione(BST* Albero){

    segnalazione s = acquisisciSegnalazione();

    if(s == NULL){
        return;
    }

    controlloID(*Albero, getID(s));

    *Albero = insert(*Albero, s);

    printf("\n=== Segnalazione Inserita! ===\n");
}

void visualizzaSegnalazione(BST Albero){
    outputBST(Albero);
}

/*
La funzione consente di ricercare una segnalazione
tramite due criteri differenti:
- codice identificativo
- categoria
*/
void ricercaSegnalazione(BST Albero){

    if(Albero == NULL){
        printf("\n=== Nessuna segnalazione registrata ===\n");
        return NULL;
    }

    int choice;
    char IDtemp[9];
    char CategoriaTemp[50];
    printf("Scegliere il criterio di ricerca: ");
    printf("\n1. Ricerca per ID\n2. Ricerca per Categoria");
    scanf("%d", &choice);
    getchar();

    switch (choice){
    case 1: 

        printf("\nInserire ID: ");
        fgets(IDtemp, 9, stdin);
        IDtemp[strcspn(IDtemp, "\n")] = '\0';

        segnalazione s = ricercaPerId(Albero, IDtemp);

        if(s == NULL){
            printf("segnalazione non trovata");
        } else {
            stampaSegnalazione(s);
        }
        break;
    case 2: 

        printf("\nInserire Categoria: ");
        fgets(CategoriaTemp, 50, stdin);
        CategoriaTemp[strcspn(CategoriaTemp, "\n")] = '\0';

        if(ricercaPerCategoria(Albero, CategoriaTemp) == 0){
        printf("=== NESSUNA SEGNALAZIONE TROVATA ===");
        }
        
        break;

    default:
        printf("\n---Scelta non valida---");        
    }
}

/*
La funzione ricerca una segnalazione tramite ID
e consente l'aggiornamento del suo stato.

Viene impedito l'inserimento dello stesso
stato già presente.
*/
void aggiornaStato(BST Albero){

    char IDtemp[10];
    int choice;
    char statusTmp[20];

    printf("\nInserire ID della segnalazione: ");
    fgets(IDtemp, 10, stdin);
    IDtemp[strcspn(IDtemp, "\n")]= '\0';

    segnalazione s = ricercaPerId(Albero, IDtemp);
    if(s == NULL){
        printf("\nSegnalazione non trovata\n");
        return;
    }

    strcpy(statusTmp, getStatus(s));

    printf("\nStatus: %s", getStatus(s));
    printf("\nScegliere il nuovo status della segnalazione:");
    printf("\n1. Aperta \n2. In lavorazione\n3. Chiusa");
    printf("\nscelta: ");

    scanf("%d", &choice);
    // pulisce il buffer dopo l'input
    getchar();

    switch(choice){
    case 1:
        if(strcmp(getStatus(s), "aperta") == 0){
            printf("\n---------------------------------\n");
            printf("=== Nuovo stato corrisponde all'attuale! ===\n");
            printf("---------------------------------\n");
            return;
        }
        setStatus(s, "aperta");
        break;
    case 2:
        if(strcmp(getStatus(s), "in lavorazione") == 0){
            printf("\n---------------------------------\n");
            printf("=== Nuovo stato corrisponde all'attuale! ===\n");
            printf("---------------------------------\n");
            return;
        }
        setStatus(s, "in lavorazione");
        break;
    case 3:
        if(strcmp(getStatus(s), "chiusa") == 0){
            printf("\n---------------------------------\n");
            printf("=== Nuovo stato corrisponde all'attuale! ===\n");
            printf("---------------------------------\n");
            return;
        }
        setStatus(s, "chiusa");
        break;
    default:
        printf("\n---Scelta non valida---");
    }

    printf("\n---------------------------------\n");
    printf("=== Stato aggiornato! ===\n");
    printf("---------------------------------\n");      
}

void filtraSegnalazioni(BST Albero){
    int trovato = 0;

    if(Albero == NULL){
        printf("\n---------------------------------\n");
        printf("=== Nessuna Segnalazione presente! ===\n");
        printf("---------------------------------\n");
        return;
    } 

    int choice;

    printf("\nQuali segnalazioni vuoi visualizzare:\n");
    printf("1. Aperte\n2. In lavorazione\n3. Chiuse\n4. Elenco completo");
    printf("\nscelta:");
    scanf("%d", &choice);
    getchar();

    switch(choice){
    case 1:

        printf("\n---------------------------------\n");
        printf("\n=== Segnalazioni Aperte! ===\n");
        stampaPerStatus(Albero, "aperta", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo stato richiesto ===\n");
        }
        break;
    case 2: 

        printf("\n---------------------------------\n");
        printf("\nSegnalazioni In Lavorazione\n");
        stampaPerStatus(Albero, "in lavorazione", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo stato richiesto ===\n");
        }
        break;
    case 3:

        printf("\n---------------------------------\n");
        printf("\nSegnalazioni Chiuse\n");
        stampaPerStatus(Albero, "chiusa", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo stato richiesto ===\n");
        }
        break;
    case 4: 

        printf("\n---------------------------------\n");
        printf("\n=== ELENCO COMPLETO ===\n");

        trovato = 0;
        printf("\n---------------------------------\n");
        printf("Segnalazioni Aperte: \n");
        stampaPerStatus(Albero, "aperta", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }

        trovato = 0;
        printf("\n---------------------------------\n");
        printf("Segnalazioni In Lavorazione: \n");
        stampaPerStatus(Albero, "in lavorazione", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }

        trovato = 0;
        printf("\n---------------------------------\n");
        printf("Segnalazioni Chiuse: \n");
        stampaPerStatus(Albero, "chiusa", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }
        break;
    default:
        printf("\n---Scelta non valida---\n");
    }
}

void mostraUrgenza(BST Albero){

    if(Albero == NULL){
        printf("\n---------------------------------\n");
        printf("=== Nessuna Segnalazione presente! ===\n");
        printf("---------------------------------\n");
        return;
    }

    if(esisteUrgenza(Albero, 1)){
        printf("\nSegnalazioni con urgenza Massima (1):\n");
        stampaPerUrgenza(Albero, 1);
    } 
    else if(esisteUrgenza(Albero, 2)){
        printf("\nSegnalazioni con urgenza Media (2):\n");
        stampaPerUrgenza(Albero, 2);
    } 
    else if(esisteUrgenza(Albero, 3)){
        printf("\nSegnalazione con urgenza Minima (3):\n");
        stampaPerUrgenza(Albero, 3);
    }
    else{
        printf("\nNessuna segnalazione trovata\n");
    }

}

/*
La funzione consente di eliminare una segnalazione
tramite il suo ID.

Una volta individuata, viene utilizzata la chiave
interna per eseguire la cancellazione nel BST.
*/
void eliminaSegnalazione(BST* Albero){
    if(*Albero == NULL){
        printf("\n=== Nessuna segnalazione presente ===\n");
        return;
    }

    char IDtemp[9];

    printf("\nInserire ID della segnalazione da eliminare: ");
    fgets(IDtemp, 9, stdin);
    // toglie la new line dall'input
    IDtemp[strcspn(IDtemp, "\n")] = '\0';

    segnalazione s = ricercaPerId(*Albero, IDtemp);
    if(s == NULL){
        printf("\nSegnalazione non trovata\n");
        return;
    }

    *Albero = CancellaSegnalazione(*Albero, getChiave(s));
    printf("\n---------------------------------\n");
    printf("=== Cancellazione Riuscita! ===\n");
}

/*
Funzione controlloID(Albero, ID)
    La funzione ha lo scopo di verificare che
    l'ID generato sia unico di quella segnalazione.

    Parametri:
        - Albero -> puntatore alla struttura dati BST
        - ID -> puntatore ad un array di caratteri

    Return:
        - Nessun valore restituito
*/
static void controlloID(BST Albero, char* ID){

    while(ricercaPerId(Albero, ID) != NULL){

        generaID(ID);

    }
}

/*
Funzione acquisisciSegnalazione
    La funzione si occupa della parte di interfaccia utente 
    acquisendo i parametri necessari, passandoli poi alla funzione 
    creaSegnalazione.
    La funzione si occupa anche della stampa di valori generati automaticamente
    come ID, chiave e data.

    Parametri: 
        - Nessun parametro in input

    Return:
        - Restituisce la segnalazione
*/
static segnalazione acquisisciSegnalazione(){

    char nome[50];
    char categoria[50];
    char descrizione[100];
    int urgenza;
    int stato;

    do{
        printf("Inserire Nome del Segnalatore:\n");

        fgets(nome, 50, stdin);

        nome[strcspn(nome, "\n")] = '\0';

    }while(strlen(nome) == 0);
    
    printf("-----------------------------\n");

    do{
        printf("Inserire Categoria della segnalazione:\n");

        fgets(categoria, 50, stdin);

        categoria[strcspn(categoria, "\n")] = '\0';

    }while(strlen(categoria) == 0);

    printf("-----------------------------\n");

    do{
        printf("Inserire informazioni aggiuntive della segnalazione:\n");

        fgets(descrizione, 100, stdin);

        descrizione[strcspn(descrizione, "\n")] = '\0';

    }while(strlen(descrizione) == 0);

    printf("-----------------------------\n");

    do{
        printf("Inserire livello di urgenza (1 = Alta, 2 = Media, 3 = Bassa):\n");

        scanf("%d", &urgenza);

        getchar();

    }while(urgenza < 1 || urgenza > 3);

    printf("-----------------------------\n");

    do{

        printf("Inserisci stato:\n");

        printf("1. Aperta\n");

        printf("2. In lavorazione\n");

        printf("3. Chiusa\n");

        printf("Scelta:\n");

        scanf("%d", &stato);

        getchar();

    }while(stato < 1 || stato > 3);

    printf("-----------------------------\n");

    segnalazione s = creaSegnalazione(
        nome,
        categoria,
        descrizione,
        urgenza,
        stato
    );

    printf("Codice identificativo: %s", getID(s));
    printf("\nNumero Segnalazione: 0%d\n", getChiave(s));
    stampaData(getData(s));

    return s;
}
