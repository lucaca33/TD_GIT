#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../TP4_TU_PARC/cas.h"
#include "../TP4_TU_PARC/parc.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TP4TUPARCTEST
{
	TEST_CLASS(TP4TUPARCTEST)
	{
	public:
		
		TEST_METHOD(TestCreerFile)
		{
			File* test = creerFile();
			Assert::IsNull(test->premier);
			Assert::IsNull(test->dernier);
		}
		TEST_METHOD(TestCreerGroupe)
		{
			Groupe* test = creerGroupe(8);
			Assert::IsNull(test->suivant);
			Assert::AreEqual(test->taille, 8);
		}
		TEST_METHOD(TestGain)
		{
			File* test1 = creerFile();
			Groupe* test2 = creerGroupe(2);
			Groupe* test3 = creerGroupe(3);
			ajouterGroupeDansFile(test2, test1);
			ajouterGroupeDansFile(test3, test1);
			
			Assert::AreEqual((int)gains(test1, 2, 3, 2), 5);
		}
	};
}
