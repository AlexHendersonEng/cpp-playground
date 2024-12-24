#include <iostream>
#include <vector>

struct Vertex {
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

int main() {
	// Create a Vertex vector and add elements
	std::vector<Vertex> vertices;
	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 4, 5, 6 });

	// Print vertices
	for (const Vertex& vertex : vertices) {
		std::cout << vertex << std::endl;
	}

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}