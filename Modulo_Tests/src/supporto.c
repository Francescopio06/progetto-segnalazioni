#include "BST.h"
#include "gestione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supporto.h"


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

void caricaDatasetMisto(BST* T){

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
void datasetStessaUrgenzaAlta(BST* T){

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
void datasetSenzaUrgenzaAlta(BST* T){

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
void datasetSenzaUrgenzaAltaMedia(BST* T){

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
void datasetUrgenzaFoglia(BST* T){

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
void datasetTutteAperte(BST* T){

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
void datasetCategorieUguali(BST* T){

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

int confrontaFile(FILE* output, FILE* oracolo){

    int c1;
    int c2;

    do{

        c1 = fgetc(output);
        c2 = fgetc(oracolo);

        if(c1 != c2){
            return 0;
        }

    }while(c1 != EOF && c2 != EOF);

    return 1;
}

void verificaOracolo(const char* outputFile, const char* oracoloFile){

    FILE* output;
    FILE* oracolo;

    output = fopen(outputFile, "r");

    oracolo = fopen(oracoloFile, "r");

    if(output == NULL || oracolo == NULL){

        printf("\n=== ERRORE APERTURA FILE ===\n");

        return;
    }

    if(confrontaFile(output, oracolo)){

        printf("\n=== TEST SUPERATO ===\n");

    }else{

        printf("\n=== TEST FALLITO ===\n");
    }

    fclose(output);

    fclose(oracolo);
}

void ripristinaStandardIO(void){

    freopen("/dev/tty", "r", stdin);

    freopen("/dev/tty", "w", stdout);
}
