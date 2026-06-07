# include <iostream>
# include "String.h"
# include "Account.h"
# include "CreditAccount.h"

CreditAccount::CreditAccount
(
	__int64 _id,
	__int64 _balance,
	unsigned __int64 _limit,
	unsigned __int64 _debtRate
) : 
	Account(_id, _balance),
	limit{ _limit },
	debtRate{ _debtRate }
{
	if (this->balance < -(__int64)limit)
		throw std::invalid_argument("BALANCE CANNOT EXCEED CREDIT LIMIT");
}

__int64 CreditAccount::calcInterest()
{
	if (this->balance < 0)
		return (this->balance * debtRate) / 100;
	return 0;
}

std::ostream& operator<< (std::ostream& OUT, const CreditAccount& cac)
{
	OUT << "Id: " << cac.id << std::endl
		<< " | Balance: " << cac.balance << std::endl
		<< " | Credit Limit: " << cac.limit << std::endl
		<< " | Debt Rate: " << cac.debtRate << '%' << std::endl
		<< " | Blocked: " << std::boolalpha << cac.blocked
		<< std::endl;
	return OUT;
}