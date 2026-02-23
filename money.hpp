#ifndef MONEY_H
#define MONEY_H

struct Money
{
    int grn;
    short int cop;
};

Money addMoney(Money money1, Money money2), multiplyMoney(Money money, int count), roundMoney(Money money);
void printMoney(Money money);

#endif