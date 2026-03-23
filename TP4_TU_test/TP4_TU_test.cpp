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
			Assert::AreEqual(estPair(4), 1);
			Assert::AreEqual(estPair(7), 0);
			Assert::AreEqual(estPair(0), 1);
			Assert::AreEqual(estPair(-2), 1);
			Assert::AreEqual(estPair(-3), 0);
			// tout les test passent pas au début, il y avait marqué == 1 au lieu de == 0
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
		TEST_METHOD(TestSommeTableau)
		{
			int test1[5] = { 1,2,3,4,-5 };
			Assert::AreEqual(sommeTableau(test1, 5), 5);
			int test2[6] = { 4,2,6,0,16,7 };
			Assert::AreEqual(sommeTableau(test2, 6), 35);

		}
	};
}
