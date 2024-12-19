#include <iostream>

int main() {
	// Define integer variable
	int a = 4;

	// Create reference (alias)
	int& ref = a;
	std::cout << "Variable pointer: " << &a
		<< ", Variable value: " << a << std::endl
		<< "Reference pointer: " << &ref
		<< ", Reference value: " << ref << std::endl;

	// Wait for user input to not close debug window instantly
	std::cin.get();
}