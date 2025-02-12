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
void DodajPrzedLubZa(lista *l, int element, int gdzie, int opcja, int ktore);
void UsunWskazany(lista *l, int number, int opcja);

void WyswietlListeOdPoczatku(lista l);
void WyswietlListeOdKonca(lista l);

//zadanie 2
void UsunWszystkieNierekurencyjnie(lista *l, int number);
void UsunWszystkieRekurencyjnie(lista *l, int number);

