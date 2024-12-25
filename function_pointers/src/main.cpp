#include <iostream>

void Hello(int a) {
	std::cout << "Hello, " << a << std::endl;
}

int main() {
	// Create function pointer
	void(*function)(int a) = Hello;

	// Call function using function pointer
	function(2);

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}