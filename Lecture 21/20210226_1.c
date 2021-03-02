/* Задача 1. Дефинирайте структура като
потребителски тип. Инициализирайте членовете на
структурата, използвайки новия потребителски тип.
Отпечатайте. */

#include <stdio.h>

typedef struct {char c; int i;} t_structure;

int main(void){
    t_structure firstStruct = {.c = 'J', .i = 3};

    printf("Custom structure: Character = %c, Integer = %d", firstStruct.c, firstStruct.i);
    
    return 0;
}