#ifndef CONSTANTS_H
#define CONSTANTS_H

const double PRETTY_LOW = 0.0000001;

enum STATUSES
{
    ZERO_SOLUTIONS      = 0,
    ONE_SOLUTION        = 1,
    TWO_SOLUTIONS       = 2,
    INFINITY_SOLUTIONS  = -1
};

enum PARSER_RESULTS
{
    OK                          = 0,
    WRONG_NUMBER_OF_ARGUMENTS   = 1,
    UNKNOWN_ARGUMENT            = 2
};

enum PROGRAM_RESULTS
{
    END_OF_PROGRAM              =  0,
    ERROR_WITH_ROOTS            = -1,
    INCORRECT_USER_INPUT        = -2,
    TESTS_FAILED                = -3,
    ERROR_WITH_ARGUMENTS        = -4
};
#endif
