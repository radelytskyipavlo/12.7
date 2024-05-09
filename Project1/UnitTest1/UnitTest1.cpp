#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


    namespace UnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestRemoveEven)
        {
            Elem* list = NULL;
            Elem* last = NULL;
            enqueue(list, last, 1);
            enqueue(list, last, 2);
            enqueue(list, last, 3);
            enqueue(list, last, 4);
            enqueue(list, last, 5);

            removeEven(list);

            // Expected result: 1 3 5
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            printList(list);
            std::string result = buffer.str();
            std::cout.rdbuf(old);

            Assert::AreEqual(std::string("1 3 5 \n"), result);
        }
    };
}