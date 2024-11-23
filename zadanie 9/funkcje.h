#include <stdio.h>

struct el {
    int klucz;
    struct el *nast, *poprz;
};

typedef struct el elListy;
typedef elListy *lista;

void WyswietlListeOdPoczatku(lista l);
void WyswietlListeOdKonca(lista l);

//listy nieposortowane
void DodajNaPoczatek(lista *l, int klucz);
void DodajNaKoniec(lista *l, int klucz);
void UsunPierwszy(lista *l);
void UsunOstatni(lista *l);
lista* OdszukajElement(lista *l, int element);
void DodajPrzed(lista *l, int element, int gdzie);
void DodajZa(lista *l, int element, int gdzie);
void UsunWskazany(lista *l, int number);


//listy posortowane
void DodanieWartownika(lista *l);


void DodajDoPosortowanej(lista *l, int klucz);
void DodajDoPosortowanejWartownik(lista *l, int number);