#include "account.hpp"

Account::Account(){}

Account::Account(int id, int value){
	this->id = id;
	this->value = value;
}

Account::~Account(){}

Account& Account::operator=(Account& copy){
	this->id = copy.id;
	this->value = copy.value;
}

Account::Account(const Account& copy){
	
}