#include <stdio.h>

struct el {
    int klucz;
    struct el *nast;
};

typedef struct el elListy;
typedef elListy *lista;

void DodanieWartownika(lista *l);


void DodajDoPosortowanej(lista *l, int klucz);
void DodajDoPosortowanejWartownik(lista *l, int klucz);


lista * ZnajdzPosortowana(lista *l, int klucz);
lista * ZnajdzPosortowanaWartownik(lista *l, int klucz);


void UsunWskazanyPosortowana(lista *l, int number);
void UsunWskazanyPosortowanaWartownik(lista *l, int number);


lista* ZnajdzPierwszy(lista *l);
lista* ZnajdzPierwszyWartownik(lista *l);


lista* ZnajdzOstatni(lista *l);
lista* ZnajdzOstatniWartownik(lista *l);


void WyswietlListeOdPoczatku(lista l);
void WyswietlListeOdKonca(lista l);