#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"
#include "urgenza.h"

void testUrgenza(void){

    BST T;

    int tipoTest;

    do{

        pulisciSchermo();

        printf("\nPossibili Test...\n");

        printf("1. Caso limite - Struttura Vuota\n");

        printf("2. Caso limite - Stessa Urgenza\n");

        printf("3. Caso limite - Nessuna urgenza massima\n");

        printf("4. Caso limite - Solo urgenza minima\n");

        printf("5. Caso limite - Urgenza richiesta nel nodo foglia\n");

        printf("0. esci\n");

        printf("Scelta: ");

        if(scanf("%d", &tipoTest) != 1){

            printf("\nInserire un valore valido da 0 a 5\n");

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
"tests/test_4_Priorità/caso_limite_1_Struttura_vuota/input.txt",
"r",
stdin
);

                freopen(
"tests/test_4_Priorità/caso_limite_1_Struttura_vuota/output.txt",
"w",
stdout
);

                mostraUrgenza(T);

                fflush(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 2:

                T = newBST();

                srand(1);

                datasetStessaUrgenzaAlta(&T);

                freopen(
"tests/test_4_Priorità/caso_limite_2_stessa_urgenza_massima/input.txt",
"r",
stdin
);

                freopen(
"tests/test_4_Priorità/caso_limite_2_stessa_urgenza_massima/output.txt",
"w",
stdout
);

                mostraUrgenza(T);

                fflush(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 3:

                T = newBST();

                srand(1);

                datasetSenzaUrgenzaAlta(&T);

                freopen(
"tests/test_4_Priorità/caso_limite_3_nessuna_urgenza_livello_1/input.txt",
"r",
stdin
);

                freopen(
"tests/test_4_Priorità/caso_limite_3_nessuna_urgenza_livello_1/output.txt",
"w",
stdout
);

                mostraUrgenza(T);

                fflush(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 4:

                T = newBST();

                srand(1);

                datasetSenzaUrgenzaAltaMedia(&T);

                freopen(
"tests/test_4_Priorità/caso_limite_4_nessuna_urgenza_livello_1_e_2/input.txt",
"r",
stdin
);

                freopen(
"tests/test_4_Priorità/caso_limite_4_nessuna_urgenza_livello_1_e_2/output.txt",
"w",
stdout
);

                mostraUrgenza(T);

                fflush(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 5:

                T = newBST();

                srand(1);

                datasetUrgenzaFoglia(&T);

                freopen(
"tests/test_4_Priorità/caso_limite_5_urgenza_nel_nodo_foglia/input.txt",
"r",
stdin
);

                freopen(
"tests/test_4_Priorità/caso_limite_5_urgenza_nel_nodo_foglia/output.txt",
"w",
stdout
);

                mostraUrgenza(T);

                fflush(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 0:

                printf("Uscita...\n");

                break;

            default:

                printf("\nInserire un valore valido tra 0 e 5\n");
        }

        if(tipoTest != 0){

            printf("\npremi INVIO per continuare...\n");

            getchar();
        }

    }while(tipoTest != 0);
}
