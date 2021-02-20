/*Задача 2. Инициализиране на структура, вложени структури*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date 
{
    int day;
    int month;
    int year;
}date;

typedef struct time
{
    int hours;
    int minutes;
    int seconds;
}time;

typedef struct dateAndTime
{
    date sDate;
    time sTime;
}dateAndTime;


main(void){

    dateAndTime birthday = {{6,12,1987},{12,30,00}};
    
    printf("My birthady: %d,%d,%d   %d:%d:%d", birthday.sDate.day, birthday.sDate.month, birthday.sDate.year, birthday.sTime.hours,
    birthday.sTime.minutes, birthday.sTime.seconds);
    

    return 0;
}
