#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "segnalazione.h"

typedef struct Segnalazione{
    char id[9];
    int chiave; //per ordinare ADT albero
    char nome[50];
    char categoria[50];
    char descrizione[100];
    time_t data;
    int urgenza;
    char status[20];
}Segnalazione;

//helper
void stampaData(time_t data);
void generaID(char* id);
int IncrementaChiave();
time_t generaData();


segnalazione creaSegnalazione(){
    segnalazione s;

    
    s = malloc(sizeof(Segnalazione));
    if(s == NULL) return NULL;

    generaID(s->id);
    printf("\nID generato Automaticamente: %s\n", s->id);
    printf("-----------------------------\n");

    s->chiave = IncrementaChiave();

    do{
    printf("Inserire Nome del Segnalatore:\n");
    fgets(s->nome, 50, stdin);
    s->nome[strcspn(s->nome, "\n")] = '\0';
    }while(strlen(s->nome) == 0);

    printf("-----------------------------\n");
    
    do{
    printf("Inserire Categoria della segnalazione:\n");
    fgets(s->categoria, 50, stdin);
    s->categoria[strcspn(s->categoria, "\n")] = '\0';
    }while(strlen(s->categoria) == 0);

    printf("-----------------------------\n");

    do{
    printf("Inserire informazioni aggiuntive della segnalazione:\n");
    fgets(s->descrizione, 100, stdin);
    s->descrizione[strcspn(s->descrizione, "\n")] = '\0';
    }while(strlen(s->descrizione) == 0);

    printf("-----------------------------\n");

    s->data = generaData();
    stampaData(s->data);
    printf("-----------------------------\n");

    do{
    printf("Inserire livello di urgenza (1 = Alta, 2 = Media, 3 = Bassa):\n");
    scanf("%d", &s->urgenza);
    getchar();
    }while(s->urgenza < 1 || s->urgenza > 3);
    
    printf("-----------------------------\n");

    //Status segnalazione
    int choice = 0;
    do{
    printf("Inserisci stato:");
    printf("\n1. Aperta");
    printf("\n2. In lavorazione");
    printf("\n3. Chiusa");
    printf("\nScelta:\n");
    
    scanf("%d", &choice);
    getchar();

   } while(choice < 1 || choice > 3);
    
    switch(choice){
    case 1:
        strcpy(s->status, "aperta");
        break;
    case 2:
        strcpy(s->status, "in lavorazione");
        break;
    case 3:
        strcpy(s->status, "chiusa");
        break;
    default:
        printf("\nScelta non valida");
    }
    printf("-----------------------------\n");

    printf("\n=== Segnalazione Inserita! ===\n");

    return s;
}

void stampaSegnalazione(segnalazione s){
    if(s == NULL){
        printf("\nSegnalazione non valida\n");
        return;
    }
    //ID utente
    printf("\nCodice Identificativo: %s\n", s->id);
    printf("-----------------------------\n");

    //Nome segnalatore
    printf("Nome Segnalatore: %s\n", s->nome);
    printf("-----------------------------\n");

    //Categoria Segnalazione
    printf("Categoria della segnalazione: %s\n", s->categoria);
    printf("-----------------------------\n");

    //Descrizione Segnalazione
    printf("Descrizione: %s\n", s->descrizione);
    printf("-----------------------------\n");

    //Data di inserimento
    stampaData(s->data);
    printf("-----------------------------\n");

    //Livello di urgenza 
    printf("Livello di Urgenza: %d (1= elevato, 2= intermedio, 3= lieve)\n", s->urgenza);
    printf("-----------------------------\n");

    printf("Stato della segnalazione: %s\n", s->status);
    printf("-----------------------------\n");

    printf("===STAMPA COMPLETATA===");
}

//helper
void generaID(char* id){
    const char set[] = "ABCDEFGHIJKLMNOPQRSTUVWYZ0123456789";

    for(int i = 0; i < 8; i++){
        int indice = rand() % (sizeof(set)-1);
        id[i] = set[indice];
    }
    id[8] = '\0';
}

int IncrementaChiave(){ 
    static int contatore = 0;
    return contatore++;
}

time_t generaData(){
    return time(NULL);
}

void stampaData(time_t data){
    struct tm tm = *localtime(&data);

    printf("Data di inserimento: %02d/%02d/%d\n", 
        tm.tm_mday, 
        tm.tm_mon + 1, 
        tm.tm_year + 1900);
}

//getter
char* getID(segnalazione s){
    return s->id;
}

char* getCategoria(segnalazione s){
    return s->categoria;
}

char* getStatus(segnalazione s){
    return s->status;
}

int getUrgenza(segnalazione s){
    return s->urgenza;
}

int getChiave(segnalazione s){
    return s->chiave;
}

//setter
void setStatus(segnalazione s, char* status){
    strcpy(s->status, status);
}
