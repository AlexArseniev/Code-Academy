/*
Задача 1. Да се направи програма, която заделя динамичен масив с брой елементи
зададени от потребителя. За всеки елемент от масива се очаква потребителят да въведе
цяло и число и след това се изчислява сумата на всички елементи от масива.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int i = 0, l = 0, sum = 0;
    printf("Please, eneter the length of the array: ");
    scanf("%d", &l);

    int *p = NULL;
    p = (int*) malloc(l * sizeof(int));


    printf("Please, eneter %d numbers\n", l);

    for(i = 0; i < l; i++){
        int number = 0;
        scanf("%d", &number);
        p[i] = number;
        sum += *(p + i);
    }
 
    free(p);

    printf("The sum of the numbers is: %d", sum);

    return 0;
}
