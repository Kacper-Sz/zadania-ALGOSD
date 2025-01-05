#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funkcje.h"


//wyswietlanie listy

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
        printf("%d ", nowa->klucz);
        nowa = nowa->nast;
    }
    printf("\n\n");    
}


//dodawanie dla listy uporzadkowanej
void DodajDoPosortowanej(lista *l, int number)
{
    //alokacja pamieci dla nowego elementu
    lista nowa = malloc(sizeof(elListy));
    nowa->klucz = number;

    //jesli lista jest pusta
    if(*l == 0)
    {
        nowa->nast = *l;
        *l = nowa;
        return;
    }

    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while(*l != NULL && (*l)->klucz < number)
    {
        //adres czesci nastepnej
        l = &((*l)->nast);
    }

    //dodajemy element przed elementem wiekszym
    nowa->nast = *l;
    *l = nowa;
}

//laczenie list
void polaczListy(lista *l, lista *q)
{
    lista *k, t;
    k = q;

    while (*q != NULL)
    {
        while(*l != NULL && (*l)->klucz <= (*k)->klucz)
        {
            l = &((*l)->nast);
        }

        //kiedy lista l jest pusta
        if(*l == NULL)
        {
            *l = *q;
            *q = NULL;
        }
        else
        {
            while(*k != NULL && (*k)->klucz <= (*l)->klucz)
            {
                k = &((*k)->nast);
            }
            t = *l;
            *l = *q;
            *q = *k;
            *k = t;
            l = k;
            k = q;
        }
    }
    
}


//tutaj rozwiazanie inne 
/*
Oleksandr Sokolov
lista polacz(lista q, lista p)
{
    if (q == NULL)
        return p;
    else if (p == NULL)
        return q;

    lista nowa = NULL;
    if (q->klucz <= p->klucz)
    {
        nowa = q;
        nowa->nast = polacz(q->nast, p);
    }
    else
    {
        nowa = p;
        nowa->nast = polacz(q, p->nast);
    }
    return nowa;
}

10.12.2024, 3:09:28 PM
*/