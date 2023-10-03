// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void no_vowels(string s);
char vowel_to_number(char c);

int main(int argc, string argv[])
{
    // if there's program name
    // and one command-line parameter
    if (argc == 2)
    {
        no_vowels(argv[1]);
    }
    else
    {
        printf("Usage: ./no-vowels word\n");
    }
}

void no_vowels(string s)
{
    // Iterates string length number of times
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        // Checks every character from string
        // and using function below,
        // prints digits instead of vowels
        // but consonants prints in default
        printf("%c", vowel_to_number(s[i]));
    }
    printf("\n");
}

// switches vowels to particular digits
char vowel_to_number(char c)
{
    switch (c)
    {
        case 'a':
            return '6';

        case 'e':
            return '3';

        case 'i':
            return '1';

        case 'o':
            return '0';

        default:
            return c;
    }
}
