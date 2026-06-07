#pragma once
# include <iostream>
# include "Person.h"
# include "Array.h"
# include "Account.h"

class Client : public Person
{
private:
	Array <Account*> accounts;

public:
	Client
	(
		String _name,
		unsigned int _age,
		__int64 _id,
		Array <Account*> _accounts
	);

	Client(String _name, unsigned int _age, __int64 _id);

	void addAccount(Account* ac);
	void removeAccount(Account* ac);
	Account* getAccount(const size_t& index);
	__int64 getId() const;

	friend std::ostream& operator<< (std::ostream& OUT, const Client& c);
};
