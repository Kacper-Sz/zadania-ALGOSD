#include <stdio.h>

#include "funkcje.h"

int main()
{
    int choice, wartosc;
    drzewo root1 = NULL;
    drzewo root2 = NULL;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");
        printf("1 - wyswietl drzewa\n");
        printf("2 - dodaj element do drzewa 1\n");
        printf("3 - dodaj element do drzewa 2\n");
        printf("4 - czy drzewa maja takie same elemnty\n\n");
        printf("0 - wyjdz\n\n");

        printf("twoj wybor: ");
        scanf("%d", &choice);
        printf("------------------------------------\n");
        printf("\n");

        if(choice == 0)
        {
            break;
        }
        
        switch(choice)
        {
            case 1:
            {
                // drukuje drzewo
                printf("Drzewo 1:\n");
                DrukujDrzewo(root1);
                printf("\n\nDrzewo 2:\n");
                DrukujDrzewo(root2);
                break;
            }
            case 2:
            {
                // dodaje element do drzewa 1
                printf("Podaj wartosc: ");
                scanf("%d", &wartosc);
                if(root1 == NULL)
                {
                    DodajElement(&root1, wartosc, NULL);
                }
                else
                {
                    DodajElement(&root1, wartosc, root1);
                }
                break;
            }
            case 3:
            {
                // dodaje element do drzewa 2
                printf("Podaj wartosc: ");
                scanf("%d", &wartosc);
                if(root2 == NULL)
                {
                    DodajElement(&root2, wartosc, NULL);
                }
                else
                {
                    DodajElement(&root2, wartosc, root2);
                }
                break;
            }
            case 4:
            {
                // sprawdza czy drzewa maja takie same elementy
                if(CzyTakieSame(root1, root2))
                {
                    printf("Drzewa maja takie same elementy\n");
                }
                else
                {
                    printf("Drzewa nie maja takich samych elementow\n");
                }
                break;
            }
        }
    }

    return 0;
}