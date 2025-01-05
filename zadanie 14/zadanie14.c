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
                DodajElement(&root, wyraz);
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
        }
    }

    return 0;
}