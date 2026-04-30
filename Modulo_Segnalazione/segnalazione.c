#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "segnalazione.h"
#include "BST.h"

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

//funzioni per creaSegnalazione
void generaID(char* id);
int IncrementaChiave();
void InserimentoNome(char* nome);
void InserimentoCategoria(char* categoria);
void InserimentoDescrizione(char* descrizione);
time_t generaData();
void InserimentoUrgenza(int livello);
void InserimentoStatus(char* stato);


segnalazione creaSegnalazione(){
    segnalazione s;

    
    s = malloc(sizeof(segnalazione));
    if(s == NULL) return NULL;

    generaID(s->id);
    printf("-----------------------------\n");

    s->chiave = IncrementaChiave();
    printf("-----------------------------\n");

    InserimentoNome(s->nome);
    printf("-----------------------------\n");

    InserimentoCategoria(s->categoria);
    printf("-----------------------------\n");

    InserimentoDescrizione(s->descrizione);
    printf("-----------------------------\n");

    s->data = generaData();
    printf("-----------------------------\n");

    InserimentoUrgenza(s->urgenza);
    printf("-----------------------------\n");

    InserimentoStatus(s->status);
    printf("-----------------------------\n");

    return s;
}

void stampaSegnalazione(segnalazione s){
    if(s == NULL){
        printf("Segnalazione non valida\n");
        return;
    }
    //ID utente
    printf("Codice Identificativo: %s\n", s->id);
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

    //Status segnalazione
    printf("Stato della segnalazione: %s\n", s->status);
    printf("-----------------------------\n");
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

void InserimentoNome(char* nome){
    printf("Inserire Nome del Segnalatore: \n");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

void InserimentoCategoria(char* categoria){
    printf("Inserire Categoria della segnalazione: \n");
    fgets(categoria, 50, stdin);
    categoria[strcspn(categoria, "\n")] = '\0';
}

void InserimentoDescrizione(char* descrizione){
    printf("Inserire informazioni aggiuntive della segnalazione: \n");
    fgets(descrizione, 100, stdin);
    descrizione[strcspn(descrizione, "\n")] = '\0';
}

time_t generaData(){
    return time(NULL);
}

void InserimentoUrgenza(int livello){
    printf("Inserire livello di urgenza (1 = Alta, 2 = Media, 3 = Bassa): \n");
    scanf("%d", &livello);
    getchar();
}

void InserimentoStatus(char* stato){
    int choice = 0;
    do{
    printf("Inserisci stato:\n");
    printf("1. Aperta\n");
    printf("2. In lavorazione\n");
    printf("3. Chiusa\n");
    
    scanf("%d", &choice);
    getchar();

   } while(choice < 1 || choice > 3);
    
    switch(choice){
    case 1:
        strcpy(stato, "aperta");
        break;
    case 2:
        strcpy(stato, "in lavorazione");
        break;
    case 3:
        strcpy(stato, "chiusa");
        break;
    default:
        printf("Scelta non valida\n");
    }


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

void stampaData(time_t data){
    struct tm tm = *localtime(&data);

    printf("Data di inserimento: %02d/%02d/%d", 
        tm.tm_mday, 
        tm.tm_mon + 1, 
        tm.tm_year + 1900);
}
