#pragma once

# include <iostream>
# include "String.h"
# include "Account.h"

class CreditAccount : public Account
{
private:
	unsigned __int64 limit; // credit limit
	unsigned __int64 debtRate;

public:
	CreditAccount
	(
		__int64 _id,
		__int64 _balance,
		unsigned __int64 _limit,
		unsigned __int64 _debtRate
	);

	virtual __int64 calcInterest() override;
	
	friend std::ostream& operator<< (std::ostream& OUT, const CreditAccount& cac);
};
