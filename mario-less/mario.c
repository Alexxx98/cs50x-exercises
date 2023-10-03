#include <cs50.h>
#include <stdio.h>

int get_hight(void);
void print_pyramid(int height);

int main(void)
{
    // TODO: get hight of pyramid
    int height = get_hight();

    // TODO: print pyramid
    print_pyramid(height);
}

int get_hight(void)
{
    int height;
    // gets input from user, until while condition will be satisfied
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramid(int height)
{
    int count = 1;
    int hashes = 1;
    int spaces = height - 1;
    // for loop iterate "height" amount of times
    for (int i = 0; i < height; i++)
    {

        // Order of while loops determines the way how # are printed
        // When first while loop print spaces and second while loop prints hashes, it seems like we it prints # from right to left,
        // Especially when amount of spaces decrement and hashes increment after every while loops activity
        // Also setting count variable to 1 each time after while loop finishes its activity, provides possibility to use it again, insted of creating a new one
        while (count <= spaces)
        {
            printf(" ");
            count++;
        }
        count = 1;

        while (count <= hashes)
        {
            printf("#");
            count++;
        }
        printf("\n");
        // After every while loops activity, for loop increment amount of hashes and decrement spaces
        count = 1;
        hashes++;
        spaces--;
    }
}
