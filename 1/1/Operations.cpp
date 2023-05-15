#include "Operations.hpp"
#include <iostream>
short choise, totalSum = 0;

int const sizeID = 10;
int arrID[sizeID]
{
10001, 10002, 10003, 10004, 10005, 10006, 10007, 10008, 10009, 10010
};
int const sizePrice = 10;
double arrPrice[sizePrice]
{
2450, 560, 350, 310, 150, 1200, 1670, 3500, 4300, 530
};
int const sizeName = 10;
std::string arrName[sizeName]
{
"Поршень Yamaha XJR400R2  ", "Коленчатый вал JOG       ", "Звезда ведущая 420 14зуб ", "Кольца поршневые 100сс 56",
"Палец поршневой 100сс 15 ", "Бензобак Yamaha 20 литров", "Карбюратор Yamaha 100сс ", "Диск передний brembo R14 ",
"Тормозная система brembo ", "Крыло заднее Stinger(V)  "
};
int const sizeValue = 10;
int arrValue[sizeValue]
{
50, 30, 45, 70, 50, 20, 150, 30, 40, 15
};



int addValue, ID, newPrice;


void Sklad()
{
	std::cout << "  ID            Название      кол-во  цена\n";
	for (short i = 0; i < sizeID; i++)
	{
		std::cout << arrID[i] << "  "
			<< arrName[i] << "  "
			<< arrValue[i] << "  "
			<< arrPrice[i] << "  \n";

	}
}
void NewPrice()
{
	Sklad();
	std::cout << "Введите номер товара: ";
	std::cin >> ID;
	std::cout << "Введите новую цену: ";
	std::cin >> newPrice;
	arrPrice[ID - 1] = newPrice;
	Sklad();
}
void Purchase()
{
	short totalsum = 0;
	int value, currID = 0, currCount = 0;
	int choise = -1;
	int* checkID;
	int size = 0;

	std::cout << "Введите количество покупок: ";
	std::cin >> size;
	checkID = new int[size];
	for (short i = 0; i < size; i++)
	{


		do
		{
			std::cout << "\nВведите ID товара: ";
			std::cin >> currID;
			std::cout << "\nВведите количество товара: ";
			std::cin >> currCount;
		} while ((currID < 1 && currID> 10) && (currCount > arrValue[currID - 1] && currCount < 1));
		totalsum += arrPrice[currID - 1] * currCount;
		arrValue[currID - 1] -= currCount;
	}
	std::cout << "Итого: " << totalsum << "\n";
	delete[]checkID;
}

void AddValue()
{
	Sklad();

	std::cout << "Введите номер товара: ";
	std::cin >> ID;
	std::cout << "Введите кол-во добавляемого товара: ";
	std::cin >> addValue;
	arrValue[ID - 1] += addValue;
	Sklad();

}
void RevueValue()
{
	Sklad();

	std::cout << "Введите номер товара: ";
	std::cin >> ID;
	std::cout << "Введите кол-во убавляемого товара: ";
	std::cin >> addValue;
	arrValue[ID - 1] -= addValue;
	Sklad();
}
void Motorshop()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		short choise, totalSum = 0;

		do
		{


			std::cout << "\t\tВас приветствует магазин мотозапчастей 'По-хрустим?)'\n";
			std::cout << "1 - Начать продажу\n2 - Показать склад\n3 - Пополнить склад\n4 - Уменьшить склад\n5 - Изменить цену товаров\n0 - Выход\n\nВыбор: ";
			std::cin >> choise;
			if (choise == 1)
			{
				Purchase();
			}
			else if (choise == 2)
			{
				Sklad();
			}
			else if (choise == 3)
			{
				AddValue();
			}
			else if (choise == 4)
			{
				RevueValue();
			}
			else if (choise == 5)
			{
				NewPrice();
			}
			else if (choise == 0)
			{
				break;
			}
		} while (choise >= 0 && choise < 6);


	}
}

