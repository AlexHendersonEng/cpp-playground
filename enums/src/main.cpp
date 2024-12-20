#include <iostream>

int main() {
	// Define enumeration
	enum LogLevel : int
	{
		Error = 0, Warning = 1, Info = 2
	};

	// Create variable using enumeration
	LogLevel level = LogLevel::Warning;

	// Print message based on variable
	switch (level) {
		case LogLevel::Error: {
			std::cout << "We have an error!" << std::endl;
			break;
		}
		case LogLevel::Warning: {
			std::cout << "We have a warning!" << std::endl;
			break;
		}
		case LogLevel::Info: {
			std::cout << "Here is some info!" << std::endl;
			break;
		}
		default: {
			std::cout << "Default case." << std::endl;
		}
	}

	// Wait for user input to stop debug window closing
	std::cin.get();
}