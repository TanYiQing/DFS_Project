#ifndef FUNCTION1_H
#define FUNCTION1_H

#ifdef FUNCTION1_EXPORTS  // Defined when building the DLL
#define FUNCTION1_API __declspec(dllexport)
#else  // Defined when using the DLL
#define FUNCTION1_API __declspec(dllimport)
#endif

#include <iostream>

// Example function declaration that will be exported
extern "C" {
    FUNCTION1_API void function_from_function1();
    FUNCTION1_API int add(int a, int b);
}

#endif // FUNCTION1_H
