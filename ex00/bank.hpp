#pragma once
#include <iostream>
#include "account.hpp"
#include <vector>

class Account;

class Bank {
	private:
		std::vector<Account> accountList;
		int vault;
	public:
		Bank();
		~Bank();
		Bank& operator=(const Bank& copy);
		Bank(const Bank& copy);
		void createAccount(int value);
		void deleteAccount(int id);
		void loan(int id, int value);
		void deposit(int id, int value);
		void withdraw(int id, int value);
		int getValue(int id);
		int getVault();
		int getNAccounts();
};