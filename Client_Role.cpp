# include <iostream>
# include "String.h"
# include "Array.h"
# include "Client.h"
# include "Bank.h"
# include "Transfer.h"
# include "Payment.h"

void clientMenu();
void open_ca_c(Bank bank, Client* client); // ca - client account
void close_ca_c(Bank bank, Client* client);
void makeTransaction(Bank bank, Client* client);
void makePayment(Bank bank, Client* client);
void makeTransfer(Bank bank, Client* client);

void client_role(Bank bank)
{
	unsigned __int64 id;
	std::cout << "Write your id: ";
	std::cin >> id;

	Client* client = bank.findClientById(id);
	if (client == nullptr)
	{
		std::cerr << "No such client" << std::endl;
		return;
	}

	clientMenu();
	char cl_choice; std::cin >> cl_choice;

	switch (cl_choice)
	{
	case '0':									break;
	case '1': open_ca_c(bank, client);			break;
	case '2': close_ca_c(bank, client);			break;
	case '3': makeTransaction(bank, client);	break;
	default: std::cerr << "Invalid choice!" << std::endl; break;
	}
}

void clientMenu()
{
	std::cout << "\033[2J\033[H"
		<< "Client Menu: " << std::endl
		<< "\t1. Open Account " << std::endl
		<< "\t2. Close Account " << std::endl
		<< "\t3. Make Transaction " << std::endl
		<< "\t0. Exit" << std::endl
		<< "Your choice: ";
}

void open_ca_c(Bank bank, Client* client)
{
	int type;
	std::cout << "Write account type, client wants: " << std::endl
		<< "\t1. Debit" << std::endl
		<< "\t2. Savings" << std::endl
		<< "\t3. Credit" << std::endl
		<< "Choice: ";
	std::cin >> type;

	try { bank.openAccount(client, type); }
	catch (std::invalid_argument er) { std::cerr << er.what() << std::endl; }
}

void close_ca_c(Bank bank, Client* client)
{
	int index;
	std::cout << "Write Account index: ";
	std::cin >> index;

	if (client->getAccount(index) != nullptr)
	{
		bank.closeAccount(client, client->getAccount(index));
		std::cout << "Account closed successfully!" << std::endl;
	}
	else std::cerr << "No such account index!" << std::endl;
}

void makeTransaction(Bank bank, Client* client)
{
	std::cout << "Types of transaction: Payment/Transfer (1/2): ";
	char type; std::cin >> type;

	switch (type)
	{
	case '1': makePayment(bank, client); break;
	case '2': makeTransfer(bank, client); break;
	default:
		std::cerr << "No such type!" << std::endl;
		break;
	}
}

void makePayment(Bank bank, Client* client)
{
	std::cout << "How much money: ";
	__int64 amount; std::cin >> amount;

	std::cin.ignore();

	std::cout << "Today's date: ";
	String date; std::cin >> date;

	std::cin.ignore();

	std::cout << "Account index (from which account): ";
	size_t index; std::cin >> index;

	if (client->getAccount(index) == nullptr)
	{
		std::cerr << "No such index!" << std::endl;
		return;
	}

	std::cin.ignore();

	std::cout << "To wich service: ";
	String service; std::cin >> service;

	Payment pm
	(
		client->getId(), amount, date,
		client->getAccount(index), service
	);

	pm.execute();
}

void makeTransfer(Bank bank, Client* client)
{
	std::cout << "How much money: ";
	__int64 amount; std::cin >> amount;

	std::cin.ignore();

	std::cout << "Today's date: ";
	String date; std::cin >> date;

	std::cin.ignore();

	std::cout << "Account index (from which account): ";
	size_t index_from; std::cin >> index_from;

	if (client->getAccount(index_from) == nullptr)
	{
		std::cerr << "No such index!" << std::endl;
		return;
	}

	std::cout << "Account index (from which account): ";
	size_t index_to; std::cin >> index_to;

	if (client->getAccount(index_to) == nullptr)
	{
		std::cerr << "No such index!" << std::endl;
		return;
	}

	Transfer tf
	(
		client->getId(), amount, date,
		client->getAccount(index_from),
		client->getAccount(index_to)
	);

	tf.execute();
}
