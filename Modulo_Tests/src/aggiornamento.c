#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"
#include "aggiornamento.h"

void testAggiornamento(void){

    BST T;

    int tipoTest;

    do{

        pulisciSchermo();

        printf("-------------------------");

        printf("\nScegliere il tipo di test:\n");

        printf("1. Transizione di stato\n");

        printf("2. Inserimento stesso stato\n");

        printf("3. Aggiornamento stato radice\n");

        printf("4. Aggiornamento nodo recente\n");

        printf("0. Esci\n");

        printf("\nScelta: ");

        if(scanf("%d", &tipoTest) != 1){

            printf("\nInserire un valore valido da 0 a 4\n");

            while(getchar() != '\n');

            printf("\nPremi INVIO per continuare...");

            getchar();

            continue;
        }

        getchar();

        srand(1);

        T = newBST();

        caricaDatasetMisto(&T);

        switch(tipoTest){

            case 1:

                freopen(
"tests/test_3_Aggiornamento/caso_limite_1_transizione_di_stato/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_3_Aggiornamento/caso_limite_1_transizione_di_stato/output.txt",
                "w",
                stdout
                );

                aggiornaStato(T);

                aggiornaStato(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_3_Aggiornamento/caso_limite_1_transizione_di_stato/output.txt",
"tests/test_3_Aggiornamento/caso_limite_1_transizione_di_stato/oracolo.txt"
                );

                break;

            case 2:

                freopen(
"tests/test_3_Aggiornamento/caso_limite_2_inserimento_stesso_stato/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_3_Aggiornamento/caso_limite_2_inserimento_stesso_stato/output.txt",
                "w",
                stdout
                );

                aggiornaStato(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_3_Aggiornamento/caso_limite_2_inserimento_stesso_stato/output.txt",
"tests/test_3_Aggiornamento/caso_limite_2_inserimento_stesso_stato/oracolo.txt"
                );

                break;

            case 3:

                freopen(
"tests/test_3_Aggiornamento/caso_limite_3_aggiornamento_stato_radice/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_3_Aggiornamento/caso_limite_3_aggiornamento_stato_radice/output.txt",
                "w",
                stdout
                );

                aggiornaStato(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_3_Aggiornamento/caso_limite_3_aggiornamento_stato_radice/output.txt",
"tests/test_3_Aggiornamento/caso_limite_3_aggiornamento_stato_radice/oracolo.txt"
                );

                break;

            case 4:

                freopen(
"tests/test_3_Aggiornamento/caso_limite_4_aggiornamento_nodo_recente/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_3_Aggiornamento/caso_limite_4_aggiornamento_nodo_recente/output.txt",
                "w",
                stdout
                );

                aggiornaStato(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_3_Aggiornamento/caso_limite_4_aggiornamento_nodo_recente/output.txt",
"tests/test_3_Aggiornamento/caso_limite_4_aggiornamento_nodo_recente/oracolo.txt"
                );

                break;

            case 0:

                printf("\nUscita...\n");

                break;

            default:

                printf("\nInserire un valore valido tra 0 e 4\n");
        }

        if(tipoTest != 0){

            printf("\nPremi INVIO per continuare...\n");

            getchar();
        }

    }while(tipoTest != 0);
}
