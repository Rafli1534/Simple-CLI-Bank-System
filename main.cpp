# include <iostream>
# include "Employee_Role.h"
# include "Client_Role.h"
# include "BankSystem.h"

void printMenu();
void checkRole(char choice, Bank bank);

int main()
{
	Bank bank(fill());
	char proceed = ' ';
	do
	{
		char role_choice;
		printMenu();
		std::cin >> role_choice;
		checkRole(role_choice, bank);
		std::cout << "Do u wanna continue work with some role? (y/N): ";
		std::cin >> proceed;
	} 
	while (proceed == 'y' || proceed == 'Y');
	return 0;
}

void printMenu()
{
	std::cout << "\033[2J\033[H"
		<< "Choose role: " << std::endl
		<< "\t1. Admin (Employee)" << std::endl
		<< "\t2. Client" << std::endl
		<< "\t0. Exit" << std::endl
		<< "Your choice: ";
}

void checkRole(char choice, Bank bank)
{
	switch (choice)
	{
	case '0':  break;
	case '1': employee_role(bank); break;
	case '2': client_role(bank); break;
	default:
		std::cerr << "No such choice!" << std::endl;
		break;
	}
}
