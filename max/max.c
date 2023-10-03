// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    // max value equal to first element on array
    int max = array[0];

    //Repeat comparing through all elements of array
    for (int i = 0; i < n - 1; i++)
    {
        // if next element is higher, change max value
        // to the higher element
        if (array[i] < array[i + 1])
        {
            max = array[i + 1];
        }
    }
    return max;
}
