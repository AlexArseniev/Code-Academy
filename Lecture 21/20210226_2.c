/*
Задача 2 Създайте нов потребителски тип
към тип long long int. Използвайте го във функцията
printf, отпечатайте размера.
*/

#include <stdio.h>

typedef long long int t_customLLI;

int main(void){
    t_customLLI number = 240795270199;
    printf("Value of custom type = %lld\nSize of custom type = %d Bytes",number, sizeof(t_customLLI));

    return 0;
}