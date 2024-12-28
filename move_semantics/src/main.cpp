#include <iostream>

// Move semantics in general allow us to move data into another object rather
// than copying it which would cause memory allocations.

// String class
class String {
public:
	// Default compiler generated constructor
	String() = default;
	
	// C style char array constructor
	String(const char* string) {
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	// Copy constructor
	String(const String& other) {
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	// rvalue only constructor
	String(String&& other) noexcept {
		printf("Moved!\n");

		// Steal data
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		// Handle left over object
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	// Assignment operator
	String& operator=(String&& other) noexcept {
		printf("Moved!\n");

		if (this != &other) {
			// Delete current object data
			delete[] m_Data;

			// Steal data
			m_Size = other.m_Size;
			m_Data = other.m_Data;

			// Handle left over object
			other.m_Size = 0;
			other.m_Data = nullptr;
		}

		// Return current object
		return *this;
	}

	// Destrutor
	~String() {
		printf("Destroyed!\n");
		delete m_Data;
	}

	// Print string
	void Print() {
		for (uint32_t i = 0; i < m_Size; i++) {
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}
private:
	char* m_Data;
	uint32_t m_Size;
};

// Entity class
class Entity {
public:
	// Entity copy constructor
	Entity(const String& name) : m_Name(name) { }

	// Entity rvalue constructor
	Entity(String&& name) : m_Name(std::move(name)) { }

	// Print Entity name
	void PrintName() {
		m_Name.Print();
	}
private:
	String m_Name;
};

int main() {
	// Create Entity instance and print name
	std::cout << "Creating Entity object instance without any String object"
		<< " memory allocations:" << std::endl;
	Entity entity(String("Entity!"));
	entity.PrintName();
	std::cout << std::endl;

	// Create String object by moving data from one String object to
	// the new String object
	std::cout << "Creating a String by moving data from another String object"
		<< std::endl;
	String source = "Hello";
	String dest(std::move(source));
	std::cout << "dest: ";
	dest.Print();
	std::cout << std::endl;

	// Move data from one String object to another String object
	std::cout << "Move data from one String object to another String object"
		<< std::endl;
	String source1 = "Hello";
	String dest1;
	dest1 = std::move(source1);
	std::cout << "dest1: ";
	dest1.Print();

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}