# include <iostream>
# include "String.h"
# include "Account.h"
# include "Transaction.h"
# include "Transfer.h"

Transfer::Transfer
(
	__int64 _id, 
	__int64 _amount, 
	String _date, 
	Account* _from, 
	Account* _to
) :
	Transaction(_id, _amount, _date),
	fromAccount{ _from },
	toAccount{ _to }
{}

void Transfer::execute()
{
	this->fromAccount->withdraw(this->amount);
	this->toAccount->deposit(this->amount);
}

std::ostream& operator<< (std::ostream& OUT, const Transfer& tf)
{
	OUT << "Transfered from: " << *tf.fromAccount
		<< ", to: " << *tf.toAccount << std::endl;
	return OUT;
}
