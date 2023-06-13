#pragma once
#include <string>
#include <iostream>
#include <vector>

class Account
{
public:
	Account(std::string nameAccaunt ="", const float totalBalance = 0.0f) : nameAccaunt{nameAccaunt},
		totalBalance{ totalBalance }{}
	~Account(){}

	enum Categories
	{
		DEFAULT,
		REFILL,
		HOUSING_COSTS,
		FOOD_EXPENSES,
		DEBTS,
		TRANSPORTATION_COSTS,
		VACANTION_EXPENSES,
		PERSONAL_EXPENSES,
		SAVINGS,
		OTHER_EXPENSES
	};

	struct Operations
	{
		std::string description;
		unsigned year = 0;
		unsigned month = 0;
		unsigned day = 0;
		Categories categories = Categories(0);
		float sumOperation = 0.0f;

	};

	//���������� ����� �������� ��� �����
	 virtual void refill(std::string& discription,
		 const float money, const unsigned year, const unsigned month, const unsigned day);
	//�������� �������� �� ������
	 virtual void expenditure(std::string& discription,
		 const float money, const unsigned year, const unsigned month, const unsigned day, const int categorie);
	//������� ������� �� �������
	const float getTotalBalance() { return totalBalance; }
	//������� ����� �����
	const std::string getName() { return nameAccaunt; }
	//��������� �����
	void setName(std::string name) { nameAccaunt = name; }
	//����� ������ �� �����
	virtual void showAccaunt() const;
	//�������� �������� �� �����/ ������� �����
	void showOperation() const;
	//�������� ��� ������� � �������� �������
	Operations& operator[](const int index) { return accaunt[index]; }
	//����� �������� � ������� ��������
	std::vector<Operations> findOperation(const unsigned year, const int category = 0);
	std::vector<Operations> findOperation(const unsigned year, const unsigned month, const int category = 0);
	std::vector<Operations> findOperation(const unsigned year, const unsigned month, const unsigned day, const int category = 0);
	std::vector<Operations> findTopCatOperation(const unsigned year, const unsigned month);
	std::vector<Operations> findTopCatOperation(const unsigned year, const unsigned month, const unsigned day);
	std::vector<Operations> findTopMoneyOperation(const unsigned year, const unsigned month);
	std::vector<Operations> findTopMoneyOperation(const unsigned year, const unsigned month, const unsigned day);

protected:

	std::vector<Operations> accaunt;
	std::string nameAccaunt;
	float totalBalance;
	
	//���. ����� ��� ���������� ������ �� ���������
	Operations fillOperation(std::string& discription, const float money,
		const unsigned year, const unsigned month, const unsigned day, int category);
	//����� ��������

};

