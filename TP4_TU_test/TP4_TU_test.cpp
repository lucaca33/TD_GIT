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
			Assert::AreEqual(max2(5, 3), 5);
			Assert::AreEqual(max2(3, 5), 5);
			Assert::AreEqual(max2(-1, -8), -1);
			Assert::AreEqual(max2(4, 4), 4);
			// le test 2 
		}
		TEST_METHOD(TestFactorielle)
		{
			Assert::AreEqual(factorielle(0), 1);
			Assert::AreEqual(factorielle(1), 1);
			Assert::AreEqual(factorielle(4), 24);
			Assert::AreEqual(factorielle(5), 120);
			// non, le comportement sur les négatifs ne doit pas etre accepté, on doit renvoyer un NULL
		}
		TEST_METHOD(TestContientMajuscule)
		{
			Assert::AreEqual(contientMajuscule("bonjour"), 0);
			Assert::AreEqual(contientMajuscule("BonJour"), 1);
			Assert::AreEqual(contientMajuscule("ABC"), 1);
			Assert::AreEqual(contientMajuscule(""), 0);

		}
		TEST_METHOD(TestDivisionExacte)
		{
			Assert::AreEqual(divisionExacte(10,2), 1);
			Assert::AreEqual(divisionExacte(10, 3), 0);
			Assert::AreEqual(divisionExacte(0, 5), 1);
			Assert::AreEqual(divisionExacte(10, 0), 0);
			// ce cas est dangereux car on divise par 0

		}
		TEST_METHOD(TestSommeTableau)
		{
			int test1[] = { 1,2,3 };
			Assert::AreEqual(sommeTableau(test1, 3), 6);
			int test2[] = { 5 };
			Assert::AreEqual(sommeTableau(test2, 1), 5);
			int test3[] = { -1, 4, -3 };
			Assert::AreEqual(sommeTableau(test3, 3), 0);
			//int test4[] = {}; impossible de faire un tableau vide
			//Assert::AreEqual(sommeTableau(test2, 3), 0);

		}
	};
}
