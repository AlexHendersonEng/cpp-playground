#include <iostream>

int main() {
	// Define double variable
	double a = 5.25;
	std::cout << "Variable of type double, a: " << a << std::endl;

	// Implicit cast
	int b = a; // double implicitly casted to an int
	std::cout << "Variable a implictly casted to int, b: " << b << std::endl;

	// Explicit C style cast
	int c = (int)a; // double explicitly casted to an int
	std::cout << "Variable a explicitly C style casted to int, c: "
		      << c << std::endl;

	// Explicit C++ style cast
	int d = static_cast<int>(a);
	std::cout << "Variable a explicitly C++ style casted to int, d: "
			  << d << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}