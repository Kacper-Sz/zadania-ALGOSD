#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void DodajNaPoczatek(lista *l, int klucz)
{
    lista nowy = malloc(sizeof(elListy));
    nowy->klucz = klucz;
    nowy->nast = *l;
    if(*l != NULL)
    {
        nowy->poprz = (*l)->poprz;
        (*l)->poprz = nowy;
    }
    else
    {
        nowy->poprz = NULL;
    }
    *l = nowy;
}

void DodajNaKoniec(lista *l, int klucz)
{
    
}

void UsunPierwszy(lista *l)
{
    
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

void WyswietlListeOdPoczatku(lista l)
{
    
}

void WyswietlListeOdKonca(lista l)
{
}