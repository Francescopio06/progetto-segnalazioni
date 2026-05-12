#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulo_BST/BST.h"
#include "Modulo_Gestione/gestione.h"
#include "Modulo_Segnalazione/segnalazione.h"

static void testInserimento();
static void testRicerca();
static void testAggiornamento();
static void testUrgenza();
static void testFiltra();
static void testReport();
static void caricaDataset(BST* T);

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

            case 4:
                testUrgenza();
                break;

            case 5: 
                testFiltra();
                break;
            case 6:
                testReport();
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

    caricaDataset(&T);

    int scelta;

    scanf("%d", &scelta);

    getchar();


    if(scelta == 1){

        char idRicerca[20];

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

        fgets(categoria, 50, stdin);

        categoria[strcspn(categoria, "\n")] = '\0';


        if(ricercaPerCategoria(T, categoria) == 0){

            printf("\n=== Nessuna segnalazione trovata ===\n");
        }
    }
}

static void testAggiornamento(){

    srand(1);

    BST T = newBST();

    caricaDataset(&T);

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

static void testUrgenza(){

    BST T = newBST();

    int tipoTest;

    scanf("%d", &tipoTest);
    getchar();

    if(tipoTest == 1){

        mostraUrgenza(T);

        return;
    }

    srand(1);

    caricaDataset(&T);

    mostraUrgenza(T);
}

static void testFiltra(){

    BST T = newBST();

    int tipoTest;

    scanf("%d", &tipoTest);
    getchar();

    if(tipoTest == 1){
        filtraSegnalazioni(T);
        return;
    }

    srand(1);

    caricaDataset(&T);

    filtraSegnalazioni(T);
}

static void testReport(){

    BST T = newBST();

    int tipoTest;

    scanf("%d", &tipoTest);
    getchar();

    if(tipoTest == 1){
        generaReport(T);
        return;
    }

    srand(1);

    if(tipoTest == 2){
        segnalazione s1 = creaSegnalazione("Mario Rossi", "Strade", "Buca davanti scuola", 1, 1); 
        T = insert(T, s1);
        generaReport(T);
        return;
    }

    caricaDataset(&T);

    generaReport(T);
}

static void caricaDataset(BST* T){

    segnalazione s1 = creaSegnalazione(
        "Mario Rossi",
        "Strade",
        "Buca davanti scuola",
        1,
        1
    );

    *T = insert(*T, s1);

    segnalazione s2 = creaSegnalazione(
        "Giulia Bianchi",
        "Illuminazione",
        "Lampione guasto",
        2,
        2
    );

    *T = insert(*T, s2);

    segnalazione s3 = creaSegnalazione(
        "Luca Verdi",
        "Rifiuti",
        "Cassonetto pieno",
        3,
        3
    );

    *T = insert(*T, s3);
}