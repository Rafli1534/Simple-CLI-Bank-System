# include <iostream>
# include <climits>
# include <sstream>
# include "String.h"
# include "Array.h"
# include "Employee.h"
# include "Bank.h"

void employeeMenu();
void create_account(Bank bank);
void delete_client(Bank bank);
void find_client(Bank bank);
void block_client(Bank bank);
void unblock_client(Bank bank);
void open_ca(Bank bank); // ca = client account
void close_ca(Bank bank);

void employee_role(Bank bank)
{
	__int64 id;
	std::cout << "Write your id: ";
	std::cin >> id;

	Employee* employer = bank.findEmployee(id);
	if (employer == nullptr)
	{ 
		std::cerr << "No such employer" << std::endl;
		return;
	}

	employeeMenu();
	char em_choice; 
	std::cin >> em_choice;

	switch (em_choice)
	{
	case '0': break;
	case '1': create_account(bank);		break;
	case '2': delete_client(bank);		break;
	case '3': find_client(bank);		break;
	case '4': block_client(bank);		break;
	case '5': unblock_client(bank);		break;
	case '6': open_ca(bank);			break;
	case '7': close_ca(bank);			break;
	default: std::cerr << "Invalid choice!" << std::endl; break;
	}
}

void employeeMenu()
{
	std::cout << "\033[2J\033[H"
		<< "Employer Menu: " << std::endl
		<< "\t1. Add Client " << std::endl
		<< "\t2. Delete Client " << std::endl
		<< "\t3. Find Client " << std::endl
		<< "\t4. Block Client " << std::endl
		<< "\t5. Unblock Client " << std::endl
		<< "\t6. Open Account for Client " << std::endl
		<< "\t7. Close Account for Client " << std::endl
		<< "\t0. Exit" << std::endl
		<< "Your choice: ";
}

void create_account(Bank bank)
{
	srand(time(0));

	std::cin.ignore();

	String name;
	std::cout << "Write clients name: ";
	std::cin >> name;

	unsigned int age;
	std::cout << "Write clients age: ";
	std::cin >> age;

	__int64 max_val = LLONG_MAX;
	unsigned __int64 id = rand() % max_val;

	while (bank.findClientById(id) != nullptr)
		id = rand() % max_val;

	std::cout << "New client ID: " << id << std::endl;

	Client* new_client = new Client(name, age, id);
	bank.addClient(new_client);

	std::cout << "Client successfully created!" << std::endl;
}

void delete_client(Bank bank)
{
	unsigned __int64 id;
	std::cout << "Write client id: ";
	std::cin >> id;
	if (id <= 0)
	{
		std::cerr << "Cannot delete employer from base" << std::endl;
		return;
	}

	Client* client = bank.findClientById(id);

	if (client == nullptr) 
	{ 
		std::cerr << "No such client" << std::endl;
		return;
	}

	bank.removeClient(client);
	std::cout << "Client successfully removed from base!" << std::endl;
}

void find_client(Bank bank)
{
	unsigned __int64 id;
	std::cout << "Write id: ";
	std::cin >> id;

	if (id <= 0)
	{
		std::cerr << "Cannot find employee" << std::endl;
		return;
	}

	Client* client = bank.findClientById(id);
	if (client != nullptr)
		std::cout << *client << std::endl;
	else
	{
		std::cerr << "No such client" << std::endl;
		return;
	}
}

void block_client(Bank bank)
{
	unsigned __int64 id;
	std::cout << "Write id: ";
	std::cin >> id;

	if (id <= 0)
	{
		std::cerr << "Cannot find employee" << std::endl;
		return;
	}

	Client* client = bank.findClientById(id);
	if (client == nullptr)
	{
		std::cerr << "No such client" << std::endl;
		return;
	}
	
	size_t index;
	std::cout << "Write account index: ";
	std::cin >> index;

	if (client->getAccount(index) != nullptr)
	{
		bank.block(client, index);
		std::cout << "Client successfully blocked" << std::endl;
	}
	else std::cerr << "No such client account index!" << std::endl;
}

void unblock_client(Bank bank)
{
	unsigned __int64 id;
	std::cout << "Write id: ";
	std::cin >> id;

	if (id <= 0)
	{
		std::cerr << "Cannot find employee" << std::endl;
		return;
	}

	Client* client = bank.findClientById(id);
	if (client == nullptr)
	{
		std::cerr << "No such client" << std::endl;
		return;
	}

	size_t index;
	std::cout << "Write account index: ";
	std::cin >> index;

	if (client->getAccount(index) != nullptr)
	{
		bank.unblock(client, index);
		std::cout << "Client successfully unblocked" << std::endl;
	}
	else std::cerr << "No such client account index!" << std::endl;
}

void open_ca(Bank bank)
{
	unsigned __int64 id;
	std::cout << "Write id: ";
	std::cin >> id;

	if (id <= 0)
	{
		std::cerr << "Cannot find employee" << std::endl;
		return;
	}

	Client* client = bank.findClientById(id);
	if (client != nullptr)
		std::cout << *client << std::endl;
	else
	{
		std::cerr << "No such client" << std::endl;
		return;
	}

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

void close_ca(Bank bank)
{
	unsigned __int64 id;
	std::cout << "Write id: ";
	std::cin >> id;

	if (id <= 0)
	{
		std::cerr << "Cannot find employee" << std::endl;
		return;
	}

	Client* client = bank.findClientById(id);
	if (client != nullptr)
		std::cout << *client << std::endl;
	else
	{
		std::cerr << "No such client" << std::endl;
		return;
	}

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
