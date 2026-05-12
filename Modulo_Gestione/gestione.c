#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "segnalazione.h"

//struttura Helper
typedef struct {
    char categoria[50];
    int count;
} ContaCategoria;

static void visitaReport(BST Albero, int* tot, int* aperte, int* chiuse, int* inLavorazione, ContaCategoria stats[], int* nCategorie);
static void controlloID(BST Albero, char* ID);
static segnalazione acquisisciSegnalazione();

//funzioni principali
void inserisciSegnalazione(BST* T){

    segnalazione s = acquisisciSegnalazione();

    if(s == NULL){
        return;
    }

    controlloID(*T, getID(s));

    *T = insert(*T, s);

    printf("\n=== Segnalazione Inserita! ===\n");
}

void visualizzaSegnalazione(BST Albero){
    outputBST(Albero);
}

void ricercaSegnalazione(BST Albero){

    int choice;
    char IDtemp[9];
    char CategoriaTemp[50];
    printf("Scegliere il criterio di ricerca: ");
    printf("\n1. Ricerca per ID\n2. Ricerca per Categoria");
    scanf("%d", &choice);
    getchar();

    switch (choice){
    case 1: 

        printf("\nInserire ID: ");
        fgets(IDtemp, 9, stdin);
        IDtemp[strcspn(IDtemp, "\n")] = '\0';

        segnalazione s = ricercaPerId(Albero, IDtemp);

        if(s == NULL){
            printf("segnalazione non trovata");
        } else {
            stampaSegnalazione(s);
        }
        break;
    case 2: 

        printf("\nInserire Categoria: ");
        fgets(CategoriaTemp, 50, stdin);
        CategoriaTemp[strcspn(CategoriaTemp, "\n")] = '\0';

        if(ricercaPerCategoria(Albero, CategoriaTemp) == 0){
        printf("=== NESSUNA SEGNALAZIONE TROVATA ===");
        }
        
        break;

    default:
        printf("\n---Scelta non valida---");        
    }
}

void aggiornaStato(BST Albero){

    char IDtemp[10];
    int choice;
    char statusTmp[20];

    printf("\nInserire ID della segnalazione: ");
    fgets(IDtemp, 10, stdin);
    IDtemp[strcspn(IDtemp, "\n")]= '\0';

    segnalazione s = ricercaPerId(Albero, IDtemp);
    if(s == NULL){
        printf("\nSegnalazione non trovata\n");
        return;
    }

    strcpy(statusTmp, getStatus(s));

    printf("\nStatus: %s", getStatus(s));
    printf("\nScegliere il nuovo status della segnalazione:");
    printf("\n1. Aperta \n2. In lavorazione\n3. Chiusa");
    printf("\nscelta: ");

    scanf("%d", &choice);
    getchar();

    switch(choice){
    case 1:
        if(strcmp(getStatus(s), "aperta") == 0){
            printf("\n---------------------------------\n");
            printf("=== Nuovo stato corrisponde all'attuale! ===\n");
            printf("---------------------------------\n");
            return;
        }
        setStatus(s, "aperta");
        break;
    case 2:
        if(strcmp(getStatus(s), "in lavorazione") == 0){
            printf("\n---------------------------------\n");
            printf("=== Nuovo stato corrisponde all'attuale! ===\n");
            printf("---------------------------------\n");
            return;
        }
        setStatus(s, "in lavorazione");
        break;
    case 3:
        if(strcmp(getStatus(s), "chiusa") == 0){
            printf("\n---------------------------------\n");
            printf("=== Nuovo stato corrisponde all'attuale! ===\n");
            printf("---------------------------------\n");
            return;
        }
        setStatus(s, "chiusa");
        break;
    default:
        printf("\n---Scelta non valida---");
    }

    printf("\n---------------------------------\n");
    printf("=== Stato aggiornato! ===\n");
    printf("---------------------------------\n");      
}

void filtraSegnalazioni(BST Albero){
    int trovato = 0;

    if(Albero == NULL){
        printf("\n---------------------------------\n");
        printf("=== Nessuna Segnalazione presente! ===\n");
        printf("---------------------------------\n");
        return;
    } 

    int choice;

    printf("\nQuali segnalazioni vuoi visualizzare:\n");
    printf("1. Aperte\n2. In lavorazione\n3. Chiuse\n4. Elenco completo");
    printf("\nscelta:");
    scanf("%d", &choice);
    getchar();

    switch(choice){
    case 1:

        printf("\n---------------------------------\n");
        printf("\n=== Segnalazioni Aperte! ===\n");
        stampaPerStatus(Albero, "aperta", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }
        break;
    case 2: 

        printf("\n---------------------------------\n");
        printf("\nSegnalazioni In Lavorazione\n");
        stampaPerStatus(Albero, "in lavorazione", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }
        break;
    case 3:

        printf("\n---------------------------------\n");
        printf("\nSegnalazioni Chiuse\n");
        stampaPerStatus(Albero, "chiusa", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }
        break;
    case 4: 

        printf("\n---------------------------------\n");
        printf("\n=== ELENCO COMPLETO ===\n");

        trovato = 0;
        printf("\n---------------------------------\n");
        printf("Segnalazioni Aperte: \n");
        stampaPerStatus(Albero, "aperta", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }

        trovato = 0;
        printf("\n---------------------------------\n");
        printf("Segnalazioni In Lavorazione: \n");
        stampaPerStatus(Albero, "in lavorazione", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }

        trovato = 0;
        printf("\n---------------------------------\n");
        printf("Segnalazioni Chiuse: \n");
        stampaPerStatus(Albero, "chiusa", &trovato);
        if(trovato == 0){
            printf("\n=== Nessuna Segnalazione presente per lo satto richiesto ===\n");
        }
        break;
    default:
        printf("\n---Scelta non valida---\n");
    }
}

void mostraUrgenza(BST Albero){

    if(Albero == NULL){
        printf("\n---------------------------------\n");
        printf("=== Nessuna Segnalazione presente! ===\n");
        printf("---------------------------------\n");
        return;
    }

    if(esisteUrgenza(Albero, 1)){
        printf("\nSegnalazioni con urgenza Massima (1):\n");
        stampaPerUrgenza(Albero, 1);
    } 
    else if(esisteUrgenza(Albero, 2)){
        printf("\nSegnalazioni con urgenza Media (2):\n");
        stampaPerUrgenza(Albero, 2);
    } 
    else if(esisteUrgenza(Albero, 3)){
        printf("\nSegnalazione con urgenza Minima (3):\n");
        stampaPerUrgenza(Albero, 3);
    }
    else{
        printf("\nNessuna segnalazione trovata\n");
    }

}

void eliminaSegnalazione(BST Albero){
    if(Albero == NULL){
        printf("Nessuna segnalazione trovata");
        return;
    }

    char IDtemp[9];

    printf("Inserire ID della segnalazione da eliminare: ");
    fgets(IDtemp, 9, stdin);
    IDtemp[strcspn(IDtemp, "\n")] = '\0';

    segnalazione s = ricercaPerId(Albero, IDtemp);
    if(s == NULL){
        printf("Segnalazione non trovata\n");
        return;
    }

    Albero = CancellaSegnalazione(Albero, getChiave(s));

    printf("Cancellazione Riuscita!\n");
}

void generaReport(BST Albero){

    if(Albero == NULL){
        printf("\n---------------------------------\n");
        printf("=== Nessuna Segnalazione presente! ===\n");
        printf("---------------------------------\n");
        return;
    }

    int tot = 0;
    int aperte = 0;
    int chiuse = 0;
    int inLavorazione = 0;

    ContaCategoria stats[100];
    int nCategorie = 0;

    visitaReport(Albero, &tot, &aperte, &chiuse, &inLavorazione, stats, &nCategorie);

    // stampa base
    printf("\n--- REPORT ---\n");
    printf("Totale segnalazioni: %d\n", tot);
    printf("Aperte: %d\n", aperte);
    printf("Chiuse: %d\n", chiuse);
    printf("In lavorazione: %d\n", inLavorazione);

    // per categoria
    printf("\nSegnalazioni per categoria:\n");
    for(int i = 0; i < nCategorie; i++){
        printf("%s: %d\n", stats[i].categoria, stats[i].count);
    }

    // categoria più frequente
    int max = 0;
    int indice = -1;

    for(int i = 0; i < nCategorie; i++){
        if(stats[i].count > max){
            max = stats[i].count;
            indice = i;
        }
    }

    if(indice != -1){
        printf("\nCategoria più frequente: %s (%d)\n",
               stats[indice].categoria,
               stats[indice].count);
    }
}

//funzione helper per il Report
static void visitaReport(BST Albero, int* tot, int* aperte, int* chiuse,int* inLavorazione, ContaCategoria stats[], int* nCategorie){

    if(Albero == NULL) return;

    visitaReport(figlioSX(Albero), tot, aperte, chiuse, inLavorazione, stats, nCategorie);

    segnalazione s = getSegnalazione(Albero);

    (*tot)++;

    // stato
    if(strcmp(getStatus(s), "aperta") == 0)
        (*aperte)++;
    else if(strcmp(getStatus(s), "chiusa") == 0)
        (*chiuse)++;
    else if(strcmp(getStatus(s), "in lavorazione") == 0)
        (*inLavorazione)++;

    // categoria
    char* cat = getCategoria(s);
    int trovato = 0;

    for(int i = 0; i < *nCategorie; i++){
        if(strcmp(stats[i].categoria, cat) == 0){
            stats[i].count++;
            trovato = 1;
            break;
        }
    }

    if(!trovato){
        strcpy(stats[*nCategorie].categoria, cat);
        stats[*nCategorie].count = 1;
        (*nCategorie)++;
    }

    visitaReport(figlioDX(Albero), tot, aperte, chiuse, inLavorazione, stats, nCategorie);
}

static void controlloID(BST Albero, char* ID){

    while(ricercaPerId(Albero, ID) != NULL){

        generaID(ID);

    }
}

static segnalazione acquisisciSegnalazione(){

    char nome[50];
    char categoria[50];
    char descrizione[100];
    int urgenza;
    int stato;

    do{
        printf("Inserire Nome del Segnalatore:\n");

        fgets(nome, 50, stdin);

        nome[strcspn(nome, "\n")] = '\0';

    }while(strlen(nome) == 0);
    
    printf("-----------------------------\n");

    do{
        printf("Inserire Categoria della segnalazione:\n");

        fgets(categoria, 50, stdin);

        categoria[strcspn(categoria, "\n")] = '\0';

    }while(strlen(categoria) == 0);

    printf("-----------------------------\n");

    do{
        printf("Inserire informazioni aggiuntive della segnalazione:\n");

        fgets(descrizione, 100, stdin);

        descrizione[strcspn(descrizione, "\n")] = '\0';

    }while(strlen(descrizione) == 0);

    printf("-----------------------------\n");

    do{
        printf("Inserire livello di urgenza (1 = Alta, 2 = Media, 3 = Bassa):\n");

        scanf("%d", &urgenza);

        getchar();

    }while(urgenza < 1 || urgenza > 3);

    printf("-----------------------------\n");

    do{

        printf("Inserisci stato:\n");

        printf("1. Aperta\n");

        printf("2. In lavorazione\n");

        printf("3. Chiusa\n");

        printf("Scelta:\n");

        scanf("%d", &stato);

        getchar();

    }while(stato < 1 || stato > 3);

    printf("-----------------------------\n");

    return creaSegnalazione(
        nome,
        categoria,
        descrizione,
        urgenza,
        stato
    );
}
