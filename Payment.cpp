# include <iostream>
# include "String.h"
# include "Account.h"
# include "Transaction.h"
# include "Payment.h"

Payment::Payment
(
	__int64 _id,
	__int64 _amount,
	String _date,
	Account* _from,
	String _service
) :
	Transaction(_id, _amount, _date),
	fromAccount{ _from },
	service{ _service }
{}

void Payment::execute()
{
	this->fromAccount->withdraw(this->amount);
}

std::ostream& operator<< (std::ostream& OUT, const Payment& pm)
{
	OUT << "Payment was from: " << *pm.fromAccount
		<< ", to service: \"" << pm.service << '\"'
		<< std::endl;
	return OUT;
}
