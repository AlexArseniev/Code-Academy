//1. Дефинирайте константи PI, Е, и други с помощта на макроси. Използвайте
//ги в кода.

#include <stdio.h>
#define PI 3.14
#define E 10

int main(void){

    float circleArea = PI * E * E;

    printf("%f", circleArea);
    
    return 0;
}
