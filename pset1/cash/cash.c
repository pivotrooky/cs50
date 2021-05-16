#include <math.h>
#include <cs50.h>
#include <stdio.h>

void substract_value_of_coin(int *pointer_cents, int *pointer_coins, int value);

void loop_through_coin_values(int *pointer_cents, int *pointer_coins, int coin_values_size, int coin_values[]);

int main(void)

{
    float input;
    int cents, coins, coin_values_size;

    do
    {
        input = get_float("How much change are you owed?\n"); //get change
        cents = round(input * 100); //get cents
        coins = 0; //counter
        coin_values_size = 4;

        int coin_values[4] = {25, 10, 5, 1};

        int *pointer_cents = &cents; //pointers
        int *pointer_coins = &coins;

        loop_through_coin_values(pointer_cents, pointer_coins, coin_values_size, coin_values);
        //passes the pointers and the values of the coins as arguments, which will then be substracted from the total amount of change

        printf("%d\n", coins);

    }

    while (!(input > 0)); //checks correct change input
}

void substract_value_of_coin(int *pointer_cents, int *pointer_coins, int value) //substract an individual value of the change left, as many times as doable
{
    while (*pointer_cents >= value)
    {
        *pointer_cents = *pointer_cents - value;
        *pointer_coins = *pointer_coins + 1;

    }

    return;
}


void loop_through_coin_values(int *pointer_cents, int *pointer_coins, int coin_values_size, int coin_values[])
{

    //iterates through coin values
    for (int i = 0; i < coin_values_size; i++)
    {
        substract_value_of_coin(pointer_cents, pointer_coins, coin_values[i]); //passes each value to substract function
    }

    return;

}
