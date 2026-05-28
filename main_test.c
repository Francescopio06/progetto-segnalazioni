#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "gestione.h"
#include "segnalazione.h"
#include "Modulo_Tests/include/aggiornamento.h"
#include "Modulo_Tests/include/cancellazione.h"
#include "Modulo_Tests/include/filtra.h"
#include "Modulo_Tests/include/inserimento.h"
#include "Modulo_Tests/include/report.h"
#include "Modulo_Tests/include/ricerca.h"
#include "Modulo_Tests/include/urgenza.h"


/*
FILE: main_test.c
AUTORE: Francesco Pio Siano

Questo file si occupa dell'esecuzione dei test delle 
funzioni richieste.

Sono stati adottati dei dataset pre-impostati per poter
evitare di sporcare l'output dei test con l'output di richiesta
degli input per l'inserimento delle segnalazioni.

I test eseguiti sono relativi alle funzioni utilizzate nel main
e riguardano le operazioni di:
- Inserimento
- Ricerca (ID e Categoria)
- Aggiornamento stato
- Stampa per urgenza
- Filtra per status
- Cancellazione della segnalazione
- Generazione del report
*/

int main(void){

    int scelta;

    do{
    
    pulisciSchermo();

    printf(
    "  __  __                _____       _   \n"
    " |  \\/  |___ _ _ _  _  |_   _|__ __| |_ \n"
    );

    printf(
    " | |\\/| / -_) ' \\ || |   | |/ -_|_-<  _|\n"
    " |_|  |_|\\___|_||_\\_,_|   |_|\\___/__/\\__|\n"
    "                                         \n"
    ); 
    printf("1. Test Inserimento\n");
    printf("2. Test Ricerca\n");
    printf("3. Test Aggiornamento\n");
    printf("4. Test Urgenza\n");
    printf("5. Test Filtro\n");
    printf("6. Test Report\n");
    printf("7. Test Cancellazione\n");
    printf("0. Esci\n");
    printf("Scelta: ");

    if(scanf("%d", &scelta) != 1){
        
        printf("\nInserire un valore valido da 0 a 8\n");
        printf("---------------------------------\n");
            
        while(getchar() != '\n');

        printf("\nPremi INVIO per continuare...");
        getchar();
        continue;
    }
    
    getchar();

    switch(scelta){

        case 1:
            printf("\n=== Avvio Test Inserimento ===\n");
            testInserimento();
            printf("\n=== Test completato ===\n");
            break;

        case 2:
            printf("\n=== Avvio Test Ricerca ===\n");
            testRicerca();
            printf("\n=== Test completato ===\n");
            break;

        case 3:
            printf("\n=== Avvio Test Aggiornamento ===\n");
            testAggiornamento();
            printf("\n=== Test completato ===\n");
            break;

        case 4:
            printf("\n=== Avvio Test Urgenza ===\n");
            testUrgenza();
            printf("\n=== Test completato ===\n");
            break;

        case 5:
            printf("\n=== Avvio Test Filtro ===\n");
            testFiltra();
            printf("\n=== Test completato ===\n");
            break;

        case 6:
            printf("\n=== Avvio Test Report ===\n");
            testReport();
            printf("\n=== Test completato ===\n");
            break;

        case 7:
            printf("\n=== Avvio Test Cancellazione ===\n");
            testCancellazione();
            printf("\n=== Test completato ===\n");
            break;

        case 0: 
            printf("Uscita...\n");
            break;

        default:
            printf("Inserire un valore tra 0 a 7\n");
        }

        if(scelta != 0){
            printf("\npremi INVIO per continuare...\n");
            getchar();
        }

    }while(scelta != 0);
    
    return 0;
}
