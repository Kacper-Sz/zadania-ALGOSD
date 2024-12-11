#include <stdio.h>

struct el {
    int klucz;
    struct el *nast;
};

typedef struct el elListy;
typedef elListy *lista;

void WyswietlListeOdPoczatku(lista l);

void DodajDoPosortowanej(lista *l, int klucz);

void polaczListy(lista *l, lista *q);