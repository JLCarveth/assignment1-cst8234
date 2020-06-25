/*
Module that offers a variety of functions for string/char formatting

    Author:
        John L. Carveth <jlcarveth@gmail.com>
*/
#include <stdlib.h>

// Returns a char array containing n entries of c
char * repeatChar (char c, int n) {
    char *result = malloc(n);

    for (int i=0; i < n; i++) {
        result[i] = c;
    }
    return result;
}