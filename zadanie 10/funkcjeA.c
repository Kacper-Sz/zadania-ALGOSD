#include <stdio.h>
#include <stdlib.h>
#include "funkcjeA.h"

//listy nieposortowane cykliczne

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
    lista odwrotna = NULL;
    while(q->nast != l)
    {
        DodajNaPoczatekA(&odwrotna, q->klucz);
        q = q->nast;
    }
    DodajNaPoczatekA(&odwrotna, q->klucz);

    WyswietlListeOdPoczatkuA(odwrotna);

    while(odwrotna != NULL)
    {
        UsunPierwszyA(&odwrotna);
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
        //dodaje nowy element za pierwszym
        //przepisuje klucz pierwszego elementu na nowy
        nowa->klucz = (*l)->klucz;
        (*l)->klucz = number;
        nowa->nast = (*l)->nast;
        (*l)->nast = nowa;

    }
}

void DodajNaKoniecA(lista *l, int number)
{
    //dodanie na poczaatek i zmiana pierwszego elementu
    DodajNaPoczatekA(l, number);
    *l = (*l)->nast;
}

void UsunPierwszyA(lista *l)
{
    lista q;
    //jesli lista nie jest pusta
    if(*l != NULL)
    {
        //q to drugi element listy
        q = (*l)->nast;
        //jesli lista ma tylko jeden element to staje sie pusta
        if(q == *l)
        {
            *l = NULL;
        }
        else
        {
            //przepisanie drugiego elementu na pierwszy
            //zeby nie utracic wskaznika na pierwszy element (cyklicznosc)
            (*l)->klucz = q->klucz;
            (*l)->nast = q->nast;
        }
        //usuwam q
        free(q);
    }
    return;
}

void UsunOstatniA(lista *l)
{
    //jak lista pusta
    if (*l == NULL)
    {
        return;
    }

    //jeśli lista ma tylko jeden element
    if ((*l)->nast == *l) 
    {
        free(*l);
        *l = NULL;
        return;
    }

    //znajduej przedostatni i ostatni element
    lista przedostatni = NULL;
    lista ostatni = *l;

    //ostatni elemet to ten co wskazuje na pierwszy
    while (ostatni->nast != *l)
    {
        przedostatni = ostatni;
        ostatni = ostatni->nast;
    }

    //przedostatni jest nowym koncem listy
    przedostatni->nast = *l;

    //usuwam ostatni
    free(ostatni);
}


lista *OdszukajElementA(lista *l, int element)
{
    //jak lista jest pusta
    if (*l == NULL)
    {
        return NULL;
    }


    lista *q = l;
    do
    {
        //jeśli znaleziono element
        if ((*q)->klucz == element)
        {
            //zwracam wkaznik na ten element (wskaźnik na wskaźnik)
            return q;
        }
        //przechodze do nastepnego adresu nastepnika
        q = &((*q)->nast);
    //dopóki nie wrócę do początku
    } while (*q != *l);

    //jak nic nie znaleziono to null
    return NULL;
}

void DodajPrzedA(lista *l, int element, int gdzie)
{
    //jak lista pusta
    if(*l == NULL)
    {
        return;
    }

    //odszukuje element przed którym chce wstawić nowy element
    lista *q = OdszukajElementA(l, gdzie);
    //jak nie znaleziono elementu to nic nie robie
    if(q == NULL)
    {
        return;
    }

    //tworze nowy element
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = element;

    //jak dodaje przed 1. elementem
    if(*q == *l)
    {
        //dodaje na poczatek
        DodajNaPoczatekA(l, element);
    }
    else
    {
        //dodaje przed elementem
        nowa->nast = *q;
        *q = nowa;
    }
}


void DodajZaA(lista *l, int element, int gdzie)
{
    //jak lista pusta to nic nie robie
    if(*l == NULL)
    {
        return;
    }

    //odszukuje element za którym chce wstawić nowy element
    lista *q = OdszukajElementA(l, gdzie);

    //jak nie znaleziono/nie ma elementu to nic nie robie
    if(q == NULL)
    {
        return;
    }

    //tworze nowy element
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = element;
    //dodaje za elementem
    nowa->nast = (*q)->nast;
    (*q)->nast = nowa;
}
void UsunWskazanyA(lista *l, int number)
{
    //jak lista pusta to nic nie robie
    if(*l == NULL)
    {
        return;
    }

    //odszukuje element do usunięcia
    lista *q = OdszukajElementA(l, number);

    //jak nie znaleziono/nie ma elementu to nic nie robie
    if(q == NULL)
    {
        return;
    }

    //jeśli usuwamy pierwszy element
    lista dousuniecia = *q;
    if (*q == *l)
    {
        //jeśli lista ma tylko jeden element
        if ((*l)->nast == *l)
        {
            free(*l);
            *l = NULL;
        }
        else //jeśli lista ma więcej elementów
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
    else //jeśli usuwamy inny element niż pierwszy
    {
        *q = (*q)->nast;
    }
    //usuwam element
    free(dousuniecia);
    
}





