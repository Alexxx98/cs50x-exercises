#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool key_validation(string s);
void encrypted_msg(string s, int k);

int main(int argc, string argv[])
{
    // Get and validate the key from command-line
    int key;
    if (argc == 2 && key_validation(argv[1]))
    {
        key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // get message
    string msg = get_string("plaintext: ");

    // encrypt message and print it
    encrypted_msg(msg, key);
}

bool key_validation(string s)
{
    // Length of string
    int sl = strlen(s);

    // Converts to integer
    int n;
    n = atoi(s);

    // length of string after using atoi
    int il = 1;
    while (n > 10)
    {
        n /= 10;
        il++;
    }

    // If both length are equal,
    // return true
    if (sl == il)
    {
        return true;
    }
    return false;
}


void encrypted_msg(string s, int k)
{
    // Create alphabet for lowercase
    // and uppercase
    int al = 26;
    char upper_alphabet[al];
    char lower_alphabet[al];
    char letter = 'A';
    for (int i = 0; i < al; i++)
    {
        upper_alphabet[i] = letter + i;
        lower_alphabet[i] = tolower(letter) + i;
    }

    // First part of output
    printf("ciphertext: ");

    // Iterate through amount of characters in the string
    int n;
    for (int i = 0, l = strlen(s); i < l; i++)
    {

        // If character is a letter,
        // proceed to the second loop
        if (islower(s[i]) || isupper(s[i]))
        {

            // Iterate through all letters in the alphabet
            for (int j = 0; j < al; j++)
            {

                // Ckecks if string character matches an uppercase letter
                // on 'j' position
                if (s[i] == upper_alphabet[j])
                {

                    // Check if sum of numbers of key
                    // and position of the letter in the alphabet
                    // is higher than amount of letters in alphabet
                    if ((j + k) >= al)
                    {

                        // determine the position of a letter in the alphabet
                        n = k - (al - j);
                        while (n >= al)
                        {
                            n -= al;
                        }
                        printf("%c", upper_alphabet[n]);
                    }
                    else
                    {
                        printf("%c", upper_alphabet[j + k]);
                    }
                }

                // Almost same code as above,
                // but this time checks if string character matches a lowercase letter
                // on 'j' position
                else if (s[i] == lower_alphabet[j])
                {
                    if ((j + k) >= al)
                    {
                        n = k - (al - j);
                        while (n >= al)
                        {
                            n -= al;
                        }
                        printf("%c", lower_alphabet[n]);
                    }
                    else
                    {
                        printf("%c", lower_alphabet[j + k]);
                    }
                }
            }
        }

        // if a charachter from string is not a letter
        // print it's current form
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}





