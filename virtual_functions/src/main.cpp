#include <iostream>
#include <string>

class Printable {
public:
	// This is a pure virtual function or interface which
	// must be overwritten in child classes
	virtual std::string GetClassName() = 0;
};

class Entity : public Printable{
public:
	// Set method as virtual so it can be overrode in child classes
	virtual std::string GetName() { return "Entity!"; };

	// Override pure virtual function in parent class
	std::string GetClassName() override { return "Entity!"; };
};

class Player : public Entity {
private:
	std::string m_Name;

public:
	Player(const std::string& Name)
		: m_Name(Name) // Member initialiser list
	{ };

	// Mark method with override to show it is overridden. Not required
	// if method is set as virtual in parent class but shows developer 
	// the method is overwritten.
	std::string GetName() override { 
		return m_Name;
	};

	// Override function in parent class
	std::string GetClassName() override { return "Player!"; };
};

int main() {
	// Virtual function heading
	std::cout << "Virtual Functions" << std::endl;

	// Instantiate entity object and print result of GetName
	Entity* e = new Entity;
	std::cout << e->GetName() << std::endl;

	// Instantiate player object and print result of GetName
	Player* p = new Player("Player!");
	std::cout << p->GetName() << std::endl;

	// Assign player object to Entity pointer.
	// Prints "Entity!" if GetName() functon in Entity parent class is
	// not set as a virtual function. Prints "Player!" if GetName()
	// function is set as virtual in Entity parent class
	Entity* e1 = p;
	std::cout << e1->GetName() << std::endl;

	// Pure virtual function heading
	std::cout << "Pure Virtual Functions" << std::endl;

	// Print result of GetClassName
	std::cout << e->GetClassName() << std::endl;

	// Print result of GetClassName
	std::cout << p->GetClassName() << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}