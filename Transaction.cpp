# include <iostream>
# include "String.h"
# include "Transaction.h"

Transaction::Transaction
(__int64 _id, __int64 _amount, String _date) :
	id{ _id },
	amount{ _amount },
	date{ _date }
{}

std::ostream& operator<< (std::ostream& OUT, const Transaction& ts)
{
	OUT << "Id: " << ts.id << std::endl
		<< "Amount: " << ts.amount << std::endl
		<< "Date: " << ts.date << std::endl;
	return OUT;
}
