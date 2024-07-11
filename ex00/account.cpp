#include "account.hpp"

Account::Account(){}

Account::Account(int id, int value){
	this->id = id;
	this->value = value;
}

Account::~Account(){}

Account& Account::operator=(const Account& copy){
	this->id = copy.id;
	this->value = copy.value;
	return *this;
}

Account::Account(const Account& copy){
	this->id = copy.id;
	this->value = copy.value;
}

int Account::getID()const{
	return (this->id);
}

int Account::getValue()const{
	return (this->value);
}

void Account::setValue(int value){
	this->value = value;
}