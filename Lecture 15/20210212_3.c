/*
Задача 3 Напишете функции, с помощта на които да реализирате динамичен
масив от елементи, чиято големина може да се променя по време на
изпълнение на програмата
*/

#include <stdio.h>
#include <stdlib.h>


int main(void){

    int *p = NULL;
    int l = 0, i = 0;

    printf("Please, enter the length of the array:\n");
    scanf("%d", &l);

    p = (int*) malloc(l * sizeof(int));

    if(NULL == p){
        printf("Reallocation memory error!\n");
        exit(1);
    }

    printf("Enter %d elements\n", l);
    
    for(i; i < l; i++){
        scanf("%d", p + i);

        if(i == (l - 1)){
            int answer = 0;
            here:
            printf("To continue you need to extend the size of your array. If you want to extend it press 1. If you want to stop and print the array press 2?\n");
            scanf("%d", &answer);

            if(answer == 1){
                printf("Please, enter the new size of the array:\n");
                scanf("%d", &l);
                p = realloc(p, l * sizeof(int));
                    if(NULL == p){
                        printf("Reallocation memory error!\n");
                        exit(2);
                    }
                printf("Please enter %d more elements\n", l - (i + 1));

                continue;
        
            } else if(answer == 2){
                for(int j = 0; j < l; j++){
                    printf("%d", p[j]);
                }
            } else {
                goto here;
            }
            
            break;
        }
    }

    free(p);

    return 0;
}
