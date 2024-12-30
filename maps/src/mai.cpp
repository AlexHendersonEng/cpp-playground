#include <iostream>
#include <map>

int main() {
	// Create a map object
	std::map<std::string, int> map;

	// Add elements to map
	map["one"] = 1;
	map["two"] = 2;
	map["three"] = 3;

	// Print out elements
	for (auto& i : map)
		std::cout << "key: " << i.first << ", value: " << i.second << std::endl;
}