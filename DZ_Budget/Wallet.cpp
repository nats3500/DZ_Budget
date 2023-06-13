#include "Wallet.h"

void Wallet::expenditure(std::string& discription, const float money, const unsigned year, const unsigned month, const unsigned day, const int categorie)
{
	float newMoney = (money > 0 ? -money : money);
	
	if (totalBalance + newMoney >= 0)
	{
		accaunt.push_back(fillOperation(discription, newMoney, year, month, day, categorie));
		totalBalance += newMoney;
	}
	else
		std::cout << "Денег по счёту недостаточно для расходной операции. " << std::endl;
}
