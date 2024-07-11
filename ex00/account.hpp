#pragma once
 #include <iostream>

class Account{
	private:
		int id;
		int value;
		Account();
		Account(int id, int value);
		~Account();
		Account& operator=(Account& copy);
		Account(const Account& copy);
}; 