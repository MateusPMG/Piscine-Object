#include "bonus_bank.hpp"

BonusBank::BonusBank():vault(0),nextid(0){}

BonusBank::~BonusBank(){}

BonusBank::BonusAccount::BonusAccount(int id, int value){
	this->id = id;
	this->value = value;
}

BonusBank::BonusAccount::~BonusAccount(){}

BonusBank& BonusBank::operator=(const BonusBank& copy){}