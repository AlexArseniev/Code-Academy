/*
Задача 6.
Опишете времето в структура: часове:минути:секунди като структура tagTMyTime.
Използвайки тази структура, дефинирайте следните функции: добавяне на секунди,
добавяне на минути. Добавяне на часове към дадена променлива от тип struct
tagTMyTime. Напишете следните функции: връщане на броя секунди за дадена
променлива от въведения тип и обратна функция от секундите да се генерира
променлива tagTMyTime. Напишете две функции, които изваждат и събират две
променливи от тип struct tagMyTime и връщат променлива от същия тип.
Използвайте тези функции, за да се уверите, че работят коректно.
*/


#include <stdio.h>

struct time{
    int hour;
    int min;
    int sec;
};

struct time addSecond(struct time currentTime, int addsec){
    struct time realTime = {currentTime.hour,currentTime.min,currentTime.sec+addsec};
    if(realTime.sec >= 60){
        realTime.min++;
        realTime.sec = 60;
    }
    return realTime;
}
struct time addMinute(struct time currentTime,  int addmin){
    struct time realTime = {currentTime.hour, currentTime.min+addmin, currentTime.sec};
    if(realTime.min >= 60){
        realTime.hour++;
        realTime.min = 0;
    }
    return realTime;
}
struct time addHour(struct time currentTime, int addhour){
    struct time realTime = {currentTime.hour+addhour, currentTime.min, currentTime.sec};
    if(realTime.hour > 23){
        realTime.hour = 0;
    }
    return realTime;
}

int getSeconds(struct time currentTime){
    int seconds = currentTime.sec;
    return seconds;
}

struct time add(struct time time1, struct time time2){
    time1.hour += time2.hour;
    time1.min += time2.min;
    time1.sec += time2.sec;

    if(time1.hour > 23){
        time1.hour = 0;
    }
    if(time1.min>=60){
        time1.hour++;
        time1.min = 0;
    }
    if(time1.sec >=60){
        time1.min++;
        time1.sec = 0;
    }
    return time1;
}

struct time subtract(struct time time1, struct time time2){ 
    time1.hour -= time2.hour;
    time1.min -= time2.min;
    time1.sec -= time2.sec;
    if(time1.sec < 0){
        time1.min --;
        time1.sec += 60;
    }
    if(time1.min < 0){
        time1.hour--;
        time1.min += 60;
    }
    if(time1.hour < 0){
        time1.hour = 23;
        time1.min += 60;
        time1.sec += 60;
    }
    return time1;
}

int main(){
    struct time nowTime = {23,13,35};
    printf("Time now: %d:%d:%d", nowTime.hour, nowTime.min, nowTime.sec);

    struct time newTime = addHour(nowTime, 1);
    printf("\nNew time: %d:%d:%d",newTime.hour, newTime.min, newTime.sec);
    printf("\nGet newTime seconds: %d", getSeconds(newTime));

    struct time addTime = add(nowTime, newTime);
    printf("\nTime addition: %d:%d:%d",addTime.hour, addTime.min, addTime.sec);

    struct time subtractTime = subtract(addTime, newTime);
    printf("\nTime subtract: %d:%d:%d", subtractTime.hour, subtractTime.min, subtractTime.sec);
    
    return 0;
}
