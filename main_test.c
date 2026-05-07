#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulo_BST/BST.h"
#include "Modulo_Gestione/gestione.h"
#include "Modulo_Segnalazione/segnalazione.h"

static void testInserimento();
static void testRicerca();
static void testAggiornamento();

int main(){

    int scelta;

    scanf("%d", &scelta);
    getchar();

        switch(scelta){

            case 1:
                testInserimento();
                return 0;

            case 2:
                testRicerca();
                break;
            
            case 3:
                testAggiornamento();
                break;

            default:
                printf("Scelta non valida\n");
            }

    return 0;
}

static void testInserimento(){
    srand(1);
    BST T = newBST();
    inserisciSegnalazione(&T);
}

static void testRicerca(){

    srand(1);

    BST T = newBST();


    // Dataset di test
    inserisciSegnalazione(&T);
    inserisciSegnalazione(&T);
    inserisciSegnalazione(&T);


    int scelta;

    printf("1. Ricerca per ID\n");
    printf("2. Ricerca per Categoria\n");

    printf("Scelta:\n");

    scanf("%d", &scelta);
    getchar();


    if(scelta == 1){

        char idRicerca[20];

        printf("\nInserire ID da cercare:\n");

        fgets(idRicerca, 20, stdin);

        idRicerca[strcspn(idRicerca, "\n")] = '\0';


        segnalazione risultato = ricercaPerId(T, idRicerca);


        if(risultato != NULL){

            stampaSegnalazione(risultato);

        }else{

            printf("\n=== Segnalazione non trovata ===\n");
        }

    }
    else if(scelta == 2){

        char categoria[50];

        printf("\nInserire categoria da cercare:\n");

        fgets(categoria, 50, stdin);

        categoria[strcspn(categoria, "\n")] = '\0';


        // uso la funzione di ricerca categoria
        if(ricercaPerCategoria(T, categoria) == 0){
        printf("\n=== NESSUNA SEGNALAZIONE TROVATA ===\n");
        }
    }
}

static void testAggiornamento(){

    srand(1);

    BST T = newBST();

    inserisciSegnalazione(&T);
    inserisciSegnalazione(&T);
    inserisciSegnalazione(&T);

    int tipoTest;

    scanf("%d", &tipoTest);
    getchar();


    if(tipoTest == 1){

        aggiornaStato(T);

        aggiornaStato(T);
    }
    else{

        aggiornaStato(T);
    }
}