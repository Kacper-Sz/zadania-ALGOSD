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

}

void DodajPrzedLubZa(lista *l, int element, int gdzie, int opcja, int ktore)
{

}

void UsunWskazany(lista *l, int number, int opcja)
{
    
}







//DODAC WYSWIETLANIE OD KONCA LISTY

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