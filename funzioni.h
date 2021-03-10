//
//  funzioni.h
//  dizionario
//
//  Created by Francesco D'apolito



#include <stdio.h>

#endif /* funzioni_h */

#define MAX_PAROLA 30

#define MAX_SIGNIFICATO 1000

#define TRUE 1

#define FALSE 0

struct parola
{
    char nome[MAX_PAROLA];
    char significato[MAX_SIGNIFICATO];
};

typedef struct parola Parola;

void definisci_parole(Parola *); 

char *lettere_maiuscole( char *);

int ricerca_chiave(char [],Parola [], int, int * );

int parola_consonanti(Parola [], int);

void ord_ins_parole(Parola[],int);

int inserisci_parola(Parola [],int * );

void consonanti(Parola [], int);
