#ifndef SUPPORTO_H
#define SUPPORTO_H
#include <stdio.h>
#include "BST.h"

void caricaDatasetMisto(BST* T);
int confrontaFile(FILE* output, FILE* oracolo);
void verificaOracolo(const char* outputFile, const char* oracoloFile);
void ripristinaStandardIO(void);

/* Dataset Pre-impostati per Test Priorità */
void datasetStessaUrgenzaAlta(BST* T);
void datasetSenzaUrgenzaAlta(BST* T);
void datasetSenzaUrgenzaAltaMedia(BST* T);
void datasetUrgenzaFoglia(BST* T);

/* Dataset Pre-impostati per Test Filtri */
void datasetTutteAperte(BST* T);

/* Dataset Pre-impostati per Test Report */
void datasetCategorieUguali(BST* T);



#endif
