#ifndef SEGNALAZIONE_H
#define SEGNALAZIONE_H

typedef struct {
    int id;
    char nome[50];
    char categoria[50];
    char descrizione[100];
    char data[11];
    int urgenza;
    char status[20];
}segnalazione;

segnalazione creaSegnalazione();
void stampaSegnalazione(segnalazione* s);

#endif