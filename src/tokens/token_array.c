#ifndef TOKEN_ARRAY_H
#define TOKEN_ARRAY_H

#include "token.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief A dynamic array of tokens.
 */
typedef struct token_array_t
{
    token_t *items;
    int size;
} token_array_t;

// Function prototypes
void push_back_token(token_array_t *token_array, token_t token);
token_array_t *new_token_array();
void print_token_array(token_array_t *token_array);

/**
 * @brief Pushes a token to the back of a token array.
 *
 * @param token_array The token array.
 * @param token The token to push.
 * @return void
 */
void push_back_token(token_array_t *token_array, token_t token)
{
    // Add the new token to the end of the new token array
    token_array->items[token_array->size] = token;

    // Update the token size
    token_array->size++;
}

/**
 * @brief Makes a token array.
 *
 * @return token_tArray The token array.
 */
token_array_t *new_token_array()
{
    // Create the token array
    token_array_t *token_array = malloc(sizeof(token_array_t));
    token_array->size = 0;
    token_array->items = malloc(sizeof(token_t));

    // Return the token array
    return token_array;
}

/**
 * @brief Prints a token array.
 *
 * @param token_array The token array.
 * @return void
 */
void print_token_array(token_array_t *token_array)
{
    // Print the token array
    for (int i = 0; i < token_array->size; i++)
    {
        printf("Token (%d): [%s]\n", token_array->items[i].type, token_array->items[i].value);
    }
}

#endif // TOKEN_ARRAY_H