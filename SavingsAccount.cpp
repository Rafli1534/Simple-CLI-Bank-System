# include <iostream>
# include "String.h"
# include "Account.h"
# include "SavingsAccount.h"

SavingsAccount::SavingsAccount(__int64 _id, size_t _balance, __int64 _interestRate) :
	Account(_id, _balance),
	interestRate{ (__int16)_interestRate }
{
	if (this->balance < 0) throw std::invalid_argument("BALANCE CANNOT BE UNDER 0");
}

__int64 SavingsAccount::calcInterest()
{
	return (this->balance * this->interestRate) / 100;
}

std::ostream& operator<< (std::ostream& OUT, const SavingsAccount& sac)
{
	OUT << "Id: " << sac.id << std::endl
		<< " | Balance: " << sac.balance << std::endl
		<< " | Interest Rate: " << sac.interestRate << '%' << std::endl
		<< " | Blocked: " << std::boolalpha << sac.blocked
		<< std::endl;
	return OUT;
}