#include <iostream>
#include <Windows.h>
#include <math.h>
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int x1, y1, x2, y2, x3, y3;
	std::cout << "������� ���������� ����� 1" << '\n';
	std::cin >> x1 >> y1;
	std::cout << "������� ���������� ����� 2" << '\n';
	std::cin >> x2 >> y2;
	std::cout << "������� ���������� ����� 3" << '\n';
	std::cin >> x3 >> y3;
	std::cout << '\n';
	float a, b, c;
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	int akx = (x2 - x1);
	int aky = (y2 - y1);
	b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	int bkx(x3 - x1);
	int bky(y3 - y1);
	c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	int ckx(x3 - x2);
	int cky(y3 - y2);
	if (a > b)
	{
		float fiq = a;
		int xk = akx;
		int yk = aky;
		a = b;
		akx = bkx;
		aky = bky;
		b = fiq;
		bkx = xk;
		bky = yk;
	}
	if (b > c)
	{
		float fiq = b;
		b = c;
		bkx = ckx;
		bky = cky;
		c = fiq;
	}
	std::cout << "����������� ";
	if (a + b > c)
	{
		float h;
		if ( akx*bkx + aky*bky == 0)
		{
			std::cout << "������������� ";
			if (a == b)
			{
				std::cout << "� ��������������"<<'\n';
				h = sqrt(pow(a, 2) - pow(c / 2, 2));
				if (c > h)
				{
					if (h > a)
					{
						std::cout << " ����������=" << c << '\n';
						std::cout << " ������=" << h << '\n';
						std::cout << " �����=" << a << '\n';
					}
					else
					{
						std::cout << " ����������=" << c << '\n';
						std::cout << " �����=" << a << '\n';
						std::cout << " ������=" << h << '\n';
					}
				}
				else
				{
					std::cout << " ������=" << h << '\n';
					std::cout << " ����������=" << c << '\n';
					std::cout << " �����=" << a << '\n';
				}
			}
		}
		else
		{
			std::cout << "���������������";
		}
	}
	else
	{
		std::cout << "�� ����������"<<'\n';
	}
	std::cin.ignore(255, '\n');
	std::cout << "������� ������� <enter> ��� ������ �� ���������";
	std::cin.get();
	return 0;
}