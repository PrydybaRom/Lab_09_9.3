#include "pch.h"
#include "CppUnitTest.h"
#include "../../Lab_09_3/Lab_09_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourUnitTestNamespace
{
	TEST_CLASS(YourTestClass)
	{
	public:

		TEST_METHOD(TestGetPhoneNumberByRoom)
		{
			const int N = 100;

			Room directory[N];
			directory[0] = { "01", "John, Jane" };
			directory[1] = { "02", "Bob" };

			
			std::ostringstream output1;
			std::streambuf* coutBuffer1 = std::cout.rdbuf();
			std::cout.rdbuf(output1.rdbuf()); 
			getPhoneNumberByRoom(directory, 0);
			std::cout.rdbuf(coutBuffer1);

			Assert::AreEqual("Номер телефону: 01\n", output1.str().c_str());

			
		}
	};
}

