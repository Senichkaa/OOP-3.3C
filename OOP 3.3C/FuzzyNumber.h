//FuzzyNumber.h
#pragma once
#pragma pack(1)
#include "Object.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FuzzyNumber : public Object
{
private:
	double x, l, r;
public:
	FuzzyNumber();
	FuzzyNumber(double x, double l, double r);
	FuzzyNumber(const FuzzyNumber& v);

	void set_x(double value) { x = value; }
	void set_r(double value) { r = value; }
	void set_l(double value) { l = value; }

	double get_x() const { return x; }
	double get_r() const { return r; }
	double get_l() const { return l; }

	FuzzyNumber& operator =(const FuzzyNumber& n);
	operator string() const;

	FuzzyNumber& operator --();
	FuzzyNumber& operator ++();
	FuzzyNumber operator --(int);
	FuzzyNumber operator ++(int);

	friend FuzzyNumber operator + (FuzzyNumber a, FuzzyNumber b);
	friend FuzzyNumber operator * (FuzzyNumber a, FuzzyNumber b);

	friend ostream& operator << (ostream& out, FuzzyNumber& a);
	friend istream& operator >> (istream& in, FuzzyNumber& a);
};

