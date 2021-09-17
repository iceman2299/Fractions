#include <iostream>

class fraction
{
    int num;
    int denum;
    void reduce(void);
public:
    fraction();
    fraction(int n, int d);
    fraction(const fraction &f);
    fraction(double val);
    fraction operator+(const fraction &op2);
    fraction operator-(const fraction &op2);
    fraction operator*(const fraction &op2);
    fraction operator/(const fraction &op2);
    friend std::ostream& operator<<(std::ostream& os, const fraction& f);
	friend std::istream& operator>>(std::istream& os, fraction& f);
	int checkzero(int denum);
};