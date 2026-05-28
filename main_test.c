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
- Cancellazione della segnalazione
- Generazione del report
*/

/* Funzioni Test */
static void testInserimento(void);
static void testRicerca(void);
static void testAggiornamento(void);
static void testUrgenza(void);
static void testFiltra(void);
static void testReport(void);
static void testCancellazione(void);

/* Funzione Helper */
static void caricaDatasetMisto(BST* T);

/* Dataset Pre-impostati per Test Priorità */
static void datasetStessaUrgenzaAlta(BST* T);
static void datasetSenzaUrgenzaAlta(BST* T);
static void datasetSenzaUrgenzaAltaMedia(BST* T);
static void datasetUrgenzaFoglia(BST* T);

/* Dataset Pre-impostati per Test Filtri */
static void datasetTutteAperte(BST* T);

/* Dataset Pre-impostati per Test Report */
static void datasetCategorieUguali(BST* T);

int main(void){

    int scelta;

    do{
    
    pulisciSchermo();

    printf(
    "  __  __                _____       _   \n"
    " |  \\/  |___ _ _ _  _  |_   _|__ __| |_ \n"
    );

    printf(
    " | |\\/| / -_) ' \\ || |   | |/ -_|_-<  _|\n"
    " |_|  |_|\\___|_||_\\_,_|   |_|\\___/__/\\__|\n"
    "                                         \n"
    ); 
    printf("1. Test Inserimento\n");
    printf("2. Test Ricerca\n");
    printf("3. Test Aggiornamento\n");
    printf("4. Test Urgenza\n");
    printf("5. Test Filtro\n");
    printf("6. Test Report\n");
    printf("7. Test Cancellazione\n");
    printf("0. Esci\n");
    printf("Scelta: ");

    if(scanf("%d", &scelta) != 1){
        
        printf("\nInserire un valore valido da 0 a 8\n");
        printf("---------------------------------\n");
            
        while(getchar() != '\n');

        printf("\nPremi INVIO per continuare...");
        getchar();
        continue;
    }
    
    getchar();

    switch(scelta){

        case 1:
            printf("\n=== Avvio Test Inserimento ===\n");
            testInserimento();
            printf("\n=== Test completato ===\n");
            break;

        case 2:
            printf("\n=== Avvio Test Ricerca ===\n");
            testRicerca();
            printf("\n=== Test completato ===\n");
            break;

        case 3:
            printf("\n=== Avvio Test Aggiornamento ===\n");
            testAggiornamento();
            printf("\n=== Test completato ===\n");
            break;

        case 4:
            printf("\n=== Avvio Test Urgenza ===\n");
            testUrgenza();
            printf("\n=== Test completato ===\n");
            break;

        case 5:
            printf("\n=== Avvio Test Filtro ===\n");
            testFiltra();
            printf("\n=== Test completato ===\n");
            break;

        case 6:
            printf("\n=== Avvio Test Report ===\n");
            testReport();
            printf("\n=== Test completato ===\n");
            break;

        case 7:
            printf("\n=== Avvio Test Cancellazione ===\n");
            testCancellazione();
            printf("\n=== Test completato ===\n");
            break;

        case 0: 
            printf("Uscita...\n");
            break;

        default:
            printf("Inserire un valore tra 0 a 7\n");
        }

        if(scelta != 0){
            printf("\npremi INVIO per continuare...\n");
            getchar();
        }

    }while(scelta != 0);
    
    return 0;
}

static void testInserimento(void){
    /* Utilizzo srand(1) affinchè il codice alfanumerico generato
    sia lo stesso ad ogni nuova chiamata*/
    BST T;

    pulisciSchermo();
    srand(1);
    T = newBST();
    inserisciSegnalazione(&T);
}

static void testRicerca(void){

    BST T;
    segnalazione risultato;
    int tipoTest;
    char idRicerca[20];
    char categoria[50];

    do{
    pulisciSchermo();


printf(
"  _____       _     ___ _                    \n"
" |_   _|__ __| |_  | _ (_)__ ___ _ _ __ __ _ \n"
);

printf(
"   | |/ -_|_-<  _| |   / / _/ -_) '_/ _/ _` |\n"
"   |_|\\___/__/\\__| |_|_\\_\\__\\___|_| \\__\\__,_|\n"
"                                              \n"
);
    srand(1);
    T = newBST();
    caricaDatasetMisto(&T);

    printf("Scegliere il tipo di test\n");
    printf("\n1. Ricerca per ID\n");
    printf("2. Ricerca per Categoria\n");
    printf("0. esci\n");
    printf("Scelta: ");

    if(scanf("%d", &tipoTest) != 1){
        
        printf("\nInserire un valore valido da 0 a 8\n");
        printf("---------------------------------\n");
            
        while(getchar() != '\n');

        printf("\nPremi INVIO per continuare...");
        getchar();
        continue;
    }

    getchar();

    switch(tipoTest){
        case 1: 

            printf("-------------------------");
            printf("\nDitigare: HOYNU2JI\n");
            printf("...inserire: ");

            fgets(idRicerca, 20, stdin);

            idRicerca[strcspn(idRicerca, "\n")] = '\0';

            while(idRicerca[0] == ' '){
                memmove(idRicerca, idRicerca + 1, strlen(idRicerca));
            }

            risultato = ricercaPerId(T, idRicerca);

            if(risultato != NULL){

                stampaSegnalazione(risultato);

            }else{

                printf("\n=== Segnalazione non trovata ===\n");
            }

            break;

        case 2:

            printf("-------------------------");
            printf("\nDigitare: Rifiuti\n");
            printf("...inserire: ");

            fgets(categoria, 50, stdin);
            categoria[strcspn(categoria, "\n")] = '\0';

            while(categoria[0] == ' '){
                memmove(categoria, categoria + 1, strlen(categoria));
            }

            if(ricercaPerCategoria(T, categoria) == 0){

                printf("\n=== Nessuna segnalazione trovata ===\n");
            }
            break;

        case 0:
            printf("\nUscita...");
            break;

        default:
            printf("\nInserire un valore valido tra 0 e 2\n");
        }
        
        if(tipoTest != 0){
            printf("\npremi INVIO per continuare...\n");
            getchar();
        }

    }while(tipoTest != 0);
}

static void testAggiornamento(void){

    BST T;
    int tipoTest;
    do{
    
    pulisciSchermo();

printf(
"  _____       _       _             _                                 _       \n"
" |_   _|__ __| |_    /_\\  __ _ __ _(_)___ _ _ _ _  __ _ _ __  ___ _ _| |_ ___ \n"
);

printf(
"   | |/ -_|_-<  _|  / _ \\/ _` / _` | / _ \\ '_| ' \\/ _` | '  \\/ -_) ' \\  _/ _ \\\n"
"   |_|\\___/__/\\__| /_/ \\_\\__, \\__, |_|\\___|_| |_||_\\__,_|_|_|_\\___|_||_\\__\\___/\n"
"                         |___/|___/                                            \n"
);
    
    srand(1);
    T = newBST();
    caricaDatasetMisto(&T);
    
    printf("-------------------------");
    printf("\nID da utilizzare: HOYNU2JI\n");

    printf("\nScegliere il tipo di test:\n");
    printf("1. Transizione di stato [Aperta -> In lavorazione -> Chiusa]\n");
    printf("2. Altri test...\n");
    printf("0. esci");
    printf("\nscelta: ");

    if(scanf("%d", &tipoTest) != 1){
        
        printf("\nInserire un valore valido da 0 a 2\n");
        printf("---------------------------------\n");
            
        while(getchar() != '\n');

        printf("\nPremi INVIO per continuare...");
        getchar();
        continue;
    }
    getchar();

    /* Test transizione completa di stato */
    switch(tipoTest){
        case 1:
            aggiornaStato(T);
            printf("\nPremi INVIO per continuare...");
            getchar();
            aggiornaStato(T);
            break;
        
        case 2: 
            aggiornaStato(T);
            
            break;

        case 0:
            printf("\nUscita...");

            break;

        default:
            printf("\nInserire un valore valido tra 0 e 2\n");
        }

        if(tipoTest != 0){
            printf("\npremi INVIO per continuare...\n");
            getchar();
        }

    }while(tipoTest != 0);
}

static void testUrgenza(void){

    BST T;

    int tipoTest;



    do{

        pulisciSchermo();
      
printf(
"  _____       _        _                                                          \n"
" |_   _|__ __| |_   __| |_ __ _ _ __  _ __  __ _   _  _ _ _ __ _ ___ _ _  _____ _ \n"
);

printf(
"   | |/ -_|_-<  _| (_-<  _/ _` | '  \\| '_ \\/ _` | | || | '_/ _` / -_) ' \\|_ / _` |\n"
"   |_|\\___/__/\\__| /__/\\__\\__,_|_|_|_| .__/\\__,_|  \\_,_|_| \\__, \\___|_||_/__\\__,_|\n"
"                                     |_|                   |___/                   \n"
);  



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
        printf("---------------------------------\n");
            
        while(getchar() != '\n');

        printf("\nPremi INVIO per continuare...");
        getchar();
        continue;
    }
    getchar();

    switch(tipoTest){

         /* caso limite struttura vuota */
        case 1: 
            T = newBST();
            mostraUrgenza(T);
            break;
         /* caso limite stessa urgenza (massima) */
        case 2: 
            T = newBST();
            srand(1);
            datasetStessaUrgenzaAlta(&T);
            mostraUrgenza(T);
            break;

         /* caso limite nessuna urgenza massima */
        case 3:
            T = newBST();
            srand(1);
            datasetSenzaUrgenzaAlta(&T);
            mostraUrgenza(T);
            break;

         /* caso limite solo urgenza minima */
        case 4:
            T = newBST();
            srand(1);
            datasetSenzaUrgenzaAltaMedia(&T);
            mostraUrgenza(T);
            break;

         /* caso limite urgenza richiesta nel nodo foglia */
        case 5:
            T = newBST();
            srand(1);
            datasetUrgenzaFoglia(&T);
            mostraUrgenza(T);
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

static void testFiltra(void){

    BST T;

    int tipoTest;


    do{

        pulisciSchermo();

printf(
"  _____       _     ___ _ _ _            \n"
" |_   _|__ __| |_  | __(_) | |_ _ _ __ _ \n"
);

printf(
"   | |/ -_|_-<  _| | _|| | |  _| '_/ _` |\n"
"   |_|\\___/__/\\__| |_| |_|_|\\__|_| \\__,_|\n"
"                                          \n"
);

    printf("\nPossibili Test...\n");
    printf("1. Caso limite - Struttura Vuota\n");
    printf("2. Caso limite - Segnalazioni tutte aperte\n");
    printf("3. Caso limite - Stato richiesto (in lavorazione) assente\n");
    printf("4. Caso limite - Stato nella radice\n");
    printf("5. Caso limite - Stato nel nodo foglia\n");
    printf("6. Caso limite - Elenco completo\n");
    printf("0. esci\n");
    printf("Scelta: ");

    if(scanf("%d", &tipoTest) != 1){
        
        printf("\nInserire un valore valido da 0 a 6\n");
        printf("---------------------------------\n");
            
        while(getchar() != '\n');

        printf("\nPremi INVIO per continuare...");
        getchar();
        continue;
    }

    getchar();

    switch(tipoTest){

         /* caso limite struttura vuota */
        case 1:
            T = newBST();
            filtraSegnalazioni(T);
            break;
        
         /* caso limite segnalazioni tutte aperte */
        case 2: 
            T = newBST();
            srand(1);
            datasetTutteAperte(&T);
            filtraSegnalazioni(T);
            break;

         /* caso limite stato richiesto (in lavorazione) assente */
        case 3:
            T = newBST();
            srand(1);
            datasetTutteAperte(&T);
            filtraSegnalazioni(T);
            break;

         /* caso limite stato nella radice */
        case 4:
            T = newBST();
            srand(1);
            caricaDatasetMisto(&T);
            filtraSegnalazioni(T);
            break;

         /* caso limite stato nel nodo foglia */
        case 5: 
            T = newBST();
            srand(1);
            caricaDatasetMisto(&T);
            filtraSegnalazioni(T);
            break;
        
         /* caso limite elenco completo */
        case 6:
            T = newBST();
            srand(1);
            caricaDatasetMisto(&T);
            filtraSegnalazioni(T);
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

static void testReport(void){

    segnalazione s1;
    BST T;
    int tipoTest;

    do{

        pulisciSchermo();

printf(
"  _____       _     ___                   _   \n"
" |_   _|__ __| |_  | _ \\___ _ __  ___ _ _| |_ \n"
);

printf(
"   | |/ -_|_-<  _| |   / -_) '_ \\/ _ \\ '_|  _|\n"
"   |_|\\___/__/\\__| |_|_\\___| .__/\\___/_|  \\__|\n"
"                           |_|                 \n"
);

        printf("\nPossibili Test...\n");
        printf("1. Caso limite - Struttura Vuota\n");
        printf("2. Caso limite - Struttura con una segnalazione\n");
        printf("3. Caso limite - Segnalazioni con le stesse categorie\n");
        printf("4. Caso limite - Categorie diverse\n");
        printf("0. esci\n");
        printf("Scelta: ");

        if(scanf("%d", &tipoTest) != 1){
        
            printf("\nInserire un valore valido da 0 a 4\n");
            printf("---------------------------------\n");
            
            while(getchar() != '\n');

            printf("\nPremi INVIO per continuare...");
            getchar();
            continue;
        }

        getchar();

    switch(tipoTest){

         /* Test struttura vuota */
        case 1:
            T = newBST();
            generaReport(T);
            break;

         /* Test struttura con un'unica segnalazione */
        case 2:
            T = newBST();
            srand(1);
            s1 = creaSegnalazione("Mario Rossi", "Strade", "Buca davanti scuola", 1, 1); 
            T = insert(T, s1);
            generaReport(T);
            break;
        
         /* Test tutte stesse categorie */
        case 3:
            T = newBST();
            srand(1);
            datasetCategorieUguali(&T);
            generaReport(T);
            break;

         /* Test categoria diverse */
        case 4:
            T = newBST();
            srand(1);
            caricaDatasetMisto(&T);
            generaReport(T);
            break;
        
        case 0:
            printf("\nUscita...");
            break;
            
        default:
            printf("\nInserire un valore valido tra 0 a 4\n");
            break;
        }

        if(tipoTest != 0){

            printf("\npremi INVIO per continuare...\n");
            getchar();
        }

    }while(tipoTest != 0);   
}

static void testCancellazione(void){
    
    int tipoTest;
    BST T;

    do{

    /*pulisciSchermo();*/

printf(
"  _____       _      ___                  _ _         _              \n"
" |_   _|__ __| |_   / __|__ _ _ _  __ ___| | |__ _ __(_)___ _ _  ___ \n"
);

printf(
"   | |/ -_|_-<  _| | (__/ _` | ' \\/ _/ -_) | / _` |_ / / _ \\ ' \\/ -_)\n"
"   |_|\\___/__/\\__|  \\___\\__,_|_||_\\__\\___|_|_\\__,_/__|_\\___/_||_\\___|\n"
"                                                                      \n"
);

    printf("\nPossibili Test...\n");
    printf("1. Caso limite - Struttura Vuota\n");
    printf("2. Caso limite - Eliminazione radice [ID da Inserire: HOYNU2JI]\n");
    printf("3. Caso limite - Eliminazione nodo foglia[ID da inserire: 0RST4HPD]\n");
    printf("0. esci\n");
    printf("Scelta: ");

    if(scanf("%d", &tipoTest) != 1){
        
        printf("\nInserire un valore valido da 0 a 8\n");
        printf("---------------------------------\n");
            
        while(getchar() != '\n');

        printf("\nPremi INVIO per continuare...");
        getchar();
        continue;
    }
    getchar();

    switch(tipoTest){
        
        /* test struttura vuota */
        case 1:
            T = newBST(); 
            eliminaSegnalazione(&T);
            break;
        
        /* test eliminazione radice */
        case 2:
            T = newBST();
            srand(1);
            caricaDatasetMisto(&T);
            eliminaSegnalazione(&T);
            break;
        
        /* test eliminazione nodo foglia */
        case 3:
            T = newBST();
            srand(1);
            caricaDatasetMisto(&T);
            eliminaSegnalazione(&T);
            break;

        case 0:
            printf("\nUscita...");
            break;

        default:
            printf("\nInserire un valore valido tra 0 e 3\n");

        }
        
        if(tipoTest != 0){
            printf("\npremi INVIO per continuare...\n");
            getchar();
        }

    }while(tipoTest != 0);
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

    segnalazione s1, s2, s3;

    s1 = creaSegnalazione(
        "Mario Rossi",
        "Strade",
        "Buca davanti scuola",
        1,
        1
    );
    setChiave(s1, generaChiave(*T));
    *T = insert(*T, s1);

    s2 = creaSegnalazione(
        "Giulia Bianchi",
        "Illuminazione",
        "Lampione guasto",
        2,
        2
    );
    setChiave(s2, generaChiave(*T));
    *T = insert(*T, s2);

    s3 = creaSegnalazione(
        "Luca Verdi",
        "Rifiuti",
        "Cassonetto pieno",
        3,
        3
    );
    setChiave(s3, generaChiave(*T));
    *T = insert(*T, s3);
}


/* Dataset Pre-impostati per Test Priorità */
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

    segnalazione s1, s2, s3;

    s1 = creaSegnalazione("Mario","Strade","Buca",1,1);
    setChiave(s1, generaChiave(*T));
    *T = insert(*T, s1);

    s2 = creaSegnalazione("Giulia","Luci","Lampione",1,1);
    setChiave(s2, generaChiave(*T));
    *T = insert(*T, s2);

    s3 = creaSegnalazione("Luca","Rifiuti","Cassonetto",3,1);
    setChiave(s3, generaChiave(*T));
    *T = insert(*T, s3);
}

/* Caso limite stampa segnalazioni con urgenza (2) */
static void datasetSenzaUrgenzaAlta(BST* T){

    segnalazione s1, s2, s3;

    s1 = creaSegnalazione("Mario","Strade","Buca",2,1);
    setChiave(s1, generaChiave(*T));
    *T = insert(*T, s1);

    s2 = creaSegnalazione("Giulia","Luci","Lampione",2,1);
    setChiave(s2, generaChiave(*T));
    *T = insert(*T, s2);

    s3 = creaSegnalazione("Luca","Rifiuti","Cassonetto",3,1);
    setChiave(s3, generaChiave(*T));
    *T = insert(*T, s3);
}

/* Caso limite stampa segnalazioni con urgenza (3) */
static void datasetSenzaUrgenzaAltaMedia(BST* T){

    segnalazione s1, s2, s3;

    s1 = creaSegnalazione("Mario","Strade","Buca",3,1);
    setChiave(s1, generaChiave(*T));
    *T = insert(*T, s1);

    s2 = creaSegnalazione("Giulia","Luci","Lampione",3,1);
    setChiave(s2, generaChiave(*T));
    *T = insert(*T, s2);

    s3 = creaSegnalazione("Luca","Rifiuti","Cassonetto",3,1);
    setChiave(s3, generaChiave(*T));
    *T = insert(*T, s3);
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

    segnalazione s1, s2, s3;

    s1 = creaSegnalazione("Mario","Strade","Buca",3,1);
    setChiave(s1, generaChiave(*T));
    *T = insert(*T, s1);

    s2 = creaSegnalazione("Giulia","Luci","Lampione",2,1);
    setChiave(s2, generaChiave(*T));
    *T = insert(*T, s2);

    s3 = creaSegnalazione("Luca","Rifiuti","Cassonetto",1,1);
    setChiave(s3, generaChiave(*T));
    *T = insert(*T, s3);
}

/* Dataset che crea tre segnalazioni con lo status aperto */
static void datasetTutteAperte(BST* T){

    segnalazione s1, s2, s3;
    
    s1 = creaSegnalazione("Mario","Strade","Buca",1,1);
    setChiave(s1, generaChiave(*T));
    *T = insert(*T, s1);

    s2 = creaSegnalazione("Giulia","Luci","Lampione",1,1);
    setChiave(s2, generaChiave(*T));
    *T = insert(*T, s2);

    s3 = creaSegnalazione("Luca","Rifiuti","Cassonetto",1,1);
    setChiave(s3, generaChiave(*T));
    *T = insert(*T, s3);
}

/* Dataset che crea tre segnalazioni con la stessa categorie 
    per verificare il relativo caso limite*/
static void datasetCategorieUguali(BST* T){

    segnalazione s1, s2, s3;

    s1 = creaSegnalazione("Mario","Strade","Buca",1,1);
    setChiave(s1, generaChiave(*T));
    *T = insert(*T, s1);

    s2 = creaSegnalazione("Giulia","Strade","Lampione",1,1);
    setChiave(s2, generaChiave(*T));
    *T = insert(*T, s2);

    s3 = creaSegnalazione("Luca","Strade","Cassonetto",1,1);
    setChiave(s3, generaChiave(*T));
    *T = insert(*T, s3);
}
