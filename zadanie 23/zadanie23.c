#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "funkcje.h"

int main()
{
    srand(time(NULL));
    int k, i;
    
    int tab[100];

    // wypelniamy tablice losowymi wartosciami z zakresu 0-9
    for(i=0; i<100; i++)
    {
        tab[i] = rand() % 10;
    }

    wyswietl(tab, 100);

    printf("\npodaj k: ");
    scanf("%d", &k);
    printf("\n");

    // tablica 100 elementowa sortuje dla k elementow
    SortowanieZliczanie(tab, k);
    wyswietl(tab, k);
    
    return 0;
}