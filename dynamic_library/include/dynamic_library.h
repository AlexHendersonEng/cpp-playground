#pragma once

// Setup dll importing/exporting
#ifdef DYNAMIC_LIBRARY_EXPORT
#define DYNAMICLIBRARY_API __declspec(dllexport) __stdcall
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

// extern "C" is a linkage specification ensuring C linkage so the compiler does not
// mangle the name so that client C code can link to the function. Required for succesful
// finding of the function in the DLL when using 'LoadLibrary' and 'GetProcAddress'
extern "C" float DYNAMICLIBRARY_API Multiply(float x, float y);
