#pragma once
#include <iostream>

class Bank;

class Account{
	private:
		int id;
		int value;
		Account();
		void setValue(int value);
		void addValue(int value);
		void removeValue(int value);
		friend class Bank;
	public:
		Account& operator=(const Account& copy);
		Account(const Account& copy);
		Account(int id, int value);
		~Account();
		int getID() const;
		int getValue() const;
}; 