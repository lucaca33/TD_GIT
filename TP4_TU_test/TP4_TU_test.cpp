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
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(max2(7,5), 5);
		}
	};
}
