#include <math.h>
#include <cs50.h>
#include <stdio.h>

int digit(int n);
int main(void)
{
    
    long input;

    input = get_long("What's your credit card number?\n"); //get card number
     
    int d2 = (input % 100) / 10; //get every other digit
    int d4 = (input % 10000) / 1000;
    int d6 = (input % 1000000) / 100000;
    int d8 = (input % 100000000) / 10000000;
    int d10 = (input % 10000000000) / 1000000000;
    int d12 = (input % 1000000000000) / 100000000000;
    int d14 = (input % 100000000000000) / 10000000000000;
    int d16 = (input % 10000000000000000) / 1000000000000000;

    int s2 = digit(2 * d2); //get products and the sum of their digits
    int s4 = digit(2 * d4);
    int s6 = digit(2 * d6);
    int s8 = digit(2 * d8);
    int s10 = digit(2 * d10);
    int s12 = digit(2 * d12);
    int s14 = digit(2 * d14);
    int s16 = digit(2 * d16);

    int sum_a = s2 + s4 + s6 + s8 + s10 + s12 + s14 + s16;

    int d1 = input % 10; //get remaining digits
    int d3 = (input % 1000) / 100;
    int d5 = (input % 100000) / 10000;
    int d7 = (input % 10000000) / 1000000;
    int d9 = (input % 1000000000) / 100000000;
    int d11 = (input % 100000000000) / 10000000000;
    int d13 = (input % 10000000000000) / 1000000000000;
    int d15 = (input % 1000000000000000) / 100000000000000;
    
    int sum_b = d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;

    int sum = sum_a + sum_b;

    if ((sum % 10) == 0) //check sum, then determine brand
    {
        if ((d16 == 5) && ((d15 == 1) || ((d15 == 2) || (d15 == 3) || (d15 == 4) || (d15 == 5)))) 
            // checks digits from 16 since it doesn't know where to start, is it Mastercard?
        {
            printf("MASTERCARD\n");
        }

        else if ((d16 == 0) && ((d15 == 3) && ((d14 == 4) || (d14 == 7)))) //is it AMEX?
        {
            printf("AMEX\n");
        }

        else if ((d16 == 4) || (d16 + d15 + d14 == 0) & (d13 == 4)) //is it VISA?
        {
            printf("VISA\n");
        }
        else //in this case, the last digit of the sum being 0 may be random
        {
            printf("INVALID\n"); 
        }
    }

    else
    {
        printf("INVALID\n"); //last digit of the sum isn't zero so doesn't qualify
    }

}

int digit(int n) //to distinguish between single digit and double digit products
{   
    int r;
    if (n >= 10)
    {
        r = (n % 10) + ((n % 100) / 10);  
    }  
    else
    {
        r = n;
    }
        
    return r;
}

