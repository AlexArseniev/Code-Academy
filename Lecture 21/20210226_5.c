/*
Задача 5 Дефинирайте потребителски тип
към масив. Инициализирайте масива, изведете на
конзолата.
*/
#include <stdio.h>

typedef int array[5];

int main(void){
    int i;
    array myArray = {1, 2, 3, 4, 5};
    
    for(i = 0; i < 5; i++){
        printf("Array[%d] = %d\n", i, myArray[i]);
    }

    return 0;
}