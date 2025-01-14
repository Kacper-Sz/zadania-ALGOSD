#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

void sortowanie_babelkowe(int tab[], int rozmiar, sortowanie *wynik)
{
    int i, j, temp;
    for(i=0; i<rozmiar-1; i++)
    {
        for(j=0; j<rozmiar-1; j++)
        {
            if(tab[j]>tab[j+1])
            {
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
                wynik->przestawienia+=3;
                //wyniki->przestawienia+=2;
                //wyniki->przestawienia+=1;
            }
            wynik->porownania+=1;
        }
    }
}

void sortowanie_wstawianie(int tab[], int rozmiar, sortowanie *wynik)
{
    int i, j, temp;
    
    for(i=1; i<rozmiar; i++)
    {
        wynik->przestawienia+=1;
        wynik->porownania+=1;

        temp=tab[i];
        j=i-1;

        while(j>=0 && tab[j]>temp)
        {
            wynik->przestawienia+=1;
            wynik->porownania+=1;
            
            tab[j+1]=tab[j];
            j--;
        }

        tab[j+1]=temp;
        wynik->przestawienia+=1;        
    }
}

void sortowanie_szybkie(int tab [], int rozmiar, sortowanie *wynik, int lewy, int prawy)
{
    int i, j, srodek, temp;

    if(prawy <= lewy)
    {
        return;
    }

    i = lewy - 1;
    j = prawy + 1;
    srodek = tab[(lewy + prawy) / 2];

    while(1)
    {
        while(srodek>tab[++i])
        {
            wynik->porownania+=1;
        }

        while(srodek<tab[--j])
        {
            wynik->porownania+=1;
        }

        if(i <= j)
        {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            wynik->przestawienia+=3;
            i++;
            j--;
        }
        else
        {
            break;
        }

        wynik->porownania+=1;

        if(j > lewy)
        {
            sortowanie_szybkie(tab, rozmiar, wynik, lewy, j);
        }
        if(i < prawy)
        {
            sortowanie_szybkie(tab, rozmiar, wynik, i, prawy);
        }
    }
}

void sortowanie_shella(int tab [], int rozmiar, sortowanie *wyniki)
{
    int i, j, temp;
    int polowa;

    for(polowa = rozmiar / 2; polowa>0; polowa /= 2)
    {
        for(i=polowa; i<size; i++)
        {
            temp = tab[i];
            int j;
        }
    }
}