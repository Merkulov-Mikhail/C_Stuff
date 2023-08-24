#include "callsMaker.h"
#include "solver.h"
#include "constants.h"
#include "defaultFunctions.h"
#include "argumentParser.h"
#include "parameter.h"
#include "test.h"
#include "structs.h"
#include <stdlib.h>

/*!
  \file
  \brief Cool program to solve quadratic equations
  \date 20.08.2023 - 23.08.2023
*/


int main (int argc, char *argv[])
{
    struct options programOptions;

    int status = parseArguments (argc, argv, programOptions);

    if (status == PARSER_RESULTS::WRONG_NUMBER_OF_ARGUMENTS)
    {
        printf ("Incorrect number of arguments: required 3\n");
        return PROGRAM_RESULTS::ERROR_WITH_ARGUMENTS;
    }
    if (status == PARSER_RESULTS::UNKNOWN_ARGUMENT){
       return PROGRAM_RESULTS::ERROR_WITH_ARGUMENTS;
    }

    // runs with --help/-h flag
    if (programOptions.help)
    {
        callHelp();
        return 0;
    }
    // runs tests, if --test/-t argument was passed
    if (programOptions.tests){
        return callTests();
    }

    // if --no-info/-ni flag wasn't found, prints extra info
    if (programOptions.info)
    {
        greetings();
    }

    double a = NAN, b = NAN, c = NAN;
    if (!programOptions.have_args){
        // if there is no --arguments/-ar flag, asks user for a, b, c
        if (getAllParameterValues (&a, &b, &c, programOptions.info) != 3)
        {
            printf ("Incorrect user input\n");
            return PROGRAM_RESULTS::INCORRECT_USER_INPUT;
        }
    }
    else
    {
        // if there is --arguments/-ar flag, implements X, Y, Z as a, b, c for the equation
        int stat = getParsedArguments (&a, &b, &c, programOptions.arguments, programOptions.info);
        if (stat)
            return stat;

    }
    double x1 = NAN, x2 = NAN;
    // number of roots, that equation has
    int nRoots = solveSquare (a, b, c, &x1, &x2);
    return printResult (nRoots, x1, x2, programOptions.info);
}
