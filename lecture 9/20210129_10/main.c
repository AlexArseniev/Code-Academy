/*
Задача 10. Напишете програма на С, която съдържа 3 функции,
изнесете прототипите им в отделен .h файл.
1. Първата функция да калкулира най-малко общо кратно на две положителни
числа.
2. Втората функция връща абсолютна стойност на числата (положителната
стойност на числата).
a. Трябва да може да приеме като параметър float и да върне float.
b. Тествайте с инт и float.
3. Напишете функция, която калкулира корен квадратен от число.
a. Проверете дали резултатът е отрицателно число и върнете -1.
b. Използвайте втората си функция, за да обърнете числото в положително и
да намерите корен квадратен от него.
*/

#include <stdio.h>
#include <math.h>
#include "10.h"


int main(void){

    int result = 0;

    while (1){

        int a = 0;

        printf("What funcion do you want to use?\n");
        printf("If you want to get the lowest common multiple of two numbers - press 1.\n");
        printf("If you want to find the absolute value of two numbers - press 2.\n");
        printf("If you want to find the square root of a number - press 3.\n");
        printf("If you want to exit the program - press 9\n");
        scanf("%d", &a);

        if(a == 1) {
            int numOne = 0;
            int numTwo = 0;
            printf("Please, enter two positive numbers: ");
            scanf("%d %d", &numOne, &numTwo);

            int result = lcMult(numOne, numTwo);

            printf("The lowest common multiple of %d and %d is %d\n\n", numOne, numTwo, result);

        } else if(a == 2){
            float numOne = 0;
            float numTwo = 0;
            printf("Please, enter two numbers: ");
            scanf("%f %f", &numOne, &numTwo);

            float absNumOne = absolute(numOne);
            float absNumTwo = absolute(numTwo);

            printf("The absoulute values of %f and %f are %f and %f\n\n", numOne, numTwo, absNumOne, absNumTwo);
        } else if(a == 3){

            int number = 0;
            printf("Please enter a number: ");
            scanf("%d", &number);
            int result = root(number);

            if(number <0){
                printf("%d is a negative number. The square root of its positive value is %d.\n", number, result);
            } else {
                printf("Square root of %d is %d.\n", number, result);
            }

        } else if(a == 9){
            break;
        } else {
            printf("Please, enter a valid number\n");
        }
        
    }
    
    return 0;
}
