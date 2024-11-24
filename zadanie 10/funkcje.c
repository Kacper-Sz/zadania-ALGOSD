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
    if(l!= NULL)
    {
        printf("xd");
    }
}


void DodajNaPoczatekA(lista *l, int number)
{
    lista nowa = malloc(sizeof(elListy));

    if(*l == NULL)
    {
        nowa->klucz = number;
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
    return;
}

void UsunOstatniA(lista *l)
{
    if (*l == NULL) // Jeśli lista jest pusta
    {
        return;
    }

    if ((*l)->nast == *l) // Jeśli lista ma tylko jeden element
    {
        free(*l);
        *l = NULL;
        return;
    }

    lista przedostatni = NULL;
    lista ostatni = *l;

    // Znajdź przedostatni i ostatni element
    while (ostatni->nast != *l)
    {
        przedostatni = ostatni;
        ostatni = ostatni->nast;
    }

    // przedostatni->nast powinien wskazywać na pierwszy element
    przedostatni->nast = *l;

    // Zwolnij pamięć zajmowaną przez ostatni element
    free(ostatni);
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

    if(*q == *l) //jak przed 1. elementem
    {
        DodajNaPoczatekA(l, element);
    }
    else
    {
        nowa->nast = *q;
        *q = nowa;
    }
}


void DodajZaA(lista *l, int element, int gdzie)
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
    nowa->nast = (*q)->nast;
    (*q)->nast = nowa;
}
void UsunWskazanyA(lista *l, int number)
{
    if(*l == NULL)
    {
        return;
    }

    lista *q = OdszukajElementA(l, number);

    if(q == NULL)
    {
        return;
    }

    lista dousuniecia = *q;
    if (*q == *l) // Jeśli usuwamy pierwszy element
    {
        if ((*l)->nast == *l) // Jeśli lista ma tylko jeden element
        {
            free(*l);
            *l = NULL;
        }
        else
        {
            *l = (*l)->nast;
            lista ostatni = *l;
            while (ostatni->nast != dousuniecia)
            {
                ostatni = ostatni->nast;
            }
            ostatni->nast = *l;
        }
    }
    else
    {
        *q = (*q)->nast;
    }

    free(dousuniecia);
    
}





