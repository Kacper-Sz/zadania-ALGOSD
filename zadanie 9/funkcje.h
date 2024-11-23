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


void DodajDoPosortowanej(lista *l, int number);
void DodajDoPosortowanejWartownik(lista *l, int number);


lista * ZnajdzPosortowana(lista *l, int number);
lista * ZnajdzPosortowanaWartownik(lista *l, int number);


void UsunWskazanyPosortowana(lista *l, int number);
void UsunWskazanyPosortowanaWartownik(lista *l, int number);


lista* ZnajdzPierwszy(lista *l);
lista* ZnajdzPierwszyWartownik(lista *l);


lista* ZnajdzOstatni(lista *l);
lista* ZnajdzOstatniWartownik(lista *l);