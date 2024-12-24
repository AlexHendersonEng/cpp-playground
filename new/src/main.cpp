#include <iostream>
#include <string>

class Entity {
private: 
	std::string m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const std::string& name) : m_Name(name) {}

	const std::string& GetName() const { return m_Name;  }
};

int main() {
	// The new keyword is used to allocate data on the heap
	int a = 2;
	int* b = new int;
	*b = 2;
	std::cout << "Integer allocated on the stack: " << a << std::endl
			  << "Integer allocated on the heap: " << *b << std::endl;

	// Using the new keyword to instantiate an object will allocate object data 
	// on the heap and call the constructor
	Entity* entity = new Entity("Entity!");
	std::cout << "Entity allocated on the heap: " << entity->GetName() 
		      << std::endl;

	// Any memory allocated using the new keyword must be freed using the
	// delete keyword to free the memory on the heap. This will also call the
	// class destructor if the data was an object.
	delete b, entity;

	// The new keyword can also be used to allocate arrays which must be freed
	// using the delete[] keyword.

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}