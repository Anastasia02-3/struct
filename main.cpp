#include <iostream>
#include "money.hpp"
using namespace std;

int main() {
    FILE* f;
    if (fopen_s(&f,"input.txt","r")) return 0;

    Money money{0,0}; 
    int grn, count; 
    short cop;

    char name[50];
    while (fscanf_s(f,"%s %d %hd %d", name, sizeof(name), &grn, &cop, &count) == 4){
        if (grn < 0 || count < 0 || cop < 0){ 
            cout<<"Інвалід вводь додані значення"; 
            return 0; 
        }
        else{
            money = addMoney(money, multiplyMoney({grn, cop}, count));
        }
    }

    fclose(f);
    money = roundMoney(money);
    printMoney(money);
}