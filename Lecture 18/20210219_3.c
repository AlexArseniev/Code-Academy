/*
Задача 3. Указатели към структура, предаване на структура на функция по
стойност и по референция
*/

#include <stdio.h>


struct date 
{
    int day;
    int month;
    int year;
};

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct dateAndTime
{
    struct date sDate;
    struct time sTime;
};


main(void){

   struct dateAndTime birthday, *dateBirth;
   dateBirth = &birthday;
   dateBirth -> sDate.day = 06;
   dateBirth -> sDate.month = 12;
   dateBirth -> sDate.year = 1987;
   dateBirth -> sTime.hours = 12;
   dateBirth -> sTime.minutes = 30;
   dateBirth -> sTime.seconds = 10;
    
    printf("My birthady: %d,%d,%d   %d:%d:%d", birthday.sDate.day, birthday.sDate.month, birthday.sDate.year, birthday.sTime.hours,
    birthday.sTime.minutes, birthday.sTime.seconds);
    

    return 0;
}
