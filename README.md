# Sistema di Gestione Segnalazioni
## Descrizione 
Questo progetto si occupa di gestire le segnalazioni relative a problemi urbani.
- Le segnalazioni saranno divise per categoria ed il sistema consente di:
1. archiviare le segnalazioni; 
2. visualizzarle;
3. aggiornarne lo stato;
4. cancellarle.

Ogni segnalazione sarà identificata con un apposito codice identificativo (che dovrà essere inserito dall'utente).
- Un grado di urgenza ne definirà la priorità e seguirà la seguente classificazione:
    -  **1: Massima Urgenza** 
    -  **2: Media Urgenza**
    -  **3: Minima Urgenza**


## Funzionalità
- Registrazione di una segnalazione
- Visualizzazione di tutte le segnalazioni
- Ricerca di una segnalazione in base al Codice Identificativo o per Categoria
- Aggiornamento dello stato di una segnalazione
- Visualizzazione delle segnalazioni filtrate per stato:
    -  Aperte
    -  In corso
    -  Chiuse
- Visualizzazione delle segnalazioni in base al livello di urgenza
- Cancellazione di una segnalazione
- Generazione di un Report con: 
    -  Numero totale di segnalazioni
    -  Segnalazioni per categoria
    -  Segnalazioni aperte e chiuse
    -  Segnalazioni più frequenti per tipologia

## Stuttura del progetto
Il progetto è strutturato su più livelli ed è diviso nei seguenti moduli:

- **main.c**: svolge il ruolo di pannello di controllo
- **lista.c / lista.h**: gestione della lista collegata
- **segnalazione.c / segnalazione.h**: gestione delle segnalazioni
- **Makefile**: compilazione del progetto

## Compilazione
Per compilare il progetto utilizzare 
`make` 

## Esecuzione 
Per eseguire il programma
`./programma` 