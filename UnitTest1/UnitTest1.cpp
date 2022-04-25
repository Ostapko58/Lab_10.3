#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.3/Lab_10.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		string FromFile(char* fname)
		{
			ifstream fin(fname);
			string s;
			getline(fin, s);
			fin.close();
			return s;
		}


		TEST_METHOD(TestMethod1)
		{
			string List[] =
			{
				"звичайний",
				"підвищеного комфорту",
				"швидкісний експрес"
			};
			AutoCreat("proba.txt", 1, List, "стрий", 0, 6, 56);
			string s = FromFile("proba.txt");
			string s2 = "стрий звичайний 6:56";
			Assert::AreEqual(s, s2);
		}
	};
}
