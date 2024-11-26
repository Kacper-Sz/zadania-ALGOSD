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
    //przechodze na koniec listy
    while(l->nast != NULL)
    {
        l = l->nast;
    }
    //dopoki nie dojde do poczatku
    while(l != NULL)
    {
        if(l->klucz == INT_MAX)
        {
            printf("Wartownik ");
            l = l->poprz;
            continue;
        }
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
    //jesli lista nie jest pusta
    if(*l != NULL)
    {
        nowy->poprz = (*l)->poprz;
        (*l)->poprz = nowy;
    }
    else    //jesli lista jest pusta
    {
        nowy->poprz = NULL;
    }
    //przypisanie nowego elementu jako pierwszego
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

    //przechowuje adres pierwszego elementu
    lista nowy = *l;
    //jesli jest tylko jeden element
    if((*l)->nast == NULL)
    {
        *l = NULL;
    }
    else //jesli jest wiecej elementow
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
    //ide na koniec listy
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
            //jak znajde element to zwracam adres na ten element
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
            //jak znajde element to dodaje przed nim
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
            //jak znajde element to dodaje za nim
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


void DodajDoPosortowanejWartownik(lista *l, int number)
{
    if(*l == 0)
    {
        printf("lista nie posiada wartownika");
        return;
    }

    //zawsze znajde mniejszy element
    while((*l)->klucz < number)
    {
        l = &((*l)->nast);
    }

    lista nowa = malloc(sizeof(elListy));
    nowa->klucz = number;
    nowa->nast = *l;
    nowa->poprz = (*l)->poprz;
    (*l)->poprz = nowa;
    *l = nowa;
}


lista* ZnajdzPosortowana(lista *l, int number)
{
    //dopoki nie znajdziemy elementu wiekszego od tego co chcemu dodac
    while((*l) != NULL && (*l)->klucz < number)
    {
        l = &((*l)->nast);
    }
    //jesli nie ma elementu lub jest nie rowny
    if((*l) == NULL || (*l)->klucz != number)
    {
        return NULL;
    }
    else
    {
        return l;
    }
}

lista* ZnajdzPosortowanaWartownik(lista *l, int number)
{
    while((*l)->klucz < number)
    {
        l = &((*l)->nast);
    }

    if((*l)->klucz == number)
    {
        return l;
    }
    else
    {
        return NULL;
    }
}


void UsunWskazanyPosortowana(lista *l, int number)
{
    lista element = 0;
    while((*l) != NULL && (*l)->klucz < number)
    {
        element = *l;
        l = &((*l)->nast);
    }

    if((*l) != NULL && (*l)->klucz == number)
    {
        lista nowa = *l;
        *l = (*l)->nast;
        (*l)->poprz = element;
        free(nowa);
    }
    else
    {
        printf("element %d nie znajduje sie na liscie.\n", number);
    }

}


void UsunWskazanyPosortowanaWartownik(lista *l, int number)
{
    lista element = 0;
    while((*l)->klucz < number)
    {
        element = *l;
        l = &((*l)->nast);
    }

    if((*l)->klucz == number)
    {
        lista nowa = *l;
        *l = (*l)->nast;
        (*l)->poprz = element;
        free(nowa);
    }
    else
    {
        printf("element %d nie znajduje sie na liscie.\n", number);
    }
}


lista* ZnajdzPierwszy(lista *l)
{
    return l;
}

lista* ZnajdzPierwszyWartownik(lista *l)
{
    if((*l)->klucz == INT_MAX)
    {
        return NULL;
    }
    return l;
}

//znajdowanie ostatniego elementu
lista* ZnajdzOstatni(lista *l)
{
    //jesli lista jest pusta
    if (l == NULL) {
        //printf("Lista jest pusta.\n");
        return NULL;
    }
    //ide na koniec listy
    while ((*l)->nast != NULL) {
        l = &((*l)->nast);
    }
    //zwracam ostatni element
    return l;
}


//znajdowanie ostatniego elementu z wartownikiem
lista* ZnajdzOstatniWartownik(lista *l)
{
    //jesli lista jest pusta
    if((*l)->klucz == INT_MAX)
    {
        return NULL;
    }
    //ide na koniec listy
    //sprawdzam czy element po wartowniku nie jest nullem
    while((*l)->nast->klucz != INT_MAX)
    {
        l = &((*l)->nast);
    }
    //zwracam ostatni element
    return l;
}