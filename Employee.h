#pragma once

# include <iostream>
# include "String.h"
# include "Person.h"

class Employee : public Person
{
protected:
	size_t salary;
	String position; 

public:
	Employee
	(
		String _name,
		size_t _age,
		__int64 _id,
		size_t _salary,
		String _position
	);

	friend std::ostream& operator<< (std::ostream& OUT, const Employee& em);

	inline String getName() const { return this->name; }
	inline size_t getAge() const { return this->age; }
	inline __int64 getId() const { return this->id; }
	inline size_t getSalary() const { return this->salary; }
	inline String getPosition() const { return this->position; }
};
