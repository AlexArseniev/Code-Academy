/*
Задача 7.
Заделяне на памет с calloc
*/

#include <stdio.h>
#include <stdlib.h>


int main(void){

    int* p = NULL;
    int l = 0, i = 0, n = 0; 
    printf("Please, enter the desired length of your array: \n");
    scanf("%d", &l);

    p = (int*) calloc(l, sizeof(int));

    if(NULL == p){
        printf("Game over!");
        exit(1);
    }

    printf("The array before the entered values\n");
    for(i = 0; i < l; i++){
        printf("%d", *(p + i));
    }

    i = 0;

    printf("\nPlease enter %d digits to fill the array\n", l);
    for(i; i < l; i++){
        scanf("%d", &n);
        *(p + i) = n;
    }

    i = 0;

    printf("The array after we enter values\n");
    for(i = 0; i < l; i++){
        printf("%d", *(p + i));
    }

    
    free(p);


    return 0;
}
