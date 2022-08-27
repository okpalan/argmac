#ifndef ARGMAC_H
#define ARGMAC_H
#define DO_VA_ARGS_DEBUG 0

// define DO_PRAGMA to use the _Pragma operator.
#define DO_PRAGMA(x) _Pragma(#x)

// define the argument length

#define _VA_ARGS_LENGTH_(n) #n || 0

// perform the pragmas.
#define DO_ARGS(x)                                 \
    for (int i = 0; i < __VAR_ARGS__LENGTH__; i++) \
    DO_PRAGMA(x)

// Define the macros for the argument list
// and prevent them from being called more than
// once.
#define DO_VA_ARGS__(...) \
    do                    \
    {                     \
        DO_ARGS(DO_ARGS)  \
    } while (0)

#endif // ARGMAC_H