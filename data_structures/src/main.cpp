#include <iostream>
#include "data_structures.h"

int main() {
	// Create Array object
	std::cout << "Array data structure:" << std::endl;
	Array<int, 5> data;

	// Populate array with data
	for (size_t i = 0; i < data.Size(); i++)
		data[i] = (int)i;

	// Print array data
	for (size_t i = 0; i < data.Size(); i++)
		std::cout << data[i] << std::endl;
	std::cout << std::endl;

	// Create vector object
	std::cout << "Vector data structure:" << std::endl;
	Vector<std::string> vector;

	// Populate vector with data
	vector.PushBack("Hello");
	vector.PushBack("World!");

	// Print vector data
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;
	std::cout << std::endl;
}