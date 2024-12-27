#include <iostream>

// The RValueFcn function returns an rvalue
int RValueFcn() {
	return 10;
}

// The LValueFcn function returns an lvalue
int& LValueFcn() {
	static int value = 10;
	return value;
}

// The PrintMessage function takes in only an lvalue string. Adding const
// allows for either an lvalue or rvalue to be taken in.
void PrintMessage(/* const */ std::string& message)
{ 
	std::cout << __FUNCTION__ << " lvalue only overload called" << std::endl;
	std::cout << message << std::endl;
}

// The PrintMessage function takes in only an rvalue string
void PrintMessage(std::string&& message)
{
	std::cout << __FUNCTION__ << " rvalue only overload called" << std::endl;
	std::cout << message << std::endl;
}

int main() {
	// Variable a is an lvalue getting assigned the rvalue returned from
	// RValueFcn
	int a = RValueFcn();
	std::cout << "Variable a: " << a << ", is an lvalue being assigned the"
		<< " rvalue from the function RValueFcn()" << std::endl;

	// Variable b is an lvalue being assinged a value from the rvalue a
	int b = a;
	std::cout << "Variable b: " << b << ", is an lvalue being assigned the"
		<< " lvalue a" << std::endl;

	// Function LValueFcn return an lvalue which is being assigned the value 20
	LValueFcn() = 20;
	std::cout << "The LValueFcn function returns an lvalue which is being"
		<< " assigned the rvalue expression 20" << std::endl;

	// The PrintMessage function can take in a lvalue or rvalue
	std::string message = "Hello";
	PrintMessage(message);
	PrintMessage(message + std::string(" World!"));

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}