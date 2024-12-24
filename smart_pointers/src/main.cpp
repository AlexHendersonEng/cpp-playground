#include <iostream>
#include <memory>

class Entity {
public:
	Entity() // Constructor 
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity() // Destructor
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print() {
		std::cout << "Hello, I am an Entity." << std::endl;
	}
};

int main() {
	// Create unique pointer which is a type of smart pointer. Cannot be copied
	// hence, it is unique.
	{
		std::cout << "Unique Pointer:" << std::endl;
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();
		entity->Print();
	}

	// Create a shared pointer which is a type of smart pointer. It can be
	// copied and controls memory allocation through reference counting.
	{
		std::cout << "Shared Pointer:" << std::endl;
		std::shared_ptr<Entity> entity = std::make_shared<Entity>();
		std::shared_ptr<Entity> entity1 = entity;
		entity->Print();
	}

	// Create a weak pointer which is a type of smart pointer. It can be
	// copied from a shared pointer but doesn't increase the reference count.
	// Therefore, the underlying memory will be freed when all smart pointer
	// references are out of scope.
	{
		std::cout << "Weak Pointer:" << std::endl;
		std::shared_ptr<Entity> entity = std::make_shared<Entity>();
		std::weak_ptr<Entity> entity1 = entity;
		entity->Print();
	}

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}