#ifndef UTILS_C
#define UTILS_C

#include <string.h>
#include <stdlib.h>

/**
 * @brief String type
 */
typedef char *string;

/**
 * @brief String array type
 */
typedef struct str_array_t
{
    string *items;
    size_t size;
} str_array_t;

/**
 * @brief Checks if a character is an integer.
 *
 * @param s The string to check.
 * @return true If the character is an integer.
 * @return false If the character is not an integer.
 */
int is_int(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}
int is_int_char(char c)
{
    return c >= '0' && c <= '9';
}

/**
 * @brief Checks if a character is a digit.
 *
 * @param s The string to check.
 * @return true If the character is a digit.
 * @return false If the character is not a digit.
 */
int is_alpha(char *s)
{
    for (unsigned int i = 0; i < strlen(s); i++)
    {
        if ((s[i] < 'a' && s[i] < 'z') || (s[i] < 'A' && s[i] < 'Z'))
        {
            return 0;
        }
    }
    return 1;
}
int is_alpha_char(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * Check if the character is a whitespace character.
 * @return int
 */
int is_whitespace(char c)
{
    return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}

/**
 * @brief Splits a string by a delimiter.
 *
 * @param s The string to split.
 * @param delim The delimiter to split by.
 * @return str_array_t The split string.
 */
str_array_t split_str(char *s, char delim)
{
    // Get the length of the src
    unsigned long len = strlen(s);

    // Create the result array
    str_array_t res = {malloc(sizeof(char *) * len), 0};

    // Store the last index (for determining splits)
    int last_index = 0;

    // Iterate over the string
    for (unsigned int i = 0; i < len; i++)
    {
        // If the current character is the delimiter
        int is_last = (i + 1 == len);
        if (s[i] == delim || is_last)
        {
            // Get the value from the last index to the current index
            char *tmp = malloc(sizeof(char) * (i - last_index + is_last));
            for (unsigned int j = last_index; j < i + is_last; j++)
            {
                if (s[j] == delim)
                    break;
                tmp[j - last_index] = s[j];
            }
            tmp[i - last_index + is_last] = '\0';

            // Add the tmp to the result array
            res.items[res.size] = tmp;

            // Update the last index
            last_index = i + 1;

            // Increment the total split size
            res.size++;
        }
    }

    // Create a copy of the result array with only the correct size
    str_array_t final_res = {malloc(sizeof(char *) * res.size), res.size};
    for (unsigned int i = 0; i < res.size; i++)
    {
        final_res.items[i] = res.items[i];
    }

    // Return the final result
    return final_res;
}

#endif // UTILS_C