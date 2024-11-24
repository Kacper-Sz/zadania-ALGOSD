#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"


void WyswietlListeOdPoczatkuA(lista l)
{
    if(l == NULL)
    {
        printf("lista jest pusta\n");
        return;
    }

    lista q = l;
    do
    {
        printf("%d ", q->klucz);
        q = q->nast;
    } while(q != l);
    printf("\n");
}

void WyswietlListeOdKoncaA(lista l)
{
    if(l == NULL)
    {
        printf("lista jest pusta\n");
        return;
    }
    lista q = l;
    if(l != 0)
    {
        if(l->nast == q)
        {
            printf("%d ", l->klucz);
        }
        else
        {
            WyswietlListeOdKoncaA(l->nast);
            printf("%d ", l->klucz);
        }
    }
}


void DodajNaPoczatekA(lista *l, int number)
{
    //tworzenie nowego elementu listy
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = number;
    
    if(*l == NULL)
    {
        nowa->nast = nowa;
        *l = nowa;
    }
    else
    {
        nowa->klucz = (*l)->klucz;
        (*l)->klucz = number;
        nowa->nast = (*l)->nast;
        (*l)->nast = nowa;
    }
}

void DodajNaKoniecA(lista *l, int number)
{
    DodajNaPoczatekA(l, number);
    *l = (*l)->nast;
}

void UsunPierwszyA(lista *l)
{
    lista q;
    if(*l != NULL)
    {
        q = (*l)->nast;
        //jesli lista ma tylko jeden element
        if(q == *l)
        {
            *l = NULL;
        }
        else
        {
            (*l)->klucz = q->klucz;
            (*l)->nast = q->nast;
        }
        free(q);
    }
}

void UsunOstatniA(lista *l)
{
    if(*l == NULL)
    {
        return;
    }

    lista q;

    if((*l)->nast == *l)
    {
        free(*l);
        *l = NULL;
    }
    else
    {
        q = *l;
        while(q->nast != *l)
        {
            q = q->nast;
        }
        q->nast = (*l)->nast;
        free(*l);
        *l = q;
    }
}


lista *OdszukajElementA(lista *l, int element)
{
    if (*l == NULL) // Jeśli lista jest pusta
    {
        return NULL;
    }

    lista *q = l; // Zacznij od wskaźnika na pierwszy element listy
    do
    {
        if ((*q)->klucz == element) // Jeśli znaleziono element
        {
            return q; // Zwróć wskaźnik do wskaźnika na ten element
        }
        q = &((*q)->nast); // Przejdź do wskaźnika na następny element
    } while (*q != *l); // Powtarzaj dopóki nie wrócisz do początku listy

    return NULL; // Jeśli nie znaleziono elementu
}

void DodajPrzedA(lista *l, int element, int gdzie)
{
    if(*l == NULL)
    {
        return;
    }

    lista *q = OdszukajElementA(l, gdzie);

    if(q == NULL)
    {
        return;
    }

    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = element;
    nowa->nast = *q;
    *q = nowa;
}


void DodajZaA(lista *l, int element, int gdzie)
{
    return;
}
void UsunWskazanyA(lista *l, int number)
{
    return;
}








