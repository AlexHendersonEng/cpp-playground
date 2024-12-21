#include <iostream>
#include <string>

class Entity {
public:
	// Set method as virtual so it can be overrode in child classes
	virtual std::string GetName() { return "Entity!"; };
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
};

int main() {
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

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}