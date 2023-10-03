#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Takes input from user
    string name = get_string("What's your name?: ");
    // Prints message with phrase user passed to input above, in place of %s
    printf("Hello, %s\n", name);
}