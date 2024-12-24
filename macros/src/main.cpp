#include <iostream>

// Setup logging macro only called when logging macro enabled
#ifdef LOGGING
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

int main() {
	// Log something using macro
	LOG("Hello");

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}