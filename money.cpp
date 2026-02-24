#include "money.hpp"
#include <fstream>
#include <string>
#include <sstream>

void addMoney(Money& result, Money a, Money b)
{
    result.Moneuk = a.Moneuk + b.Moneuk;
    result.Moneyg = a.Moneyg + b.Moneyg + result.Moneuk / 100; 
    result.Moneuk %= 100;
}

void multiplyMoney(Money& result, Money a, int count)
{
    result.Moneuk = a.Moneuk * count;
    result.Moneyg = a.Moneyg * count + result.Moneuk / 100; 
    result.Moneuk %= 100;
}

void roundTo10(Money& money)
{
    int lastDigit = money.Moneuk % 10;
    if (lastDigit <= 7)
        money.Moneuk -= lastDigit;
    else
        money.Moneuk += (10 - lastDigit);

    money.Moneyg += money.Moneuk / 100;
    money.Moneuk %= 100;
}

void printMoney(const Money& money)
{
    std::cout << money.Moneyg << " грн ";
    if (money.Moneuk < 10) std::cout << "0";
    std::cout << money.Moneuk << " коп";
}

void start(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Помилка відкриття файлу!\n";
        return;
    }

    Money total{0,0};
    Money temp;
    Money price;

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name;
        int count, grn, cop;

        if (!(iss >> name >> count >> grn >> cop))
        {
            std::cout << "Помилка в рядку  інвалід : " << line << "\n";
            continue;
        }

        if (count <= 0 || grn < 0 || cop < 0 || cop >= 100)
        {
            std::cout << "Інвалід вводь додатні значення: " << line << "\n";
            continue;
        }

        price.Moneyg = grn;
        price.Moneuk = cop;

        multiplyMoney(temp, price, count);
        addMoney(total, total, temp);
    }

    file.close();

    std::cout << "Загальна сума чеку: ";
    printMoney(total);
    std::cout << "\n";

    roundTo10(total);

    std::cout << "До оплати (з округленням): ";
    printMoney(total);
    std::cout << "\n";
}