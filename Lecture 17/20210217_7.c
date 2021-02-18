/*
Задача 7.
Хванете дълъг стринг и пребройте колко пъти се среща всяка буква от
азбуката в него. Запишете резултата в масив за всяка буква.
*/


#include <stdio.h>
#include <stdlib.h>


int array[25];
char string[150];

void count(char*, int*);

int main(void){

    char c;
    int i = 0;
    
    printf("Please enter a message: ");
    while ((c = getchar())!= '\n'){
        string[i++] = c;
    }

    int *p = array;
    char* j = string;

    count(j, p);

    for(int i = 0; i < 26; i++){
        if(array[i] > 0){
            printf("The letter %c was found %d times\n", 65+i, array[i]);
        }
    }


    return 0;
}

void count(char* j, int* p){
    int smallLetter = 65;
    int bigLetter = 97;
    int const letters = 26;
    int index = 0;
    int counter = 0;


    for(int i = 0; i <= letters; i++){
        while (*j != '\0'){
            if(*j == smallLetter || *j == bigLetter){
               counter++;
            }
            j++;
        }
        
        j = string;
        smallLetter++;
        bigLetter++;
        p[index++] = counter;
        counter = 0;
    }

}
