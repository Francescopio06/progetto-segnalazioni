#ifndef SEGNALAZIONE_H
#define SEGNALAZIONE_H
#include <time.h>

/*
FILE: segnalazione.h
AUTORE: Francesco Pio Siano

Questo header definisce l'interfaccia pubblica
del modulo 'Segnalazione'.

Il modulo espone:
- il tipo astratto segnalazione
- funzioni di creazione e stampa
- funzioni di accesso e modifica (getter/setter)

L'implementazione interna della struttura
è nascosta secondo il principio di
information hiding.
*/

typedef struct Segnalazione* segnalazione;

/*
Funzione creaSegnalazione()
    La funzione ha lo scopo di compilare i singoli campi della struttura segnalazione.

    Parametri: 
        - nome -> puntatore ad un array di caratteri
        - categoria -> puntatore ad un array di caratteri
        - descrizione -> puntatore ad un array di caratteri
        - urgenza -> intero che indica il livello di urgenza
        - stato -> intero che indica lo stato da assegnare
    
    Return:
        - Puntatore alla segnalazione creata
*/
segnalazione creaSegnalazione(char* nome, char* categoria, char* descrizione, int urgenza, int stato);

/*
Funzione stampaSegnalazione(segnalazione s)
    La funzione accede ai campi della segnalazione data in input e ne stampa i valori.
    
    Parametri:
        - s -> puntatore alla struttura segnalazione

    Return:
        - Nessun valore restituito
*/
void stampaSegnalazione(segnalazione s);

/*
Funzione generaID(char *id)
    la funzione genera un codice alfanumerico che 
    identifica una segnalazione

    Parametri:
        - id -> puntatore ad un array di caratteri da riempire
    
    Return:
        - nessun parametro restituito
*/
void generaID(char* id);
void stampaData(time_t data);
/*
La funzione liberaSegnalazione incapsula la procedura di deallocazione
della memoria
*/
void liberaSegnalazione(segnalazione s);
/*
Funzioni di getter e setter necessarie per concedere l'accesso 
alla struttura dati in altri moduli che non ne hanno accesso
*/
char* getID(segnalazione s);
char* getCategoria(segnalazione s);
char* getStatus(segnalazione s);
int getUrgenza(segnalazione s);
int getChiave(segnalazione s);
time_t getData(segnalazione s);
void setStatus(segnalazione s, char* status);
void setChiave(segnalazione s, int chiave);
void setID(segnalazione s, const char* id);

#endif
