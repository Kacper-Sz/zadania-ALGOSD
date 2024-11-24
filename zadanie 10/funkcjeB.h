#include <stdio.h>

struct elB {
    int klucz;
    struct elB *nast, *poprz;
};

typedef struct elB elListyB;
typedef elListyB *listaB;




//listy nieposortowane
void WyswietlListeOdPoczatkuB(listaB l);
void WyswietlListeOdKoncaB(listaB l);

void DodajNaPoczatekB(listaB *l, int number);

void DodajNaKoniecB(listaB *l, int number);

void UsunPierwszyB(listaB *l);

void UsunOstatniB(listaB *l);

listaB* OdszukajElementB(listaB *l, int element);

void DodajPrzedB(listaB *l, int element, int gdzie);

void DodajZaB(listaB *l, int element, int gdzie);

void UsunWskazanyB(listaB *l, int number);
