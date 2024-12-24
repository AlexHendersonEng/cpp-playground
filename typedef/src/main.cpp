#include <iostream>

int main() {
	// The typedef keyword allows an alias name to be used for some other name
	typedef int* ptr; // ptr now represent an integer pointer
	int a = 4;
	ptr b = &a;
	std::cout << "Using typdef keyword to implement alias" << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}