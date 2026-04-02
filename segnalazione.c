#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "segnalazione.h"

Segnalazione* creaSegnalazione(){
    Segnalazione *s = malloc(sizeof(Segnalazione));
    if(s == NULL) return NULL;

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

    printf("Inserire status della segnalazione: \n");
    fgets(s->status, 20, stdin);
    s->status[strcspn(s->status, "\n")] = '\0';

    printf("-----------------------------\n");

    return s;
}

void stampaSegnalazione(Segnalazione* s){
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