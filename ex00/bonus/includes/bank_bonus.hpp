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
				~Account();
				Account(int id, double value):id(id),value(value){};
				Account& operator=(const Account& copy);
				Account(const Account& copy);
			public:
				int getID()const;
				double getValue()const;
		};
		
		std::map<int, Account*> clients;
	public:
		Bank();
		~Bank();
		Bank& operator=(const Bank& copy);
		Bank(const Bank& copy);

};