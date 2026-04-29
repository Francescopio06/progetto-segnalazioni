#ifndef SEGNALAZIONE_H
#define SEGNALAZIONE_H

typedef struct Segnalazione* segnalazione;

//creazione
segnalazione creaSegnalazione();

//stampa
void stampaSegnalazione(segnalazione s);

//Funzioni ausiliari per lista e gestioni
char* getID(segnalazione s);
char* getCategoria(segnalazione s);
char* getStatus(segnalazione s);
int getUrgenza(segnalazione s);
int getIDInterno(segnalazione s);

//Per impostare in altri file
void setStatus(segnalazione s, char* status);

#endif