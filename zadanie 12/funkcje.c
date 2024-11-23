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








