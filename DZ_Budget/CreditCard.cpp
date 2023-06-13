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
		std::cout << "Денег по счёту недостаточно для расходной операции. " << std::endl;
}

void CreditCard::showAccaunt() const
{
	std::cout << "Название счёта: " << nameAccaunt << std::endl;
	std::cout << "Доступный остаток по счёту: " << totalBalance << " Rub" << std::endl;
	std::cout << "Максимальный кредитный лимит по счёту: " << maxCreditLimit << " Rub" << std::endl;
	std::cout << "Задолженность по счёту: -" << debt << " Rub" << std::endl;
}
