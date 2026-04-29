#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "segnalazione.h"

// struct nodo
struct nodo{
    //item
    segnalazione* s;
    struct nodo* sx;
    struct nodo* dx;
};
