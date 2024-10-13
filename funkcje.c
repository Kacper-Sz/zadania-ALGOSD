#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void DodajNaPoczatek(lista *l, int klucz)
{
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = klucz;
    nowa->nast = *l;
    *l=nowa;
}

void DodajNaKoniec(lista *l, int klucz)
{
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = klucz;
    nowa->nast = 0;
    while(*l)
    {
        l=&(*l)->nast;
    }
    *l=nowa;
}

void UsunPierwszy(lista *l)
{
    lista poczatek;
    if(*l != 0 )
    {
        poczatek = *l;
        *l = (*l)->nast;
        free(poczatek);
    }
}

void UsunOstatni(lista *l)
{
    if(*l == 0) return;
    while((*l)->nast)
    {
        l=&(*l)->nast;
    }
    free(*l);
    *l=0;
}

void OdszukajElement(lista l, int element)
{
    lista nowa = l;
    int licznik = 0;
    while(nowa) 
    {
        if(nowa->klucz == element)
        {
            licznik++;
            printf("znaleziono element o wartosci %d pod adresem: %p\n", element, nowa);
        }
        nowa = nowa->nast;
    }
    printf("lacznie element: %d, znaleziono %d ", element, licznik);
    if(licznik == 1) printf("raz\n\n");
    else if (licznik == 0) printf("razy, element nie znajduje sie na liscie\n\n");
    else printf("razy\n\n");
}






void WyswietlListeOdPoczatku(lista l)
{
    lista nowa = l;
    while (nowa)
    {
        printf("%d ", nowa->klucz);
        nowa = nowa->nast;
    }
    printf("\n\n");    
}