# include <iostream>
# include "Account.h"
# include "DebitAccount.h"

DebitAccount::DebitAccount(__int64 _id, size_t _balance) :
	Account(_id, _balance) 
{ 
	if (this->balance < 0) throw std::invalid_argument("BALANCE CANNOT BE UNDER 0");
}

__int64 DebitAccount::calcInterest() { return 0; }

std::ostream& operator<< (std::ostream& OUT, const DebitAccount& dac)
{
	OUT << "Id: " << dac.id
		<< " | Balance: " << dac.balance
		<< " | Blocked: " << std::boolalpha << dac.blocked 
		<< std::endl;
	return OUT;
}