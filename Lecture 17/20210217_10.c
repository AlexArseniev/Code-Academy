/*
Задача 10.
Да намерим простите числа до 1000 и да ги сложим в масив.
Да напишем функция, която да ни казва дали дадено число от 0 - до 1000
е просто.
Просто число е се нарича всяко естествено число, по-голямо от 1,
което има точно два естествени делителя – 1 и самото себе си.
Например 5 е просто, защото се дели единствено на 1 и 5, докато 6 не
е, защото се дели освен на 1 и 6, и на 2 и 3.
*/

#include <stdio.h>
#include <math.h>

int findNumbers(int*);
int numberCheck(int*, int, int);


int main(void){


    int array[1000];
    int* p = array;

    int size = findNumbers(p);

    int num = 0;
    printf("Please enter the number you want to check: ");
    scanf("%d", &num);

    p = array;

    int result = numberCheck(p, num, size);

    if(result == 1){
        printf("%d is a prime number", num);
    } else{
        printf("%d is not a prime number", num);
    }

    return 0;
}

int findNumbers(int* p){
    int i = 2, j;
    int size = 0;

    for(i; i <= 1000; i++){
        int c = 0;
        for(j = 1; j <= i; j++){
            if(i % j == 0){
                c++;
            }
        }

        if(c == 2){
            *p = i;
            p++;
            size++;
        }
    }

    return size;
}

int numberCheck(int* p, int number, int size){
    
    int middle = floor(size/2);
    int flag = 0;

    if(number > middle){
        for(middle; middle < size; middle++){
            if(*p == number){
                flag = 1;
            }
            p++;
        }
    } else {
        for(int i = 0; i <= middle; i++){
            if(*p == number){
                flag = 1;
            }
            p++;
        }
    }

    return flag;
}
