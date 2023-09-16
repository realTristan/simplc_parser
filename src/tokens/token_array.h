#ifndef TOKEN_ARRAY_H
#define TOKEN_ARRAY_H

#include "token.h"

/**
 * @brief A dynamic array of tokens.
 */
typedef struct token_array_t
{
    token_t *items;
    int size;
} token_array_t;

/**
 * @brief Pushes a token to the back of a token array.
 *
 * @param token_array The token array.
 * @param token The token to push.
 * @return void
 */
void push_back_token(token_array_t *token_array, token_t token);

/**
 * @brief Makes a token array.
 *
 * @return TokenArray The token array.
 */
token_array_t *new_token_array();

/**
 * @brief Prints a token array.
 *
 * @param token_array The token array.
 * @return void
 */
void print_token_array(token_array_t *token_array);

#endif // TOKEN_ARRAY_H