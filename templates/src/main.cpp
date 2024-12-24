#include <iostream>
#include <string>

// Create a template Print function which can take in any type and print
template<typename T>
void Print(T message) {
	std::cout << message << std::endl;
}

int main() {
	// Used Print template with multiple types 
	std::cout << "Template generated functions:" << std::endl;
	Print<int>(5);
	Print<std::string>("Hello");
	Print<float>(5.5f);

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}