#include <cs50.h>
#include <stdio.h>
#include <math.h>

int number_length(long n);
bool check_validation(int length, double number);
void print_card_name(double number, int length);

int main(void)
{
    // TODO: Get input
    long number = get_long("Number: ");

    // TODO: Get length of the number
    int length = number_length(number);

    // TODO: validate the number
    if (check_validation(length, number))
    {
        print_card_name(number, length);
    }
    else
    {
        printf("INVALID\n");
    }
}


int number_length(long n)
{
    // Each time credit card number divides by
    // and it's still greater than 0,
    // count variable (which represents length of the number),
    // increments
    int count = 0;
    do
    {
        n /= 10;
        count++;
    }
    while (n > 0);
    return count;
}

bool check_validation(int length, double number)
{
    int first_sum = 0;
    int second_sum = 0;
    float n;
    int l;
    int r;
    for (int i = 0; i < length; i++)
    {
        // Half of checksum algorythm
        number /= 10;
        n = number * 10 - (long) number * 10;
        first_sum += (int) n;

        // gets rid of unnecessary decimal numbers
        number = floor(number);

        // Second half of checksum algorythm,
        // with numbers multiplied by 2
        number /= 10;
        n = (number * 10 - (long) number * 10) * 2;
        l = number_length(n);

        // If it's 1 digit number, just add it to sum
        if (l == 1)
        {
            second_sum += (int) n;
        }

        // If it's 2 digit number,
        // Use same pattern as with first half of checksum algorythm
        // In this case, it will execute 2 times, once for each digit
        else
        {
            while (l > 0)
            {
                n /= 10;
                r = n * 10 - (int) n * 10;
                second_sum += r;
                l--;
            }
        }
    }

    // If checksum divides by 10 with no remainder, return true
    if ((first_sum + second_sum) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_card_name(double number, int length)
{
    // The point is to get first two digit
    // if the credit card number
    int n;
    while (number > 100)
    {
        number /= 10;
    }

    n = (int) number;

    // Then set conditions for that 2 digit number
    // and also check if number length is accurate
    // for certain card name
    if ((n >= 51 && n <= 55) && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((n == 34 || n == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if ((n >= 40 && n < 50) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}