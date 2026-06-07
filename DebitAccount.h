#pragma once
# include "Account.h"

class DebitAccount : public Account
{
public:
	DebitAccount(__int64 _id, size_t _balance);

	virtual __int64 calcInterest() override;
	
	friend std::ostream& operator<< (std::ostream& OUT, const DebitAccount& dac);
};