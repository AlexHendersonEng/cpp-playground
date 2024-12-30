#include <iostream>
#include <bitset>

int main() {
	// Initialise variables
	unsigned int a = 7; // 0111
	unsigned int b = 5; // 0101

	// Bit shift a variable
	std::cout << "Variable a: " << std::bitset<4>(a) << std::endl;
	std::cout << "Variable a >> 2: " << std::bitset<4>(a >> 2)
		<< std::endl; // 0001
	std::cout << "Variable a << 2: " << std::bitset<4>(a << 2)
		<< std::endl; // 1100

	// Bitwise operations
	std::cout << "Variable ~a: " << std::bitset<4>(~a) << std::endl; // 1000
	std::cout << "Variable a & b: " << std::bitset<4>(a & b) << std::endl; // 0101
	std::cout << "Variable a | b: " << std::bitset<4>(a | b) << std::endl; // 0111
	std::cout << "Variable a ^ b: " << std::bitset<4>(a ^ b) << std::endl; // 0010

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}