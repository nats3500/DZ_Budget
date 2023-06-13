#include "CreditCard.h"

void CreditCard::setMaxCreditLimit(float maxCreditLimit)
{
	this->maxCreditLimit = maxCreditLimit;
	totalBalance = maxCreditLimit - debt;
}

void CreditCard::refill(std::string& discription, const float money, const unsigned year, const unsigned month, const unsigned day)
{
	float newMoney = (money < 0 ? -money : money);
	accaunt.push_back(fillOperation(discription, newMoney, year, month, day, REFILL));
	totalBalance += newMoney;
	debt -= newMoney;
}

void CreditCard::expenditure(std::string& discription, const float money, const unsigned year, const unsigned month, const unsigned day, const int categorie)
{
	if ( (maxCreditLimit - debt) > money )
	{
		accaunt.push_back(fillOperation(discription, money, year, month, day, categorie));
		totalBalance += (money > 0 ? -money : money);
		debt += (money < 0 ? -money : money);
	}
	else
		std::cout << "����� �� ����� ������������ ��� ��������� ��������. " << std::endl;
}

void CreditCard::showAccaunt() const
{
	std::cout << "�������� �����: " << nameAccaunt << std::endl;
	std::cout << "��������� ������� �� �����: " << totalBalance << " Rub" << std::endl;
	std::cout << "������������ ��������� ����� �� �����: " << maxCreditLimit << " Rub" << std::endl;
	std::cout << "������������� �� �����: -" << debt << " Rub" << std::endl;
}
