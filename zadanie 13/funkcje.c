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
    
}