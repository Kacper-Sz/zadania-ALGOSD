#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"


void WyswietlListeOdPoczatku(lista l)
{
    if(l == 0)
    {
        printf("\nlista jest pusta\n");
        return;
    }
    while (l)
    {
        if(l->klucz == INT_MAX)
        {
            printf("Wartownik");
            l = l->nast;
            continue;
        }
        printf("%d ", l->klucz);
        l = l->nast;
    }
    printf("\n\n");   
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

//listy nieposortowane
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

void UsunOstatni(lista *l)
{
    if(*l == NULL)
    {
        return;
    }

    while((*l)->nast != NULL)
    {
        l = &((*l)->nast);
    }
    UsunPierwszy(l);
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
    if(*l == NULL)
    {
        return;
    }

    while(*l != NULL)
    {
        if((*l)->klucz == gdzie)
        {
            lista nowa = malloc(sizeof(elListy));
            nowa->klucz = element;
            nowa->nast = *l;
            nowa->poprz = (*l)->poprz;
            *l = nowa;
            return;
        }
        l = &((*l)->nast);
    }
}

void DodajZa(lista *l, int element, int gdzie)
{
    if(*l==NULL)
    {
        return;
    }

    while(*l != NULL)
    {
        if((*l)->klucz == gdzie)
        {
            lista nowa = malloc(sizeof(elListy));
            nowa->klucz = element;
            nowa->nast = (*l)->nast;
            nowa->poprz = *l;
            (*l)->nast = nowa;
            return;
        }
        l = &((*l)->nast);
    }
}

void UsunWskazany(lista *l, int number)
{
    lista *element = OdszukajElement(l, number);
    return UsunPierwszy(element);
}


//lista uporzadkowana

void DodanieWartownika(lista *l)
{
    //alokacja pamieci dla wartownika
    lista wartownik = malloc(sizeof(elListy));
    wartownik->klucz = INT_MAX;
    //dodam na koniec wiec pole nast to 0
    wartownik->nast = 0;
    //dopoki nie znajdziemy ostatniego elementu
    while(*l)
    {
        l=&((*l)->nast);
    }
    wartownik->poprz = *l;
    //przypisanie ostatniego elementu jako wartownika
    *l=wartownik;
}


void DodajDoPosortowanej(lista *l, int number)
{
    lista nowa = malloc(sizeof(elListy));
    nowa->klucz = number;

    if(*l == 0)
    {
        nowa->nast = *l;
        nowa->poprz = NULL;
        *l = nowa;
        return;
    }

    lista k = NULL;
    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while(*l != NULL && (*l)->klucz < number)
    {
        //k przechowuje watosc na ktora wskazuje l
        k = *l;
        //adres czesci nastepnej
        l = &((*l)->nast);
    }
    
    nowa->nast = *l;
    
    if(*l != NULL)
    {
        nowa->poprz = (*l)->poprz;
        (*l)->poprz = nowa;
    }
    else
    {
        nowa->poprz = k;
    }

    *l = nowa;
}
