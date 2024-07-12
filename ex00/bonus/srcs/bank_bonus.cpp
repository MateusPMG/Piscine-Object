#include "../includes/bank_bonus.hpp"

Bank::Account::Account(int id, double value):id(id),value(value){}

Bank::Account::~Account(){}

Bank::Account::Account(const Account& copy):id(copy.id),value(copy.value){}

Bank::Account& Bank::Account::operator=(const Account& copy){
	if (this != &copy){
		id = copy.id;
		value = copy.value;
	}
	return *this;
}

int Bank::Account::getID()const{
	return id;
}

double Bank::Account::getValue()const{
	return value;
}

Bank::Bank(){}

Bank::~Bank(){}

Bank::Bank(const Bank& copy):nr_clients(copy.nr_clients),vault(copy.vault),clients(copy.clients){}

Bank::Account& Bank::operator[](size_t id){
	return (clients[id]);
}

void Bank::deleteAccount(size_t id){
	clients.erase(id);
}

void Bank::createAccount(size_t id, double value){
	if (clients.find(id) != clients.end()) {
			return;
		}
	clients[id] = Account(id, value);
}

