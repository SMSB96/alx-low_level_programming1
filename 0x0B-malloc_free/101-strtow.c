#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str == ' ')
            in_word = 0;
        else if (in_word == 0)
        {
            in_word = 1;
            count++;
        }

        str++;
    }

    return count;
}

/**
 * strtow - Splits a string into an array of words.
 * @str: The input string to split.
 *
 * Return: Pointer to the array of words or NULL on failure.
 */
char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int i, j, k, len, word_count;
    char **words;

    len = strlen(str);
    word_count = count_words(str);

    words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    i = 0;
    j = 0;
    while (i < len)
    {
        while (i < len && str[i] == ' ')
            i++;

        k = i;
        while (k < len && str[k] != ' ')
            k++;

        if (k > i)
        {
            int word_length = k - i;
            words[j] = malloc((word_length + 1) * sizeof(char));
            if (words[j] == NULL)
            {
                for (int m = 0; m < j; m++)
                    free(words[m]);
                free(words);
                return NULL;
            }

            strncpy(words[j], &str[i], word_length);
            words[j][word_length] = '\0';
            j++;
        }

        i = k;
    }

    words[j] = NULL;

    return words;
}
