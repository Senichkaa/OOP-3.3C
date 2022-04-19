//Source.cpp
#include "FuzzyNumber.h"

int main()
{
	double x, l, r;
	do
	{
		cout << "x = "; cin >> x;
		cout << "l = "; cin >> l;
		cout << "r = "; cin >> r;
	} while (!(x > (x - l) && (x + r) > x));

	FuzzyNumber A(x, l, r), B;
	cout << "A = " << A << endl;

	cin >> B;
	cout << "B = " << B << endl;

	cout << "Number of elements of class FuzzyNumber : " << FuzzyNumber::Count() << "\n";
	cout << "\n";

	FuzzyNumber C = A + B;
	cout << "C = " << C << endl;
	cout << "Number of elements of class FuzzyNumber(sum) : " << FuzzyNumber::Count()<<"\n";
	cout << "\n";
	
	FuzzyNumber D = A * B;
	cout << "D = " << D << endl;
	cout << "Number of elements of class FuzzyNumber(multiply) : " << FuzzyNumber::Count() << "\n";
}