#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	float a = get_float ("Side 1\n");
	float b = get_float ("Side 2\n");
	float c = get_float ("Side 3\n");
	bool valid_triangle(float a, float b, float c);
	if (valid_triangle(a, b, c) == true)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
}

bool valid_triangle (float a, float b, float c)
{
		if ((a > 0) && (b > 0) && (c > 0) && (a < b + c) && (b < a + c) && (c < a + b))
		{
			return true;
		}
		else
		{
			return false;
		}
}