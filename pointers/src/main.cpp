#include <iostream>

int main() {
	// Define integer variable
	int a = 4;

	// Pointers on the stack
	int* b = &a;
	std::cout << "Stack pointer: " << b
		<< ", Stack pointer value: " << *b
		<< std::endl;

	// Pointers on the heap
	int* c = new int;
	memset(c, a, sizeof(int));
	std::cout << "Heap pointer: " << c
		<< ", Heap pointer value: " << *c
		<< std::endl;

	// Pointers to pointers
	int** d = &b;
	std::cout << "Pointer to stack pointer: " << d
		<< ", Stack pointer: " << *d
		<< ", Stack pointer value: " << **d
		<< std::endl;

	// Wait for user input to not close debug window instantly
	std::cin.get();
}