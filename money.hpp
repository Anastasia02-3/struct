#ifndef MONEY_HPP
#define MONEY_HPP

#include <iostream>

struct Money
{
    int Moneyg;   
    int Moneuk;   
};

void normalize(Money& money);
void addMoney(Money& result, Money a, Money b);
void multiplyMoney(Money& result, Money a, int count);
void roundTo10(Money& money);
void printMoney(const Money& money);
void start(const char* filename);

#endif