#pragma once
#include <iostream>
#include <vector>

class BonusBank{
	class BonusAccount{
		private:
			int id;
			int value;
			BonusAccount();
			BonusAccount(int id, int value);
		public:
			BonusAccount& operator=(const BonusAccount& copy);
			BonusAccount(const BonusAccount& copy);
			~BonusAccount();
			const int &getID() const;
			const int &getValue() const;
	};
	private:
		std::vector<BonusAccount> accountList;
		int vault;
		int nextid;
	public:
		BonusBank();
		~BonusBank();
		BonusBank& operator=(const BonusBank& copy);
		BonusBank(const BonusBank& copy);
		void createAccount(int value);
		void deleteAccount(int id);
		void loan(int id, int value);
		void deposit(int id, int value);
		void withdraw(int id, int value);
		int getValue(int id);
		int getVault();
		int getNAccounts();
		void printAid();
};