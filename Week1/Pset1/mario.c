#include <stdio.h>
#include <cs50.h>
void print_pyramid(int n, int h);
int pyramid_height(void);
int main (void)
{
    //ask the user the height of the pyramid;
    int height = pyramid_height();
    //build the pyramid
    for (int i = 1; i <= height; i++)
    {
        print_pyramid(i, height);
    }
}
//This funcion print a row of the pyramid. row 1 get  # #, row 2 gets two ## ##
void print_pyramid(int n, int h)
{
    for(int j=0; j<(h-n); j++)
    {
        printf(" ");
    }
    for (int i=0; i< n; i++)
    {

        printf ("#");
    }
    printf (" ");
    for (int i=0; i< n; i++)
    {
        printf ("#");
    }
    printf("\n");
}

// Function that asks for the height. The height muss to be between 0 and 8;

int pyramid_height(void)
{
    int height;
    do
    {
    height = get_int("Height: ");
    } while (height > 8 || height < 1);
    return height;
}