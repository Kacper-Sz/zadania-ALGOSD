#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void WyswietlKolejke(lista l)
{
    if(l == NULL)
    {
        printf("kolejka jest pusta\n");
        return;
    }

    while(l)
    {
        // dopoki nie jest null to wypisuje element z priorytetem
        printf("[ klucz: %d, priorytet: %d ]\t", l->klucz, l->priorytet);
        l = l->nast;
    }
}

void DodajDoKolejkiPriorytetowej(lista *l, int wartosc, int nowy_priorytet)
{
    // tworze nowy element listy
    lista nowy = malloc(sizeof(elListy));
    nowy->klucz = wartosc;
    nowy->priorytet = nowy_priorytet;

    // jesli lista jest pusta to dodaje element na poczatek
    if(*l == NULL)
    {
        nowy->nast = NULL;
        *l = nowy;
    }
    else
    {
        // jesli nie to szukam odpowiedniego miejsca dla elementu
        while((*l) != NULL && (*l)->priorytet >= nowy_priorytet)
        {
            l = &(*l)->nast;
        }

        nowy->nast = *l;
        *l = nowy;
    }
}

lista PobierzElement(lista *l)
{
    // jak lista jest pusta to zwracam null
    if(*l == NULL)
    {
        return NULL;
    }
    // pobieram pierwszy element z listy
    lista pobrany = *l;
    *l = (*l)->nast;
    pobrany->nast = NULL;
    // i zwracam go
    //zwalnianie pamieci w mainie
    return pobrany;
}

void ZmienPriorytet(lista *l, int wartosc, int nowy_priorytet)
{
    if(*l == NULL)
    {
        printf("kolejka jest pusta\n");
        return;
    }

    // tmp to wskaznik na poczatek listy
    lista *tmp = l;
    // szukam elementu o podanym kluczu
    while((*l) != NULL && (*l)->klucz != wartosc)
    {
        l = &(*l)->nast;
    }

    if(*l == NULL)
    {
        printf("nie znaleziono elementu o podanym kluczu\n");
        return;
    }

    int stary_priorytet = (*l)->priorytet;

    UsunElement(tmp, wartosc, stary_priorytet);

    DodajDoKolejkiPriorytetowej(tmp, wartosc, nowy_priorytet);

    printf("zmieniono priorytet elementu o kluczu %d z priorytetu %d na %d\n", wartosc, stary_priorytet, nowy_priorytet);

}

void UsunElement(lista *l, int wartosc, int priorytet_szukany)
{
    if(*l == NULL) return;

    // szukam elementu o podanym kluczu i priorytecie
    while((*l) != NULL)
    {
        if((*l)->klucz != wartosc && (*l)->priorytet != priorytet_szukany)
        {
            l = &(*l)->nast;
        }
        else
        {
            // jesli znalazlem to usuwam go
            lista tmp = *l;
            *l = (*l)->nast;
            free(tmp);
        }
    }
}