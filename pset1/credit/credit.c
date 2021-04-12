#include <math.h>
#include <cs50.h>
#include <stdio.h>

int get_digit_or_sum(int n);
int get_specific_digit(long input, int index);
int process_digit(int num, int index);
void validate(int sum, int digits[]);

int main(void)
{

    long input;
    int digits[16];
    int processed_digits[16];

    input = get_long("What's your credit card number?\n"); //get card number

    //loop through input and get all digits
    for (int i = 0; i < 16; i++)
    {
        digits[i] = get_specific_digit(input, i);
    }

    //loop through and process digits
    for (int i = 0; i < 16; i++)
    {
        processed_digits[i] = process_digit(digits[i], i);
    }

    int sum = processed_digits[0];

    //get sum of all processed digits
    for (int i = 1; i < 16; i++)
    {
        sum += processed_digits[i];
    }

    validate(sum, digits);
}

int get_digit_or_sum(int n) //to distinguish between single digit and double digit products
{
    if (n < 10)
    {
        return n;
    }

    return (n % 10) + ((n % 100) / 10);
}

int get_specific_digit(long input, int index)
{
    return fmod(input, pow(10, index + 1)) / pow(10, index);
}

int process_digit(int num, int index)

{
    //first case: index is even. then, return number as is.
    if (index % 2 == 0)
    {
        return num;
    }

    int num_doubled = num * 2;

    //second case: index is odd and doubling the number results in a single digit. then, double it and return that single digit.
    if (num_doubled < 5)
    {
        return num_doubled;
    }

    //third case: index is odd and doubling the number results in two digits. then, double it, add those digits and return the result.
    return (num_doubled % 10) + ((num_doubled % 100) / 10);
}



void validate(int sum, int digits[])
{
    if ((sum % 10) == 0) //check sum, then determine brand
    {
        if ((digits[15] == 5) && ((digits[14] == 1) || ((digits[14] == 2) || (digits[14] == 3) || (digits[14] == 4) || (digits[14] == 5))))
            // checks digits from 16 since it doesn't know where to start, is it Mastercard?
        {
            printf("MASTERCARD\n");
        }

        else if ((digits[15] == 0) && ((digits[14] == 3) && ((digits[13] == 4) || (digits[13] == 7)))) //is it AMEX?
        {
            printf("AMEX\n");
        }

        else if ((digits[15] == 4) || (digits[15] + digits[14] + digits[13] == 0) & (digits[12] == 4)) //is it VISA?
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