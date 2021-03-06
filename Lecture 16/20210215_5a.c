/*
Можете ли да умножите пойнтер по пойнтер?
При тази декларация колко пойнтера имаме:
int *p, k;

при декларация int *p, k - имаме само 1 пойнер. 
Ако искаме да имаме 2 пойнера трябва да декларираме по следния начин:
int *p, *k. Това се налага заради precedence rule.  

*/

#include <stdio.h>

int main(void){

    int x = 1,y = 2, *p1 = &x, *p2 = &y;  
    printf("%d", p1 + p2);  // invalid 
    printf("%d", p1 * p2);  // invalid 
    printf("%d", p1 / p2);  // invalid 
    printf("%d", p1 - p2);  // valid, но само ако двата пойнера са от един и същи тип. 

    return 0;
}
