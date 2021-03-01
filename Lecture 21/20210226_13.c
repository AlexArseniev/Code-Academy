/*Задача 13.Опишете времето: часове:минути:секунди като структура
tagTMyTime. Използвайки тази структура, дефинирайте следните функции:
добавяне на секунди, добавяне на минути. добавяне на часове към
дадена променлива от тип struct tagTMyTime. Напишете следните
функции: връщане на броя секунди за дадена променлива от въведения
тип и обратна функция от секундите да се генерира променлива
tagTMyTime. Напишете две функции, които изваждат и събират две
променливи от тип struct tagMyTime и връщат променлива от същия тип.
Използвайте тези функции, за да се уверите, че работят коректно. В
решението трябва да се използва динамично заделяне на памет и typedef.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    int hours;
    int minutes;
    int seconds;
} myTime;
void addSeconds(myTime *time, int s){
    time->seconds+=s;
    while(time->seconds>=60){
        time->minutes+=1;
        time->seconds-=60;
    }
        while(time->minutes>=60){
            time->hours+=1;
            time->minutes-=60;
        }
    
}
void addMinutes(myTime *time, int m){
    time->minutes=time->minutes+m;
    while(time->minutes>=60){
        time->hours=time->hours+1;
        time->minutes=time->minutes-60;
    }
}
void addHours(myTime *time, int h){
    time->hours+=h;
    while(time->hours>=24){
        time->hours=time->hours-24;
    }
}
int seconds(myTime *time){
    return time->seconds;
}
void generate(myTime *p, int sec){
    int h,m,s;
    h=sec/3600;
    s=sec%360;
    m=sec/60;
    s=sec%60;
    while(s>=60){
        m+=1;
        s-=60;
    }    
    while(m>=60){
        h+=1;
        m-=60;
    }
    while(h>=24){
        h-=24;
    }
    p->hours=h;
    p->minutes=m;
    p->seconds=s;
}
void plus(myTime *one, myTime *two){
        
    one->seconds=one->seconds+two->seconds;
    one->minutes=one->minutes+two->minutes;
    one->hours=one->hours+two->hours;
    while(one->seconds>=60){
        one->minutes+=1;
        one->seconds-=60;
    }    
    while(one->minutes>=60){
        one->hours+=1;
        one->minutes-=60;
    }
    while(one->hours>=24){
        one->hours-=24;
    }
}
void minus(myTime *one, myTime *two){
       
    one->seconds=one->seconds-two->seconds;
    one->minutes=one->minutes-two->minutes;
    one->hours=one->hours-two->hours;
    while(one->seconds<0){
        one->minutes-=1;
        one->seconds=60-abs(one->seconds);
    }    
    while(one->minutes<0){
        one->hours-=1;
        one->minutes=60-abs(one->minutes);
    }
    while(one->hours<0){
        one->hours=24-abs(one->hours);
    }
}


int main(){
    myTime *ptr=(myTime*)malloc(sizeof(myTime));
    myTime *ptr2=(myTime*)malloc(sizeof(myTime));
    printf("Enter hours:");
    scanf("%d",&ptr->hours);
    printf("Enter minutes 0-59:");
    scanf("%d",&ptr->minutes);
    printf("Enter seconds 0-59:");
    scanf("%d",&ptr->seconds);
    printf("You entered %d:%d:%d\n",ptr->hours,ptr->minutes,ptr->seconds);
    addHours(ptr,2);
    printf("After addHours(): %d:%d:%d\n",ptr->hours,ptr->minutes,ptr->seconds);
    addMinutes(ptr,80);
    printf("After addMinutes(): %d:%d:%d\n",ptr->hours,ptr->minutes,ptr->seconds);
    addSeconds(ptr,70);
    printf("After addSeconds(): %d:%d:%d\n",ptr->hours,ptr->minutes,ptr->seconds);
    printf("seconds() returns %d\n",seconds(ptr));
    
    int s;
    printf("Enter from how many secondds to generate time: ");
    scanf("%d",&s);
    generate(ptr2,s);
    printf("After generate(): %d:%d:%d\n",ptr2->hours,ptr2->minutes,ptr2->seconds);
    
    plus(ptr2,ptr);
    printf("After plus() %d:%d:%d\n",ptr2->hours,ptr2->minutes,ptr2->seconds);

    minus(ptr2,ptr);
    printf("After minus() %d:%d:%d",ptr2->hours,ptr2->minutes,ptr2->seconds);
    
    free(ptr);
    free(ptr2);
    return 0;
}