/*
Задача 9.
Разширяване на заделена памет с realloc
Напишете програма, която пита потребителя колко
памет иска и заделя съответния блок памет. След
това попитайте потребителя за нов размер и
използвайте функция, която прави това.
*/

#include <stdlib.h>
#include <stdio.h>

int *p = NULL;
int size = 0;

void makeItBigger(void);

int main(void){


    printf("How much memory do you want alocate for the array?\n");
    scanf("%d", &size);
    
    p = (int*)  malloc(size * sizeof(int));

    if(NULL == p){
        printf("You ran out of space, sorry... not sorry");
        exit(1);
    }

    printf("The alocated memory is: %d\n", (size * sizeof(int)));
 
    printf("If you want to expand the size of the array press 1\nIf you want to keep the current size press any key?\n");

    int answer = 0; 
    
    scanf("%d", &answer);

    if(answer == 1){
        makeItBigger();
    } else {
        printf("Your array will remain with size: %d", (size * sizeof(int)));
    }

    free(p);

    return 0;
}

void makeItBigger(void){
        printf("Enter the new size of the array: \n");
        scanf("%d", &size);
        p = (int*) realloc(p, size * sizeof(int));
        if(NULL == p){
            printf("Hodi si kupi oshte pamet");
            exit(2);
        }
        printf("The alocated memory is: %d\n", (size * sizeof(int)));
}
