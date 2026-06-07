# include <iostream>
# include <initializer_list>
# include <stdexcept>
# include "String.h"
# include "Array.h"
# include "Account.h"

template class Array<Account*>;
template class Array<String>;
template class Array<int>;
template class Array<double>;

class Client;
class Employee;

template class Array<Client*>;
template class Array<Employee*>;

template <typename T> Array<T>::Array(const std::initializer_list<T>& list) :
	size{ list.size() },
	capacity{ list.size() + 10 },
	arr{ new T[list.size() + 10] }
{
	size_t index = 0;
	for (const T& el : list)
		this->arr[index++] = el;
}

template <typename T> Array<T>::Array() :
	capacity{ 10 },
	size{ 0 },
	arr{ new T[10] }
{}

template <typename T> Array<T>::Array(const Array& other) :
	capacity{ other.capacity },
	size{ other.size },
	arr{ nullptr }
{
	if (other.arr != nullptr && other.size > 0) 
	{
		this->arr = new T[capacity];
		for (size_t i = 0; i < size; i++)
			this->arr[i] = other.arr[i];
	}

	else 
	{
		this->capacity = 10;
		this->size = 0;
		this->arr = new T[10];
	}
}

template <typename T> Array<T>::~Array()
{
	delete[] arr; 
	arr = nullptr;
}

template <typename T> void Array<T>::add(const T& element)
{
	if (this->arr == nullptr) 
	{
		this->capacity = 10;
		this->size = 0;
		this->arr = new T[this->capacity];
	}

	if (this->capacity == this->size)
	{
		if (this->capacity > std::numeric_limits<size_t>::max() - 10)
			throw std::bad_array_new_length();

		this->capacity += 10;
		T* tmp = new T[this->capacity];
		for (size_t i = 0; i < this->size; i++)
			tmp[i] = this->arr[i];

		delete[] this->arr;
		this->arr = tmp;
	}

	this->arr[this->size++] = element;
}

template <typename T> void Array<T>::remove(size_t index)
{
	if (index >= this->size)
		throw std::invalid_argument("ELEMENT NUMBER CANNOT BE BIGGER THAN ARRAY SIZE");

	for (size_t i = index; i < this->size - 1; i++)
		this->arr[i] = this->arr[i + 1];

	this->size--;
}

template <typename T> void Array<T>::remove(const T& element)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->arr[i] == element)
		{
			for (size_t j = i; j < this->size - 1; j++)
				this->arr[j] = this->arr[j + 1];

			this->size--;
			return;
		}
	}
}

template <typename T> void Array<T>::remove()
{
	if (this->size != 0)
		this->arr[--this->size] = T(); 
	else throw std::out_of_range("ARRAY SIZE IS 0");
}

template <typename T> bool Array<T>::find(const T& element) const
{
	for (size_t i = 0; i < this->size; i++)
		if (this->arr[i] == element)
			return true;
	return false;
}

template <typename T> const T* Array<T>::findEl(const T& element) const
{
	for (size_t i = 0; i < this->size; i++)
		if (this->arr[i] == element)
			return &this->arr[i];
	return nullptr;
}

template <typename T> inline size_t Array<T>::getSize() const { return this->size; }

template <typename T> T& Array<T>::operator[] (size_t index)
{
	if (this->arr == nullptr)
		throw std::runtime_error("ARRAY NOT INITIALIZED");
	if (index >= this->size)
		throw std::out_of_range("INDEX OUT OF RANGE");

	return this->arr[index];
}

template <typename T> const T& Array<T>::operator[] (size_t index) const
{
	if (this->arr == nullptr)
		throw std::runtime_error("ARRAY NOT INITIALIZED");
	if (index >= this->size)
		throw std::out_of_range("INDEX OUT OF RANGE");

	return this->arr[index];
}