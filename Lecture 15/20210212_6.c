/*
Задача 6.
Заделете динамично с malloc памет за char* buffer с размер size = 2,
въвеждайте символи от конзолата с getchar() ги четете, записвайте ги в
буфера. Увеличавайте размера на буфера преди да се препълни с
realloc().
Прекъснете цикъла с Ctrl + Z. Принтирайте буфера и освободете паметта.
*/

#include <stdio.h>
#include <stdlib.h>


int main(void){

    char *p = NULL;
    int l = 2, i = 0;

    p = (char*) malloc(l * sizeof(char));

    if(NULL == p){
        printf("Reallocation memory error!\n");
        exit(1);
    }

    printf("Enter elements\n", l);
    
    char c;

    while ((c = getchar()) != EOF){

        *(p + i++) = c;

        if(i >= (l - 1)){
            p = (char*) realloc(p, (l + 1) * sizeof(char));
            if(NULL == p) {
                printf("Not enough mana!");
                exit(2);
            }
        }
        
    }
    
    int j = 0;
    while (*(p + j) != '\0'){
        printf("%c", *(p + j++));
    }
    
    free(p);

    return 0;
}
