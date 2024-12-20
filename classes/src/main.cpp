#include <iostream>

// NOTE:
// The only difference between a class and struct is
// that a class has it's members private by default
// whereas a struct has it's members public by default

// Log class definition
class Log {
	public:
		const int LogLevelError = 0;
		const int LogLevelWarning = 1;
		const int LogLevelInfo = 2;

	private:
		int m_LogLevel;

	public:
		Log() {
			m_LogLevel = LogLevelInfo;
		}

		Log(int LogLevel) {
			m_LogLevel = LogLevel;
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

int main() {
	// Instantiate log class
	Log log;
	log.SetLevel(log.LogLevelInfo);
	log.Error("Error occurred!");
	log.Warn("Consider yourself warned!");
	log.Info("For your information!");

	// Wait for user input to not close debug window instantly
	std::cin.get();
}