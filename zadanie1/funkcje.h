#include <stdio.h>

struct el {
    int klucz;
    struct el *nast;
};

typedef struct el elListy;
typedef elListy *lista;

void DodajNaPoczatek(lista *l, int klucz);
void DodajNaKoniec(lista *l, int klucz);
void UsunPierwszy(lista *l);
void UsunOstatni(lista *l);
void OdszukajElement(lista l, int element);

void WyswietlListeOdPoczatku(lista l);
