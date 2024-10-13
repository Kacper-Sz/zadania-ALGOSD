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
    lista nowa = l;
    int licznik = 0;
    while(nowa) 
    {
        if(nowa->klucz == element)
        {
            licznik++;
            printf("znaleziono element o wartosci %d pod adresem: %p\n", element, nowa);
        }
        nowa = nowa->nast;
    }
    printf("lacznie element: %d, znaleziono %d ", element, licznik);
    if(licznik == 1) printf("raz\n\n");
    else if (licznik == 0) printf("razy, element nie znajduje sie na liscie\n\n");
    else printf("razy\n\n");
}
//OD TEGO MOMENTU MOZNA SIE ZASTANOAWIAC NAD POPRAWA
// OD TEGO MOEMENTU DZIAL DO PIERWSZEGO SPOTKANEGO
void DodajPrzedLubZa(lista *l, int element, int gdzie, int opcja)
{
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = element;

    if(*l == 0)
    {
        *l = nowa;
        nowa->nast = 0;
        return;
    }

    lista poprzedni = 0;
    lista obecny = *l;

    while(obecny != 0 && obecny->klucz != gdzie)
    {
        poprzedni = obecny;
        obecny = obecny->nast;
    }

    if(obecny == 0)
    {
        printf("na liscie brak elementu: %d", gdzie);
        free(nowa);
        return;
    }
    //1 dodaje przed
    //2 dodaje za
    if(opcja == 1)
    {
        if(poprzedni)
        {
            poprzedni->nast = nowa;
            nowa->nast = obecny;
        }
        else
        {
            //pokazuja w to samo miejsce
            nowa->nast = *l;
            //pokazuje ze nowa bedzei pierwszym elementem
            *l=nowa;
        }
    }
    else if (opcja == 2)
    {
        nowa->nast = obecny->nast;
        obecny->nast = nowa;
    }

}

void UsunWskazany(lista *l, int number)
{
    if (*l == 0)
    {
        printf("lista pusta brak elementu: %d", number);
        return;
    }

    lista obecny = *l;
    if (obecny->klucz == number)
    {
        *l = obecny->nast;
        free(obecny);
        printf("usunieto eleemnt: %d", number);
        return;
    }

    lista poprzedni = 0;

    while(obecny != 0 && obecny->klucz != number)
    {
        poprzedni = obecny;
        obecny = obecny->nast;
    }

    if (obecny == NULL) {
        printf("element %d nie znajduje sie na liscie.\n", number);
        return;
    }

    poprzedni->nast=obecny->nast;
    free(obecny);
    printf("usunieto element %d\n", number);
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