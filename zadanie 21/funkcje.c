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