#include <iostream>
#include <chrono>
#include <Windows.h>
#include "Budget.h"
#include "Wallet.h"
#include "Budget.h"
#include "CreditCard.h" 

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Добро пожаловать в приложение \"Мой бюджет\"\n\n" ;

	Budget myBudget;
	string filenameMainReport = "MainReport.txt";
	string filenameTopCat = "TopCat.txt";
	string filenameTopMoney = "TopMoney.txt";

	bool noExit = true;
	do
	{
		cout << "Вы находитесь в главном меню\n\n";
		cout << "Укажите число для выбора нужного раздела меню\n";
		cout << "0 - для выхода из программы\n";
		cout << "1 - создание кошелька\\дебетовой карты\\кредитной карты\n";
		cout << "2 - пополение счёта \n";
		cout << "3 - внесение расходов по счёту\n";
		cout << "4 - формирование отчётов по затратам\n";
		cout << "5 - формирование отчётов по категориям\n";
		cout << "6 - формирование рейтинга по максимальной суммам расходов\n";
		cout << "7 - показать все счета на экране\n";
		cout << "8 - показать операции по счёту\n";
		

		int chose;
		cin >> chose;
		switch (chose)
		{
		case 0:
		{
			cout << "Всего доброго\n";
			noExit = false;

			//сохранение объекта в файл
			ofstream fileMainReport;
			ofstream fileTopCat;
			ofstream fileTopMoney;
			
			fileMainReport.open(filenameMainReport);
			if (fileMainReport.is_open())
			{
				myBudget.saveMainReport(fileMainReport);
				fileMainReport.close();
			}

			fileTopCat.open(filenameTopCat);
			if (fileMainReport.is_open())
			{
				myBudget.saveTopCat(fileTopCat);
				fileTopCat.close();
			}

			fileTopMoney.open(filenameTopMoney);
			if (fileTopMoney.is_open())
			{
				myBudget.saveMainReport(fileTopMoney);
				fileTopMoney.close();
			}
		}
			break;
		case 1:
		{
			cout << "Вы находитесь в меню добавления счёта\n";
			cout << "Укажите число для выбора нужного раздела \n";
			cout << "1 - для добавления кошелька\\дебетовой карты\n";
			cout << "2 - для добавления кредитной карты\n";
			cout << "0 или любое другое число для выхода из меню добавления счёта\n";

			int choseAccaunt;
			cin >> choseAccaunt;

			myBudget.createAccaunt(choseAccaunt);
		}
			break;
		case 2:
		{
			myBudget.fillAccaunts();
		}
			break;
		case 3:
		{
			myBudget.expendeturAccaunts();
		}
			break;
		case 4:
		{
			myBudget.mainReport();
		}
			break;
		case 5:
		{
			myBudget.ratingCategoryReport();
		}
			break;
		case 6:
		{
			myBudget.ratingExpendeturReport();
		}
			break;
		case 7:
		{
			myBudget.showAccaunts();
		}
			break;
		case 8:
		{
			myBudget.showOperation();
		}
			break;
		default:
			break;
		}

	} while (noExit);


	return 0;
}
