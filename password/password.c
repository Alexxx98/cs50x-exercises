// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // set all chceckers to false
    bool is_number = false;
    bool is_uppercase = false;
    bool is_lowercase = false;
    bool is_symbol = false;
    // if string character satisfied any condition
    // set that certain checjer variable to true
    for (int i = 0, l = strlen(password); i < l; i++)
    {
        if (isdigit(password[i]))
        {
            is_number = true;
        }
        else if (isupper(password[i]))
        {
            is_uppercase = true;
        }
        else if (islower(password[i]))
        {
            is_lowercase = true;
        }
        else
        {
            is_symbol = true;
        }
    }

    // if every checker variable is true,
    // your password is valid (return true)
    if (is_number && is_uppercase && is_lowercase && is_symbol)
    {
        return true;
    }

    return false;
}





