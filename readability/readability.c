#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int number_of_letters(string text);
int number_of_words(string text);
int number_of_sentences(string text);
void print_grade(int index);

int main(void)
{
    // prompt input
    string text = get_string("Text: ");

    // get number of letters, words, and sentences
    int letters = number_of_letters(text);
    int words = number_of_words(text);
    int sentences = number_of_sentences(text);

    // Use the Coleman-Liau index
    float L = (float) letters / words * 100.0;
    float S = (float) sentences / words * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // print out the grade
    print_grade(round(index));
}

int number_of_letters(string text)
{
    // craeting array of uppercase alphabet letter
    int a_len = 26;
    char letter = 'A';
    char alphabet[a_len];
    for (int i = 0; i < a_len; i++)
    {
        alphabet[i] = letter + i;
    }

    // Detecting letters (uppercase and lowercase)
    // in text string, and counting them in sum variable
    int sum = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        for (int j = 0; j < a_len; j++)
        {
            if (text[i] == alphabet[j] || text[i] == tolower(alphabet[j]))
            {
                sum += 1;
            }
        }
    }
    return sum;

}

int number_of_words(string text)
{
    // Looking for spaces in text string
    // counting them with sum variable
    int sum = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == ' ')
        {
            sum += 1;
        }
    }
    // incrementing sum is necessary,
    // because there will always be one more space than words in text
    return sum + 1;
}

int number_of_sentences(string text)
{
    // Counting sentences by looking for '.', '!' and '?',
    // which of course always ends a sentence,
    // and incrementing sum, when one is found.
    int sum = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sum += 1;
        }
    }
    return sum;
}

void print_grade(int index)
{
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}