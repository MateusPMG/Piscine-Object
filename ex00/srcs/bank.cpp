#include "../includes/bank.hpp"

Bank::Bank():vault(0),nextid(0){}

Bank::~Bank(){}

Bank& Bank::operator=(const Bank& copy){
	if (this != &copy) {
            accountList.clear();
            for (size_t i = 0; i < copy.accountList.size(); ++i) {
                accountList.push_back(Account(copy.accountList[i]));
            }
        }
        return *this;
}

Bank::Bank(const Bank& copy){
	for (size_t i = 0; i < copy.accountList.size(); ++i) {
            accountList.push_back(Account(copy.accountList[i]));
	}
}

void Bank::createAccount(int value){
	if (value <= 0){
		std::cout << "Accounts cannot be created without an initial deposit value > 0\n";
	}
	if (accountList.size() == 0){
		vault += 0.05 * value;
		accountList.push_back(Account(0, 0.95 * value));
		std::cout << "Account number " << nextid << " was created\n";
		nextid++;
	}
	else{
		vault += 0.05 * value;
		std::cout << "Account number " << nextid << " was created \n";
		accountList.push_back(Account(nextid, 0.95 * value));
		nextid++;
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
	for (std::vector<Account>::iterator it = accountList.begin(); it < accountList.end(); it++){
		if ((*it).getID() == id){
			(*it).addValue(0.95 * value);
			vault += 0.05 * value;
			return;
		}
	}
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
	for (std::vector<Account>::iterator it = accountList.begin(); it < accountList.end(); it++){
		if ((*it).getID() == id){
			return ((*it).getValue());
		}
	}
	return (-1);
}

int Bank::getVault(){
	return (vault);
}

int Bank::getNAccounts(){
	return (accountList.size());
}

void Bank::printAid(){
	for (std::vector<Account>::iterator it = accountList.begin(); it < accountList.end(); it++){
		std::cout << "Account id: " << (*it).getID() << std::endl;
	}
}