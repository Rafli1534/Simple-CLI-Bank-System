#pragma once

# include <iostream>
# include "String.h"
# include "Account.h"
# include "Transaction.h"

class Transfer : public Transaction
{
private:
	Account* fromAccount;
	Account* toAccount;

public:
	Transfer
	(
		__int64 _id,
		__int64 _amount,
		String _date,
		Account* _from,
		Account* _to
	);

	virtual void execute() override;

	friend std::ostream& operator<<
	(std::ostream& OUT, const Transfer& tf);
};
