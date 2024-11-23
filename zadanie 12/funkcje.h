#include <stdio.h>

struct el {
    int klucz;
    struct el *nast;
};

typedef struct el elListy;
typedef elListy *lista;




//listy nieposortowane
void WyswietlListeOdPoczatkuA(lista l);
void WyswietlListeOdKoncaA(lista l);

void DodajNaPoczatekA(lista *l, int number);
void DodajNaKoniecA(lista *l, int number);
void UsunPierwszyA(lista *l);
void UsunOstatniA(lista *l);
lista* OdszukajElementA(lista *l, int element);
void DodajPrzedA(lista *l, int element, int gdzie);
void DodajZaA(lista *l, int element, int gdzie);
void UsunWskazanyA(lista *l, int number);