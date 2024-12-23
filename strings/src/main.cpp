#include <iostream>
#include <string>

int main() {
	// Define C style string which implicitly adds null termination character
	// to end of character array represented as 0 or '\0'
	const char* a = "Hello";
	std::cout << "C style string: " << a << std::endl;

	// C++ style string
	std::string b = "Hello";
	std::cout << "C++ style string: " << b << std::endl;

	// Different char types
	std::cout << "Different char types" << std::endl;
	//
	const char* c = u8"Hello";
	const wchar_t* d = L"Hello";
	const char16_t* e = u"Hello";
	const char32_t* f = U"Hello";
	//
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	// Raw string (ignores escape characters)
	const char* g = R"(Hello)";
	std::cout << "Raw string: " << g << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}