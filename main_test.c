#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulo_BST/BST.h"
#include "Modulo_Gestione/gestione.h"
#include "Modulo_Segnalazione/segnalazione.h"

/*
FILE: main_test.c
AUTORE: Francesco Pio Siano

Questo file si occupa dell'esecuzione dei test delle 
funzioni richieste.

Sono stati adottati dei dataset pre-impostati per poter
evitare di sporcare l'output dei test con l'output di richiesta
degli input per l'inserimento delle segnalazioni.

I test eseguiti sono relativi alle funzioni utilizzate nel main
e riguardano le operazioni di:
- Inserimento
- Ricerca (ID e Categoria)
- Aggiornamento stato
- Stampa per urgenza
- Filtra per status
- Generazione del report
*/

// Funzioni Test
static void testInserimento();
static void testRicerca();
static void testAggiornamento();
static void testUrgenza();
static void testFiltra();
static void testReport();
static void testCancellazione();

// Funzione Helper
static void caricaDatasetMisto(BST* T);

// Dataset Pre-impostati per Test Priorità
static void datasetStessaUrgenzaAlta(BST* T);
static void datasetSenzaUrgenzaAlta(BST* T);
static void datasetSenzaUrgenzaAltaMedia(BST* T);
static void datasetUrgenzaFoglia(BST* T);

// Dataset Pre-impostati per Test Filtri
static void datasetTutteAperte(BST* T);

// Dataset Pre-impostati per Test Report
static void datasetCategorieUguali(BST* T);

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
            
            case 7:
                testCancellazione();
                break;

            default:
                printf("Scelta non valida\n");
            }

    return 0;
}

static void testInserimento(){
    /* Utilizzo srand(1) affinchè il codice alfanumerico generato
    sia lo stesso ad ogni nuova chiamata*/
    srand(1);
    BST T = newBST();
    inserisciSegnalazione(&T);
}

static void testRicerca(){

    srand(1);

    BST T = newBST();

    caricaDatasetMisto(&T);

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

    caricaDatasetMisto(&T);

    int tipoTest;

    scanf("%d", &tipoTest);
    getchar();

    // Test transizione completa di stato
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

    switch(tipoTest){

         // caso limite struttura vuota
        case 1: 
            mostraUrgenza(T);
            break;
         // caso limite stessa urgenza (massima)
        case 2: 
            srand(1);
            datasetStessaUrgenzaAlta(&T);
            mostraUrgenza(T);
            break;

         // caso limite nessuna urgenza massima
        case 3:
            srand(1);
            datasetSenzaUrgenzaAlta(&T);
            mostraUrgenza(T);
            break;

         // caso limite solo urgenza minima 
        case 4:
            srand(1);
            datasetSenzaUrgenzaAltaMedia(&T);
            mostraUrgenza(T);
            break;

         // caso limite urgenza richiesta nel nodo foglia
        case 5:
            srand(1);
            datasetUrgenzaFoglia(&T);
            mostraUrgenza(T);
            break;

        default:
            printf("--- Scelta non valida ---");
    }
}

static void testFiltra(){

    BST T = newBST();

    int tipoTest;

    scanf("%d", &tipoTest);

    switch(tipoTest){

         // caso limite struttura vuota
        case 1:
            filtraSegnalazioni(T);
            break;
        
         // caso limite segnalazioni tutte aperte
        case 2: 
            srand(1);
            datasetTutteAperte(&T);
            filtraSegnalazioni(T);
            break;

         // caso limite stato richiesto (in lavorazione) assente 
        case 3:
            srand(1);
            datasetTutteAperte(&T);
            filtraSegnalazioni(T);
            break;

         // caso limite stato nella radice
        case 4:
            srand(1);
            caricaDatasetMisto(&T);
            filtraSegnalazioni(T);
            break;

         // caso limite stato nel nodo foglia
        case 5: 
            srand(1);
            caricaDatasetMisto(&T);
            filtraSegnalazioni(T);
            break;
        
         // caso limite elenco completo
        case 6:
            srand(1);
            caricaDatasetMisto(&T);
            filtraSegnalazioni(T);
            break;

        default:
            printf("\n--- Scelta non valida ---\n");
    }
}

static void testReport(){

    BST T = newBST();

    int tipoTest;

    scanf("%d", &tipoTest);
    getchar();

    switch(tipoTest){

         // Test struttura vuota
        case 1:
            generaReport(T);
            break;

         // Test struttura con un'unica segnalazione
        case 2:
            srand(1);
            segnalazione s1 = creaSegnalazione("Mario Rossi", "Strade", "Buca davanti scuola", 1, 1); 
            T = insert(T, s1);
            generaReport(T);
            break;
        
         // Test tutte stesse categorie
        case 3:
            srand(1);
            datasetCategorieUguali(&T);
            generaReport(T);
            break;

         // Test categoria diverse
        case 4:
            srand(1);
            caricaDatasetMisto(&T);
            generaReport(T);
            break;
            
        default:
            printf("\n--- Scelta non valida ---\n");
            break;
    }
}

static void testCancellazione(){
    
    BST T = newBST();

    int tipotest;
    scanf("%d", &tipotest);
    getchar();

    switch(tipotest){
        
        //test struttura vuota
        case 1: 
            eliminaSegnalazione(&T);
            break;
        
        //test eliminazione radice
        case 2:
            caricaDatasetMisto(&T);
            eliminaSegnalazione(&T);
            break;
        
        //test eliminazione nodo foglia 
        case 3:
            caricaDatasetMisto(&T);
            eliminaSegnalazione(&T);
            break;

        default:
            printf("\nScelta non valida\n");
            break;

    }
}


/*
Funzione caricaDatasetMisto
    La funzione crea tre segnalazioni predefinite 
    con lo scopo di ricoprire più casi
    di test possibili.

    Parametri:
        - T -> puntatore all'ADT BST

    Return:
        - Nessun valore restituito
*/
static void caricaDatasetMisto(BST* T){

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


// Dataset Pre-impostati per Test Priorità
/*
Funzione datasetStessaUrgenzaAlta(T)
    La funzione ha lo scopo di creare due segnalazioni
    aventi lo stesso livello di urgenza(1), tale funzione sarà
    usata anche per altri test rendendola riutilizzabile.

    Parametri:
        - T -> puntatore all' ADT BST

    Return:
        - Nessun valore restituito
*/
static void datasetStessaUrgenzaAlta(BST* T){

    *T = insert(*T,
        creaSegnalazione("Mario","Strade","Buca",1,1));

    *T = insert(*T,
        creaSegnalazione("Giulia","Luci","Lampione",1,1));

    *T = insert(*T,
        creaSegnalazione("Luca","Rifiuti","Cassonetto",3,1));
}

/* Caso limite stampa segnalazioni con urgenza (2) */
static void datasetSenzaUrgenzaAlta(BST* T){

    *T = insert(*T,
        creaSegnalazione("Mario","Strade","Buca",2,1));

    *T = insert(*T,
        creaSegnalazione("Giulia","Luci","Lampione",2,1));

    *T = insert(*T,
        creaSegnalazione("Luca","Rifiuti","Cassonetto",3,1));
}

/* Caso limite stampa segnalazioni con urgenza (3) */
static void datasetSenzaUrgenzaAltaMedia(BST* T){
    
    *T = insert(*T,
        creaSegnalazione("Mario","Strade","Buca",3,1));

    *T = insert(*T,
        creaSegnalazione("Giulia","Luci","Lampione",3,1));

    *T = insert(*T,
        creaSegnalazione("Luca","Rifiuti","Cassonetto",3,1));
}

/*
Funzione datasetUrgenzaFoglia
    La funzione ha lo scopo di generare un dataset ove
    la segnalazione da ricercare ricopra il ruolo di 
    foglia.

    Parametri:
        - T -> puntatore all' ADT BST

    Return:
        - Nessun valore restituito

*/
static void datasetUrgenzaFoglia(BST* T){

    *T = insert(*T,
        creaSegnalazione("Mario","Strade","Buca",3,1));

    *T = insert(*T,
        creaSegnalazione("Giulia","Luci","Lampione",2,1));

    *T = insert(*T,
        creaSegnalazione("Luca","Rifiuti","Cassonetto",1,1));
}

/* Dataset che crea tre segnalazioni con lo status aperto */
static void datasetTutteAperte(BST* T){
    
    *T = insert(*T,
        creaSegnalazione("Mario","Strade","Buca",1,1));

    *T = insert(*T,
        creaSegnalazione("Giulia","Luci","Lampione",1,1));

    *T = insert(*T,
        creaSegnalazione("Luca","Rifiuti","Cassonetto",1,1));
}

/* Dataset che crea tre segnalazioni con la stessa categorie 
    per verificare il relativo caso limite*/
static void datasetCategorieUguali(BST* T){
     
    *T = insert(*T,
        creaSegnalazione("Mario","Strade","Buca",1,1));

    *T = insert(*T,
        creaSegnalazione("Giulia","Strade","Lampione",1,1));

    *T = insert(*T,
        creaSegnalazione("Luca","Strade","Cassonetto",1,1));
}