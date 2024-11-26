#include <stdio.h>
#include <stdlib.h>
#include "funkcjeB.h"

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

void WyswietlListeOdKoncaB(listaB l)
{
    if(l == NULL)
    {
        printf("lista jest pusta\n");
        return;
    }

    listaB q = l;
    //przechodze do ostatniego elementu
    while(q->poprz != l)
    {
        q = q->poprz;
        printf("%d ", q->klucz);
    }
    q = q->poprz;
    printf("%d ", q->klucz);
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

void UsunOstatniB(listaB *l)
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
        listaB ostatni = q->poprz;
        q->poprz->poprz->nast = q;
        q->poprz = q->poprz->poprz;
        free(ostatni);
    }
}


listaB* OdszukajElementB(listaB *l, int element)
{
    //jak null to nic nie robie
    if(*l == NULL)
    {
        return NULL;
    }

    listaB *q = l;
    do //przechodze przez liste dopoki nie wroce do poczatku
    {
        //jak znajde element to zwracam wskaznik na niego
        if((*q)->klucz == element)
        {
            return q;
        }
        //przechodze do adresu czesci nastepnka
        q = &((*q)->nast);
    } while(*q != *l);

    return NULL;
}

void DodajPrzedB(listaB *l, int element, int gdzie)
{
    if(*l == NULL)
    {
        return;
    }
    //szukam elementu
    listaB *q = OdszukajElementB(l, gdzie);
    //jak nie ma to nic nie robie
    if(q == NULL)
    {
        return;
    }
    //tworze nowy element i dodaje go przed znalezionym
    listaB nowa = malloc(sizeof(elListyB));
    nowa->klucz = element;
    nowa->nast = *q;
    nowa->poprz = (*q)->poprz;
    (*q)->poprz->nast = nowa;
    (*q)->poprz = nowa;
    //jak dodaje przed pierwszym elementem to przesuwam wskaznik na poczatek
    if(*q == *l)
    {
        *l = nowa;
    }
}

void DodajZaB(listaB *l, int element, int gdzie)
{
    //jak null to nic nie robie
    if(*l == NULL)
    {
        return;
    }
    //szukam elementu
    listaB *q = OdszukajElementB(l, gdzie);

    if(q == NULL)
    {
        return;
    }
    //tworze nowy element i dodaje go za znalezionym
    listaB nowa = malloc(sizeof(elListyB));
    nowa->klucz = element;
    nowa->nast = (*q)->nast;
    nowa->poprz = *q;
    (*q)->nast->poprz = nowa;
    (*q)->nast = nowa;
}

void UsunWskazanyB(listaB *l, int number)
{
    if(*l == NULL)
    {
        return;
    }

    listaB *q = OdszukajElementB(l, number);

    if(q == NULL)
    {
        return;
    }
    //jak usuwam pierwszy element to przesuwam wskaznik na poczatek
    listaB doUsuniecia = *q;
    if(doUsuniecia == *l)
    {
        *l = doUsuniecia->nast;
    }
    doUsuniecia->poprz->nast = doUsuniecia->nast;
    doUsuniecia->nast->poprz = doUsuniecia->poprz;
    free(doUsuniecia);
}