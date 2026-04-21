#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "segnalazione.h"

void aggiornaStatus(lista lista1, int id){

    segnalazione* tmp = ricercaPerId(lista1, id);
    if(tmp == NULL){
        printf("Segnalazione non trovata"); 
        return;
    }

    printf("Inserire il nuovo stato della segnalazione: \n");
    getchar(); //pulisco il buffer
    fgets(tmp->status, 20, stdin);
    tmp->status[strcspn(tmp->status, "\n")] = '0';

    printf("Status aggiornato con successo!\n");
}

void filtraPerStatus(lista lista1){

    printf("---SEGNALAZIONI APERTE---\n");
    stampaPerStatus(lista1, "aperta");

    printf("---SEGNALAZIONI IN LAVORAZIONE---\n");
    stampaPerStatus(lista1, "in lavorazione");

    printf("---SEGNALAZIONI CHIUSE---\n");
    stampaPerStatus(lista1, "chiusa");

}