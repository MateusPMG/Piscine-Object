#include "bonus_bank.hpp"

BonusBank::BonusBank():vault(0),nextid(0){}

BonusBank::~BonusBank(){}

BonusBank::BonusAccount::BonusAccount(int id, int value){
	this->id = id;
	this->value = value;
}

BonusBank::BonusAccount::~BonusAccount(){}

BonusBank::BonusAccount& BonusBank::BonusAccount::operator=(const BonusAccount& copy){
	if (this != &copy){
		id = copy.id;
		value = copy.value;
	}
	return (*this);
}

BonusBank::BonusAccount::BonusAccount(const BonusAccount& copy):id(copy.id),value(copy.value){}

BonusBank& BonusBank::operator=(const BonusBank& copy){
	if (this != &copy){
		accountList = copy.accountList;
		vault = copy.vault;
		nextid = copy.nextid;
	}
	return (*this);
}

BonusBank::BonusBank(const BonusBank& copy):accountList(copy.accountList),
vault(copy.vault),nextid(copy.nextid){}

const int& BonusBank::BonusAccount::getID()const{
	return (id);
}

const int& BonusBank::BonusAccount::getValue()const{
	return (value);
}

void BonusBank::createAccount(int value){
	if (value <= 0){
		throw(std::runtime_error("Accounts cannot be created without an initial deposit value > 0"));
	}
	else {
		accountList.insert({nextid, BonusAccount(nextid, value)});
		std::cout << "Account number " << nextid << " was created \n";
		nextid++;
	}
}

void BonusBank::deleteAccount(int id){
	accountList.erase(id);
}

void loan(int id, int value){
	
}