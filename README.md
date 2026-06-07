# 💵 CLI Project "Bank System"
 
An application for working with bank system. Program works only in **Console Line Interface (*CLI*)** mode. The main language for this program that was selected is **The C++ Programming Language**.
 
---
 
## 🚀 Features
 
- 👔 Two working modes (Employee, Client)
- 🖥️ Optimization by using mostly own classes
- 📱 Simplified menu for both modes
- 💪 Own `String` and `Array` classes (lightweight alternatives to `std::string` and `std::vector`)
- 🏦 Oriented on work with a real Bank workflow
- 💳 Support for multiple account types: Debit, Credit, Savings
- 💸 Payments and transfers between accounts
- 🔐 Role-based access system
---
 
## 🏗️ Project Structure
 
```
BankSystem/
├── main.cpp              # Entry point
│
├── Person.cpp/.h         # Base class for people
├── Employee.cpp/.h       # Bank employee entity
├── Client.cpp/.h         # Bank client entity
│
├── Employee_Role.cpp/.h  # Employee menu functions (procedural)
├── Client_Role.cpp/.h    # Client menu functions (procedural)
│
├── Bank.cpp/.h           # Core bank logic
├── BankSystem.cpp/.h     # System entry & menu controller (procedural)
│
├── Account.cpp/.h        # Base account class
├── DebitAccount.cpp/.h   # Debit account
├── CreditAccount.cpp/.h  # Credit account
├── SavingsAccount.cpp/.h # Savings account
│
├── Payment.cpp/.h        # Payment operations
├── Transaction.cpp/.h    # Transaction history
├── Transfer.cpp/.h       # Transfer between accounts
│
├── Array.cpp/.h          # Custom dynamic array (std::vector alternative)
└── String.cpp/.h         # Custom string class (std::string alternative)
```
 
---
 
## 🧱 Architecture
 
The project combines **OOP** for data modeling with **procedural** style for UI/menu logic:
 
### OOP part (classes)
- **Inheritance** — `DebitAccount`, `CreditAccount`, `SavingsAccount` inherit from `Account`; `Employee` and `Client` inherit from `Person`
- **Encapsulation** — all data is managed through class methods
- **Abstraction** — clean interfaces between Bank, Accounts, and Users
### Procedural part (functions)
- `BankSystem.cpp/.h` — system startup and main menu routing
- `Employee_Role.cpp/.h` — employee menu and actions
- `Client_Role.cpp/.h` — client menu and actions
- `main.cpp` — entry point
---
 
## 👥 Roles
 
### 👔 Employee Mode
- View all clients and their accounts
- Open / close accounts
- Manage client data
- View transaction history
### 🧑 Client Mode
- View own accounts and balance
- Make payments
- Transfer funds between accounts
- View personal transaction history
---
 
## 💳 Account Types
 
| Type | Description |
|------|-------------|
| **Debit** | Standard account, balance ≥ 0 |
| **Credit** | Allows negative balance up to a credit limit |
| **Savings** | Accumulates interest over time |
 
---
 
## ⚙️ Build & Run
 
### Requirements
- C++17 or later
- Any C++ compiler: `g++`, `clang++`, MSVC
### Compile (g++)
```bash
g++ -std=c++17 -o BankSystem *.cpp
```
 
### Run
```bash
./BankSystem
```
 
> On Windows: `BankSystem.exe`
 
---
 
## 🛠️ Built With
 
- **C++17** — core language
- **OOP + Procedural** — mixed design paradigm
- Minimal use of standard headers:
| Header | Purpose |
|--------|---------|
| `<iostream>` | Console I/O |
| `<cstring>` | Low-level string operations (used in custom `String` class) |
| `<stdexcept>` | Exception handling |
| `<sstream>` | String stream conversions |
| `<climits>` | Numeric limits constants |
| `<initializer_list>` | Support for `{}` initialization in custom `Array` class |
| `<algorithm>` | Minimal use for utility operations |
 
---
 
## 📌 Notes
 
- All input/output is done through the console (CLI only)
- Custom `String` and `Array` classes are used instead of STL equivalents to demonstrate low-level understanding
- The project is educational and simulates real banking operations
---
 
## 👨‍💻 Author
 
> Made by *null* (or *nullptr*?)

