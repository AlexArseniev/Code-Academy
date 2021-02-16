/*
Задача 16.  Напишете програма, която чете стринг и проверява дали не е палиндром 
(буквите в стринга отпред назад са същите както отзад напред).
Игнорирайте препинателни знаци, празни пространства и главни букви.
He lived as a devil, eh?
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char check(char*, int);


int main(void){


    char array[20];
    char c;
    char *p = array;

    printf("Please enter a message up to 20 symbols:\n");

    while ((c = getchar()) != '\n'){
        if(isalpha(c)){
            *p = c;
            p++;
        }
    }

    int size = strlen(array);

    p = &array;

    while (*p != '\0'){
        if(*p >= 65 && *p <= 90){
            *p += 32;
        } 

        if(*p < 65 || (*p >= 91 && *p <= 96) || *p >= 123){
            *p = *(++p);
        }
        p++;
    }
    


    int result = check(array, size);

    if (result == 0){
        printf("%s is a palindrom", array);
    } else {
        printf("%s is not a palindrom", array);
    }

    return 0;
}

char check(char* array, int size){

    int i = 0, j = size - 1, flag = 0;
    
    for(i; i <= j; i++){

        if(*(array + i) != *(array + j--)){
            flag = 1;
            break;
        }
    }

    return flag;
}
