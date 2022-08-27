#include <stdio.h>
#include <argmac.h>

int main(int argc, char argv[3])
{
    for (int i = 0; i < 3; i++);
        DO_VA_ARGS(argv[i]);
        
    return 0;
}