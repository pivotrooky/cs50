#include <stdio.h>
#include <cs50.h>

int col(int n);

int main(void)
{

    int n = get_int("Enter int");
    printf("%d", col(n));

}

int col(int n)

{   int i = 0;;

    if (n == 1)
    {
        return 0;
    }

    if (n % 2 != 0)
    {
        return 1 + col(1 + (3 * n));
    }

    else
    {
        return 1 + col(n / 2);
    }

    i++;

    return i;
}