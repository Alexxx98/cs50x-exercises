#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void convert_to_bytes(string m);

int main(void)
{
    // TODO
    // get message from input
    string msg = get_string("Message: ");

    // Output bulbs
    convert_to_bytes(msg);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void convert_to_bytes(string m)
{
    int n = strlen(m);
    int numbers[n];
    // Convert string characters to ASCII numbers
    for (int i = 0; i < n; i++)
    {
        numbers[i] = (int) m[i];
    }

    int bit_digit = 2;
    int bit_power = 7;
    // Iterates through number of bytes
    for (int i = 0; i < n; i++)
    {
        // Loop will iterates 8 number of times,
        // same as amount of bits in one byte,
        // From last to first bit from right side
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {

            if ((numbers[i] - pow(bit_digit, bit_power)) >= 0)
            {
                numbers[i] -= pow(bit_digit, bit_power);
                bit_power--;
                print_bulb(1);
            }
            else
            {
                bit_power--;
                print_bulb(0);
            }
        }
        bit_power = 7;
        // Separates bytes
        printf("\n");
    }
}
