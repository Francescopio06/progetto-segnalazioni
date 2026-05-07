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

static void visitaReport(BST Albero, int* tot, int* aperte, int* chiuse, ContaCategoria stats[], int* nCategorie);
static void controlloID(BST Albero, char* ID);

//funzioni principali
void inserisciSegnalazione(BST* Albero){

    segnalazione s = creaSegnalazione();
    controlloID(*Albero, getID(s));
    *Albero = insert(*Albero, s);
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
        setStatus(s, "aperta");
        break;
    case 2:
        setStatus(s, "in lavorazione");
        break;
    case 3:
        setStatus(s, "chiusa");
        break;
    default:
        printf("\n---Scelta non valida---");
    }

    if(strcmp(statusTmp, getStatus(s)) == 0){
        printf("\n=== REINSERITO LO STESSO STATO ===\n");
    } else printf("\n=== STATO AGGIORNATO CORRETTAMENTE ===\n");
}

void filtraSegnalazioni(BST Albero){

    int choice;

    printf("\nQuali segnalazioni vuoi visualizzare:\n");
    printf("1. Aperte\n2. In lavorazione\n3. Chiuse\n4. Elenco completo");
    scanf("%d", &choice);
    getchar();

    switch(choice){
    case 1:
        printf("\nSegnalazioni Aperte\n");
        stampaPerStatus(Albero, "aperta");
        break;
    case 2: 
        printf("\nSegnalazioni In Lavorazione\n");
        stampaPerStatus(Albero, "in lavorazione");
        break;
    case 3:
        printf("\nSegnalazioni Chiuse\n");
        stampaPerStatus(Albero, "chiusa");
        break;
    case 4: 
        printf("\n--- ELENCO COMPLETO ---\n");

        printf("\nSegnalazioni Aperte\n");
        stampaPerStatus(Albero, "aperta");

        printf("\nSegnalazioni In Lavorazione\n");
        stampaPerStatus(Albero, "in lavorazione");

        printf("\nSegnalazioni Chiuse\n");
        stampaPerStatus(Albero, "chiusa");
        break;
    default:
        printf("\n---Scelta non valida---\n");
    }
}

void mostraUrgenza(BST Albero){

    if(Albero == NULL){
        printf("Nessuna Segnalazione presente\n");
        return;
    }

    if(esisteUrgenza(Albero, 1)){
        printf("Segnalazioni con urgenza Massima (1):\n");
        stampaPerUrgenza(Albero, 1);
    } 
    else if(esisteUrgenza(Albero, 2)){
        printf("Segnalazioni con urgenza Media (2):\n");
        stampaPerUrgenza(Albero, 2);
    } 
    else if(esisteUrgenza(Albero, 3)){
        printf("Segnalazione con urgenza Minima (3):\n");
        stampaPerUrgenza(Albero, 3);
    }
    else{
        printf("Nessuna segnalazione trovata\n");
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
        printf("Nessuna segnalazione presente\n");
        return;
    }

    int tot = 0;
    int aperte = 0;
    int chiuse = 0;

    ContaCategoria stats[100];
    int nCategorie = 0;

    visitaReport(Albero, &tot, &aperte, &chiuse, stats, &nCategorie);

    // stampa base
    printf("\n--- REPORT ---\n");
    printf("Totale segnalazioni: %d\n", tot);
    printf("Aperte: %d\n", aperte);
    printf("Chiuse: %d\n", chiuse);

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
static void visitaReport(BST Albero, int* tot, int* aperte, int* chiuse, ContaCategoria stats[], int* nCategorie){

    if(Albero == NULL) return;

    visitaReport(figlioSX(Albero), tot, aperte, chiuse, stats, nCategorie);

    segnalazione s = getSegnalazione(Albero);

    (*tot)++;

    // stato
    if(strcmp(getStatus(s), "aperta") == 0)
        (*aperte)++;
    else if(strcmp(getStatus(s), "chiusa") == 0)
        (*chiuse)++;

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

    visitaReport(figlioDX(Albero), tot, aperte, chiuse, stats, nCategorie);
}

static void controlloID(BST Albero, char* ID){

    while(ricercaPerId(Albero, ID) != NULL){

        generaID(ID);

    }

}
