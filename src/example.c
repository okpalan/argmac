#include <stdio.h>
#include "argmac.h"

int main(int argc, char argv[])
{
    // set the arguments
    DO_VA_ARGS("hello", "world", "this", "is", "a", "test");
    // print the arguments
    for (int i = 0; i < __VA_ARGS__LENGTH; i++)
    {
        printf("%s", GET_VA_AGRS_AT(i, __VA_ARGS__));
    }
    return 0;
}