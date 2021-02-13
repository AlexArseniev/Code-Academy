/*
Задача 5 Разширяване на заделена памет с realloc.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int* p = NULL;
    int l = 0, i = 0;
    printf("Please enter length:\n");
    scanf("%d", &l);


    p = (int* ) malloc(l * sizeof(int));

    if(NULL == p){
        printf("You should've bought more memory!");
        exit(1);
    }

    printf("Please enter %d elements: \n", l);

    for(i; i < l; i++){

        scanf("%d", p + i);

        if(i == (l - 1)){
            int answer = 0;
            here:
            printf("Do you want to extend you array?\n");
            printf("Press 1 if you want to, press 2 to exit and print the current array\n");
            scanf("%d", &answer);
            if(answer == 1){
                printf("Enter new size: \n");
                scanf("%d", &l);
                p = realloc(p, l * sizeof(int));
                if(NULL == p){
                    printf("Not enough mana!");
                    exit(2);
                }
                printf("Please, enter %d new elements\n", l - (i + 1));
                continue;
            } else if(answer == 2){
                printf("This is your array: ");
                for(int j = 0; j < l; j++){
                    printf("%d", *(p+j));
                }
                break;
            } else {
                goto here;
            }
        }
    }

    free(p);

    return 0;
}
