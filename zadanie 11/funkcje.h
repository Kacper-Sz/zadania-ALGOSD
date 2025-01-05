#include <stdio.h>

struct elB {
    int klucz;
    struct elB *nast, *poprz;
};

typedef struct elB elListyB;
typedef elListyB *listaB;


void WyswietlListeOdPoczatkuB(listaB l);

void DodajNaPoczatekB(listaB *l, int number);

void DodajNaKoniecB(listaB *l, int number);

void UsunPierwszyB(listaB *l);

void UsuwanKaty(listaB *l, int k);