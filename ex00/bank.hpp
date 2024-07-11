#pragma once
#include <iostream>
#include "account.cpp"
#include <vector>

class Bank {
	private:
		std::vector<int> accountList;
		int vault;
	public:
		Bank();
		~Bank();
		Bank& operator=(const Bank& copy);
		Bank(const Bank& copy);
		void loan(int id, int value);
		void deposit(int value);
};