#pragma once

# include <iostream>
# include "String.h"

class Transaction
{
protected:
	__int64 id;
	__int64 amount;
	String date;

public:
	Transaction(__int64 _id, __int64 _amount, String _date);

	virtual void execute() = 0;

	friend std::ostream& operator<< (std::ostream& OUT, const Transaction& ts);
};
