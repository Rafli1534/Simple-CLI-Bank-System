#pragma once

# include <iostream>
# include "Array.h"
# include "Client.h"
# include "Employee.h"
# include "Payment.h"
# include "Transfer.h"

class Bank
{
private:
	Array <Client*> clients;
	Array <Employee*> employers;
	int counter; // account counter

public:
	Bank
	(
		Array <Client*> _clients,
		Array <Employee*> _employers
	);

	// Employer abilities
		void addClient(Client* client);
		void removeClient(Client* client);
		bool findClient(Client* client) const;
		void block(Client* client, const size_t& account_index);
		void unblock(Client* client, const size_t& account_index);

	// Client abilities
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
		void openAccount(Client* user, int type);
		void closeAccount(Client* user, Account* acc);
		void transaction(Transfer* tf);
		void transaction(Payment* pm);

	Employee* findEmployee(__int64 _id) const;
	Client* findClientById(__int64 _id) const;

	size_t getClientsCount() const;
	size_t getEmployeesCount() const;
	Client* getClientAt(size_t index) const;
	Employee* getEmployeeAt(size_t index) const;
};
