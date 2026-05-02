#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BST.h"
#include "gestione.h"

int main(){

    BST T = newBST();
    int scelta;
    srand(time(NULL));

    do{
        printf("\n===== MENU =====\n");
        printf("1. Inserisci segnalazione\n");
        printf("2. Visualizza tutte le segnalazioni\n");
        printf("3. Ricerca segnalazione\n");
        printf("4. Aggiorna stato\n");
        printf("5. Filtra segnalazioni\n");
        printf("6. Mostra urgenza\n");
        printf("7. Elimina segnalazione\n");
        printf("8. Genera report\n");
        printf("0. Esci\n");
        printf("Scelta: ");

        scanf("%d", &scelta);
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
                eliminaSegnalazione(T);
                break;

            case 8:
                generaReport(T);
                break;

            case 0:
                printf("Uscita...\n");
                break;

            default:
                printf("Scelta non valida\n");
        }

    } while(scelta != 0);

    return 0;
}