#ifndef ARGMAC_H
#define ARGMAC_H
// for debugging
#define DO_VA_ARGS_DEBUG 0

// define DO_PRAGMA to use the _Pragma operator.
#define DO_PRAGMA(x) _Pragma(#x)

// define the argument length
#define _VA_ARGS_LENGTH_(n) n || 0

// Define the macros for the argument list
// and prevent them from being called more than
// once perform the pragmas.

// unsafe
#define _DO_VA_ARGS(x)                            \
    for (int i = 0; i < __VA_ARGS__LENGTH__ ; i++) \
    DO_PRAGMA(x)

// safe
#define DO_VA_ARGS__(...)        \
    do                           \
    {                            \
        _DO_VA_ARGS(__VA_ARGS__) \
    } while (0)

#endif // ARGMAC_H