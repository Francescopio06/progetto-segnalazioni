#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"
#include "inserimento.h"

void testInserimento(void){

    BST T;

    int tipoTest;

    do{

        pulisciSchermo();

        printf("\n1. Inserimento corretto\n");

        printf("2. Inserimento con campi vuoti\n");

        printf("0. Esci\n");

        printf("\nScelta: ");

        if(scanf("%d", &tipoTest) != 1){

            printf("\nInserire un valore valido\n");

            while(getchar() != '\n');

            printf("\nPremi INVIO per continuare...");

            getchar();

            continue;
        }

        getchar();

        switch(tipoTest){

            case 1:

                srand(1);

                T = newBST();

                freopen(
"tests/test_1_Registrazione/caso_limite_1_inserimento/input.txt",
"r",
stdin
);

                freopen(
"tests/test_1_Registrazione/caso_limite_1_inserimento/output.txt",
"w",
stdout
);

                inserisciSegnalazione(&T);

                fclose(stdin);

                fclose(stdout);

                ripristinaStandardIO();

                if(T != NULL){

                    printf("\n=== TEST SUPERATO ===\n");

                }else{

                    printf("\n=== TEST FALLITO ===\n");
                }

                break;

            case 2:

                srand(1);

                T = newBST();

                freopen(
"tests/test_1_Registrazione/caso_limite_2_inserimento_campi_vuoti/input.txt",
"r",
stdin
);

                freopen(
"tests/test_1_Registrazione/caso_limite_2_inserimento_campi_vuoti/output.txt",
"w",
stdout
);

                inserisciSegnalazione(&T);

                fclose(stdin);

                fclose(stdout);

                ripristinaStandardIO();

                if(T != NULL){

                    printf("\n=== TEST SUPERATO ===\n");

                }else{

                    printf("\n=== TEST FALLITO ===\n");
                }

                break;

            case 0:

                printf("\nUscita...\n");

                break;

            default:

                printf("\nInserire un valore valido tra 0 e 2\n");
        }

        if(tipoTest != 0){

            printf("\nPremi INVIO per continuare...");

            getchar();
        }

    }while(tipoTest != 0);
}
