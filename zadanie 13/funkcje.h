#include <stdio.h>

struct el {
    int klucz;
    int priorytet;
    struct el *nast;
};

typedef struct el elListy;
typedef elListy *lista;


void WyswietlKolejke(lista l);

void DodajDoKolejkiPriorytetowej(lista *l, int wartosc, int nowy_priorytet);

lista PobierzElement(lista *l);

void ZmienPriorytet(lista *l, int wartosc, int nowy_priorytet);

void UsunElement(lista *l, int wartosc, int priorytet_szukany);

