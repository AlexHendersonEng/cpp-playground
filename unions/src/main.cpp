#include <iostream>

// A union is a speical type of class that can only hold one of its
// non-static data members at a time

// Define union
union test {
	int a;
	int b;
};

int main() {
	// Create union
	test u;

	// Change value using member a. Both the a and b member values
	// are the same as they occupy the same memory.
	u.a = 5;
	std::cout << "Union a member value: " << u.a << std::endl;
	std::cout << "Union b member value: " << u.b << std::endl;

	// Change value using member b. Both the a and b member values
	// are the same as they occupy the same memory.
	u.b = 2;
	std::cout << "Union a member value: " << u.a << std::endl;
	std::cout << "Union b member value: " << u.b << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}