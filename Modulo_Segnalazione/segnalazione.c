#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segnalazione.h"
#include "lista.h"

typedef struct Segnalazione{
    int id;
    char nome[50];
    char categoria[50];
    char descrizione[100];
    char data[11];
    int urgenza;
    char status[20];
};

segnalazione creaSegnalazione(){
    segnalazione s;
    s = malloc(sizeof(segnalazione));
    if(s == NULL) return;
    int choice;

    printf("Inserire Codice di Identificazione: \n");
    scanf("%d", &s->id);
    getchar();

    printf("-----------------------------\n");

    printf("Inserire Nome del Segnalatore: \n");
    fgets(s->nome, 50, stdin);
    s->nome[strcspn(s->nome, "\n")] = '\0';

    printf("-----------------------------\n");

    printf("Inserire Categoria della segnalazione: \n");
    fgets(s->categoria, 50, stdin);
    s->categoria[strcspn(s->categoria, "\n")] = '\0';

    printf("-----------------------------\n");

    printf("Inserire informazioni aggiuntive della segnalazione: \n");
    fgets(s->descrizione, 100, stdin);
    s->descrizione[strcspn(s->descrizione, "\n")] = '\0';

    printf("-----------------------------\n");

    printf("Inserire data: \n");
    fgets(s->data, 11, stdin);
    s->data[strcspn(s->data, "\n")] = '\0';

    printf("-----------------------------\n");

    printf("Inserire livello di urgenza (1 = Alta, 2 = Media, 3 = Bassa): \n");
    scanf("%d", &s->urgenza);
    getchar();

    printf("-----------------------------\n");

   
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
        strcpy(s->status, "aperta");
        break;
    case 2:
        strcpy(s->status, "in lavorazione");
        break;
    case 3:
        strcpy(s->status, "chiusa");
        break;
    default:
        printf("Scelta non valida\n");
    }


    printf("-----------------------------\n");


    return s;
}

void stampaSegnalazione(segnalazione s){
    if(s == NULL){
        printf("Segnalazione non valida\n");
        return;
    }
    printf("Codice Identificativo: %d\n", s->id);
    printf("-----------------------------\n");
    printf("Nome Segnalatore: %s\n", s->nome);
    printf("-----------------------------\n");
    printf("Categoria della segnalazione: %s\n", s->categoria);
    printf("-----------------------------\n");
    printf("Descrizione: %s\n", s->descrizione);
    printf("-----------------------------\n");
    printf("Data di inserimento: %s\n", s->data);
    printf("-----------------------------\n");
    printf("Livello di Urgenza: %d (1= elevato, 2= intermedio, 3= lieve)\n", s->urgenza);
    printf("-----------------------------\n");
    printf("Stato della segnalazione: %s\n", s->status);
    printf("-----------------------------\n");
}


//per poter eseguire queste operazioni in livelli più lontani dalla struct
int getID(segnalazione s){
    return s->id;
}

char* getCategoria(segnalazione s){
    return s->categoria;
}

char* getStatus(segnalazione s){
    return s->status;
}

char* getUrgenza(segnalazione s){
    return s->urgenza;
}

void setStatus(segnalazione s, char* status){
    strcpy(s->status, status);
}
