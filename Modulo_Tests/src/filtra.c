#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"
#include "filtra.h"

void testFiltra(void){

    BST T;

    int tipoTest;

    do{

        pulisciSchermo();

        printf("\nPossibili Test...\n");

        printf("1. Caso limite - Struttura Vuota\n");

        printf("2. Caso limite - Segnalazioni tutte aperte\n");

        printf("3. Caso limite - Stato richiesto assente\n");

        printf("4. Caso limite - Stato nella radice\n");

        printf("5. Caso limite - Stato nel nodo foglia\n");

        printf("6. Caso limite - Elenco completo\n");

        printf("0. esci\n");

        printf("Scelta: ");

        if(scanf("%d", &tipoTest) != 1){

            printf("\nInserire un valore valido da 0 a 6\n");

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
"tests/test_5_Filtri/caso_limite_1_struttura_vuota/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_5_Filtri/caso_limite_1_struttura_vuota/output.txt",
                "w",
                stdout
                );

                filtraSegnalazioni(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_5_Filtri/caso_limite_1_struttura_vuota/output.txt",
"tests/test_5_Filtri/caso_limite_1_struttura_vuota/oracolo.txt"
                );

                break;

            case 2:

                T = newBST();

                srand(1);

                datasetTutteAperte(&T);

                freopen(
"tests/test_5_Filtri/caso_limite_2_tutte_aperte/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_5_Filtri/caso_limite_2_tutte_aperte/output.txt",
                "w",
                stdout
                );

                filtraSegnalazioni(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_5_Filtri/caso_limite_2_tutte_aperte/output.txt",
"tests/test_5_Filtri/caso_limite_2_tutte_aperte/oracolo.txt"
                );

                break;

            case 3:

                T = newBST();

                srand(1);

                datasetTutteAperte(&T);

                freopen(
"tests/test_5_Filtri/caso_limite_3_stato_richiesto_assente/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_5_Filtri/caso_limite_3_stato_richiesto_assente/output.txt",
                "w",
                stdout
                );

                filtraSegnalazioni(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_5_Filtri/caso_limite_3_stato_richiesto_assente/output.txt",
"tests/test_5_Filtri/caso_limite_3_stato_richiesto_assente/oracolo.txt"
                );

                break;

            case 4:

                T = newBST();

                srand(1);

                caricaDatasetMisto(&T);

                freopen(
"tests/test_5_Filtri/caso_limite_4_stato_nella_radice/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_5_Filtri/caso_limite_4_stato_nella_radice/output.txt",
                "w",
                stdout
                );

                filtraSegnalazioni(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_5_Filtri/caso_limite_4_stato_nella_radice/output.txt",
"tests/test_5_Filtri/caso_limite_4_stato_nella_radice/oracolo.txt"
                );

                break;

            case 5:

                T = newBST();

                srand(1);

                caricaDatasetMisto(&T);

                freopen(
"tests/test_5_Filtri/caso_limite_5_stato_nel_nodo_foglia/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_5_Filtri/caso_limite_5_stato_nel_nodo_foglia/output.txt",
                "w",
                stdout
                );

                filtraSegnalazioni(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_5_Filtri/caso_limite_5_stato_nel_nodo_foglia/output.txt",
"tests/test_5_Filtri/caso_limite_5_stato_nel_nodo_foglia/oracolo.txt"
                );

                break;

            case 6:

                T = newBST();

                srand(1);

                caricaDatasetMisto(&T);

                freopen(
"tests/test_5_Filtri/caso_limite_6_elenco_completo/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_5_Filtri/caso_limite_6_elenco_completo/output.txt",
                "w",
                stdout
                );

                filtraSegnalazioni(T);

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_5_Filtri/caso_limite_6_elenco_completo/output.txt",
"tests/test_5_Filtri/caso_limite_6_elenco_completo/oracolo.txt"
                );

                break;

            case 0:

                printf("Uscita...\n");

                break;

            default:

                printf("\nInserire un valore valido tra 0 e 6\n");

                break;
        }

        if(tipoTest != 0){

            printf("\npremi INVIO per continuare...\n");

            getchar();
        }

    }while(tipoTest != 0);
}
