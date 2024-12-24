#include <iostream>

int main() {
	// The auto keyword tells the compiler to automatically determine the type
	// of a variable
	int a = 3;
	auto b = a;
	std::cout << "Type of variable automatically determined using auto" << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}