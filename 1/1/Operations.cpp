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
"������� Yamaha XJR400R2  ", "���������� ��� JOG       ", "������ ������� 420 14��� ", "������ ��������� 100�� 56",
"����� ��������� 100�� 15 ", "�������� Yamaha 20 ������", "���������� Yamaha 100�� ", "���� �������� brembo R14 ",
"��������� ������� brembo ", "����� ������ Stinger(V)  "
};
int const sizeValue = 10;
int arrValue[sizeValue]
{
50, 30, 45, 70, 50, 20, 150, 30, 40, 15
};



int addValue, ID, newPrice;


void Sklad()
{
	std::cout << "  ID            ��������      ���-��  ����\n";
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
	std::cout << "������� ����� ������: ";
	std::cin >> ID;
	std::cout << "������� ����� ����: ";
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

	std::cout << "������� ���������� �������: ";
	std::cin >> size;
	checkID = new int[size];
	for (short i = 0; i < size; i++)
	{


		do
		{
			std::cout << "\n������� ID ������: ";
			std::cin >> currID;
			std::cout << "\n������� ���������� ������: ";
			std::cin >> currCount;
		} while ((currID < 1 && currID> 10) && (currCount > arrValue[currID - 1] && currCount < 1));
		totalsum += arrPrice[currID - 1] * currCount;
		arrValue[currID - 1] -= currCount;
	}
	std::cout << "�����: " << totalsum << "\n";
	delete[]checkID;
}

void AddValue()
{
	Sklad();

	std::cout << "������� ����� ������: ";
	std::cin >> ID;
	std::cout << "������� ���-�� ������������ ������: ";
	std::cin >> addValue;
	arrValue[ID - 1] += addValue;
	Sklad();

}
void RevueValue()
{
	Sklad();

	std::cout << "������� ����� ������: ";
	std::cin >> ID;
	std::cout << "������� ���-�� ����������� ������: ";
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


			std::cout << "\t\t��� ������������ ������� ������������� '��-�������?)'\n";
			std::cout << "1 - ������ �������\n2 - �������� �����\n3 - ��������� �����\n4 - ��������� �����\n5 - �������� ���� �������\n0 - �����\n\n�����: ";
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

