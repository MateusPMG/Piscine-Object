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

void Bank::loan(int id, int value){
	if (value > vault){
		std::cout << "Loan amount requested surpasses bank vault amount\n";
		return;
	}
	accountList[id].setValue(value);
}