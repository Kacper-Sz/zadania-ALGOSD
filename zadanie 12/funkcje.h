#include <stdio.h>

struct el {
    int klucz;
    struct el *nast;
};

typedef struct el elListy;
typedef elListy *lista;




//listy nieposortowane
void WyswietlListeOdPoczatku(lista l);

void DodajNaKoniec(lista *l, int number);
void DodajNaPoczatek(lista *l, int number);

//usuwa z listy l powtorzenia elementow z listy q
void UsunPowtorzenia(lista *l, lista q);