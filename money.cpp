#include "money.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

void addMoney(Money *money, Money *other)
{
    money->grn += other->grn;
    money->cop += other->cop;
}

void multiplyMoney(Money *money, int count)
{
    money->grn *= count;
    money->cop *= count;
}

void roundMoney(Money *money)
{
    int lastDigit = money->cop % 10;
    money->cop = (money->cop / 10) * 10;
    if (lastDigit >= 8) {
        money->cop += 10;
    }
}

void printMoney(Money *money)
{
    system("chcp 65001 > nul");
    cout << money->grn << " грн " << money->cop << " коп" << endl;
}

void start(const char *path)
{
    FILE *file;
    int err = fopen_s(&file, path, "r");
    if (err != 0 || file == nullptr)
    {
        cout << "Error open file" << endl;
        return;
    }

    Money total = {0, 0};
    char name[100];
    int count;
    int grn;
    short int cop;

    while (fscanf_s(file, "%s %d %hd %d", name, sizeof(name), &grn, &cop, &count) == 4)
    {
        if (count < 0 || grn < 0 || cop < 0)
        {
            cout << "Incorrect data in file" << endl;
            fclose(file);
            return;
        }
        Money temp = {grn, cop};
        multiplyMoney(&temp, count);
        addMoney(&total, &temp);
    }

    if(total.cop >= 100){
        total.grn += total.cop / 100;
        total.cop %= 100;
    }

    cout << "Total: ";
    printMoney(&total);

    roundMoney(&total);

    cout << "After round: ";
    printMoney(&total);

    fclose(file);
}