#include <iostream>

class Entity {
private:
	float x, y;

public:
	Entity(float x, float y) : x(x), y(y) { }
	float GetX() { return x; }
	float GetY() { return y; }
	
	// Define a function which is friend which allows it access and change
	// private members of the Entity class.
	friend void ChangeX(Entity& entity, float x) {
		entity.x = x;
	}
};


int main() {
	// Instantiate entity object and change x
	Entity entity(1.0f, 2.0f);
	ChangeX(entity, 2.4f);
	std::cout << "Entity: " << entity.GetX() << ", " << entity.GetY()
		      << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}