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



		std::cout << "1. Сумма заданного количества слагаемых.\n";
		std::cout << "2. Сумма с заданной точностью.\n";
		std::cout << "3. Сумма с более высокой точностью.\n";
		std::cout << "4. Точное значение.\n";
		std::cout << "5. Завершить работы.\n";


		do {
			std::cout << "-> ";
			std::cin >> choice;
			if (!std::cin.good() || choice < 1 || choice > 5) {
				std::cout << "Ошибка ввода. Значени должно быть от 1 до 5.\n"; // cin.good() - все хорошо; cin.fail() - все плохо
				std::cin.clear(); // разблокировка потока.
				std::cin.ignore(std::cin.rdbuf()->in_avail()); // вроде как чистим и удаляем введённое значение
			}
			else
				isError = false;
		} while (isError);
		//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
		if (choice != 5) {

			//--- ввод x ---
			std::cout << "Введите значение x: ";
			do {
				std::cin >> x;
				if (!std::cin.good() || abs(x) < 1) {
					std::cout << "Ошибка ввода. Значени должно быть от -1 до 1.\n"; // cin.good() - все хорошо; cin.fail() - все плохо
					std::cin.clear(); // разблокировка потока.
					std::cin.ignore(std::cin.rdbuf()->in_avail()); // вроде как чистим и удаляем введённое значение
				}
				else
					isError = false;
			} while (isError);
			switch (choice) {
			case 1: {
				int n;
				std::cout << "Введите количество слагаемых N:";
				std::cin >> n;
				double s = 0, a = x;
				for (int i = 0; i < n; i++) {
					s += a;
					a *= (i/(i+1))*((x*x)/(i*2-1));
				}
				std::cout << "Сумма заданного количества слагаемых раен " << s;
				break;
			};
			case 2: {};
			case 3: {

				std::cout << "Введите точность: ";
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
				std::cout << "Точное значение равно " << s;

				break;

			};
			case 4: {
				std::cout << "Точное значение.\n";
				break;
			};
			}

			std::cout << "Завершить работу (Y|N)";
			std::cin >> isExit;
			if (isExit == 'Y' || isExit == 'y')
				choice = 5;
		}

	} while (choice != 5);

}