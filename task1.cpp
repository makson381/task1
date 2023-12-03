#include <iostream>
#include <vector>
#include <locale>

// Функція для знаходження кількості дільників числа
int countDivisors(int num) {
    int count = 0;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    // Встановлення локалізації
    std::locale::global(std::locale(""));

    int a, b, k;

    // Введення діапазону та кількості дільників
    std::wcout << L"Enter the range [a, b]: ";
    std::wcin >> a >> b;
    std::wcout << L"Enter the number of divisors (k): ";
    std::wcin >> k;

    std::vector<int> resultNumbers; // Масив для зберігання результатів

    // Пошук чисел з вказаною кількістю дільників
    for (int i = a; i <= b; ++i) {
        if (countDivisors(i) == k) {
            resultNumbers.push_back(i);
        }
    }

    // Виведення знайдених чисел
    std::wcout << L"Numbers with " << k << L" divisors: ";
    for (int num : resultNumbers) {
        std::wcout << num << L" ";
    }

    // Знаходження та виведення суми цифр масиву
    int sumOfDigits = 0;
    for (int num : resultNumbers) {
        int tempNum = num;
        while (tempNum != 0) {
            sumOfDigits += tempNum % 10;
            tempNum /= 10;
        }
    }

    std::wcout << L"\nSum of digits in the array: " << sumOfDigits << std::endl;

    return 0;
}
    