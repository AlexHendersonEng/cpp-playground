#include <iostream>

template<typename T>
class Container {
private:
    T* data;
    size_t size;

public:
    // Constructor
    Container(size_t size) : size(size) {
        data = new T[size];
    }

    // Destructor
    ~Container() {
        delete[] data;
    }

    // Overload subscript operator
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    // Get size
    size_t getSize() const {
        return size;
    }

    // Nested Iterator class
    class Iterator {
    private:
        T* ptr;

    public:
        // Constructor
        Iterator(T* ptr) : ptr(ptr) {}

        // Dereference operator
        T& operator*() {
            return *ptr;
        }

        // Pre-increment operator
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality operator
        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        // Inequality operator
        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Begin and End methods
    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + size);
    }
};

int main() {
    // Instantiate container class
    Container<int> container(5);

    // Populate container
    for (size_t i = 0; i < container.getSize(); ++i)
        container[i] = static_cast<int>(i * 10);

    // Use the iterator to traverse
    for (auto i : container)
        std::cout << i << " ";
    std::cout << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}