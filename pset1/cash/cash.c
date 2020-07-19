#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <stdarg.h> //necessary when dealing with variadic functions -> those in which an undeterminate amount of arguments are passed

void sub(int *pcents, int *pcoins, int val);

void givec(int *pcents, int *pcoins, int howMany, ...);

int main(void)

{
    float input;
    int cents, coins;

    do
    {
        input = get_float("How much change are you owed?\n"); //get change
        cents = round(input * 100); //get cents
        coins = 0;
        int *pcents = &cents; //pointers
        int *pcoins = &coins;
        givec(pcents, pcoins, 4, 25, 10, 5, 1);
        //passes as arguments the pointers and the values of the coins which will then be substracted from the total amount of change

        printf("%d\n", coins);

    }

    while (!(input > 0)); //checks correct change input
}

void sub(int *pcents, int *pcoins, int val) //substract an individual value of the change left, as many times as doable
{
    while (*pcents >= val)
    {
        *pcents = *pcents - val;
        *pcoins = *pcoins + 1;

    }

    return;
}


void givec(int *pcents, int *pcoins, int howMany, ...)
{
    va_list ap; //argument pointer

    va_start(ap, howMany); //iterates through arguments starting from "howMany"
    for (int i = 0; i < howMany; i++)
    {
        sub(pcents, pcoins, va_arg(ap, int)); //passes each value to function sub
    }
    va_end(ap);

    return;

}
