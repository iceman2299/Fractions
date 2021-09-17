#include <iostream>
#include "Fractions.h"


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

fraction::fraction(int n, int d)
{
	while (d == 0)
	{
		std::cerr << "Ошибка, знаменатель не может быть нулём" << std::endl;
	}
	num = n;
	denum = d;
}

fraction::fraction(double val)
{

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
	denum = denum = n;
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

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 5;
	int b = 0;
	fraction f(a, b);
	fraction c = f + f;
	std::cout << c;


}
