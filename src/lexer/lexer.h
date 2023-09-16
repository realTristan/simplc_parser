#ifndef LEXER_H
#define LEXER_H

#include "../tokens/token.h"
#include "../tokens/token_array.h"
#include <stdlib.h>

/**
 * @brief Tokenizes a string.
 *
 * @param token_array The tokens array.
 * @param src The string to tokenize.
 * @return void
 */
void tokenize(token_array_t *token_array, char *src);

#endif // LEXER_H