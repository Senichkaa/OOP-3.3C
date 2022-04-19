#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 3.3C/FuzzyNumber.cpp"
#include "../OOP 3.3C/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTOOP33C
{
	TEST_CLASS(UTOOP33C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber A(3.5, 1.2, 7.9), B(4.3, 2.0, 8.4);
			FuzzyNumber C = A + B;
			Assert::AreEqual(C.get_x(), 7.8);
		}
	};
}
