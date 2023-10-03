#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // a_len variable stands for alphabet length
    int a_len = 26;
    char letters[a_len];
    char letter = 'A';
    // This for loop creates array
    // of all uppercase letters in alphabet
    for (int i = 0; i < a_len; i++)
    {
        letters[i] = letter + i;
    }

    int sum = 0;
    // This for loop iterates word length number of times
    for (int i = 0, l = strlen(word); i < l; i++)
    {
        // This nested loop checks if character from word string in uppercase
        // matches character from letters array (which is the alphabet)
        // and adds value from POINTS array,
        // corresponding to index of letters array,
        // to the total sum
        for (int j = 0; j < a_len; j++)
        {

            if (toupper(word[i]) == letters[j])
            {
                sum += POINTS[j];
            }
        }
    }
    return sum;
}

