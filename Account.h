#pragma once
# include <iostream>
# include "String.h"

class Account
{
protected:
	__int64 id;
	__int64 balance;
	bool blocked = false;

public:
	Account(__int64 _id, __int64 _balance);

	void deposit(size_t amount);
	void withdraw(size_t amount);
	void block();
	void unblock();

	inline __int64 getId();
	inline __int64 getBalance();
	inline bool isBlocked();

	virtual __int64 calcInterest() = 0;
	
	friend std::ostream& operator<< (std::ostream& OUT, const Account& ac);
};
