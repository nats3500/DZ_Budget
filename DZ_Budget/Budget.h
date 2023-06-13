#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
//#include <sstream>
#include <fstream>
#include "Account.h"
#include "CreditCard.h"
#include "Wallet.h"


class Budget
{
public:

	Budget()
	{
		totalBalance = 0.0f;
	}
	~Budget()
	{
		for (auto ptr: accaunts)
			if (ptr)
				delete ptr;
		accaunts.clear();
	}

	//добавление счёта в бюджет
	void addAccaunt( Account* accaunt) { accaunts.push_back(accaunt);}
	//создание кошелька или карты
	void createAccaunt(const int typeAccaunt);
	// получение количества счетов
	size_t getSize() const { return accaunts.size(); }
	//показ на экране названия счёта и его баланс
	void showAccaunts() const;
	//оператор для доступа к элементу массива
	Account* operator[](const int index) { return accaunts[index]; }
	// Пополнение кошельков
	void fillAccaunts();
	// Внесение расходов
	void expendeturAccaunts();
	// формирование отчёта
	void mainReport();
	// формирование рейтингов по категориям/нужно доделать
	void ratingCategoryReport();
	// формирование рейтинга по затратам
	void ratingExpendeturReport();
	// показать операции по счёту
	void showOperation();
	//сохранение всех данных бюжджета в файл
	void saveMainReport(std::ofstream& file);
	void saveTopCat(std::ofstream& file);
	void saveTopMoney(std::ofstream& file);

private:
	std::vector<Account*> accaunts;
	std::vector<std::vector<Account::Operations>> reportTimeOperation;
	std::vector<std::vector<Account::Operations>> reportCategoryOperation;
	std::vector<std::vector<Account::Operations>> reportMoneyOperation;
	float totalBalance;

	//Проверка месяца на корректность
	unsigned int checkMonth();
	//Проверка дня на корректность
	unsigned int checkDay(const unsigned year, const unsigned month);
	//выбор категории расходов
	unsigned choseCategory();

	//показ операций из отчёта
	void showOperationsInReport(std::vector<std::vector<Account::Operations>>& res);

};

