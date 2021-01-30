/*
Задача 9. Напишете три функции, които да правят изчисление по ваш
избор и да се извикват по следния начин:
Main вика Ф1;
Ф1 вика Ф 2;
Ф2 вика Ф3;
Изнесете прототипите им в отделен .h файл.
*/


#include <stdio.h>
#include "9.h"

int main(void){

    int fistNumber = 0; 

    printf("Enter number: ");
    scanf("%d", &fistNumber);

    int result = addition(fistNumber);

    printf("%d", result);

    return 0;
}

int addition(int a){
    int result = a + a;
    division(result);
}

int division(int b){
    int result = b / 2;
    power(result);
}

int power(int c){
    return c * c;
}
