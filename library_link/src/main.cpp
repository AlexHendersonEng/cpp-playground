#include <iostream>
#include "static_library.h"
#include "dynamic_library.h"
#include <windows.h>

// Define type for getting functio handle address in dll
typedef float(__stdcall* MYPROC)(float x, float y);

int main() {
	// Call static library Add function
	std::cout << "Static library Add function output: " << Add(1.2f, 3.4f) << std::endl;

	// Call dynamic library Multiply function
	std::cout << "Dynamic library Multiply function output: " << Multiply(2.8f, 2.0f) << std::endl;

	// Load dll dynamically
	HINSTANCE hinst = LoadLibrary(TEXT("dynamic_library.dll"));

	if (hinst != NULL) {
		// If dll loaded correctly get Multiply function handle
		MYPROC proc = (MYPROC)GetProcAddress(hinst, "Multiply");

		// If function handle retrieved successfully call function
		if (proc != NULL)
			std::cout << "Dynamic library Multiply function output: " << proc(2.4f, 2.0f) << std::endl;

		// Free the dll module
		FreeLibrary(hinst);
	}

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}