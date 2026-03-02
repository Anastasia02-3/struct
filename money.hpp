#ifndef MONEY_HPP
#define MONEY_HPP

struct Money
{
    int grn;
    short int cop;
};

void addMoney(Money *money, Money *other);
void multiplyMoney(Money *money, int count);
void roundMoney(Money *money);
void printMoney(Money *money);
void start(const char *path);

#endif