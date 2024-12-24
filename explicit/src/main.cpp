#include <iostream>
#include <string>

class Entity {
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name) : m_Name(name), m_Age(-1) {}

	// The explicit keyword forces method to be called explictly and therefore
	// cannot be called through implicit conversion
	explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

int main() {
	// Create entity class using implict construction
	Entity a = std::string("Entity");
	std::cout << "Entity class constructed implicitly" << std::endl;

	// Cannot create entity class using second constructor implicitly due to
	// use of the explicit keyword
	Entity b(10);
	std::cout << "Entity class constructed explicitly" << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}