#ifndef FUNCTION2_H
#define FUNCTION2_H

#ifdef FUNCTION2_EXPORTS  // Defined when building the DLL
#define FUNCTION2_API __declspec(dllexport)
#else  // Defined when using the DLL
#define FUNCTION2_API __declspec(dllimport)
#endif

#include <iostream>

// Example function declaration that will be exported
extern "C" {
    FUNCTION2_API void function_from_function2();
    FUNCTION2_API int multiply(int a, int b);
}

#endif // FUNCTION2_H
