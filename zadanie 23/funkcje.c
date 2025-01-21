#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"

// wybieramy najwieksza wartosc z tablicy
int maximum(int* tab, int k)
{
    int max = tab[0];
    for (int i = 1; i < k; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
    return max;
}

// sortowanie przez zliczanie
void SortowanieZliczanie(int* tab, int k)
{
    int i;

    // szukamy najwiekszej wartosci w tablicy
    int max = maximum(tab, k);

    // tworzymy tablice zlicz do zliczania ilosci wystapien kazdej wartosci
    int* zlicz = malloc((max + 1) * sizeof(int));
    // tworzymy tablice wynik do przechowywania posortowanych wartosci
    int* wynik = malloc((k+1) * sizeof(int));

    // wypelniamy tablice zlicz zerami
    for (i = 0; i <= max; i++)
    {
        zlicz[i] = 0;
    }

    // zliczamy ilosc wystapien kazdej wartosci
    // indeks tablicy zlicz odpowiada wartosci w tablicy tab
    for(i=0; i<k; i++)
    {
        zlicz[tab[i]]++;
    }

    // sumujemy ilosc wystapien kazdej wartosci
    for(i=1; i<=max; i++)
    {
        zlicz[i] += zlicz[i-1];
    }

    // buduje tablice wynik
    for(i=k-1; i>=0; i--)
    {
        wynik[zlicz[tab[i]]-1] = tab[i];
        zlicz[tab[i]]--;
    }

    // przepisuje posortowane wartosci do tablicy tab
    for(i=0; i<k; i++)
    {
        tab[i] = wynik[i];
    }

    free(zlicz);
    free(wynik);
}

// wyswietlanie tablicy
void wyswietl(int* tab, int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}