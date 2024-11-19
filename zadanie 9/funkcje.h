#include <stdio.h>

struct el {
    int klucz;
    struct el *nast, *poprz;
};

typedef struct el elListy;
typedef elListy *lista;

void DodajNaPoczatek(lista *l, int klucz);
void DodajNaKoniec(lista *l, int klucz);
void UsunPierwszy(lista *l);
lista* OdszukajElement(lista *l, int element);
void DodajPrzed(lista *l, int element, int gdzie);
void DodajZa(lista *l, int element, int gdzie);
void UsunWskazany(lista *l, int number);

void WyswietlListeOdPoczatku(lista l);
void WyswietlListeOdKonca(lista l);