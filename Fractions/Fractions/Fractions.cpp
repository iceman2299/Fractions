#include <iostream>
#include "Fractions.h"

int checkcode = 0;

fraction::fraction()
{
	num = 0;
	denum = 1;
}

fraction::fraction(const fraction& f)
{
	num = f.num;
	denum = f.denum;
}

int checkzero(int denum)
{
	while (denum == 0)
	{
		std::cerr << "Ошибка, знаменатель не может быть нулём" << std::endl;
		return 1;
	}
}

fraction::fraction(int n, int d)
{
	num = n;
	denum = d;
}

fraction::fraction(double val)
{
	int znak = 1;
	int c = 1;
	denum = 1;
	if (val < 0)
	{
		znak = -1;
	}
	int step = 0;
	while (c > 0.0001)
	{
		val = val * 10;
		int temp = int(val);
		c = val - temp;
		step = step + 1;
	}
	num = int(val) * znak;
	for (int i = 0; i < step; i++)
	{
		denum = denum * 10;
	}
}

int nod(int a, int b)
{
	int res = 1;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (a != 0)
	{
		if (a < b)
		{
			int c = a;
			a = b;
			b = c;
		}
		a = a % b;
	}
	res = b;
	return res;
}


void fraction::reduce()
{
	int n = nod(num, denum);
	num = num / n;
	denum = denum / n;
}

fraction fraction::operator+(const fraction& op2)
{
	fraction res;
	res.num = num * op2.denum + op2.num * denum;
	res.denum = denum * op2.denum;
	res.reduce();
	return res;
}

fraction fraction::operator-(const fraction& op2)
{
	fraction res;
	res.num = num * op2.denum - op2.num * denum;
	res.denum = denum * op2.denum;
	res.reduce();
	return res;
}

fraction fraction::operator*(const fraction& op2)
{
	fraction res;
	res.num = num * op2.num;
	res.denum = denum * op2.denum;
	res.reduce();
	return res;
}

fraction fraction::operator/(const fraction& op2)
{
	fraction res;
	res.num = num * op2.denum;
	res.denum = denum * op2.num;
	res.reduce();
	return res;
}

std::ostream& operator<<(std::ostream& os, const fraction& f)
{
	os << f.num << "/" << f.denum << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, fraction& f)
{
	std::cout << "Введите числитель или десятичную дробь" << std::endl;
	double time;
	is >> time;
	f = time;
	if (f.denum < 10)
	{
		std::cout << "Введите знаменатель" << std::endl;
		is >> f.denum;
	}
	return is;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите первое число" << std::endl;
	fraction f;
	std::cin >> f;
	std::cout << "Введите второе число" << std::endl;
	fraction k;
	std::cin >> k;
	fraction t = f + k;
	std::cout << "Сумма чисел = " << t;


}
