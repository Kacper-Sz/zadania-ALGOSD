#include <stdio.h>

struct DrzewoB
{
    int klucz;
    struct DrzewoB *lewy;
    struct DrzewoB *prawy;
    struct DrzewoB *rodzic;
};
typedef struct DrzewoB wDrzewoB;
typedef wDrzewoB* drzewo;

void Wypisz(drzewo d,int lvl);
void DrukujDrzewo(drzewo root);

void DodajElement(drzewo *root, int wartosc, drzewo rodzic);
drzewo Minimum(drzewo root);
drzewo Nastepnik(drzewo root);
int CzyTakieSame(drzewo root1, drzewo root2);

