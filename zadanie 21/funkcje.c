#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

void sortowanie_babelkowe(int tab[], int rozmiar, sortowanie *wyniki)
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
                //wyniki->przestawienia+=2;
                //wyniki->przestawienia+=1;
            }
            wyniki->porownania+=1;

            /*
            mam pytanie cos takiego powinienem liczyc jako jedno przestawienie czy jako 2 bo jakby teoretycznie sa 2 przestawienia bo z j+1 na j i z j na j+1 ale znowu mozna to tez w sumie policzyc jako 1 jako operacje ze zamieniaja sie miejscami
            */
        }
    }
}