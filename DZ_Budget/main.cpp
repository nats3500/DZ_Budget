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

	cout << "����� ���������� � ���������� \"��� ������\"\n\n" ;

	Budget myBudget;
	string filenameMainReport = "MainReport.txt";
	string filenameTopCat = "TopCat.txt";
	string filenameTopMoney = "TopMoney.txt";

	bool noExit = true;
	do
	{
		cout << "�� ���������� � ������� ����\n\n";
		cout << "������� ����� ��� ������ ������� ������� ����\n";
		cout << "0 - ��� ������ �� ���������\n";
		cout << "1 - �������� ��������\\��������� �����\\��������� �����\n";
		cout << "2 - ��������� ����� \n";
		cout << "3 - �������� �������� �� �����\n";
		cout << "4 - ������������ ������� �� ��������\n";
		cout << "5 - ������������ ������� �� ����������\n";
		cout << "6 - ������������ �������� �� ������������ ������ ��������\n";
		cout << "7 - �������� ��� ����� �� ������\n";
		cout << "8 - �������� �������� �� �����\n";
		

		int chose;
		cin >> chose;
		switch (chose)
		{
		case 0:
		{
			cout << "����� �������\n";
			noExit = false;

			//���������� ������� � ����
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
			cout << "�� ���������� � ���� ���������� �����\n";
			cout << "������� ����� ��� ������ ������� ������� \n";
			cout << "1 - ��� ���������� ��������\\��������� �����\n";
			cout << "2 - ��� ���������� ��������� �����\n";
			cout << "0 ��� ����� ������ ����� ��� ������ �� ���� ���������� �����\n";

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
