//FuzzyNumber.cpp
#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
{
	x = 0;
	l = 0;
	r = 0;
}

FuzzyNumber::FuzzyNumber(double X, double L, double R)
{
	x = X;
	l = L;
	r = R;
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
{
	x = v.x;
	l = v.l;
	r = v.r;
}

FuzzyNumber& FuzzyNumber::operator=(const FuzzyNumber& n)
{
	set_x(n.get_x());
	set_l(n.get_l());
	set_r(n.get_r());
	return *this;
}

FuzzyNumber::operator string() const
{
	stringstream ss;
	ss << "(" << l << "; " << x << "; " << r << ")" << endl;
	return ss.str();
}

FuzzyNumber& FuzzyNumber::operator--()
{
	this->set_x(this->get_x() - 1);
	return *this;
}

FuzzyNumber& FuzzyNumber::operator++()
{
	this->set_x(this->get_x() + 1);
	return *this;
}

FuzzyNumber FuzzyNumber::operator--(int)
{
	FuzzyNumber a(*this);
	this->set_r(this->get_r() - 1);
	return a;	
}

FuzzyNumber FuzzyNumber::operator++(int)
{
	FuzzyNumber a(*this);
	this->set_r(this->get_r() + 1);
	return a;
}

FuzzyNumber operator+(FuzzyNumber a, FuzzyNumber b)
{
	FuzzyNumber T(0, 0, 0);
	T.set_l(a.get_l() + b.get_l());
	T.set_x(a.get_x() + b.get_x());
	T.set_r(a.get_r() + b.get_r());
	return T;
}

FuzzyNumber operator*(FuzzyNumber a, FuzzyNumber b)
{
	FuzzyNumber N(0, 0, 0);
	N.set_l(a.get_x() * b.get_x() - b.get_x() * a.get_l() - a.get_x() * b.get_l() - a.get_l() * b.get_l());
	N.set_x(a.get_x() * b.get_x());
	N.set_r(a.get_x() * b.get_x() + b.get_x() * a.get_r() + a.get_x() * b.get_r() + a.get_r() * b.get_r());
	return N;

}

ostream& operator<<(ostream& out, FuzzyNumber& a)
{
	out << string(a);
	return out;
}

istream& operator>>(istream& in, FuzzyNumber& a)
{
	double x, l, r;
	cout << "x = "; in >> x;
	cout << "l = "; in >> l;
	cout << "r = "; in >> r;
	a.set_x(x); a.set_l(l); a.set_r(r);
	return in;
}
