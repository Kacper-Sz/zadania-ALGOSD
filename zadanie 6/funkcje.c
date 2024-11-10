#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"


// dodanie wartownika
void DodanieWartownika(lista *l)
{
    lista wartownik = malloc(sizeof(elListy));
    wartownik->klucz = INT_MAX;
    wartownik->nast = *l;
    *l = wartownik;
}


//dodawanie na poczatek dla listy uporzadkowanej
void DodajDoPosortowanej(lista *l, int klucz)
{
    lista nowa = malloc(sizeof(elListy));
    nowa->klucz = klucz;

    if(*l == 0)
    {
        nowa->nast = *l;
        *l = nowa;
        return;
    }

    while(*l != NULL && (*l)->klucz < klucz)
    {
        l = &((*l)->nast);
    }

    nowa->nast = *l;
    *l = nowa;
}


void DodajDoPosortowanejWartownik(lista *l, int klucz)
{
    lista nowa = malloc(sizeof(elListy));
    nowa->klucz = klucz;

    while((*l)->klucz < klucz)
    {
        l = &((*l)->nast);
    }

    nowa->nast = *l;
    *l = nowa;
}



lista* ZnajdzPosortowana(lista *l, int klucz)
{
    while((*l) != NULL && (*l)->klucz < klucz)
    {
        l = &((*l)->nast);
    }
    if((*l) == NULL || (*l)->klucz > klucz)
    {
        return NULL;
    }
    else
    {
        return l;
    }
}

lista* ZnajdzPosortowanaWartownik(lista *l, int klucz)
{
    while((*l)->klucz < klucz)
    {
        l = &((*l)->nast);
    }
    if((*l)->klucz == klucz)
    {
        return l;
    }
    else
    {
        return NULL;
    }
}

void UsunWskazanyPosortowana(lista *l, int number)
{
    while((*l) != NULL && (*l)->klucz < number)
    {
        l = &((*l)->nast);
    }

    if((*l) != NULL && (*l)->klucz == number)
    {
        lista nowa = *l;
        *l = (*l)->nast;
        free(nowa);
    }
    else
    {
        printf("element %d nie znajduje sie na liscie.\n", number);
    }
}

void UsunWskazanyPosortowanaWartownik(lista *l, int number)
{
    while((*l)->klucz < number)
    {
        //przejscie do nastepnego adresu
        l = &((*l)->nast);
    }

    if((*l)->klucz == number)
    {
        lista nowa = *l;
        *l = (*l)->nast;
        free(nowa);
    }
    else
    {
        printf("element %d nie znajduje sie na liscie.\n", number);
    }
}

//zobaczyc jeszcze z cwiczen jak pisalismy te funkcje

lista ZnajdzPierwszy(lista *l)
{
   if (*l == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    return *l;
}

lista ZnajdzPierwszyWartownik(lista *l)
{
    //zakladam ze jedyny element to wartownik
    if ((*l)->nast == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    return *l;
}

lista ZnajdzOstatni(lista *l)
{
    if (*l == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    while ((*l)->nast != NULL) {
        l = &((*l)->nast);
    }
    return *l;
}

lista ZnajdzOstatniWartownik(lista *l)
{
    if ((*l)->nast == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    while ((*l)->nast->nast != NULL) {
        l = &((*l)->nast);
    }
    return *l;
}








void WyswietlListeOdPoczatku(lista l)
{
    lista nowa = l;
    if(nowa == 0)
    {
        printf("\nlista jest pusta\n");
        return;
    }
    while (nowa)
    {
        if(nowa->klucz == INT_MAX)
        {
            nowa = nowa->nast;
            continue;
        }
        printf("%d ", nowa->klucz);
        nowa = nowa->nast;
    }
    printf("\n\n");    
}

void WyswietlListeOdKonca(lista l)
{
    if(l != 0)
    {
        if(l->nast == 0)
        {
            printf("%d ", l->klucz);
        }
        else
        {
            WyswietlListeOdKonca(l->nast);
            printf("%d ", l->klucz);
        }
    }
}
