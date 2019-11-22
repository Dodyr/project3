#include<iostream>
#include<clocale>
#include<iomanip>


int main()
{

	setlocale(LC_ALL, "rus");

	short choice;
	double x;
	double eps;
	bool isError = true;
	char isExit;


	do
	{



		std::cout << "1. ����� ��������� ���������� ���������.\n";
		std::cout << "2. ����� � �������� ���������.\n";
		std::cout << "3. ��������� ������.\n";


		do
		{
			std::cout << "-> ";
			std::cin >> choice;
			if (!std::cin.good() || choice < 1 || choice > 3)
			{
				std::cout << "������ �����. ������� ������ ���� �� 1 �� 3.\n";
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
			}
			else
				isError = false;
		} while (isError);
		isError = true;
		if (choice != 3)
		{
			std::cout << "������� �������� x: ";
			do
			{
				std::cin >> x;
				if (!std::cin.good() || abs(x) >= 1)
				{
					std::cout << "������ �����. ������� ������ ���� �� -1 �� 1.\n";
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
				}
				else
					isError = false;
			} while (isError);
			switch (choice)
			{
			case 1:
			{
				int n;
				std::cout << "������� ���������� ��������� N:";
				std::cin >> n;
				n = n - 2;
				double s = x, a = x;
				for (int i = 0; i < n; i++)
				{
					a *= ((2 * i + 1) * x * x * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3));
					s += a;
				}
				std::cout << "����� ��������� ���������� ��������� ����� " << "\n                            " << s << "\n";
				break;
			}
			case 2:
			{
				std::cout << "������� ��������: ";
				std::cin >> eps;
				double s = x, a = x;
				int i = 0;
				do
				{
					a *= ((2 * i + 1) * x * x * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3));
					s += a;
					i++;
				} while (abs(asin(x) - s) >= eps);
				std::cout << "������ �������� �����       " << asin(x) << "\n";
				std::cout << "������������ �������� ����� " << s << "\n";
				std::cout << "���������� ��������         " << i + 2 << "\n";
				std::cout << "��������                    " << eps << "\n";
				eps = eps / 10;
				i = 0;
				s = x;
				a = x;
				do
				{
					a *= ((2 * i + 1) * x * x * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3));
					s += a;
					i++;
				} while (abs(asin(x) - s) >= eps);
				std::cout << "����� ������ �������� ����� " << s << "\n";
				std::cout << "���������� ��������         " << i + 2 << "\n";
				break;
			}
			}
		}
		else
		{
			std::cout << "��������� ������ (Y|N)" << "\n";
			std::cin >> isExit;
			if (isExit == 'Y' || isExit == 'y')
				choice = 4;
		}
	} while (choice != 4);
}