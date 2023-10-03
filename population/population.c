#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int start);
int reach_end_size(int start, int end);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_start_size();

    // TODO: Prompt for end size
    int end = get_end_size(start);

    // TODO: Calculate number of years until we reach threshold
    int years = reach_end_size(start, end);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}


int get_start_size(void)
{
    int start;
    // input accepts only numbers equal to or greater than 9, othwerwise function is going to ask for a number again
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    return start;
}

int get_end_size(int start)
{
    int end;
    // end size of population cannot be lesser than start size, so function is going to ask for a number, until condition will be satisfied
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    return end;
}

// function first checks if start size and end size are different (if not, just returns 0) if so, it calcutaes population after llamas born and passed out, and adds one to year variable.
// It does as above, until population (start variable) will be equal to or greater than end size.
int reach_end_size(int start, int end)
{
    int years = 0;
    int born;
    int passed;
    while (start < end)
    {
        born = start / 3;
        passed = start / 4;
        start += born - passed;
        years++;
    }
    return years;
}


