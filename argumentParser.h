#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include "constants.h"
#include "callsMaker.h"
#include <string.h>


int parseArguments (int argc, char *argv[], struct options &programOptions);

/*!
    \brief Gets cnt first arguments from argumentsToParse and puts them into argumentsToPut
    \param[in] argumentsToParse - pointer to characters to parse
    \param[in] length - length of argumentsToParse
    \param[in] cnt - number of characters to be parsed
    \param[out] argumentsToPut - where to put parsed arguments
    \return returns amount of unparsed characters
*/
int parseNArgs (char *argumentsToParse[], int length, int cnt, char *argumentsToPut[]);

int getParsedArguments (double *a, double *b, double *c, char *arguments[3], int info);
bool checkIfDouble (double *variable, char *str);
#endif
