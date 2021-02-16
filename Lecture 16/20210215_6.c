/*
Задача 6.
Дефинирайте променлива „а“, дeфинирайте пойнтер към
нея, присвоете му адреса на променливата. През пойнтера
задайте нова стойност = 5 на променливата „а“. Каква е
стойността на “а”?
*/

#include <stdio.h>

int main(void){

    int a; 
    printf("The value of \"a\" before the pointer: %d\n", a);
    int *p = &a;
    *p = 5;
    printf("The value of \"a\" after the pointer: %d\n", a);

    return 0;
}
