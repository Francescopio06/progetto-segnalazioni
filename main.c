#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BST.h"
#include "gestione.h"

/*
FILE: main.c
AUTORE: Francesco Pio Siano

Questo file rappresenta il punto di ingresso
del programma.

Il modulo si occupa della gestione dell'interazione
con l'utente attraverso un menu testuale,
consentendo l'accesso alle principali operazioni
di gestione delle segnalazioni.

Le operazioni disponibili includono:
- inserimento
- ricerca
- aggiornamento stato
- visualizzazione per urgenza
- cancellazione
- filtro per stato
- generazione report
*/

int main(void){
    
    int scelta;
    BST T; 

    T = newBST();
    srand(time(NULL));

    do{
        pulisciSchermo();

        printf(
"   _____                         __________        .__              .__             .__          \n"
"  /     \\   ____   ____  __ __   \\______   \\_______|__| ____   ____ |__|__________  |  |   ____  \n"
" /  \\ /  \\_/ __ \\ /    \\|  |  \\   |     ___/\\_  __ \\  |/    \\_/ ___\\|  \\____ \\__  \\ |  | _/ __ \\ \n"
);

printf(
"/    Y    \\  ___/|   |  \\  |  /   |    |     |  | \\/  |   |  \\  \\___|  |  |_> > __ \\|  |_\\  ___/ \n"
"\\____|__  /\\___  >___|  /____/    |____|     |__|  |__|___|  /\\___  >__|   __(____  /____/\\___  >\n"
"        \\/     \\/     \\/                                   \\/     \\/   |__|       \\/          \\/ \n"
);
        printf("\n1. Inserisci segnalazione\n");
        printf("2. Visualizza tutte le segnalazioni\n");
        printf("3. Ricerca segnalazione [Codice Identificativo o Categoria]\n");
        printf("4. Aggiorna stato segnalazione\n");
        printf("5. Stampa segnalazioni per stato\n");
        printf("6. Stampa per urgenza\n");
        printf("7. Elimina segnalazione\n");
        printf("8. Genera report\n");
        printf("9. Reset Registro\n");
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
                inserisciSegnalazione(&T);
                break;

            case 2:
                visualizzaSegnalazione(T);
                break;

            case 3:
                ricercaSegnalazione(T);
                break;

            case 4:
                aggiornaStato(T);
                break;

            case 5:
                filtraSegnalazioni(T);
                break;

            case 6:
                mostraUrgenza(T);
                break;

            case 7:
                eliminaSegnalazione(&T);
                break;

            case 8:
                visualizzaReport(T);
                break;

            case 9: 
                if(T == NULL){
                    printf("\nNon sono presenti segnalazioni | Registro vuoto...\n");
                    break;
                } 

                resetBST(&T);
                printf("\n=== Reset completato con successo ===\n");
                break;

            case 0:
                printf("Uscita...\n");
                break;

            default:
                printf("\n---------------------------------\n");
                printf("Inserire un valore valido da 0 a 8\n");
                printf("---------------------------------\n");
        }

        if(scelta != 0){
        printf("\npremi INVIO per continuare...");
        getchar();
        }
        
    } while(scelta != 0);

    return 0;
}
