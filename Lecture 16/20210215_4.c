/*
Задача 4.
Дефинирайте пойнтер и опитайте да отпечатате стойността
му на конзолата (%р) с printf.
Какво се визуализира?
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int a;
    int* p = &a;

    printf("%x\n", p);
    printf("%X\n", p);
    printf("%p\n", p);

    return 0;
}
