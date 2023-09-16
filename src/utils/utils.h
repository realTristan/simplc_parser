#ifndef UTILS_H
#define UTILS_H

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
int is_int(char *s);
int is_int_char(char c);

/**
 * @brief Checks if a character is a digit.
 *
 * @param s The string to check.
 * @return true If the character is a digit.
 * @return false If the character is not a digit.
 */
int is_alpha(char *s);
int is_alpha_char(char c);

/**
 * Check if the character is a whitespace character.
 * @return int
 */
int is_whitespace(char c);

/**
 * @brief Splits a string by a delimiter.
 *
 * @param s The string to split.
 * @param delim The delimiter to split by.
 * @return string* The array of strings from the split.
 */
str_array_t split_str(char *s, char delim);

#endif // UTILS_H