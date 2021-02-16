/*
Дефинирайте и инициализирайте три пойнтера, тип int, тип
float, тип char.
*/

#include <stdio.h>

int main(void){

    int number = 10;
    float pi = 3.14;
    char letter = 'a';

    int* n;
    float* p;
    char* l;

    n = &number;
    p = &pi;
    l = &letter;  

    printf("%d\n", *n);
    printf("%.2f\n", *p);
    printf("%c\n", *l);


    return 0;
}
