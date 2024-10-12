#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    
    while(1)
    {
        printf("1. Dodawanie\n");
        printf("2. Odejmowanie\n");
        printf("3. Mnozenie\n");
        printf("4. Dzielenie\n");
        printf("5. Wyjscie\n");
        printf("Wybierz dzialanie: ");
        scanf("%d", &choice);
        
        if(choice == 5)
        {
            break;
        }
        
        int a, b;
        printf("Podaj a: ");
        scanf("%d", &a);
        printf("Podaj b: ");
        scanf("%d", &b);
        
        switch(choice)
        {
            case 1:
                printf("Wynik: %d\n", a + b);
                break;
            case 2:
                printf("Wynik: %d\n", a - b);
                break;
            case 3:
                printf("Wynik: %d\n", a * b);
                break;
            case 4:
                if(b == 0)
                {
                    printf("Nie mozna dzielic przez 0\n");
                }
                else
                {
                    printf("Wynik: %d\n", a / b);
                }
                break;
            default:
                printf("Niepoprawny wybor\n");
        }
    }

}
