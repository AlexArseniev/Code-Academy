/*
Продължение: Опитайте да умножите 2 променливи от
различен тип, използвайки пойнтери.
*/

#include <stdio.h>

int main(void){

    int a;
    float b;
    printf("Please enter a number of type int: ");
    scanf("%d", &a);
    printf("Please enter a number of type float: ");
    scanf("%f", &b);


    int* p_a = &a;
    float* p_b = &b;

    float result = 0; 
    result = *p_a * *p_b;

    printf("%.2f", result);

    return 0;
}
