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
        printf("[ klucz: %d, priorytet: %d ]\t", l->klucz, l->priorytet);
        l = l->nast;
    }
}

void DodajDoKolejkiPriorytetowej(lista *l, int wartosc, int nowy_priorytet)
{
    lista nowy = malloc(sizeof(elListy));
    nowy->klucz = wartosc;
    nowy->priorytet = nowy_priorytet;

    if(*l == NULL)
    {
        nowy->nast = NULL;
        *l = nowy;
    }
    else
    {
        while((*l) != NULL && (*l)->priorytet < nowy_priorytet)
        {
            l = &(*l)->nast;
        }

        nowy->nast = *l;
        *l = nowy;
    }
}

lista PobierzElement(lista *l)
{
    if(*l == NULL)
    {
        return NULL;
    }

    while ((*l)->nast != NULL)
    {
        l = &(*l)->nast;
    }
    // *l to ostatni element

    lista pobrany = *l;
    free(*l);
    *l = NULL;
    return pobrany;
}

void ZmienPriorytet(lista *l, int wartosc, int nowy_priorytet)
{
    if(*l == NULL)
    {
        printf("kolejka jest pusta\n");
        return;
    }

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

    UsunElement(l, wartosc, stary_priorytet);

    DodajDoKolejkiPriorytetowej(l, wartosc, nowy_priorytet);

    printf("zmieniono priorytet elementu o kluczu %d z priorytetu %d na %d\n", wartosc, stary_priorytet, nowy_priorytet);

}

void UsunElement(lista *l, int wartosc, int priorytet_szukany)
{
    if(*l == NULL) return;

    while((*l) != NULL && (*l)->klucz != wartosc && (*l)->priorytet != priorytet_szukany)
    {
        l = &(*l)->nast;
    }

    lista tmp = *l;
    *l = (*l)->nast;
    free(tmp);
}