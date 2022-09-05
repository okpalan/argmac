#include <stdio.h>
#include "argmac.h"
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("no args\n");
        return 0;
    }
    SET_VA_ARG_LENGTH(argc);
    DO_VA_ARGS(
        printf("%s\n", GET_VA_AGRS_AT(i, argv));
    );
    
    return 0;
}
