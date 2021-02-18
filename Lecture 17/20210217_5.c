/*
Задача 5.
Намерете стойностите в интервала 1-5, включително, в двумерен масив
[5] [5] пълен със случайни числа в интервала 0-10, включително.
Използвайте функция, която да пълни числата със случайни.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int *pointer, int count);
void printPos(int *pointer);

int main(){

    srand(time(0));
    int array[5][5];
    int position[25];
    int number = 25;

    int* pointer = array;
    int* pointerTopos = position;

    fillArray(array, number);

    printPos(*pointer);

}

void fillArray(int* poiter, int number){
    int counter = 0;

    while (counter < number){
        *poiter = abs(rand()%11);
        poiter++;
        counter++;
    }

    for(int i = 0; i < number; i++){
        if(poiter[i] >= 1 && poiter[i] <= 5){
            *poiter = i;
            poiter++;
        }
    }

}

void printPos(int* p){

    for(; *p; p++){
        printf("%d", *p);
    }
}
