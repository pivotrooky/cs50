#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_next_size(int current_population_size); //calculations
int loop_user_prompt(int lower_bound, string text);
//function created in order to avoid duplicating prompt loop and checking logic

int main(void)
{
    int count_years, current_population_size, final_population_size;

    current_population_size = loop_user_prompt(9, "Start size: \n");
    final_population_size = loop_user_prompt(current_population_size, "End size: \n");
    count_years = 0;

    while (current_population_size < final_population_size)
    {
        current_population_size = get_next_size(current_population_size);
        //abstract calculations to keep loop clean
        count_years++;

    }

    printf("Years: %i\n", count_years);
}

int get_next_size(int current_population_size)
{
    //truncs integers so as not to get floats
    current_population_size += trunc(current_population_size / 3) - trunc(current_population_size / 4);
    return current_population_size;
}

int loop_user_prompt(int lower_bound, string text)
{
    int return_value;

    do
    {
        return_value = get_int("%s", text); //asks for population starting size
    }
    while (return_value < lower_bound); //starting size needs to be larger than specified lower

    return return_value;
}