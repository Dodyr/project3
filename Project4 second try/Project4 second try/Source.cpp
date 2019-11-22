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



		std::cout << "1. Сумма заданного количества слагаемых.\n";
		std::cout << "2. Сумма с заданной точностью.\n";
		std::cout << "3. Завершить работы.\n";


		do
		{
			std::cout << "-> ";
			std::cin >> choice;
			if (!std::cin.good() || choice < 1 || choice > 3)
			{
				std::cout << "Ошибка ввода. Значени должно быть от 1 до 3.\n";
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
			}
			else
				isError = false;
		} while (isError);
		isError = true;
		if (choice != 3)
		{
			std::cout << "Введите значение x: ";
			do
			{
				std::cin >> x;
				if (!std::cin.good() || abs(x) >= 1)
				{
					std::cout << "Ошибка ввода. Значени должно быть от -1 до 1.\n";
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
				std::cout << "Введите количество слагаемых N:";
				std::cin >> n;
				n = n - 2;
				double s = x, a = x;
				for (int i = 0; i < n; i++)
				{
					a *= ((2 * i + 1) * x * x * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3));
					s += a;
				}
				std::cout << "Сумма заданного количества слагаемых равна " << "\n                            " << s << "\n";
				break;
			}
			case 2:
			{
				std::cout << "Введите точность: ";
				std::cin >> eps;
				double s = x, a = x;
				int i = 0;
				do
				{
					a *= ((2 * i + 1) * x * x * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3));
					s += a;
					i++;
				} while (abs(asin(x) - s) >= eps);
				std::cout << "Точное значение равно       " << asin(x) << "\n";
				std::cout << "Приближенное значение равно " << s << "\n";
				std::cout << "Количество слагамых         " << i + 2 << "\n";
				std::cout << "Точность                    " << eps << "\n";
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
				std::cout << "Более точное значение равно " << s << "\n";
				std::cout << "Количество слагамых         " << i + 2 << "\n";
				break;
			}
			}
		}
		else
		{
			std::cout << "Завершить работу (Y|N)" << "\n";
			std::cin >> isExit;
			if (isExit == 'Y' || isExit == 'y')
				choice = 4;
		}
	} while (choice != 4);
}