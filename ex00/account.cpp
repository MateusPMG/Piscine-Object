#include "account.hpp"

Account::Account(){}

Account::Account(int id, int value){
	this->id = id;
	this->value = value;
}

Account::~Account(){}

Account::Account(const Account& copy) : id(copy.id), value(copy.value) {}

Account& Account::operator=(const Account& copy) {
    if (this != &copy) {
        id = copy.id;
        value = copy.value;
    }
    return *this;
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

void Account::addValue(int value){
	if (value > 0)
		this->value += value;
	else
		std::cout << "No negative inputs allowed\n";
}

void Account::removeValue(int value){
	if (value > 0){
		if (value <= this->value)
			this->value -= value;
		else
			std::cout << "Withdrawal ammount exceeds account value\n";
	}
	else
		std::cout << "No negative inputs allowed\n";

}