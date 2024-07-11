#pragma once
#include <iostream>

class Account{
	private:
		int id;
		int value;
		Account();
		Account(int id, int value);
		~Account();
		Account& operator=(const Account& copy);
		Account(const Account& copy);
		int getID() const;
		int getValue() const;
		void setValue(int value);
}; 