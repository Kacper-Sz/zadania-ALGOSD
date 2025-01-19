#include <stdio.h>

struct el {
    int klucz;
    struct el *nast;
};

typedef struct el elListy;
typedef elListy *lista;

void WyswietlListeOdPoczatku(lista l);

void DodanieWartownika(lista *l);

void DodajDoPosortowanejWartownik(lista *l, int klucz);

elListy* ZnajdzPosortowanaWartownik(lista l, int klucz);

void PorownajListy(lista l, lista q, lista *wynikL, lista *wynikQ);

lista PobierzListe(char* nazwaPliku);