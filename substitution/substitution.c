#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool key_validation(string s);
void encryption(string text, string key);

int main(int argc, string argv[])
{
    // Check if key is valid
    string key;
    if (argc == 2 && key_validation(argv[1]))
    {
        key = argv[1];
    }
    else if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Prompt for plaintext input
    string plaintext = get_string("plaintext: ");

    // Encrypt and print cyphertext
    encryption(plaintext, key);

}

bool key_validation(string s)
{
    int al = 26;
    char result[al];
    for (int i = 0; i < al; i++)
    {

        // Checks if character is a letter
        if (islower(s[i]) || isupper(s[i]))
        {
            for (int j = 0; j < al; j++)
            {

                //Checks if letter is unique
                if (s[i] == result[j])
                {
                    return false;
                }
            }
            result[i] = s[i];
        }
        else
        {
            return false;
        }
    }
    return true;
}

void encryption(string text, string key)
{
    // Create array with all uppercase alphabet letters
    int al = 26;
    char alphabet[26];
    char letter = 'A';
    for (int i = 0; i < al; i++)
    {
        alphabet[i] = letter + i;
    }

    // Begin of the output
    printf("ciphertext: ");

    // Iterates through all characters from text (plaintext) string
    for (int i = 0, l = strlen(text); i < l; i++)
    {

        // checks if character is a letter
        if (islower(text[i]) || isupper(text[i]))
        {

            // Iterates through all letters in alphabet
            for (int j = 0; j < al; j++)
            {

                // if text character matches 'j' position
                // of uppercase alphabet letter
                if (text[i] == alphabet[j])
                {

                    // print key character on 'j' position
                    printf("%c", toupper(key[j]));
                }

                // same as above, but for lowercase
                else if (text[i] == tolower(alphabet[j]))
                {
                    printf("%c", tolower(key[j]));
                }
            }
        }
        else
        {

            //if character is not a letter, print plain one
            printf("%c", text[i]);
        }
    }
    printf("\n");
}