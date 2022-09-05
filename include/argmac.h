#ifndef ARGMAC_H
#define ARGMAC_H
// for debugging
#define DO_VA_ARGS_DEBUG 0
int __VA_ARGS__LENGTH;



// create a macro that count the number of arguments
#define COUNT_ARGS_HELPER(N, M, O, ...) N
#define COUNT_ARGS(...) \
    COUNT_ARGS_HELPER(__VA_ARGS__, 2, 1, 0)

#define SET_VA_ARG_LENGTH(...) \
    __VA_ARGS__LENGTH = COUNT_ARGS(__VA_ARGS__)

#define SET_VA_AGRS_AT(I, ...) \
    __VA_ARGS__[I] = __VA_ARGS__

#define GET_VA_AGRS_AT(I, ...) \
    __VA_ARGS__[I]

// Define the macros for the argument list
// and prevent them from being called more than
// once perform the pragmas.

// safe macro
#define DO_VA_ARGS(...)                                  \
    do                                                   \
    {                                                    \
        for (int i = 0; i < __VA_ARGS__LENGTH; i++)      \
        {                                                \
            __VA_ARGS__LENGTH = COUNT_ARGS(__VA_ARGS__); \
            SET_VA_ARG_LENGTH(__VA_ARGS__LENGTH);              \
        }                                                \
    } while (0)

#endif // ARGMAC_H
