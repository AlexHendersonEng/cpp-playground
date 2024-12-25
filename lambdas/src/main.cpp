#include <iostream>

int main() {
	// Define lambda function (value1 is passed in, value 2 is captured)
	int value2 = 3;
	auto lambda = [&value2](int value1) { std::cout << "Value 1: " << value1 
													<< ", Value 2: "<< value2
													<< std::endl; };

	// Call lambda function
	lambda(1);

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}