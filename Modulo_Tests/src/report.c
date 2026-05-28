#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"
#include "report.h"

void testReport(void){

    segnalazione s1;

    BST T;

    int tipoTest;

    pulisciSchermo();

    do{

        printf("\nPossibili Test...\n");

        printf("1. Caso limite - Struttura Vuota\n");

        printf("2. Caso limite - Struttura con una segnalazione\n");

        printf("3. Caso limite - Segnalazioni con le stesse categorie\n");

        printf("4. Caso limite - Categorie diverse\n");

        printf("0. esci\n");

        printf("Scelta: ");

        if(scanf("%d", &tipoTest) != 1){

            printf("\nInserire un valore valido da 0 a 4\n");

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
"tests/test_7_Report/caso_limite_1_struttura_vuota/input.txt",
"r",
stdin
);

                freopen(
"tests/test_7_Report/caso_limite_1_struttura_vuota/output.txt",
"w",
stdout
);

                generaReport(T);

                fclose(stdin);

                fclose(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 2:

                T = newBST();

                srand(1);

                s1 = creaSegnalazione(
                    "Mario Rossi",
                    "Strade",
                    "Buca davanti scuola",
                    1,
                    1
                );

                T = insert(T, s1);

                freopen(
"tests/test_7_Report/caso_limite_2_unica_segnalazione/input.txt",
"r",
stdin
);

                freopen(
"tests/test_7_Report/caso_limite_2_unica_segnalazione/output.txt",
"w",
stdout
);

                generaReport(T);

                fclose(stdin);

                fclose(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 3:

                T = newBST();

                srand(1);

                datasetCategorieUguali(&T);

                freopen(
"tests/test_7_Report/caso_limite_3_stesse_categorie/input.txt",
"r",
stdin
);

                freopen(
"tests/test_7_Report/caso_limite_3_stesse_categorie/output.txt",
"w",
stdout
);

                generaReport(T);

                fclose(stdin);

                fclose(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 4:

                T = newBST();

                srand(1);

                caricaDatasetMisto(&T);

                freopen(
"tests/test_7_Report/caso_limite_4_categorie_diverse/input.txt",
"r",
stdin
);

                freopen(
"tests/test_7_Report/caso_limite_4_categorie_diverse/output.txt",
"w",
stdout
);

                generaReport(T);

                fclose(stdin);

                fclose(stdout);

                ripristinaStandardIO();

                printf("\n=== TEST COMPLETATO ===\n");

                break;

            case 0:

                printf("\nUscita...\n");

                break;

            default:

                printf("\nInserire un valore valido tra 0 e 4\n");

                break;
        }

        if(tipoTest != 0){

            printf("\npremi INVIO per continuare...\n");

            getchar();
        }

    }while(tipoTest != 0);
}
