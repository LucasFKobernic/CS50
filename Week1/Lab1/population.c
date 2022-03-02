#include <cs50.h>
#include <stdio.h>

int start_population(void);
int end_population(int start_pop);
int calculo_years(int start_pop, int end_pop);

int main(void)
{
    //Prompt for start size
    int start_pop = start_population();


    //Prompt for end size
    int end_pop = end_population (start_pop);
    // TODO: Calculate number of years until we reach threshold
    int years = calculo_years(start_pop, end_pop);



    // TODO: Print number of years
    //printf("Start size: %i\n",start_pop);
    //printf("End size: %i\n",end_pop);
    printf("Years: %i\n", years);
}

int start_population(void)
{
   int population_size;
    do {
        population_size= get_int ("Start size: ");
    }
    while (population_size<9);
    return population_size;
}

int end_population (int start_value)
{
    int end_value;
    do
    {
        end_value = get_int ("End size: ");
    }
    while (end_value <= start_value);
    return end_value;

}

int calculo_years(int start_pop, int end_pop)
{
    int population = start_pop;
    int years=0;
    do{
        population = population + (population/3)-(population/4);
        years++;
    }
    while (population < end_pop);
    return years;
}