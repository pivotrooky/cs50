#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    long input;
    int s2 = 0, s4 = 0, s6 = 0, s8 = 0, s10 = 0, s12 = 0, s14 = 0, s16 = 0;
    //Falta definir arrays de dígitos y los productos y sus sumas

    input = get_long("What's your credit card number?\n"); //get card number

     
    int d2 = (input % 100) / 10;
    int d4 = (input % 10000) / 1000;
    int d6 = (input % 1000000) / 100000;
    int d8 = (input % 100000000) / 10000000;
    int d10 = (input % 10000000000) / 1000000000;
    int d12 = (input % 1000000000000) / 100000000000;
    int d14 = (input % 100000000000000) / 10000000000000;
    int d16 = (input % 10000000000000000) / 1000000000000000;

    if (d2 >= 5)
    {
        s2 = 2 * d2;
        s2 = (s2 % 10) + ((s2 % 100) / 10);  
    }  
    else
    {  
        s2 = 2 * d2;
    }

    if (d4 >= 5)
    {
        s4 = 2 * d4;
        s4 = (s4 % 10) + ((s4 % 100) / 10);  
    }  
    else
    {  
        s4 = 2 * d4;
    }

    if (d6 >= 5)
    {
        s6 = 2 * d6;
        s6 = (s6 % 10) + ((s6 % 100) / 10);  
    }  
    else
    {  
        s6 = 2 * d6;
    }

    if (d8 >= 5)
    {
        s8 = 2 * d8;
        s8 = (s8 % 10) + ((s8 % 100) / 10);  
    }  
    else
    {  
        s8 = 2 * d8;
    }

    if (d10 >= 5)
    {
        s10 = 2 * d10;
        s10 = (s10 % 10) + ((s10 % 100) / 10);  
    }  
    else
    {  
        s10 = 2 * d10;
    }

    if (s12 >= 5)
    {
        s12 = 2 * d12;
        s12 = (s12 % 10) + ((s12 % 100) / 10);  
    }  
    else
    {  
        s12 = 2 * d12;
    }

    if (d14 >= 5)
    {
        s14 = 2 * d14;
        s14 = (s14 % 10) + ((s14 % 100) / 10);  
    }  
    else
    {  
        s14 = 2 * d14;
    }

    if (d16 >= 5)
    {
        s16 = 2 * d16;
        s16 = (s16 % 10) + ((s16 % 100) / 10);  
    }  
    else
    {  
        s16 = 2 * d16;
    }

    int sum_a = s2 + s4 + s6 + s8 + s10 + s12 + s4 + s16;

    int d1 = input % 10;
    int d3 = (input % 1000) / 100;
    int d5 = (input % 100000) / 10000;
    int d7 = (input % 10000000) / 1000000;
    int d9 = (input % 1000000000) / 100000000;
    int d11 = (input % 100000000000) / 10000000000;
    int d13 = (input % 10000000000000) / 1000000000000;
    int d15 = (input % 1000000000000000) / 100000000000000;
    
    int sum_b = d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;

    int sum = sum_a + sum_b;
    
    printf("%d\n", d1);
    printf("%d\n", d2);
    printf("%d\n", d3);
    printf("%d\n", d4);
    printf("%d\n", d5);
    printf("%d\n", d6);
    printf("%d\n", d7);
    printf("%d\n", d8);
    printf("%d\n", d9);
    printf("%d\n", d10);
    printf("%d\n", d11);
    printf("%d\n", d12);
    printf("%d\n", d13);
    printf("%d\n", d14);
    printf("%d\n", d15);
    printf("%d\n\n", d16);

    printf("%d\n", s2);
    printf("%d\n", s4);
    printf("%d\n", s6);
    printf("%d\n", s8);
    printf("%d\n", s10);
    printf("%d\n", s12);
    printf("%d\n", s14);
    printf("%d\n\n", s16);

    printf("%d\n", sum_a);
    printf("%d\n", sum_b);
    printf("%d\n\n", sum);

    

    if ((sum % 10) == 0)
    {
        if ((d16 == 5) && ((d15 == 1) || ((d15 == 2) || (d15 == 3) || (d15 == 4) || (d15 == 5))))
        {
            printf("MASTERCARD\n");
        }

        else if ((d16 == 0 ) && ((d15 == 3) && ((d14 == 4) || (d13 == 7))))
        {
            printf("MASTERCARd\n");
        }

        else if ((d16 == 4) || (d16 + d15 + d14 == 0) & (d13 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

 }

