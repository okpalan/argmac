#include <argmac.h>

int main(int argc, char *argv[])
{
    DO_VA_ARGS__(*argc, *argv);
}