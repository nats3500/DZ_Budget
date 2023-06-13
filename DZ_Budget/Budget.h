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

	//���������� ����� � ������
	void addAccaunt( Account* accaunt) { accaunts.push_back(accaunt);}
	//�������� �������� ��� �����
	void createAccaunt(const int typeAccaunt);
	// ��������� ���������� ������
	size_t getSize() const { return accaunts.size(); }
	//����� �� ������ �������� ����� � ��� ������
	void showAccaunts() const;
	//�������� ��� ������� � �������� �������
	Account* operator[](const int index) { return accaunts[index]; }
	// ���������� ���������
	void fillAccaunts();
	// �������� ��������
	void expendeturAccaunts();
	// ������������ ������
	void mainReport();
	// ������������ ��������� �� ����������/����� ��������
	void ratingCategoryReport();
	// ������������ �������� �� ��������
	void ratingExpendeturReport();
	// �������� �������� �� �����
	void showOperation();
	//���������� ���� ������ �������� � ����
	void saveMainReport(std::ofstream& file);
	void saveTopCat(std::ofstream& file);
	void saveTopMoney(std::ofstream& file);

private:
	std::vector<Account*> accaunts;
	std::vector<std::vector<Account::Operations>> reportTimeOperation;
	std::vector<std::vector<Account::Operations>> reportCategoryOperation;
	std::vector<std::vector<Account::Operations>> reportMoneyOperation;
	float totalBalance;

	//�������� ������ �� ������������
	unsigned int checkMonth();
	//�������� ��� �� ������������
	unsigned int checkDay(const unsigned year, const unsigned month);
	//����� ��������� ��������
	unsigned choseCategory();

	//����� �������� �� ������
	void showOperationsInReport(std::vector<std::vector<Account::Operations>>& res);

};

