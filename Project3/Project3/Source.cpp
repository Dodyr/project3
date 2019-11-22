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
				if (!std::cin.good() || abs(x) > 1)
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
			    	double s = 0, a = x;
			    	for (int i = 1; i <= 2 * n; i = i + 2)
			    	{
			    		s += a / (i + 2);
			    		a *= i * x * x / (i + 1);
			     	}
			    	std::cout << "����� ��������� ���������� ��������� ����� " << s << "\n";
			    	break;
			    }
		    	case 2:
				{
					std::cout << "������� ��������: ";
					std::cin >> eps;
					double s = 0, a = x;
					int i = 1;
					while (fabs(a) >= eps)
					{
						s += a / (i + 2);
						a *= i * x * x / (i + 1);
						i = i + 2;
					}
					std::cout << "������ �������� ����� " << s << "\n";
					break;
				}
			}
		}
		else
		{
			std::cout << "��������� ������ (Y|N)"<<"\n";
			std::cin >> isExit;
			if (isExit == 'Y' || isExit == 'y')
				choice = 4;
		}
	} while (choice != 4);
}