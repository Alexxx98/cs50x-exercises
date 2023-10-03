#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int n);

int main(void)
{
    // TODO: get height of pyramid
    int height = get_height();

    // TODO: print the pyramid
    print_pyramid(height);
}


int get_height(void)
{
    int n;
    // Asks user for input, until condition will be satisfied
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_pyramid(int n)
{
    int counter = 1;
    int hashes = 1;
    int spaces = n - 1;

    // The "n" number is responsible for height of the pyramid, it indicates number of times for loop below will iterate
    for (int i = 0; i < n; i++)
    {
        // Those 2 while loops are responsible for printing first half of pyramid
        while (counter <= spaces)
        {
            printf(" ");
            counter++;
        }
        counter = 1;

        while (counter <= hashes)
        {
            printf("#");
            counter++;
        }
        counter = 1;

        //space between to halfes
        printf("  ");

        // This nested for loop prints hashes for second half of pyramid
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }
        printf("\n");
        hashes++;
        spaces--;
    }
}