#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"
#include "cancellazione.h"

void testCancellazione(void){

    int tipoTest;

    BST T;

    do{

        pulisciSchermo();

        printf("\nPossibili Test...\n");

        printf("1. Caso limite - Struttura Vuota\n");

        printf("2. Caso limite - Eliminazione radice\n");

        printf("3. Caso limite - Eliminazione nodo foglia\n");

        printf("0. Esci\n");

        printf("Scelta: ");

        if(scanf("%d", &tipoTest) != 1){

            printf("\nInserire un valore valido da 0 a 3\n");

            while(getchar() != '\n');

            printf("\nPremi INVIO per continuare...");

            getchar();

            continue;
        }

        getchar();

        switch(tipoTest){

            case 1:

                T = newBST();

                freopen(
"tests/test_6_Cancellazione/caso_limite_1_struttura_vuota/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_6_Cancellazione/caso_limite_1_struttura_vuota/output.txt",
                "w",
                stdout
                );

                eliminaSegnalazione(&T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_6_Cancellazione/caso_limite_1_struttura_vuota/output.txt",
"tests/test_6_Cancellazione/caso_limite_1_struttura_vuota/oracolo.txt"
                );

                break;

            case 2:

                T = newBST();

                srand(1);

                caricaDatasetMisto(&T);

                freopen(
"tests/test_6_Cancellazione/caso_limite_2_eliminazione_radice/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_6_Cancellazione/caso_limite_2_eliminazione_radice/output.txt",
                "w",
                stdout
                );

                eliminaSegnalazione(&T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_6_Cancellazione/caso_limite_2_eliminazione_radice/output.txt",
"tests/test_6_Cancellazione/caso_limite_2_eliminazione_radice/oracolo.txt"
                );

                break;

            case 3:

                T = newBST();

                srand(1);

                caricaDatasetMisto(&T);

                freopen(
"tests/test_6_Cancellazione/caso_limite_3_eliminazione_nodo_foglia/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_6_Cancellazione/caso_limite_3_eliminazione_nodo_foglia/output.txt",
                "w",
                stdout
                );

                eliminaSegnalazione(&T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_6_Cancellazione/caso_limite_3_eliminazione_nodo_foglia/output.txt",
"tests/test_6_Cancellazione/caso_limite_3_eliminazione_nodo_foglia/oracolo.txt"
                );

                break;

            case 0:

                printf("\nUscita...\n");

                break;

            default:

                printf("\nInserire un valore valido tra 0 e 3\n");
        }

        if(tipoTest != 0){

            printf("\nPremi INVIO per continuare...\n");

            getchar();
        }

    }while(tipoTest != 0);
}
