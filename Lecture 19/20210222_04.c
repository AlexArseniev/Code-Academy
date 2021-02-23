/*
Дефинирайте структура “date” с членове ден, месец, година. Създайте
променлива към структурата “contractdate”. По колко начина можете да
я дефинирате?
Задайте стойност на членовете на структурата по три различни начина
*/

#include <stdio.h>

struct date{
    int day;
    int month;
    int year;
};

int main(void){
    struct date currentDate = {22,02,2021};
    printf("Current date: %i.%i.%i\n", currentDate.day, currentDate.month, currentDate.year); 

    struct date previousDate;
    previousDate.day = 21;
    previousDate.month = 02;
    previousDate.year = 2021;
    printf("Previous date: %i.%i.%i\n", previousDate.day, previousDate.month, previousDate.year); 

    struct date nextDate = {.year = 2021, .month = 02, .day = 23};
    printf("Next date: %i.%i.%i\n", nextDate.day, nextDate.month, nextDate.year); 

    return 0;
}
