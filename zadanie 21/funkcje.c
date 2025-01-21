#include <stdio.h>
#include <stdlib.h>

#include "funkcje.h"


void sortowanie_rosnaco(int tab[], int rozmiar)
{
    for(int i = 0; i < rozmiar - 1; i++)
    {
        for(int j = 0; j < rozmiar - i - 1; j++)
        {
            if(tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void sortowanie_malejaco(int tab[], int rozmiar)
{
    for(int i = 0; i < rozmiar - 1; i++)
    {
        for(int j = 0; j < rozmiar - i - 1; j++)
        {
            if(tab[j] < tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}


// porownuje 2 elementy i zamienia je miejscami
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
            }
            wynik->porownania+=1;
        }
    }
}

// porownuje 2 elementy i przestawia je w odpowiednie miejsce
void sortowanie_wstawianie(int tab[], int rozmiar, sortowanie *wynik)
{
    int i, j, temp;
    
    for(i=1; i<rozmiar; i++)
    {
        wynik->przestawienia+=1;
        temp=tab[i];
        j=i-1;

        while(j>=0 && tab[j]>temp)
        {
            wynik->porownania+=1;
            wynik->przestawienia+=1;
            tab[j+1]=tab[j];
            j--;
        }
        // ostatnie porownanie w while
        // bo juz nie wejdzie do petli
        wynik->porownania+=1;

        tab[j+1]=temp;
        wynik->przestawienia+=1;        
    }
}

// dzieli tablice na 2 czesci i rekurencyjnie sortuje 
// kazda z nich
void sortowanie_szybkie(int tab [], int rozmiar, sortowanie *wynik, int lewy, int prawy)
{
    int pi;

    if(lewy<prawy)
    {
        pi = partition(tab, lewy, prawy, wynik);
        sortowanie_szybkie(tab, rozmiar, wynik, lewy, pi-1);
        sortowanie_szybkie(tab, rozmiar, wynik, pi+1, prawy);
    }
}

int partition(int tab[], int lewy, int prawy, sortowanie *wynik)
{
    int pivot = tab[prawy];
    int i = lewy - 1;
    int temp;
    int j;

    for(j=lewy; j<=prawy-1; j++)
    {
        if(tab[j] < pivot)
        {
            i++;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            wynik->przestawienia+=3;
        }
        wynik->porownania+=1;
    }

    temp = tab[i+1];
    tab[i+1] = tab[prawy];
    tab[prawy] = temp;
    wynik->przestawienia+=3;

    return i+1;
}

// polega na porownywaniu elementow oddalonych od siebie
void sortowanie_shella(int tab [], int rozmiar, sortowanie *wyniki)
{
    int i, j, temp;
    int polowa;

    for(polowa = rozmiar / 2; polowa>0; polowa /= 2)
    {
        for(i=polowa; i<rozmiar; i++)
        {
            temp = tab[i];
            wyniki->przestawienia+=1;
            for(j=i; j>polowa; j-=polowa)
            {
                if(temp < tab[j-polowa])
                {
                    wyniki->porownania+=1;
                    tab[j] = tab[j-polowa];
                    wyniki->przestawienia+=1;
                }
                else
                {
                    wyniki->porownania+=1;
                    break;
                }
                tab[j] = temp;
                wyniki->przestawienia+=1;
            }
        }
    }
}






// wybieramy najwieksza wartosc z tablicy
int maximum(int tab[], int k, sortowanie *wyniki)
{
    int max = tab[0];
    wyniki->przestawienia+=1;
    for (int i = 1; i < k; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
            wyniki->przestawienia+=1;
        }
        wyniki->porownania+=1;
    }
    return max;
}

// sortowanie przez zliczanie
void SortowanieZliczanie(int tab[], int k, sortowanie *wyniki)
{
    int i;

    // szukamy najwiekszej wartosci w tablicy
    int max = maximum(tab, k, wyniki);

    // tworzymy tablice zlicz do zliczania ilosci wystapien kazdej wartosci
    int* zlicz = malloc((max + 1) * sizeof(int));
    // tworzymy tablice wynik do przechowywania posortowanych wartosci
    int* wynik = malloc((k+1) * sizeof(int));

    // wypelniamy tablice zlicz zerami
    for (i = 0; i <= max; i++)
    {
        zlicz[i] = 0;
        wyniki->przestawienia+=1;
    }

    // zliczamy ilosc wystapien kazdej wartosci
    // indeks tablicy zlicz odpowiada wartosci w tablicy tab
    for(i=0; i<k; i++)
    {
        zlicz[tab[i]]++;
        wyniki->przestawienia+=1;
    }

    // sumujemy ilosc wystapien kazdej wartosci
    for(i=1; i<=max; i++)
    {
        zlicz[i] += zlicz[i-1];
        wyniki->przestawienia+=1;
    }

    // buduje tablice wynik
    for(i=k-1; i>=0; i--)
    {
        wynik[zlicz[tab[i]]-1] = tab[i];
        zlicz[tab[i]]--;
        wyniki->przestawienia+=2;
    }

    // przepisuje posortowane wartosci do tablicy tab
    for(i=0; i<k; i++)
    {
        tab[i] = wynik[i];
        wyniki->przestawienia+=1;
    }

    free(zlicz);
    free(wynik);
}