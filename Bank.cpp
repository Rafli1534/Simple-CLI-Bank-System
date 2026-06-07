# include <iostream>
# include "Array.h"
# include "Account.h"
# include "DebitAccount.h"
# include "SavingsAccount.h"
# include "CreditAccount.h"
# include "Client.h"
# include "Employee.h"
# include "Payment.h"
# include "Transfer.h"
# include "Bank.h"

Bank::Bank
(
	Array <Client*> _clients,
	Array <Employee*> _employers
) :
	clients{ _clients },
	employers{ _employers },
	counter{ 0 }
{}

void Bank::addClient(Client* client)
{
	if (this->clients.find(client) != true)
		this->clients.add(client);
	else throw std::invalid_argument("CANNOT ADD TWO SIMILAR CLIENTS");
}

void Bank::removeClient(Client* client)
{
	if (this->clients.find(client) == true)
		this->clients.remove(client);
	else throw std::invalid_argument("THERE IS NO SUCH CLIENT");
}

bool Bank::findClient(Client* client) const
{
	return this->clients.find(client);
}

void Bank::block(Client* client, const size_t& account_index)
{
	if (this->clients.find(client) == true) {
		Account* acc = client->getAccount(account_index);
		if (acc != nullptr)
			acc->block();
		else throw std::invalid_argument("NO SUCH ACCOUNT");
	}
	else throw std::invalid_argument("THERE IS NO SUCH CLIENT");
}

void Bank::unblock(Client* client, const size_t& account_index)
{
	if (this->clients.find(client) == true) {
		Account* acc = client->getAccount(account_index);
		if (acc != nullptr)
			acc->unblock();
		else throw std::invalid_argument("NO SUCH ACCOUNT");
	}
	else throw std::invalid_argument("THERE IS NO SUCH CLIENT");
}

/*
	Type - means type of account:
	1. Debit Account
	2. Savings Account
	3. Credit Account
	else: std::invalid_argument()
	===============================
	!!! IMPORTANT !!!
		When u r creating an account, starter
		balances, rates and others are 0
*/
void Bank::openAccount(Client* user, int type)
{
	Account* acc;
	switch (type)
	{
	case 1:
		acc = new DebitAccount(this->counter++, 0);
		break;

	case 2:
		acc = new SavingsAccount(this->counter++, 0, 0);
		break;

	case 3:
		acc = new CreditAccount(this->counter++, 0, 0, 0);
		break;

	default:
		throw std::invalid_argument("NO SUCH TYPE OF ACCOUNT");
		break;
	}

	user->addAccount(acc);
}

void Bank::closeAccount(Client* user, Account* acc)
{
	if (this->clients.find(user) == true)
		user->removeAccount(acc);
	else throw std::invalid_argument("NO SUCH USER IN BANK SYSTEM");
}

void Bank::transaction(Transfer* tf) { tf->execute(); }

void Bank::transaction(Payment* pm) { pm->execute(); }

Employee* Bank::findEmployee(__int64 _id) const
{
	for (size_t i = 0; i < employers.getSize(); i++)
		if (employers[i]->getId() == _id)
			return employers[i];
	return nullptr;
}

Client* Bank::findClientById(__int64 _id) const
{
	for (size_t i = 0; i < clients.getSize(); i++)
		if (clients[i]->getId() == _id)
			return clients[i];
	return nullptr;
}

size_t Bank::getClientsCount() const
{
	return this->clients.getSize();
}

size_t Bank::getEmployeesCount() const
{
	return this->employers.getSize();
}

Client* Bank::getClientAt(size_t index) const
{
	if (index >= this->clients.getSize())
		throw std::out_of_range("CLIENT INDEX OUT OF RANGE");
	return this->clients[index];
}

Employee* Bank::getEmployeeAt(size_t index) const
{
	if (index >= this->employers.getSize())
		throw std::out_of_range("EMPLOYEE INDEX OUT OF RANGE");
	return this->employers[index];
}
