// (C)Copyright 2022 Nnamdi Michael Okpala. All rights reserved.
// # ARGMAC
// ## Argument Macros for C.
// ARGMAC is a header-only library for C that provides macros for argument parsing.
// It is designed to be simple to use and easy to extend when building c command line tools.
// DISCLAIMER: Works only for C99.

#ifndef ARGMAC_H
#define ARGMAC_H
// for debugging
#define DO_VA_ARGS_DEBUG 0
#define __VA_ARGS__LENGTH 0 

// define DO_PRAGMA to use the _Pragma operator.
#define DO_PRAGMA(x) _Pragma(#x)

// create a macro that count the number of arguments
#define COUNT_ARGS_HELPER(N, M, O, ...) N
#define COUNT_ARGS(...) \
    COUNT_ARGS_HELPER(__VA_ARGS__, 2, 1, 0)

#define SET_VA_ARG_LENGTH(...) \
    __VA_ARGS__LENGTH = COUNT_ARGS(__VA_ARGS__)

#define SET_VA_AGRS_AT(I) 
    // fix the syntax below.
    __VA_ARGS__##I = I

#define GET_VA_AGRS_AT(I) \
    __VA_ARGS__##I

// Define the macros for the argument list
// and prevent them from being called more than
// once perform the pragmas.
// unsafe macro
#define DO_VA_ARGS_UNSAFE(...)                        \
    for (int i = 0; i < COUNT_ARGS(__VA_ARGS__); i++) \
    {                                                 \
        DO_PRAGMA(__VA_ARGS__)                        \
        SET_VA_ARG_LENGTH(__VA_ARGS__)

// safe macro
#define DO_VA_ARGS(...)                \
    do                                 \
    {                                  \
        DO_VA_ARGS_UNSAFE(__VA_ARGS__) \
    } while (0)

#endif // ARGMAC_H