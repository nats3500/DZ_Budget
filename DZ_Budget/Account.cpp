#include "Account.h"

void  Account::refill( std::string& discription, const float money,
	const unsigned year, const unsigned month, const unsigned day)
{
	const float newMoney = (money < 0 ? -money : money);
	accaunt.push_back(fillOperation(discription, newMoney, year, month, day, REFILL));
	totalBalance += newMoney;
}

void  Account::expenditure( std::string& discription,
	const float money, const unsigned year, const unsigned month, const unsigned day, const int categorie)
{
	const float newMoney = (money > 0 ? -money : money);
	accaunt.push_back(fillOperation(discription, newMoney, year, month, day, categorie));
	totalBalance += newMoney; 
}

void Account::showAccaunt() const
{
	std::cout << "Название счёта: " << nameAccaunt << std::endl;
	std::cout << "Текущий баланс счёта: " << totalBalance << " Rub" << std::endl;
}

void Account::showOperation() const
{
	for (auto el : accaunt)
	{
		std::cout << "---------------------------" << std::endl;
		std::cout << el.categories << std::endl;
		std::cout << el.sumOperation << std::endl;
		std::cout << el.description << std::endl;
		std::cout << el.year << ' ' << el.month << ' ' << el.day << std::endl;
		std::cout << "---------------------------" << std::endl;
	}
}

std::vector<Account::Operations> Account::findOperation(const unsigned year, const int category)
{
	std::vector<Account::Operations> res;

	for (auto el : accaunt)
	{
		if (category != 0)
		{
			if (el.year == year && el.categories == Categories(category))
				res.push_back(el);
		}
		else
		{
			if (el.year == year)
				res.push_back(el);
		}
	}
	return res;
}

std::vector<Account::Operations> Account::findOperation(const unsigned year,
	const unsigned month, const int category)
{
	std::vector<Account::Operations> res;

	for (auto el : accaunt)
	{
		if (category != 0)
		{
			if (el.year == year &&
				el.month == month && el.categories == Categories(category))
				res.push_back(el);
		}
		else
		{
			if(el.year == year &&
				el.month == month)
				res.push_back(el);
		}
	}
	return res;
}

std::vector<Account::Operations> Account::findOperation(const unsigned year,
	const unsigned month, const unsigned day, const int category)
{
	std::vector<Account::Operations> res;

	for (auto el : accaunt)
	{
		if (category != 0)
		{
			if (el.year == year &&
				el.month == month &&
				el.day == day && el.categories == Categories(category))
				res.push_back(el);
		}
		else
		{
			if (el.year == year &&
				el.month == month &&
				el.day == day)
				res.push_back(el);
		}
	}
	return res;
}

std::vector<Account::Operations> Account::findTopCatOperation(const unsigned year, const unsigned month)
{
	std::vector<Account::Operations> res;

	unsigned Top1, Top2, Top3, count1 = 0, count2 = 0, count3 = 0;

	for (unsigned i = 2; i < 10; i++)
	{
		unsigned count = 0;
	
		for (auto el : accaunt)
		{
			
			if (el.year == year &&
				el.month == month &&
				el.categories == Categories(i))
			{
				count++;
				if (count1 < count)
				{
					count1 = count;
					Top1 = i;
				}
				else if (count < count1 && count > count2)
				{
					count2 = count;
					Top2 = i;
				}
				else if (count < count1 && count < count2 && count > count3)
				{
					count3 = count;
					Top3 = i;
				}	
			}
		}
	}

	for (auto el : accaunt)
	{
		if (el.year == year &&
			el.month == month &&
			el.categories == Categories(Top1 || Top2 || Top3))
			res.push_back(el);
	}

	return res;
}

std::vector<Account::Operations> Account::findTopCatOperation(const unsigned year, const unsigned month, const unsigned day)
{
	//переделать добавить параметры года месяца и дня от которго считать операции

	std::vector<Account::Operations> res;

	unsigned Top1, Top2, Top3, count1 = 0, count2 = 0, count3 = 0;

	for (unsigned i = 2; i < 10; i++)
	{
		unsigned count = 0;
		unsigned curYear = year, curMonth = month, curDay = day;

		for (auto el : accaunt)
		{
			if (curYear == 4 && curYear == 6 && curYear == 9 && curYear == 11)
				if (curDay >= 31)
					curDay = 1;
			else if (curMonth == 2)
				if (curYear % 400 == 0 || ((curYear % 4 == 0) && (curYear % 100 != 0)))
					if (curDay >= 30)
						curDay = 1;
			else if (curMonth != 12)
				if (curDay >= 32)
					curDay = 1;
			else if (curMonth == 12)
				if (curDay >= 32)
				{
					curDay = 1;
					curMonth = 1;
					curYear++;
				}

			if (el.year == curYear &&
				el.month == curMonth &&
				el.day == (curDay++) &&
				el.categories == Categories(i))
			{
				count++;
				if (count1 < count)
				{
					count1 = count;
					Top1 = i;
				}
				else if (count < count1 && count > count2)
				{
					count2 = count;
					Top2 = i;
				}
				else if (count < count1 && count < count2 && count > count3)
				{
					count3 = count;
					Top3 = i;
				}
			}
		}
	}

	unsigned curYear = year, curMonth = month, curDay = day;

	for (auto el : accaunt)
	{
		if (curYear == 4 && curYear == 6 && curYear == 9 && curYear == 11)
			if (curDay >= 31)
				curDay = 1;
		else if (curMonth == 2)
			if (curYear % 400 == 0 || ((curYear % 4 == 0) && (curYear % 100 != 0)))
				if (curDay >= 30)
					curDay = 1;
		else if (curMonth != 12)
			if (curDay >= 32)
				curDay = 1;
		else if (curMonth == 12)
			if (curDay >= 32)
			{
				curDay = 1;
				curMonth = 1;
				curYear++;
			}

		if (el.year == curYear &&
			el.month == curMonth &&
			el.day == (curDay++) &&
			el.categories == Categories(Top1 || Top2 || Top3))
			res.push_back(el);
	}

	return res;
}

std::vector<Account::Operations> Account::findTopMoneyOperation(const unsigned year, const unsigned month)
{
	std::vector<Account::Operations> res;

	float Top1 = 0, Top2 = 0, Top3 = 0;

	for (auto el : accaunt)
	{

		if (el.year == year &&
			el.month == month)
		{
			float CurrMoney = el.sumOperation;
			
			if (Top1 <  -CurrMoney)
				Top1 = -CurrMoney;
			else if (-CurrMoney < Top1 && -CurrMoney > Top2)
				Top2 = -CurrMoney;
			else if (-CurrMoney < Top1 && CurrMoney < Top2 && -CurrMoney > Top3)
				Top3 = -CurrMoney;
		}
	}

	for (auto el : accaunt)
	{
		if (el.year == year &&
			el.month == month &&
			el.sumOperation == Top1 || Top2 || Top3)
			res.push_back(el);
	}

	return res;
}

std::vector<Account::Operations> Account::findTopMoneyOperation(const unsigned year, const unsigned month, const unsigned day)
{
	std::vector<Account::Operations> res;

	float Top1 = 0, Top2 = 0, Top3 = 0;

	unsigned curYear = year, curMonth = month, curDay = day;

	for (auto el : accaunt)
	{

		if (curYear == 4 && curYear == 6 && curYear == 9 && curYear == 11)
			if (curDay >= 31)
				curDay = 1;
		else if (curMonth == 2)
			if (curYear % 400 == 0 || ((curYear % 4 == 0) && (curYear % 100 != 0)))
				if (curDay >= 30)
					curDay = 1;
		else if (curMonth != 12)
			if (curDay >= 32)
				curDay = 1;
		else if (curMonth == 12)
			if (curDay >= 32)
			{
				curDay = 1;
				curMonth = 1;
				curYear++;
			}

		if (el.year == curYear &&
			el.month == curMonth &&
			el.day == (curDay++))
		{
			float CurrMoney = el.sumOperation;

			if (Top1 < -CurrMoney)
				Top1 = -CurrMoney;
			else if (-CurrMoney < Top1 && -CurrMoney > Top2)
				Top2 = -CurrMoney;
			else if (-CurrMoney < Top1 && CurrMoney < Top2 && -CurrMoney > Top3)
				Top3 = -CurrMoney;
		}
	}

	curYear = year, curMonth = month, curDay = day;
	for (auto el : accaunt)
	{
		if (curYear == 4 && curYear == 6 && curYear == 9 && curYear == 11)
			if (curDay >= 31)
				curDay = 1;
		else if (curMonth == 2)
			if (curYear % 400 == 0 || ((curYear % 4 == 0) && (curYear % 100 != 0)))
				if (curDay >= 30)
					curDay = 1;
		else if (curMonth != 12)
			if (curDay >= 32)
				curDay = 1;
		else if (curMonth == 12)
			if (curDay >= 32)
			{
				curDay = 1;
				curMonth = 1;
				curYear++;
			}

		if (el.year == curYear &&
			el.month == curMonth &&
			el.day == (curDay++) &&
			el.sumOperation == -Top1 || -Top2 || -Top3)
			res.push_back(el);
	}

	return res;
}

 Account::Operations  Account::fillOperation(std::string& discription, const float money, const unsigned year, const unsigned month, const unsigned day, int category)
{
	Operations operation(discription,  year,month,day , Categories(category), money);

	return operation;
}

 
