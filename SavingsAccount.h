#pragma once

# include <iostream>
# include "String.h"
# include "Account.h"

class SavingsAccount : public Account
{
private:
	__int16 interestRate;

public:
	SavingsAccount(__int64 _id, size_t _balance, __int64 _interestRate);

	virtual __int64 calcInterest() override;
	
	friend std::ostream& operator<< (std::ostream& OUT, const SavingsAccount& sac);
};
