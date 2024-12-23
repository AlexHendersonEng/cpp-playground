#include <iostream>

class Entity {
public:
	mutable bool flag = false; // mutable keyword allows flag variable to be
							   // changed in const method
private:
	int m_X, m_Y;
public:
	int GetX() const // The const keyword stops any member variables being 
		             // modified in this member function
	{
		flag = true; // Can be changed in const method because of mutable
					 // keyord in defintion
		return m_X;
	}
};

int main() {
	// Define const variable that will not be changed it is 'constant'
	const int a = 20;
	std::cout << "const variable: " << a << std::endl;

	// Syntax difference between const pointer and const variable
	int b = 20;
	const int* c = &b; // Data being stored at the pointers memory address
					   // is const
	int* const d = &b; // The pointer value is const
	const int* const e = &b; // Both the data being pointed to and pointer
						     // value are const
	std::cout << "Data at pointer address is const: " << *c << std::endl;
	std::cout << "Pointer address is const: " << *d << std::endl;
	std::cout << "Data and pointer address is const: " << *e << std::endl;

	// Instantiate entity object and get x variable
	Entity entity = Entity();
	std::cout << "Entity class GetX method cannot modify class: "
		      << entity.GetX() << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}