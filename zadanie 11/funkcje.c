#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void WyswietlListeOdPoczatkuB(listaB l)
{
    if(l == NULL)
    {
        printf("lista jest pusta\n");
        return;
    }

    listaB q = l;
    do
    {
        //wypisuje klucz elementu i przechodze do nastepnego dopoki nie wroce do poczatku
        printf("%d ", q->klucz);
        q = q->nast;
    } while(q != l);
    printf("\n");
}

void DodajNaPoczatekB(listaB *l, int number)
{
    listaB nowaB = malloc(sizeof(elListyB));

    //jak null to dodaje pierwszy element
    if(*l == NULL)
    {
        nowaB->klucz = number;
        nowaB->nast = nowaB;
        nowaB->poprz = nowaB;
        *l = nowaB;
    }
    else
    {
        nowaB->klucz = number;
        nowaB->nast = *l;
        nowaB->poprz = (*l)->poprz;
        (*l)->poprz->nast = nowaB;
        (*l)->poprz = nowaB;
        *l = nowaB;
    }
}

void DodajNaKoniecB(listaB *l, int number)
{
    //dodaje na poczatek i przesuwam wskaznik na nastepny element zeby dodac na koncu
    DodajNaPoczatekB(l, number);
    *l = (*l)->nast;
}

void UsunPierwszyB(listaB *l)
{
    //jak null to nic nie robie
    if(*l == NULL)
    {
        return;
    }


    listaB q = *l;
    //jak jeden element to usuwam go
    if(q->nast == q)
    {
        free(q);
        *l = NULL;
    }
    else
    {
        q->poprz->nast = q->nast;
        q->nast->poprz = q->poprz;
        *l = q->nast;
        free(q);
    }
}

void UsuwanKaty(listaB *l, int k)
{

    if(l == NULL)
    {
        printf("lista jest pusta\n");
        return;
    }

    listaB q = *l;

    while(q->nast != q)
    {
        for(int i = 1; i < k; i++)
        {
            q = q->nast;
        }

        UsunPierwszyB(&q);
        *l = q;
    }
}


