#include <iostream>

// Namespaces are used to avoid naming conflicts

// Create namespace
namespace test {
	void print() {
		std::cout << "Hello World!" << std::endl;
	}
}

int main() {
	// Use test namespace print function
	test::print();

	// Use the using keyword to allow use of print function without 
	// explicit namespace declaration
	{
		using namespace test; // Allows print to be called without test:: prefix
		print();
	}

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}