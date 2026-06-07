# include "BankSystem.h"
# include "Bank.h"
# include "Client.h"
# include "Employee.h"
# include "Array.h"
# include "Account.h"
# include "DebitAccount.h"
# include "SavingsAccount.h"
# include "CreditAccount.h"

Bank fill()
{
	Array <Client*> clients_arr;
	Array <Employee*> employers_arr;

	clients_arr.add
	(
		new Client
		(
			"John", 25, (__int64)1,
			Array <Account*>
			({
				new DebitAccount(1, 25000),
				new SavingsAccount(1, 15000, 2),
				new CreditAccount(1, 5000, 100000, 0)
			})
		)
	);

	employers_arr.add
	(
		new Employee
		(
			"Jack", 30, (__int64)-1, 40000, "Manager"
		)
	);

	return Bank(clients_arr, employers_arr);
}
