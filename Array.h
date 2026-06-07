#pragma once

# include <iostream>
# include <initializer_list>

template <typename T> class Array
{
private:
	size_t capacity = 10;
	size_t size = 0;
	T* arr = nullptr; 

public:
	Array(const std::initializer_list<T>& list);
	Array();
	Array(const Array& other);
	~Array();

	void add(const T& element);
	void remove(size_t index);
	void remove(const T& element);
	void remove();

	bool find(const T& element) const;
	const T* findEl(const T& element) const;

	T& operator[] (size_t index);
	const T& operator[] (size_t index) const;

	inline size_t getSize() const;
};
