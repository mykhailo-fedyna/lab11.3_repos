#include "pch.h"
#include "CppUnitTest.h"
#include "../lab11.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тестуємо функцію parseDate
        TEST_METHOD(TestParseDateValid)
        {
            int day, month, year;
            string dateStr = "15.08.1992";
            bool result = parseDate(dateStr, day, month, year);

            Assert::IsTrue(result);  // Перевіряємо, що функція повертає true
            Assert::AreEqual(15, day);  // Перевіряємо значення дня
            Assert::AreEqual(8, month);  // Перевіряємо значення місяця
            Assert::AreEqual(1992, year);  // Перевіряємо значення року
        }

        // Тестуємо функцію parseDate для некоректного формату
        TEST_METHOD(TestParseDateInvalidFormat)
        {
            int day, month, year;
            string dateStr = "15-08-1992";  // Некоректний формат
            bool result = parseDate(dateStr, day, month, year);

            Assert::IsFalse(result);  // Перевіряємо, що функція повертає false
        }

        // Тестуємо функцію isValidDate
        TEST_METHOD(TestIsValidDate)
        {
            // Коректні дати
            Assert::IsTrue(isValidDate(29, 2, 2020));  // 29 лютого у високосному році
            Assert::IsTrue(isValidDate(31, 12, 1999));  // 31 грудня
            Assert::IsTrue(isValidDate(28, 2, 2023));  // 28 лютого у невисокосному році

            // Некоректні дати
            Assert::IsFalse(isValidDate(30, 2, 2023));  // Немає 30 лютого
            Assert::IsFalse(isValidDate(32, 1, 2023));  // Немає 32 січня
            Assert::IsFalse(isValidDate(31, 4, 2023));  // Немає 31 квітня
        }

        // Тестуємо функцію parseDate для неіснуючої дати
        TEST_METHOD(TestParseDateInvalidDate)
        {
            int day, month, year;
            string dateStr = "30.02.2023";  // Невірна дата
            bool result = parseDate(dateStr, day, month, year);

            Assert::IsFalse(result);  // Перевіряємо, що функція повертає false
        }
    };
}
