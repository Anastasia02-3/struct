#include "money.hpp"
#include <iostream>

Money fixCops(Money money)
{
    money.grn = money.grn + money.cop / 100;
    money.cop = money.cop % 100;

    return money;
}

Money addMoney(Money m1, Money m2)
{
    Money result;

    result.grn = m1.grn + m2.grn;
    result.cop = m1.cop + m2.cop;

    result = fixCops(result);

    return result;
}

Money multiplyMoney(Money money, int count)
{
    Money result;

    result.grn = money.grn * count;
    result.cop = money.cop * count;

    result = fixCops(result);

    return result;
}

Money roundMoney(Money money)
{
    int remainder = money.cop % 10;

    if (remainder >= 5)
        money.cop = money.cop + (10 - remainder);
    else
        money.cop = money.cop - remainder;

    money = fixCops(money);

    return money;
}

void printMoney(Money money){
    std::cout << money.grn << " грн " << money.cop << " коп\n";
}