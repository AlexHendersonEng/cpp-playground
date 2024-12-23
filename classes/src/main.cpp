#include <iostream>

// NOTE:
// The only difference between a class and struct is
// that a class has it's members private by default
// whereas a struct has it's members public by default

// Parent class definition
class Parent {
	public:
		const char* name = "Parent class member";
};

// Log class definition
class Log : public Parent {
	public:
		const int LogLevelError = 0;
		const int LogLevelWarning = 1;
		const int LogLevelInfo = 2;

	private:
		int m_LogLevel;

	public:
		Log() 
			: m_LogLevel(LogLevelInfo) // Class member initialiser list
		{ }

		Log(int LogLevel) {
			m_LogLevel = LogLevel;
		}

		~Log() {
			std::cout << "Destroyed Log object instance!" << std::endl;
		}

		void SetLevel(int level) {
			m_LogLevel = level;
		}

		void Error(const char* message) {
			if (m_LogLevel >= LogLevelError)
				std::cout << "[ERROR]: " << message << std::endl;
		}

		void Warn(const char* message) {
			if (m_LogLevel >= LogLevelWarning)
				std::cout << "[WARNING]: " << message << std::endl;
		}

		void Info(const char* message) {
			if (m_LogLevel >= LogLevelInfo)
				std::cout << "[INFO]: " << message << std::endl;
		}
};

// Added function so destructor can be seen being called in standard output
void Function() {
	// Instantiate log class
	Log log;

	// Set logging level and print to log
	log.SetLevel(log.LogLevelInfo);
	log.Error("Error occurred!");
	log.Warn("Consider yourself warned!");
	log.Info("For your information!");

	// Access parent class member using inheritance
	std::cout << log.name << std::endl;
}

int main() {
	// Call function
	Function();

	// Wait for user input to not close debug window instantly
	std::cin.get();
}