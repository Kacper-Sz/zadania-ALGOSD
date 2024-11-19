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
    lista k = NULL;
    while(*l != NULL)
    {
        //k przechowuje watosc na ktora wskazuje l
        k = *l;
        //adres czesci nastepnika ide na kolejny adres
        l=&((*l)->nast);
    }
    DodajNaPoczatek(l, klucz);
    (*l)->poprz = k;
}

void UsunPierwszy(lista *l)
{
    if(*l == NULL)
    {
        return;
    }

    lista nowy = *l;
    if((*l)->nast == NULL)
    {
        *l = NULL;
    }
    else
    {
        *l = (*l)->nast;
        (*l)->poprz = nowy->poprz;
    }
    free(nowy);
}

lista* OdszukajElement(lista *l, int element)
{
   while(*l != NULL)
   {
       if((*l)->klucz == element)
       {
           return l;
       }
       l = &((*l)->nast);
   }

   return NULL;
}


void DodajPrzed(lista *l, int element, int gdzie)
{
    l = OdszukajElement(l, gdzie);
    if(*l != NULL)
    {
        lista *q = &((*l)->poprz);
        DodajNaPoczatek(q, element);
        (*q)->nast = *l;
        (*l)->poprz = *q;
    }
}

void DodajZa(lista *l, int element, int gdzie)
{
    lista *q;
    l = OdszukajElement(l, gdzie);
    if(*l != NULL)
    {
        q = &((*l)->nast);
        DodajNaPoczatek(q, element);
        (*q)->poprz = *l;
        (*l)->nast = *q;
    }
}

void UsunWskazany(lista *l, int number)
{
    lista *element = OdszukajElement(l, number);
    return UsunPierwszy(element);
}

void WyswietlListeOdPoczatku(lista l)
{
    while(l != NULL)
    {
        printf("%d ", l->klucz);
        l = l->nast;
    }
    printf("\n");    
}

void WyswietlListeOdKonca(lista l)
{
    while(l->nast != NULL)
    {
        l = l->nast;
    }
    while(l != NULL)
    {
        printf("%d ", l->klucz);
        l = l->poprz;
    }
    printf("\n");
}