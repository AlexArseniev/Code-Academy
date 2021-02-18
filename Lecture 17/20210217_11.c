/*
Задача 11.
Напишете програма, която да генерира парола с малки букви (i),
специални символи (j), големи букви (k) и цифри (l), ама разбъркано.
Използвайте функции. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSmallNumber(char*, int);
void generateBigNumber(char*, int);
void generateSymbol(char*, int);
void generateNumber(char*, int);

int main(void){

    char array[21];

    srand(time(0));

    here:

    for(int i = 0; i <= 20; i++){
        
        int j = rand() % 4;
        char* p = array;

        if(j==0){
            generateSmallNumber(p, i);
        } else if(j == 1){
            generateBigNumber(p, i);
        } else if(j == 2){
            generateSymbol(p, i);
        } else{
            generateNumber(p, i);
        }

    }

    int answer = 0;
    printf("This could be your new password: %s\nIf you like it press 1.\nIf you want to change it press 2.\n", array);
    scanf("%d", &answer);
    
    if(answer == 2){
        goto here;
    }

    return 0;
}

void generateSmallNumber(char* p, int i){
    int number = 97;
    *(p + i) = rand() % 26 + number; 
}

void generateBigNumber(char* p, int i){
    int number = 65;
    *(p + i) = rand() % 26 + number; 
}
void generateSymbol(char* p, int i){
    int number = 48;
    *(p + i) = rand() % 26 + number; 
}
void generateNumber(char* p, int i){
    int number = 33;
    *(p + i) = rand() % 26 + number; 
}
