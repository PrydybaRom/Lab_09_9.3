#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_09.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestGetInfoByEmployeeName)
        {
            Room directory[100];

            
            addEntry(directory, 0, "01", "John,Doe");

            
            std::ostringstream oss;
            std::streambuf* cout_old = std::cout.rdbuf();
            std::cout.rdbuf(oss.rdbuf()); 

            getInfoByEmployeeName(directory, "Doe");

            std::cout.rdbuf(cout_old); 

            
            std::string expectedOutput = "Номер телефону: 01\nКімната: 1\n";

            Assert::AreEqual(expectedOutput, oss.str());
        }
    };
}
