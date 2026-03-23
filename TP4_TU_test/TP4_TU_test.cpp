#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Tp4_TU/TP4_TU.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TP4TUtest
{
	TEST_CLASS(TP4TUtest)
	{
	public:
		
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(7), 0);
		}
		TEST_METHOD(TestMax2)
		{
			Assert::AreEqual(max2(7,5), 7);
		}
		TEST_METHOD(TestFactorielle)
		{
			Assert::AreEqual(factorielle(5), 120);
		}
		TEST_METHOD(TestContientMajuscule)
		{
			Assert::AreEqual(contientMajuscule("comment il S'apelle"), 1);
			Assert::AreEqual(contientMajuscule("il s'apelle kante"), 0);

		}
		TEST_METHOD(TestDivisionExacte)
		{
			Assert::AreEqual(divisionExacte(14,2), 1);
			Assert::AreEqual(divisionExacte(15, 2), 0);

		}
	};
}
