/*

Задача 9. Дефинирайте и инициализирайте променлива „а“.
Пойнтер към пойнтер към променлива.
Дефинирайте и инициализирайте пойнтер към нея.
Дефинирайте и инициализирайте пойнтер към първия пойнтер. Задайте
стойност на втория пойнтер 15.
Колко е стойността на променливата „а“?

*/


#include <stdio.h>

int main(void){

    int a = 0;

    int* p_a = &a;
    int **p_p = &p_a;
    
    **p_p = 15;

    printf("%d", a);


    return 0;
}
