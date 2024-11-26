#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

//wypisywanie listy od poczatku
void WyswietlListeOdPoczatku(lista l)
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

//dodawanie elementu na poczatek listy
void DodajNaPoczatek(lista *l, int number)
{
    //tworze nowy element
    lista nowa = malloc(sizeof(elListy));

    //kiedy lista pusta to dodaje element
    if(*l == NULL)
    {
        nowa->klucz = number;
        //lista ma byc cykliczna
        //wiec nastepny to ten sam
        nowa->nast = nowa;
        *l = nowa;
    }
    else //kiedy jest wiecej niz jeden element
    {
        nowa->klucz = (*l)->klucz;
        (*l)->klucz = number;
        nowa->nast = (*l)->nast;
        (*l)->nast = nowa;
    }
}

void DodajNaKoniec(lista *l, int number)
{
    //dodanie na poczatek
    DodajNaPoczatek(l, number);
    //przesuniecie glowy na drugi
    *l = (*l)->nast;
}


void UsunPowtorzenia(lista *l, lista q) 
{
    //kiedy ktoras z list jest pusta to nie ma co usuwac
    if (*l == NULL || q == NULL) return;

    lista glowaL = *l; //glowa listy l
    lista obecnyL = *l; //aktualny element listy l
    lista poprzedniL = NULL; //poprzedni element listy l

    //czy znaleziono powtorzenie
    int found;

    //while (found);
    do
    {
        found = 0;
        obecnyL = *l;
        poprzedniL = NULL;


        //while (obecnyL != glowaL);
        //dopoki nie przejdzie calej listy l
        do 
        {
            //wskaznik na aktualny element listy q
            lista obecnyQ = q;

            //while (obecnyQ != q);
            //dopoki nie przejdzie calej listy q
            do
            {
                //jesli znajdzie powtorzenie to ustawia found na 1 i przerywa petle
                if (obecnyL->klucz == obecnyQ->klucz)
                {
                    found = 1;
                    break;
                }
                obecnyQ = obecnyQ->nast;
            } while (obecnyQ != q);
            
            //jesli znaleziono powtorzenie to usuwa element z listy l
            if (found)
            {
                //zaznaczam element do usuniecia
                lista doUsuniecia = obecnyL;

                //jesli usuwam glowe listy
                if (poprzedniL == NULL)
                {
                    //jesli jedyny element w liscie
                    if (obecnyL->nast == glowaL)
                    {
                        free(doUsuniecia);
                        *l = NULL;
                        return;
                    }
                    
                    //przesuniecie glowy na drugi element
                    *l = obecnyL->nast;
                    glowaL = *l;
                    obecnyL = obecnyL->nast;

                    //przesuniecie ostatniego elementu na glowe
                    lista ostatni = *l;
                    //dopoki nie znajdzie ostatniego elementu
                    while (ostatni->nast != doUsuniecia)
                    {
                        ostatni = ostatni->nast;
                    }
                    //przesuniecie ostatniego elementu na glowe
                    ostatni->nast = glowaL;
                    //usuniecie elementu
                    free(doUsuniecia);
                }
                else //jesli usuwam inny element niz glowa
                {
                    //przesuniecie wskaznika na nastepny element
                    poprzedniL->nast = obecnyL->nast;
                    //jesli usuwam ostatni element
                    if (obecnyL == glowaL)
                    {
                        glowaL = obecnyL->nast;
                        *l = glowaL;
                    }
                    //przesuniecie wskaznika na nastepny element
                    obecnyL = poprzedniL->nast;
                    //usuniecie elementu
                    free(doUsuniecia);
                }
                break;
            }
            else //jesli nie znaleziono powtorzenia to przesuwa wskazniki
            {
                poprzedniL = obecnyL;
                obecnyL = obecnyL->nast;
            }
            //jesli znaleziono powtorzenie to powtarza petle
            //dla kolejnego elementu z listy l
        } while (obecnyL != glowaL);
    } while (found);
}



wstystkiepowtorzenia(lista *l lista p)
{
    lista q = p
    if(p)
    {
        do
        {
            usun wszystkie(l, element)
        } while ({l!=null && p!=q});
        
    }
}