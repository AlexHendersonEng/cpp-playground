#include <iostream>

class Entity {
public:
	int x, y;

	Entity(int x, int y) {
		// The this keyword inside a class member function is a pointer to the
		// current object
		this->x = x;
		this->y = y;
	}
};

int main() {
	// Instantiate Entity object
	Entity entity(1, 2);
	std::cout << "Entity object using the 'this' keyword in the constructor: "
			  << entity.x << ", " << entity.y << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}