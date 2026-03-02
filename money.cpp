#include "money.hpp"
#include <fstream>
#include <iostream>

using namespace std;

void addMoney(Money a, Money b, Money &result)
{
    result.grn = a.grn + b.grn;
    result.cop = a.cop + b.cop;

    if (result.cop >= 100)
    {
        result.grn += result.cop / 100;
        result.cop %= 100;
    }
}

void multiplyMoney(Money money, int count, Money &result)
{
    result.grn = money.grn * count;
    result.cop = money.cop * count;

    if (result.cop >= 100)
    {
        result.grn += result.cop / 100;
        result.cop %= 100;
    }
}

void roundMoney(Money money, Money &result)
{
    int total = money.grn * 100 + money.cop;
    int lastDigit = total % 10;

    if (lastDigit <= 7)
        total -= lastDigit;
    else
        total += (10 - lastDigit);

    result.grn = total / 100;
    result.cop = total % 100;
}

void printMoney(const Money &money)
{
    cout << money.grn << " грн " << money.cop << " коп" << endl;
}

void start(const char *path)
{
    system("chcp 65001 > nul");
    ifstream file(path);

    if (!file.is_open())
    {
        cout << "Error open file" << endl;
        return;
    }

    Money total = {0, 0};

    string name;
    int count;
    int grn;
    short cop;

    while (file >> name >> grn >> cop >> count)
    {
        if (count < 0 || grn < 0 || cop < 0)
        {
            cout << "Incorrect data in file" << endl;
            file.close();
            return;
        }

        Money item = {grn, cop};
        Money line = {0, 0};
        Money temp = {0, 0};

        multiplyMoney(item, count, line);
        addMoney(total, line, temp);

        total = temp;
    }

    file.close();

    cout << "Total: ";
    printMoney(total);

    Money rounded = {0, 0};
    roundMoney(total, rounded);

    cout << "After round: ";
    printMoney(rounded);
}