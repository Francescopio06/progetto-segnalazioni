#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"
#include "ricerca.h"

void testRicerca(void){

    BST T;

    segnalazione risultato;

    int tipoTest;

    char idRicerca[20];

    char categoria[50];

    do{

        pulisciSchermo();

        srand(1);

        T = newBST();

        caricaDatasetMisto(&T);

        printf("Scegliere il tipo di test\n");

        printf("\n1. Ricerca ID inesistente\n");

        printf("2. Ricerca categoria inesistente\n");

        printf("3. Differenza maiuscole/minuscole\n");

        printf("4. Stringa ID vuota\n");

        printf("5. Stringa categoria vuota\n");

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

                freopen(
"tests/test_2_Ricerca/caso_limite_1_id_inesistente/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_2_Ricerca/caso_limite_1_id_inesistente/output.txt",
                "w",
                stdout
                );

                fgets(idRicerca, 20, stdin);

                idRicerca[strcspn(idRicerca, "\n")] = '\0';

                while(idRicerca[0] == ' '){

                    memmove(idRicerca,
                            idRicerca + 1,
                            strlen(idRicerca));
                }

                risultato = ricercaPerId(T, idRicerca);

                if(risultato != NULL){

                    printf("Segnalazione trovata\n");

                }else{

                    printf("Segnalazione non trovata\n");
                }

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_2_Ricerca/caso_limite_1_id_inesistente/output.txt",
"tests/test_2_Ricerca/caso_limite_1_id_inesistente/oracolo.txt"
                );

                break;

            case 2:

                freopen(
"tests/test_2_Ricerca/caso_limite_2_categoria_inesistente/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_2_Ricerca/caso_limite_2_categoria_inesistente/output.txt",
                "w",
                stdout
                );

                fgets(categoria, 50, stdin);

                categoria[strcspn(categoria, "\n")] = '\0';

                while(categoria[0] == ' '){

                    memmove(categoria,
                            categoria + 1,
                            strlen(categoria));
                }

                if(ricercaPerCategoria(T, categoria) == 0){

                    printf("Nessuna segnalazione trovata\n");

                }else{

                    printf("Segnalazioni trovate\n");
                }

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_2_Ricerca/caso_limite_2_categoria_inesistente/output.txt",
"tests/test_2_Ricerca/caso_limite_2_categoria_inesistente/oracolo.txt"
                );

                break;

            case 3:

                freopen(
"tests/test_2_Ricerca/caso_limite_3_differenza_min_mausc/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_2_Ricerca/caso_limite_3_differenza_min_mausc/output.txt",
                "w",
                stdout
                );

                fgets(categoria, 50, stdin);

                categoria[strcspn(categoria, "\n")] = '\0';

                while(categoria[0] == ' '){

                    memmove(categoria,
                            categoria + 1,
                            strlen(categoria));
                }

                if(ricercaPerCategoria(T, categoria) == 0){

                    printf("Nessuna segnalazione trovata\n");

                }else{

                    printf("Segnalazioni trovate\n");
                }

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_2_Ricerca/caso_limite_3_differenza_min_mausc/output.txt",
"tests/test_2_Ricerca/caso_limite_3_differenza_min_mausc/oracolo.txt"
                );

                break;

            case 4:

                freopen(
"tests/test_2_Ricerca/caso_limite_4_stringaID_vuota/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_2_Ricerca/caso_limite_4_stringaID_vuota/output.txt",
                "w",
                stdout
                );

                fgets(idRicerca, 20, stdin);

                idRicerca[strcspn(idRicerca, "\n")] = '\0';

                risultato = ricercaPerId(T, idRicerca);

                if(risultato != NULL){

                    printf("Segnalazione trovata\n");

                }else{

                    printf("Segnalazione non trovata\n");
                }

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_2_Ricerca/caso_limite_4_stringaID_vuota/output.txt",
"tests/test_2_Ricerca/caso_limite_4_stringaID_vuota/oracolo.txt"
                );

                break;

            case 5:

                freopen(
"tests/test_2_Ricerca/caso_limite_5_stringaCat_vuota/input.txt",
                "r",
                stdin
                );

                freopen(
"tests/test_2_Ricerca/caso_limite_5_stringaCat_vuota/output.txt",
                "w",
                stdout
                );

                fgets(categoria, 50, stdin);

                categoria[strcspn(categoria, "\n")] = '\0';

                if(ricercaPerCategoria(T, categoria) == 0){

                    printf("Nessuna segnalazione trovata\n");

                }else{

                    printf("Segnalazioni trovate\n");
                }

                fflush(stdout);

                ripristinaStandardIO();

                verificaOracolo(
"tests/test_2_Ricerca/caso_limite_5_stringaCat_vuota/output.txt",
"tests/test_2_Ricerca/caso_limite_5_stringaCat_vuota/oracolo.txt"
                );

                break;

            case 0:

                printf("\nUscita...\n");

                break;

            default:

                printf("\nInserire un valore valido tra 0 e 5\n");
        }

        if(tipoTest != 0){

            printf("\nPremi INVIO per continuare...");

            getchar();
        }

    }while(tipoTest != 0);
}
