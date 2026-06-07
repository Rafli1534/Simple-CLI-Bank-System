# include <iostream>
# include "String.h"
# include "Person.h"
# include "Employee.h"

Employee::Employee
(
	String _name,
	size_t _age,
	__int64 _id,
	size_t _salary,
	String _position
) :
	Person(_name, (unsigned int)_age, _id),
	salary{ _salary },
	position{ _position }
{}

std::ostream& operator<< (std::ostream& OUT, const Employee& em)
{
	OUT << "Name: " << em.name << std::endl
		<< " | Age: " << em.age << std::endl
		<< " | Id: " << em.id << std::endl
		<< " | Salary: " << em.salary << std::endl
		<< " | Position: " << em.position << std::endl;
	return OUT;
}
