#include <stdio.h>


struct DrzewoB
{
    char klucz[20];
    struct DrzewoB *lewy;
    struct DrzewoB *prawy;
    struct DrzewoB *rodzic;
};
typedef struct DrzewoB wDrzewoB;
typedef wDrzewoB* drzewo;

void StworzWezel(char *wartosc);

void dodajElement(drzewo *korzen, char *wartosc);