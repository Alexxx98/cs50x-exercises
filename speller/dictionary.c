// Implements a dictionary's functionality

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
#define BUCKETS (26 * 26)

const unsigned int N = BUCKETS;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *new = malloc(sizeof(node));

    char* wordcpy = NULL;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        wordcpy += (char) tolower(word[i]);
    }

    new = table[index];
    if (new == NULL)
    {
        return false;
    }

    while (new != NULL)
    {
        if (strcmp(new->word, wordcpy) == 0)
        {
            return true;
        }

        new = new->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hash_code = 0;
    for (int i = 0; i < 2; i++)
    {
        if (word[i] == '\0')
        {
            break;
        }

        if (i == 0)
        {
            hash_code += (tolower(word[0]) - 'a') * 26;
        }
        else
        {
            hash_code += (tolower(word[i]) - 'a');
        }
    }
    if (strlen(word) > 1)
    {
        return hash_code + 1;
    }
    return hash_code;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *ptr = fopen(dictionary, "r");
    char buffer[LENGTH + 1];
    while (fscanf(ptr, "%s", buffer) == 1)
    {
        int index = hash(buffer);
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }

        for (int i = 0, n = strlen(buffer); i < n; i++)
        {
            new->word[i] = buffer[i];
        }
        new->next = table[index];

        table[index] = new;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
