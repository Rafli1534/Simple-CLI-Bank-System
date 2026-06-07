# include <iostream>
# include "String.h"
# include "Person.h"

Person::Person(String _name, unsigned int _age, __int64 _id) :
	name{ _name },
	age{ _age },
	id{ _id }
{
	if (age < 14)
		throw std::invalid_argument("USER IS YOUNGER 14 YERS");
}

std::ostream& operator<< (std::ostream& OUT, const Person& p)
{
	OUT << "Name: " << p.name 
		<< " | Age: " << p.age 
		<< " | Id: " << p.id << std::endl;
	return OUT;
}