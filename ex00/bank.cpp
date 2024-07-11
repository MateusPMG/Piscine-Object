#include "bank.hpp"

Bank::Bank():vault(0){}

Bank::~Bank(){}

Bank& Bank::operator=(const Bank& copy){
	this->accountList = copy.accountList;
	return *this;
}

Bank::Bank(const Bank& copy){
	this->accountList = copy.accountList;
}

void Bank::createAccount(int value){
	if (value <= 0){
		std::cout << "Accounts cannot be created without an initial deposit value > 0\n";
	}
	if (accountList.size() == 0){
		accountList.push_back(Account(0, value));
		std::cout << "Account number 0 was created\n";
	}
	else{
		accountList.push_back(Account(accountList.size() + 1, value));
		std::cout << "Account number " << accountList.size() << " was created \n";
	}
}

void Bank::deleteAccount(int id){
	if ( id >= 0 && id < static_cast<int>(accountList.size())){
		accountList.erase(accountList.begin() + id);
	}
	std::cout << "Account number " << id << " was deleted\n";
}

void Bank::loan(int id, int value){
	if (value > vault){
		std::cout << "Loan amount requested surpasses bank vault amount\n";
		return;
	}
	if ( id >= 0 && id < static_cast<int>(accountList.size())){
		accountList[id].addValue(value);
		vault -= value;
	}
	else
		std::cout << "Account ID doesnt exist\n";
}

void Bank::deposit(int id, int value){
	if ( id >= 0 && id < static_cast<int>(accountList.size())){
		accountList[id].addValue(static_cast<int>(value*0.95));
		vault += static_cast<int>(value*0.05);
	}
	else
		std::cout << "Account ID doesnt exist\n";
}

void Bank::withdraw(int id, int value){
	if ( id >= 0 && id < static_cast<int>(accountList.size())){
		accountList[id].removeValue(value);
	}	
	else
		std::cout << "Account ID doesnt exist\n";
}

int Bank::getValue(int id){
	return (accountList.at(id).getValue());
}

int Bank::getVault(){
	return (vault);
}

int Bank::getNAccounts(){
	return (accountList.size());
}