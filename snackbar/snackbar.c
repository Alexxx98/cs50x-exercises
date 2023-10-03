// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 10

// Menu itmes have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first for items to the menu array
void add_items(void)
{
    string dishes[NUM_ITEMS] = {"burger", "vegan burger", "hot dog", "cheese dog", "fries", "cheese fries", "cold pressed juice", "cold brew", "water", "soda"};
    float costs[NUM_ITEMS] = {9.5, 11, 5, 7, 5, 6, 7, 3, 2, 2};

    // Add elements from arrays above to both menu elements
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        menu[i].item = dishes[i];
        menu[i].price = costs[i];
    }
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{


    float price = 0;

    // if item arguments in items, update price variable
    // by appropriate price from menu
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (strcmp(menu[i].item, item) == 0)
        {
            price = menu[i].price;
        }
    }

    // If item not in menu
    if (price == 0)
    {
        printf("Invalid Item!\n");
        return 0;
    }
    return price;
}
