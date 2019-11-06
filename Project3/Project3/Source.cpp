#include<iostream>
#include<clocale>
#include<iomanip>


int main() {

	setlocale(LC_ALL, "rus");

	short choice;
	double x;
	double eps;
	bool isError = true;
	char isExit;


	do {



		std::cout << "1. ����� ��������� ���������� ���������.\n";
		std::cout << "2. ����� � �������� ���������.\n";
		std::cout << "3. ����� � ����� ������� ���������.\n";
		std::cout << "4. ������ ��������.\n";
		std::cout << "5. ��������� ������.\n";


		do {
			std::cout << "-> ";
			std::cin >> choice;
			if (!std::cin.good() || choice < 1 || choice > 5) {
				std::cout << "������ �����. ������� ������ ���� �� 1 �� 5.\n"; // cin.good() - ��� ������; cin.fail() - ��� �����
				std::cin.clear(); // ������������� ������.
				std::cin.ignore(std::cin.rdbuf()->in_avail()); // ����� ��� ������ � ������� �������� ��������
			}
			else
				isError = false;
		} while (isError);
		//���������������������������������������������������������������������������������������������������������������������
		if (choice != 5) {

			//--- ���� x ---
			std::cout << "������� �������� x: ";
			do {
				std::cin >> x;
				if (!std::cin.good() || abs(x) < 1) {
					std::cout << "������ �����. ������� ������ ���� �� -1 �� 1.\n"; // cin.good() - ��� ������; cin.fail() - ��� �����
					std::cin.clear(); // ������������� ������.
					std::cin.ignore(std::cin.rdbuf()->in_avail()); // ����� ��� ������ � ������� �������� ��������
				}
				else
					isError = false;
			} while (isError);
			switch (choice) {
			case 1: {
				int n;
				std::cout << "������� ���������� ��������� N:";
				std::cin >> n;
				double s = 0, a = x;
				for (int i = 0; i < n; i++) {
					s += a;
					a *= (i/(i+1))*((x*x)/(i*2-1));
				}
				std::cout << "����� ��������� ���������� ��������� ���� " << s;
				break;
			};
			case 2: {};
			case 3: {

				std::cout << "������� ��������: ";
				std::cin >> eps;
				if (choice == 1)
					eps = eps / 10;
				double s = 0, a = x;
				int i = 0;
				while (fabs(x) >= eps) {
					s += a;
					a *= ((2 * i + 1) * (2 * i + 1) * x * x / ((2 * i + 1) * (2 * i + 3)));
					i++;
				}
				std::cout << "������ �������� ����� " << s;

				break;

			};
			case 4: {
				std::cout << "������ ��������.\n";
				break;
			};
			}

			std::cout << "��������� ������ (Y|N)";
			std::cin >> isExit;
			if (isExit == 'Y' || isExit == 'y')
				choice = 5;
		}

	} while (choice != 5);

}