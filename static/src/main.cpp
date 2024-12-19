#include <iostream>

// Get externally defined variable
extern int s_var;

int main() {
	// Print out variable (only works if no static keyword in static.cpp)
	std::cout << s_var << std::endl;

	// Wait for user input to not close debug window instantly
	std::cin.get();
}