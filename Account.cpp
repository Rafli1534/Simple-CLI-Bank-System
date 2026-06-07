# include <iostream>
# include "String.h"
# include "Account.h"

Account::Account(__int64 _id, __int64 _balance) :
	id{ _id },
	balance{ _balance }
{}

void Account::deposit(size_t amount) { this->balance += amount; }

void Account::withdraw(size_t amount)
{
	if (amount > this->balance)
		throw std::invalid_argument("amount cannot be smaller than balance");
	this->balance -= amount;
}

void Account::block()
{
	if (this->blocked == true)
		throw std::logic_error("ACCOUNT IS ALREADY BLOCKED");
	this->blocked = true;
}

void Account::unblock()
{
	if (this->blocked == false)
		throw std::logic_error("ACCOUNT ISNOT BLOCKED");
	this->blocked = false;
}

inline __int64 Account::getId() { return this->id; }
inline long long Account::getBalance() { return this->balance; }
inline bool Account::isBlocked() { return this->blocked; }

std::ostream& operator<< (std::ostream& OUT, const Account& ac)
{
	OUT << "Id: " << ac.id 
		<< " | Balance: " << ac.balance 
		<< " | Is blocked: " << std::boolalpha 
		<< ac.blocked << std::endl;
	return OUT;
}