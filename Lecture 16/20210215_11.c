/*
Задача 11.
Напишете програма, която умножава 2 числа, като
използва пойнтер-и
*/

#include <stdio.h>


int main(void){

    int a = 2, b = 5, *p_a, *p_b;

    p_a = &a;
    p_b = &b;

    int result = *p_a * *p_b;

    printf("%d", result);


    return 0;
}
