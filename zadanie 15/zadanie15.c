#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funkcje.h"

int main()
{
    int choice;
    char wyraz[50];
    drzewo root = NULL;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");
        printf("1 - wyswietl drzewo\n");
        printf("2 - dodaj element\n");
        printf("3 - usun element\n");
        printf("4 - szukaj elementu\n");
        printf("5 - element minimum\n");
        printf("6 - element maksimum\n");
        printf("7 - poprzednik\n");
        printf("8 - nastepnik\n");
        printf("9 - zapis do pliku\n\n");
        printf("10 - odczyt z pliku (kasuje obecne drzewo)\n\n");
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
                printf("\n");
                DrukujDrzewo(root);
                printf("\n");
                break;
            }
            case 2:
            {
                // dodaje element
                printf("\n");
                printf("podaj wyraz ktory chcesz dodac: ");
                scanf("%s", wyraz);
                // nazwa tablicy to adres pierwszego elementu
                if(root == NULL)
                {
                    DodajElement(&root, wyraz, NULL);
                }
                else
                {
                    DodajElement(&root, wyraz, root);
                }
                printf("\n");
                break;
            }
            case 3:
            {
                // usuwa element
                printf("\n");
                printf("podaj wyraz ktory chcesz usunac: ");
                scanf("%s", wyraz);
                UsunElement(&root, wyraz);
                printf("\n");
                break;
            }
            case 4:
            {
                // szuka elementu
                printf("\n");
                printf("podaj wyraz ktory chcesz znalezc: ");
                scanf("%s", wyraz);
                drzewo *znaleziony = SzukajElementu(&root, wyraz);
                if(znaleziony != NULL)
                {
                    printf("znaleziono: %s\n", (*znaleziony)->wyraz);
                }
                else
                {
                    printf("nie znaleziono\n");
                }
                printf("\n");
                break;
            }
            case 5:
            {
                // zwraca minimum
                printf("\n");
                if(root == NULL)
                {
                    printf("Drzewo jest puste\n");
                    break;
                }
                printf("minimum: %s\n", Minimum(root));
                printf("\n");
                break;
            }
            case 6:
            {
                // zwraca maksimum
                printf("\n");
                if (root == NULL)
                {
                    printf("Drzewo jest puste\n");
                    break;
                }
                printf("maksimum: %s\n", Maksimum(root));
                printf("\n");
                break;
            }
            case 7:
            {
                // zwraca poprzednika
                printf("\n");
                if (root == NULL)
                {
                    printf("Drzewo jest puste\n");
                    break;
                }

                printf("podaj wyraz ktory chcesz znalezc: ");
                scanf("%s", wyraz);
                drzewo *znaleziony = SzukajElementu(&root, wyraz);

                if(znaleziony != NULL)
                {
                    drzewo poprzedni = Poprzednik(*znaleziony);
                    if(poprzedni != NULL)
                    {
                        printf("poprzednik: %s\n", poprzedni->wyraz);
                    }
                    else
                    {
                        printf("nie ma poprzednika\n");
                    }
                }
                else
                {
                    printf("nie znaleziono takeigo elemntu\n");
                }
                printf("\n");
                break;
            }
            case 8:
            {
                // zwraca nastepnika
                printf("\n");
                if (root == NULL)
                {
                    printf("Drzewo jest puste\n");
                    break;
                }

                printf("podaj wyraz ktory chcesz znalezc: ");
                scanf("%s", wyraz);
                drzewo *znaleziony = SzukajElementu(&root, wyraz);

                if(znaleziony != NULL)
                {
                    drzewo nastepny = Nastepnik(*znaleziony);
                    if(nastepny != NULL)
                    {
                        printf("nastepnik: %s\n", nastepny->wyraz);
                    }
                    else
                    {
                        printf("nie ma nastepnika\n");
                    }
                }
                else
                {
                    printf("nie znaleziono takeigo elemntu\n");
                }
                printf("\n");
                break;
            }
            case 9:
            {
                // zapisuje drzewo do pliku
                printf("\n");
                int zapis = ZapiszDoPliku(root);
                if(zapis == 0)
                {
                    printf("zapisano do pliku\n");
                }
                else
                {
                    printf("blad zapisu\n");
                }
                printf("\n");
                break;
            }
            case 10:
            {
                // odczytuje drzewo z pliku
                printf("\n");
                root = OdczytajZPliku();
                printf("odczytano z pliku\n");
                printf("\n");
                break;
            }
        }
    }

    return 0;
}