/*
Задача 8.
Дефинирайте и инициализирайте променлива и пойнтер
към нея. Отпечатайте адреса на пойнтера с %p с printf.
*/

#include <stdio.h>

int main(void){

    int a = 10;
    int* p = &a;

    printf("%p\n", &p); //адресът на пойнтера;
    printf("%p\n", p); // адреса, към който сочи пойнтерът;
    printf("%p\n", &a); // адресът на "а";

    return 0;
}
