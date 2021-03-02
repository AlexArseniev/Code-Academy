/*Задача 9. Изведете резултата от деленето на две цели
числа от тип int като double с преобразуване и без такова*/
#include <stdio.h>
int main()
{
    int iValue = 47;
    int iDiv = 3;
    double dfRes = (double)iValue / iDiv;
    int iRes=iValue/iDiv;
    printf("Value of dfResof: %lf, value of iRes: %d\n", dfRes, iRes);
    return 0;
}