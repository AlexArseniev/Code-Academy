/*
Задача 6.
Пребройте буквите ‚а‘ в стринг (може да е число и масив).
Пример: "This is a string to test my idea for search in a char and ....";
*/

#include <stdio.h>
#include <stdlib.h>


int countLetters(char* );

int main(){

    char array[100];
    char c;
    int i = 0;
    
    printf("Enter a message (100 symbols max). The output will be the count of the letter a: ");

    while ((c = getchar()) != '\n'){
        array[i++] = c;
    }

    char* p = array;
    
    printf("%d", countLetters(p));

    return 0;
}

int countLetters(char* p){

    int counter = 0;

    while (*p != '\0'){
        if(*p == 'a' || *p == 'A'){
            counter++;
        }
        p++;
    }
    
    return counter;
}
