#pragma once

template<typename T, size_t S>
class Array
{
public:
	constexpr size_t Size() const { return S; }

	T& operator[](size_t index) { return m_Data[index]; }
	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }
private:
	T m_Data[S];
};

template<typename T>
class Vector
{
public:
	Vector() {
		ReAlloc(2);
	}

	void PushBack(const T& value) {
		// If size is greater than capacity re-allocate
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		// Assign data to vector and increment size
		m_Data[m_Size] = value;
		m_Size++;
	}

	T& operator[](size_t index) { return m_Data[index]; }
	const T& operator[](size_t index) const { return m_Data[index]; }

	size_t Size() const { return m_Size; }

private:
	void ReAlloc(size_t newCapacity) {
		// Allocate new block of memory
		T* newBlock = new T[newCapacity];

		// If new capaxity is smaller than old size only copy up to new capacity
		if (newCapacity < m_Size)
			m_Size = newCapacity;

		// Copy/move old elements into new block
		for (size_t i = 0; i < m_Size; i++)
			newBlock[i] = m_Data[i];

		// Delete old data
		delete[] m_Data;

		// Update data and capacity
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

	T* m_Data = nullptr;
	size_t m_Size = 0;
	size_t m_Capacity = 0;
};