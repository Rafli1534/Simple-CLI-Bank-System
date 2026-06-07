#pragma once

# include <iostream>
# include "String.h"
# include "Account.h"
# include "Transaction.h"

class Payment : public Transaction
{
private:
	Account* fromAccount;
	String service; // name of this service

public:
	Payment
	(
		__int64 _id,
		__int64 _amount,
		String _date,
		Account* _from,
		String _service
	);

	void execute();

	friend std::ostream& operator<< (std::ostream& OUT, const Payment& pm);
};
