#include "Budget.h"
#include <boost/optional.hpp>

using namespace std::chrono;

void Budget::createAccaunt(const int typeAccaunt)
{
	std::cout << "Введите название счёта\n";
	std::string nameAccaunt;
	std::cin.get();
	std::getline(std::cin, nameAccaunt);

	if (typeAccaunt == 1)
	{
		Wallet* newWallet;
		newWallet = new Wallet;
		newWallet->setName(nameAccaunt);
		accaunts.push_back(newWallet);
	}
	else if(typeAccaunt == 2)
	{
		CreditCard* newCreditCard;
		newCreditCard = new CreditCard;
		newCreditCard->setName(nameAccaunt);
		float maxCreditLimit;
		std::cout << "Укажите кредитный лемит по карте: ";
		std::cin >> maxCreditLimit;
		newCreditCard->setMaxCreditLimit(maxCreditLimit);
		accaunts.push_back(newCreditCard);
	}
}

void Budget::showAccaunts() const
{
	int count = 0;
	for (auto el : accaunts )
	{
		std::cout << "-----------------------------\n";
		std::cout << "Счёт номер: " << count << std::endl;
		el->showAccaunt();
		std::cout << "-----------------------------\n";
		count++;
	}
}

void Budget::fillAccaunts()
{
	bool isNotCorrect = true;

	int choseAccaunt;
	while (isNotCorrect)
	{
		std::cout << "Вы находитесь в меню добавления расходов\n";
		std::cout << "Выберете счёт указав число от 0 до " << getSize() - 1 << std::endl;
		showAccaunts();

		std::cin >> choseAccaunt;

		if (choseAccaunt >= getSize() || choseAccaunt < 0)
			std::cout << "Счёта с таким номером нет,попробуйте выбрать ещё раз\n";
		else
			isNotCorrect = false;
	}

	std::cout << "Напишите описание операции\n";
	std::string discription;
	std::cin.get();
	std::getline(std::cin, discription);

	std::cout << "Укажите сумму операции\n";
	float money;
	std::cin >> money;

	std::cout << "Год операции\n";
	unsigned year;
	std::cin >> year;
	
	unsigned month = checkMonth();
	unsigned day =checkDay(year, month);
	accaunts[choseAccaunt]->refill(discription, money, year, month, day);
}

void Budget::expendeturAccaunts()
{
	bool isNotCorrect = true;

	int choseAccaunt;
	while (isNotCorrect)
	{
		std::cout << "Вы находитесь в меню добавления расходов\n";
		std::cout << "Выберете счёт указав число от 0 до " << getSize() - 1 << std::endl;
		showAccaunts();

		std::cin >> choseAccaunt;

		if (choseAccaunt >= getSize() || choseAccaunt < 0)
			std::cout << "Счёта с таким номером нет,попробуйте выбрать ещё раз\n";
		else
			isNotCorrect = false;
	}

	int choseCat = choseCategory();

	std::cin.get();
	std::cout << "Введите описание операции\n";
	std::string discription;
	std::getline(std::cin, discription);

	float money;
	std::cout << "Укажите сумму расходов\n";
	std::cin >> money;

	std::cout << "Год операции\n";
	unsigned year;
	std::cin >> year;

	unsigned month = checkMonth();
	unsigned day = checkDay(year, month);
	if (choseCat == 1)
		accaunts[choseAccaunt]->refill(discription,money, year, month, day);
	else
		accaunts[choseAccaunt]->expenditure(discription, money, year, month, day, choseCat);
}

void Budget::mainReport()
{
	std::cout << "Если хотите формировать отчёт по определённой категории укажите любое число если нет укажите ноль\n";
	int chose;
	std::cin >> chose;

	int choseCat = 0;
	if (chose)
		 choseCat = choseCategory();

	std::cout << "Выберете вариант формирования отчёта указав число\n";
	std::cout << "1 - Отчёт по дню\n";
	std::cout << "2 - Отчёт по месяцу\n";
	std::cout << "3 - Отчёт по году\n";
	std::cout << "Любое другое число для выхода\n";

	int choseReport;
	std::cin >> choseReport;

	switch (choseReport)
	{
	case 1:
	{

		std::cout << "Укажите год числом\n";
		int year;
		std::cin >> year;
		int month = checkMonth();
		int day = checkDay(year, month);

		reportTimeOperation.clear();

		for (const auto el: accaunts)
			reportTimeOperation.push_back(el->findOperation(year, month, day, choseCat));

		showOperationsInReport(reportTimeOperation);
	}
		break;
	case 2:
	{
		std::cout << "Укажите год числом\n";
		int year;
		std::cin >> year;
		int month = checkMonth();

		reportTimeOperation.clear();

		for (const auto el : accaunts)
			reportTimeOperation.push_back(el->findOperation(year, month, choseCat));

		showOperationsInReport(reportTimeOperation);

	}
		break;
	case 3:
	{
		std::cout << "Укажите год числом\n";
		int year;
		std::cin >> year;
		reportTimeOperation.clear();

		for (const auto el : accaunts)
			reportTimeOperation.push_back(el->findOperation(year, choseCat));

		showOperationsInReport(reportTimeOperation);

	}
		break;
	default:
		std::cout << "Выходим из меню\n" << std::endl;
		break;
	}
	
}

void Budget::ratingCategoryReport()
{
	std::cout << "Вы находитесь в меню формирования рейтинга по категории\n";
	std::cout << "Введите число для выбора варианта отчёта\n";
	std::cout << "1 - Получить отчёт за конкретный месяц\n";
	std::cout << "2 - Получить отчёт за неделю\n";

	unsigned chose;
	std::cin >> chose;
	switch (chose)
	{
	case 1:
	{
		unsigned year, month;
		std::cout << "Введите год для поиска операций\n";
		std::cin >> year;
		month = checkMonth();
		
		for (const auto el : accaunts)
			reportCategoryOperation.push_back(el->findTopCatOperation(year, month));

		std::cout << "Ниже операции с топ 3 категориями\n";
		showOperationsInReport(reportCategoryOperation);
	}
		break;
	case 2:
	{
		unsigned year, month, day;
		std::cout << "Введите год для поиска операций\n";
		std::cin >> year;
		month = checkMonth();
		day = checkDay(year, month);

		for (const auto el : accaunts)
			reportCategoryOperation.push_back(el->findTopCatOperation(year, month, day));

		std::cout << "Ниже операции с топ 3 категориями\n";
		showOperationsInReport(reportCategoryOperation);
	}
		break;
	default:
		std::cout << "Такой категории нет, выходим из меню\n";
		break;
	}
}

void Budget::ratingExpendeturReport()
{
	std::cout << "Вы находитесь в меню формирования рейтинга по сумме расходов\n";
	std::cout << "Введите число для выбора варианта отчёта\n";
	std::cout << "1 - Получить отчёт за конкретный месяц\n";
	std::cout << "2 - Получить отчёт за неделю\n";

	unsigned chose;
	std::cin >> chose;
	switch (chose)
	{
	case 1:
	{
		unsigned year, month;
		std::cout << "Введите год для поиска операций\n";
		std::cin >> year;
		month = checkMonth();

		for (const auto el : accaunts)
			reportMoneyOperation.push_back(el->findTopMoneyOperation(year, month));

		std::cout << "Ниже операции с топ 3 категориями\n";
		showOperationsInReport(reportMoneyOperation);
	}
	break;
	case 2:
	{
		unsigned year, month,day;
		std::cout << "Введите год для поиска операций\n";
		std::cin >> year;
		month = checkMonth();
		day = checkDay(year,month);

		for (const auto el : accaunts)
			reportMoneyOperation.push_back(el->findTopMoneyOperation(year, month, day));

		std::cout << "Ниже операции с топ 3 операции по сумме расходов\n";
		showOperationsInReport(reportMoneyOperation);
	}
	break;
	default:
		std::cout << "Такой категории нет, выходим из меню\n";
		break;
	}
}

void Budget::showOperation()
{
	bool isNotCorrect = true;

	int choseAccaunt;
	while (isNotCorrect)
	{
		std::cout << "Вы находитесь в меню отображения операции\n";
		std::cout << "Выберете счёт указав число от 0 до " << getSize() - 1 << std::endl;
		showAccaunts();

		std::cin >> choseAccaunt;

		if (choseAccaunt >= getSize() || choseAccaunt < 0)
			std::cout << "Счёта с таким номером нет,попробуйте выбрать ещё раз\n";
		else
			isNotCorrect = false;
	}

	accaunts[choseAccaunt]->showOperation();
}

void Budget::saveMainReport(std::ofstream& file)
{
	for (auto el : reportTimeOperation )
	{
		for (auto el2: el )
		{
			file << el2.categories << ' ' << el2.description << ' ' << el2.sumOperation << ' '
				<< el2.day << ' ' << el2.month << ' ' << el2.year << ' ' << std::endl;
		}
	}
}

void Budget::saveTopCat(std::ofstream& file)
{
	for (auto el : reportCategoryOperation)
	{
		for (auto el2 : el)
		{
			file << el2.categories << ' ' << el2.description << ' ' << el2.sumOperation << ' '
				<< el2.day << ' ' << el2.month << ' ' << el2.year << ' ' << std::endl;
		}
	}
	
}

void Budget::saveTopMoney(std::ofstream& file)
{
	for (auto el : reportMoneyOperation)
	{
		for (auto el2 : el)
		{
			file << el2.categories << ' ' << el2.description << ' ' << el2.sumOperation << ' '
				<< el2.day << ' ' << el2.month << ' ' << el2.year << ' ' << std::endl;
		}
	}
}

unsigned int Budget::checkMonth()
{
	bool is_not_right = true;
	unsigned int month;
	do
	{
		std::cout << "Введите месяц числом\n";
		std::cin >> month;

		is_not_right = false;

		if (month < 1 || month > 12)
		{
			std::cout << "Вы указали неверный месяц попробуйте ещё раз\n";
			is_not_right = true;
		}

	} while (is_not_right);
	return month;

}

unsigned int Budget::checkDay(const unsigned year, const unsigned month)
{
	bool is_not_right = true;
	unsigned day;

	if (month == 1 || month == 3
		|| month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
	{
		do
		{
			std::cout << "Введите дату числом от 1 до 31\n";
			std::cin >> day;
			is_not_right = false;

			if (day < 1 || day > 31)
			{
				std::cout << "Вы ввели неверную дату попробуйте ввыести ещё раз\n";
				is_not_right = true;
			}

		} while (is_not_right);
	}

	else if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0
			|| year % 400 == 0)
		{
			do
			{
				std::cout << "Введите дату числом от 1 до 29\n";
				std::cin >> day;

				is_not_right = false;

				if ((day < 1 || day > 29))
				{
					std::cout << "Вы ввели неверную дату попробуйте ввыести ещё раз\n";
					is_not_right = true;
				}
			} while (is_not_right);
		}
		else
		{
			do
			{
				std::cout << "Введите дату числом от 1 до 28\n";
				std::cin >> day;

				is_not_right = false;

				if ((day < 1 || day > 28))
				{
					std::cout << "Вы ввели неверную дату попробуйте вывести ещё раз\n";
					is_not_right = true;
				}
			} while (is_not_right);
		}
	}
	else
	{
		do
		{
			if (month == 4 || month == 6
				|| month == 9 || month == 11)
			{
				std::cout << "Введите дату числом от 1 до 30\n";
				std::cin >> day;
				is_not_right = false;
			}
			if (day < 1 || day > 30)
			{
				std::cout << "Вы ввели неверную дату попробуйте ввыести ещё раз\n";
				is_not_right = true;
			}

		} while (is_not_right);
	}
	return day;
}

unsigned Budget::choseCategory()
{
	bool isNotCorrect = true;
	int choseCategory;
	while (isNotCorrect)
	{
		std::cout << "Выберете категорию расходов указав число от 1 до 9 включительно\n";
		std::cout << "1 - Пополнение\n";
		std::cout << "2 - Расходы на жилье (аренда, налоги, страховка, содержание дома, квартплата)\n";
		std::cout << "3 - Расходы на питание (продукты, кафе и рестораны)\n";
		std::cout << "4 - Долги (долги, кредиты)\n";
		std::cout << "5 - Расходы на транспорт (автомобиль, проезд на общественном транспорте, такси)\n";
		std::cout << "6 - Расходы на отдых ( отпуск, хобби, культурные мероприятия )\n";
		std::cout << "7 - Личные расходы (одежда, косметика, развлечения, книги, лечение и оздоровление)\n";
		std::cout << "8 - Сбережения (резервный фонд, пенсионные накопления, инвестиции)\n";
		std::cout << "9 - Другие расходы\n";

		std::cin >> choseCategory;

		if (choseCategory < 1 || choseCategory > 9)
			std::cout << "Такой категории нет, попробуйте выбрать ещё раз\n";
		else
			isNotCorrect = false;
	}
	return choseCategory;
}

void Budget::showOperationsInReport(std::vector<std::vector<Account::Operations>>& res)
{
	for (const auto el : res)
	{
		for (const auto el2 : el)
		{
			std::cout << "---------------------------" << std::endl;
			std::cout << el2.categories << std::endl;
			std::cout << el2.sumOperation << std::endl;
			std::cout << el2.description << std::endl;
			std::cout << el2.day << ' ' << el2.month << ' ' << el2.year << std::endl;
			std::cout << "---------------------------" << std::endl;
		}
	}
}
