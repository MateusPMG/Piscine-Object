#pragma once
#include <iostream>
#include <map>

class Bank {
	private:
		int nr_clients;
		double vault;

		class Account{
			private:
				int id;
				double value;
				Account(int id, double value):id(id),value(value){};
				Account& operator=(const Account& copy);
				Account(const Account& copy);
				~Account();
				friend class Bank;
			public:
				int getID()const;
				double getValue()const;
		};

		std::map<int, Account> clients;
	public:
		Bank();
		~Bank();
		Bank& operator=(const Bank& copy);
		Bank(const Bank& copy);
		Account& operator[](size_t id);
		void createAccount(size_t id, double value);
		void deleteAccount(size_t id);
		void deposit(size_t id, double value);
		void withdraw(size_t id, double value);
		void loan(size_t id, double value);
		void getNrClients();
		void getVault();
};