/*
Задача 1. Да напишем функция char *month_name(int n), която връща указател
към символен низ, съдържащ името на n-тия месец. Да декларираме въртешен static
масив от указатели, сочещ към стрингове съдържащи имената на месеците
static char *name[] = {
"Illegal month",
"January", "February", "March",
"April", "May", "June",
"July", "August", "September",
"October", "November", "December"
Декларирането на static масив в скоупа на функцията означава, че ще бъде
видимо името му в целия файл и ще продължи да живее и след излизане от скоупа на
функцията след края на програмата. Функцията връща указател към съответния месец,
отговарящ на параметъра n.
*/

#include <stdio.h>
#include <stdlib.h> 

char *month_name(int n);


int main(void){

    int number = 0;
    printf("Enter a number between 1 and 12: ");
    scanf("%d", &number);

    month_name(number);    

    return 0;
}


char *month_name(int n){

    static char* year[] = {"Illegal month", "January", "February",
    "March", "April", "May", "June", "July", "August", "September", 
    "October", "November","December"};

    if(n <= 0 || n > 12){
        printf("Illegal month");
    } else {
        printf("%s", year[n]);
    }

}
