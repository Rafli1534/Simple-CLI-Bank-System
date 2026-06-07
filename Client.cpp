# include <iostream>
# include "String.h"
# include "Person.h"
# include "Client.h"

Client::Client
(
	String _name,
	unsigned int _age,
	__int64 _id,
	Array <Account*> _accounts
) :
	Person(_name, _age, _id),
	accounts{ _accounts }
{}

Client::Client(String _name, unsigned int _age, __int64 _id) :
	Person(_name, _age, _id),
	accounts{ nullptr }
{}

void Client::addAccount(Account* ac) { accounts.add(ac); }

void Client::removeAccount(Account* ac) 
{ 
	for (size_t i = 0; i < accounts.getSize(); i++)
		if (accounts[i] == ac) {
			accounts.remove(i);
			return;
		}
}

Account* Client::getAccount(const size_t& index)
{
	if (index >= accounts.getSize())
		// throw std::out_of_range("ELEMENT NUMBER CANNOT BE BIGGER THAN SIZE");
		return nullptr;

	return accounts[index];
}

__int64 Client::getId() const
{
	return this->id;
}

std::ostream& operator<< (std::ostream& OUT, const Client& c)
{
	OUT << "Name: " << c.name << std::endl
		<< "Age: " << c.age << std::endl
		<< "Id: " << c.id << std::endl
		<< "Accounts: " << std::endl;
	for (size_t i = 0; i < c.accounts.getSize(); i++) 
		OUT << *c.accounts[i] << std::endl; 

	return OUT;
}