#pragma once
# include <iostream>
# include "String.h"

class Person
{
protected:
	String name;
	unsigned int age;
	__int64 id;

public:
	Person(String _name, unsigned int _age, __int64 _id);

	friend std::ostream& operator<< (std::ostream& OUT, const Person& p);
};
