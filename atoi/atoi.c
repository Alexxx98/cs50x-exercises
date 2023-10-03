#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // If there's onl one char left
    if (strlen(input) == 1)
    {
        // return input as integer
        return (int) input[0] - '0';
    }
    else
    {
        // Get last char from input
        char c = input[strlen(input) - 1];

        // Convert it to integer
        int n = c - '0';

        // Subtract the last element of input string
        input[strlen(input) - 1] = '\0';

        // Return previously declared int
        // and add another product of convert function,
        // but this time from shortened string,
        // multiplied by 10 to it
        return n + convert(input) * 10;
    }
}