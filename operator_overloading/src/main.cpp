#include <iostream>

struct Vector2 {
	float x, y;

	Vector2(float x, float y) : x(x), y(y) {}

	// Overload the '+' operator
	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}
};

int main() {
	// Instantiate two Vector2 objects
	Vector2 a(1, 2);
	Vector2 b(3, 4);
	std::cout << "Vector2 object 1: " << a.x << ", " << a.y << std::endl
			  << "Vector2 object 2: " << b.x << ", " << b.y << std::endl;

	// Add Vector2 objects using overloaded '+' operator
	Vector2 c = a + b;
	std::cout << "Vector2 object 1 + 2: " << c.x << ", " << c.y << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}