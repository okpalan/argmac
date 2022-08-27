#ifndef ARGMAC_H
#define ARGMAC_H
// for debugging
#define DO_VA_ARGS_DEBUG 0
#define _VA_LENGTH_ 0

// define DO_PRAGMA to use the _Pragma operator.
#define DO_PRAGMA(x) _Pragma(#x)

// create a macro that count the number of arguments
#define COUNT_ARGS_HELPER(N, ...) N
#define COUNT_ARGS(...) COUNT_ARGS_HELPER(__VA_ARGS__)

// Define the macros for the argument list
// and prevent them from being called more than
// once perform the pragmas.

// unsafe macro
#define DO_VA_ARGS_UNSAFE(...)                \
    for (int i = 0; i < COUNT_ARGS(...); i++) \
    {                                         \
        DO_PRAGMA(__VA_ARGS__)                \
        _VA_LENGTH_ = i;                      \
    }

// safe macro
#define DO_VA_ARGS(...)                \
    do                                 \
    {                                  \
        DO_VA_ARGS_UNSAFE(__VA_ARGS__) \
    } while (0)

#endif // ARGMAC_H