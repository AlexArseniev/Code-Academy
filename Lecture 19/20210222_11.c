/*  Задача 11. Направете обединение с елементи тип int, int, char. Дайте стойност на елементите 
    един по един -7, 10 и 'c' и изведете тези стойности на конзолата. */

/*  Не разбрах идеята */

#include <stdio.h>

union maracuja {
    int mar;
    int acu;
    char ja;
};

int main() {
    union maracuja mara;
    mara.mar = -7;
    printf("%d\n", mara.mar);
    mara.acu = 10;
    printf("%d\n", mara.acu);
    mara.ja = 'c';
    printf("%c\n", mara.ja);
    
    mara.mar = -7;
    mara.acu = 10;
    mara.ja = 'c';
    printf("%d\n", mara.mar);
    printf("%d\n", mara.acu);
    printf("%c\n", mara.ja);

    return 0;
}
