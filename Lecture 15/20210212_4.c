/*
Задача 4.
Заделяне и освобождаване на памет - malloc, free. Заделете
динамично памет за масив и попълнете елементите
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int *p = NULL, l = 0;

    printf("Please enter the length of the array:\n");
    scanf("%d", &l);

    p = (int*) malloc(l * sizeof(int));

    if(NULL == p){
        printf("You overestimated the power of your computer!!!");
        exit(1);
    }

    printf("Enter %d elements to fill the array\n", l);
    for(int i = 0; i < l; i++){
        scanf("%d", p + i);
    }
    for(int j = 0; j < l; j++){
        printf("%d", *(p+j));
    }

    free(p);

    return 0;
}
