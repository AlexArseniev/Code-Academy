/*
Задача 8.
Заделяне на памет от стека с alloca.
Заделете памет в стека (няма нужда от free())
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int i = 0, l = 0, sum = 0;
    printf("Please, eneter the length of the array: ");
    scanf("%d", &l);

    int *p = NULL;
    p = (int*) alloca(l * sizeof(int));


    printf("Please, eneter %d numbers\n", l);

    for(i = 0; i < l; i++){
        int number = 0;
        scanf("%d", &number);
        p[i] = number;
        sum += *(p + i);
    }
 
    printf("The sum of the numbers is: %d", sum);

    return 0;
}
