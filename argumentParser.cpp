#include "argumentParser.h"
#include <string.h>


// [param] argumentsToParse - pointer to characters to parse
// [param] length - amount of characters left in array
// [param] cnt - amount of characters, that we need to parse
// [param] argumentsToPut - where to put parsed arguments
// [retur] returns amount of unparsed characters
int parseNArgs(char *argumentsToParse[], int length, int cnt, char *argumentsToPut[])
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

void parseArguments (int argc, char *argv[], int *info, int *have_args, int *tests, char *arguments[])
{
    for (int i = 1; i < argc; i++)
    {
        char *current_option = argv[i];

        if (!strcmp (current_option, "--no-info") || !strcmp(current_option, "-nf"))
        {
            *info = 0;
        }

        if (!strcmp (current_option, "--arguments") || !strcmp (current_option, "-ar"))
        {
            /*
                argv + i + 1    => pointer to the first element of arrayToParse
                argv[0]         => name of program, so +1 is required
                argc - i - 1    => number of remaining to parse arguments
                argv[0]         => name of program, so -1 is required
                3               => number of arguments to get parsed
                arguments       => array of arguments to be put after parsing
            */
            int res = parseNArgs(argv + i + 1, argc - i - 1, 3, arguments);
            if (res == 0)
            {
                *have_args = 1;
            }
        }
        if (!strcmp (current_option, "--tests") || !strcmp (current_option, "-t"))
        {
            *tests = 1;
        }
    }

}
