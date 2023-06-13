#pragma once
#include "Account.h"
class Wallet :
	public Account
{
public:
	Wallet(std::string nameAccaunt = "������", std::string typeAccaunt = "��������� ����/������"):
		Account(nameAccaunt), typeAccaunt{typeAccaunt}{}
	~Wallet(){}
	virtual void expenditure( std::string& discription,
		const float money, const unsigned year, const unsigned month, const unsigned day, const int categorie) override;
	
private:
	std::string typeAccaunt;
};

