#include <iostream>

// Get externally defined variable
extern int s_var;

// Entity struct
struct Entity {
	// Static class/struct members point to same memory across all class 
	// instances
	static int x, y;

	// Making a class/struct static means it is not passed the class instance
	// by default
	static void Print(Entity e) {
		std::cout << e.x << ", " << e.y << std::endl;
	}
};

// Explicitly initialise Entity x and y variables as static class/struct
// members are not initialised on instantiation
int Entity::x;
int Entity::y;

// Create function with static variable
void Count() {
	static int count = 0; // static variable is persistent through calls to function
	count++;
	std::cout << "Count: " << count << std::endl;
}

int main() {
	// Print out variable (only works if no static keyword in static.cpp)
	std::cout << "Static variables: " << std::endl << s_var << std::endl;

	// Create two entities
	Entity e1; e1.x = 1; e1.y = 2;
	Entity e2; e2.x = 5; e2.y = 6;

	// Print entities position (both are the same as entity 2 updates
	// both entities x and y position as they are static member variables
	// which are shared across all entity instances)
	std::cout << "Static member variables and functions: " << std::endl;
	Entity::Print(e1);
	Entity::Print(e2);

	// Call count function a few times
	std::cout << "Static function variables: " << std::endl;
	for (int i = 0; i < 5; i++) {
		Count();
	}

	// Wait for user input to not close debug window instantly
	std::cin.get();
}