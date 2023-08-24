#include "argumentParser.h"
#include "defaultFunctions.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>


/*!
    \brief
    \param[in] argc -> number
    \param[in]
    \param[in]
    \param[in]
    \param[in]
*/
int parseArguments (int argc, char *argv[], struct options &programOptions)
{
    for (int i = 1; i < argc; i++)
    {
        char *current_option = argv[i];

        if (!strcmp (current_option, "--no-info") || !strcmp (current_option, "-ni"))
        {
            programOptions.info = 0;
        }

        else if (!strcmp (current_option, "--arguments") || !strcmp (current_option, "-ar"))
        {
            /*
                argv + i + 1    => pointer to the first element of arrayToParse
                argc - i - 1    => number of remaining to parse arguments
                3               => number of arguments to get parsed
                arguments       => array of arguments to be put after parsing
            */
            int res = parseNArgs (argv + i + 1, argc - i - 1, 3, programOptions.arguments);
            if (res == 0)
                programOptions.have_args = 1;
            else
                return PARSER_RESULTS::WRONG_NUMBER_OF_ARGUMENTS;
            i += 3;
        }
        else if (!strcmp (current_option, "--tests") || !strcmp (current_option, "-t"))
        {
            programOptions.tests = 1;
        }
        else if (!strcmp (current_option, "--help") || !strcmp (current_option, "-h"))
        {
            programOptions.help = 1;
        }
        else
        {
            printf ("Unknown argument %s", current_option);
            return PARSER_RESULTS::UNKNOWN_ARGUMENT;
        }
    }
    return PARSER_RESULTS::OK;
}


int parseNArgs (char *argumentsToParse[], int length, int cnt, char *argumentsToPut[])
{
    int startCnt = cnt;
    while (length && cnt)
    {
        argumentsToPut[startCnt - cnt] = argumentsToParse[startCnt - cnt];
        length--;
        cnt--;
    }
    return cnt;
}


int getParsedArguments (double *a, double *b, double *c, char *arguments[3], int info)
{
    if (checkIfDouble (a, arguments[0])){
        callError (info);
        return PROGRAM_RESULTS::INCORRECT_USER_INPUT;
    }

    if (checkIfDouble (b, arguments[1])){
        callError (info);
        return PROGRAM_RESULTS::INCORRECT_USER_INPUT;
    }

    if (checkIfDouble (c, arguments[2])){
        callError (info);
        return PROGRAM_RESULTS::INCORRECT_USER_INPUT;
    }
    return 0;
}


bool checkIfDouble (double *variable, char *str){
    errno = 0;
    char *ptr = nullptr;
    *variable = strtod (str, &ptr);
    if (isErrnoSet() || ptr == str){
        return 1;
    }
    return 0;
}
