#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void DodajNaPoczatek(lista *l, int klucz)
{
    //tworzenie nowego elementu listy
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = klucz;
    nowa->nast = *l;
    //przypisanie nowego elementu jako pierwszego
    *l=nowa;
}

void DodajNaKoniec(lista *l, int klucz)
{
    //tworzenie nowego elementu listy
    lista nowa = (lista)malloc(sizeof(elListy));
    nowa->klucz = klucz;
    nowa->nast = 0;
    //przejscie na koniec listy
    while(*l)
    {
        l=&(*l)->nast;
    }
    //przypisanie nowego elementu jako ostatniego
    *l=nowa;
}

void UsunPierwszy(lista *l)
{
    //sprawdzenie czy lista jest pusta
    if (*l == 0)
    {
        printf("\nlista jest pusta\n");
        return;
    }
    lista poczatek;
    if(*l != 0 )
    {
        poczatek = *l;
        //przypisanie drugiego elementu jako pierwszego
        *l = (*l)->nast;
        //usuniecie pierwszego elementu
        free(poczatek);
    }
    printf("\nusunieto pierwszy element\n");
}

void UsunOstatni(lista *l)
{
    //sprawdzenie czy lista jest pusta
    if(*l == 0) 
    {
        printf("\nlista jest pusta\n");
        return;
    }
    //przejscie na koniec listy
    while((*l)->nast)
    {
        l=&(*l)->nast;
    }
    //usuniecie ostatniego elementu
    free(*l);
    //nowy koniec listy
    *l=0;
    printf("\nusunieto ostatni element\n");
}

void OdszukajElement(lista l, int element)
{
    lista nowa = l;
    int licznik = 0;
    //przeszukanie calej listy
    while(nowa) 
    {
        //jesli element zostanie znaleziony
        if(nowa->klucz == element)
        {
            licznik++;
            printf("\nznaleziono element o wartosci %d pod adresem: %p\n", element, nowa);
        }
        //przejscie do nastepnego elementu
        nowa = nowa->nast;
    }
    //wyswietlenie ilosci znalezionych elementow
    printf("\nlacznie element: %d, znaleziono %d ", element, licznik);
    if(licznik == 1) printf("raz\n\n");
    else if (licznik == 0) printf("\nrazy, element nie znajduje sie na liscie\n\n");
    else printf("razy\n\n");
}

void DodajPrzedLubZa(lista *l, int element, int gdzie, int opcja, int ktore)
{
    lista poprzedni = 0;
    lista obecny = *l;

    //sprawdzenie czy lista jest pusta
    if(*l == 0)
    {
        printf("\nlista jest pusta, brak elementu %d na liscie\n", gdzie);
        return;
    }


    switch (ktore)
    {
    case 1:
    // DODAWANIE ELEMENTU TYLKO PRZED PIERWSZYM NAPOTKANYM
        lista nowa = (lista)malloc(sizeof(elListy));
        nowa->klucz = element;

        while(obecny != 0 && obecny->klucz != gdzie)
        {
            poprzedni = obecny;
            obecny = obecny->nast;
        }

        //kiedy lista bedzie pusta
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
            //kiedy element ma byc dodany przed i istnieje element poprzedni
            if(poprzedni)
            {
                //pokazuje ze nowy element jest przed obecnym i po poprzednim
                poprzedni->nast = nowa;
                nowa->nast = obecny;
            }
            else
            {
                //kiedy element ma byc dodany przed pierwszym
                nowa->nast = *l;
                //pokazuje ze nowa bedzei pierwszym elementem
                *l=nowa;
            }
        }
        else if (opcja == 2)
        {
            //kiedy element ma byc dodany za
            //dopisujemy go za obecnym
            nowa->nast = obecny->nast;
            obecny->nast = nowa;
        }
        printf("\npomyslnie dodano element\n");
        break;

    case 2:
    // DODAWANIE ELEMENTU PRZED KAZDYM NAPOTKANYM
        //wykonujemy dopoki obecny nie jest zero(ma elementy)
        int czyDodano = 0;
        while(obecny)
        {
        //jesli element zostanie znaleziony
            if (obecny->klucz == gdzie)
            {
                //tworzymy nowy element
                lista nowa = (lista)malloc(sizeof(elListy));
                nowa->klucz = element;

                //1 dodaje przed
                //2 dodaje za
                if (opcja == 1)
                {
                    //kiedy element ma byc dodany przed i istnieje element poprzedni
                    if (poprzedni)
                    {
                        //pokazuje ze nowy element jest przed obecnym i po poprzednim (pomiedzy)
                        poprzedni->nast = nowa;
                        nowa->nast = obecny;
                    }
                    else
                    {
                        //kiedy ma byc to pierwszy element
                        nowa->nast = *l;
                        *l = nowa;
                    }
                    //dodalismy nowy element wiec kolejnosc teraz jest taka:
                    //poprzedni nowa obecny
                    //wiec zeby zachowac spojnosc 
                    //poprzednim elementem musi sie stac ten "nowa"             
                    poprzedni = nowa;
                }
                else if(opcja == 2)
                {
                    //kiedy dodajemy za
                    //to wyglada to tak: poprzedni obecny nowa
                    nowa->nast = obecny->nast;
                    obecny->nast = nowa;
                    //tu rowniez trzeba zaktualizowac polozenie
                    poprzedni = obecny;
                    obecny = nowa;
                }
                czyDodano = 1;
            }
            //przejscie do kolejngeo elementu
            poprzedni = obecny;           
            obecny = obecny->nast;    
        }
        if(czyDodano == 1)
        {
            printf("\npomyslnie dodano element\n");
        }
        else
        {
            printf("\nna liscie brak elementu: %d\n", gdzie);
        }        
        break;
    default:
        printf("bledna opcja");
        break;
    }

}

void UsunWskazany(lista *l, int number, int opcja)
{
    int czyUsunieto = 0;
    //sprawdzenie czy lista jest pusta
    if (*l == 0)
    {
        printf("\nlista pusta brak elementu: %d\n", number);
        return;
    }

    
    lista obecny = *l;
    lista poprzedni = 0;
    //usuwanie pierwszego elementu jesli jest rowny number
    if (obecny && obecny->klucz == number)
    {
        *l = obecny->nast;
        free(obecny);
        obecny = *l;
        //OPCJA 1 USUNIECIE TYLKO PIERWSZEGO SPOTKANEGO
        if (opcja == 1) 
        {
            printf("usunieto element %d\n", number);
            return;
        }
    }

    switch (opcja)
    {
    //OPCJA 1 USUNIECIE TYLKO PIERWSZEGO SPOTKANEGO
    case 1:
        while(obecny != 0 && obecny->klucz != number)
        {
            //przejscie do nastepnego elementu
            poprzedni = obecny;
            obecny = obecny->nast;
        }
        //jesli element nie zostanie znaleziony
        if (obecny == NULL) {
            printf("element %d nie znajduje sie na liscie.\n", number);
            return;
        }
        //jesli element zostanie znaleziony to usuwa go i przypisuje nastepny element
        poprzedni->nast=obecny->nast;
        free(obecny);
        printf("usunieto element %d\n", number);
        break;
    //OPCJA 2 USUN KAZDY KOLEJNY
    case 2:
        while(obecny)
        {   //jesli element zostanie znaleziony
             if (obecny->klucz == number)
            {
                //jesli element zostanie znaleziony to usuwa go i przypisuje nastepny element
                lista nastepny = obecny->nast;
                // usuwamy biezacy element
                if (poprzedni) {
                    poprzedni->nast = nastepny;
                } else {
                    // usuwamy pierwszy element listy
                    *l = nastepny;
                }
                free(obecny);
                obecny = nastepny;
                czyUsunieto = 1;
            }
            else
            //przejscie do nastepnego elementu jesli element nie zostanie znaleziony
            {
                poprzedni = obecny;
                obecny = obecny->nast;
            }
        }
        if(czyUsunieto == 1)
        {
            printf("usunieto elementy %d\n", number);
        }
        else
        {
            printf("element %d nie znajduje sie na liscie.\n", number);
        }
        break;
    default:
        printf("bledna opcja");
        break;
    }
 
}

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

void WyswietlListeOdKonca(lista l)
{
    if(l != 0)
    {
        if(l->nast == 0)
        {
            printf("%d ", l->klucz);
        }
        else
        {
            WyswietlListeOdKonca(l->nast);
            printf("%d ", l->klucz);
        }
    }
}



//zadanie 2

void UsunWszystkieNierekurencyjnie(lista *l, int number)
{
    lista obecny = *l;
    lista poprzedni = 0;
    int czyUsunieto = 0;

    //sprawdzenie czy lista jest pusta
    if (*l == 0)
    {
        printf("\nlista pusta brak elementu: %d\n", number);
        return;
    }

    while(obecny != 0)
    {
        //jesli element znaleziony
        if(obecny->klucz == number)
        {
            //jak znajdzie element to go usuwa i przypisuje kolejne
            lista nastepny = obecny->nast;

            if(poprzedni != 0)
            {
                poprzedni->nast = nastepny;
            }
            else
            {
                *l = nastepny;
            }
            free(obecny);
            obecny = nastepny;
            czyUsunieto = 1;
        }
        else
        {
            poprzedni = obecny;
            obecny = obecny->nast;
        }
    }

    if(czyUsunieto == 1)
    {
        printf("usunieto elementy %d\n", number);
    }
    else
        {
            printf("element %d nie znajduje sie na liscie.\n", number);
        }
}

void UsunWszystkieRekurencyjnie(lista *l, int number)
{
    if(*l == 0)
    {
        return;
    }

    //kiedy znajdziemy element o poszukiwanej wartosci
    if((*l)->klucz == number)
    {

        lista nowa = *l;
        //przesuwamy wskaznik na kolejny
        *l = (*l)->nast;
        //usuwamy biezacy element
        free(nowa);
        UsunWszystkieRekurencyjnie(l, number);
    }
    else
    {
        //jak nie pasuje to ide do nastepnego
        UsunWszystkieRekurencyjnie(&(*l)->nast, number);
    }
}