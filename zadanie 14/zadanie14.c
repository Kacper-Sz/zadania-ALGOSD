#include <stdio.h>

#include "funkcje.h"

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("------------------------------------\n");
        printf("nastepna operacja: \n");
        printf("1 - wyswietl zawartosc listy\n");
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
                break;
        }
    }

    return 0;
}