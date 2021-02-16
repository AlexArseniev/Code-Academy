/*
Задача 15.
Ще копираме стрингове. Дефинирайте и инизиалицирайте два стринга:
string 1: "A string to be copied."
string3: "I am very good in strings coping!"
Дефинирайте и два празни стринга, в които ще копираме string 2,
string4. Дефинирайте функция, която през пойнтери ще извърши
копирането от стринг към стринг. Използвайте while и факта, че
*pointer++ отива към следващия символ.
Помислете за терминиращия символ. Принтирайте двата изкопирани
стринга.
Извикайте функцията и копирайте от string1 в string4.
*/

#include <stdio.h>
#define MAX 200


int main(void){

    char string1[] = "A string to be copied";
    char string3[] = "I am very good in strings coping!";
    char string2[MAX];
    char string4[MAX];

    char* p;
    int i = 0;
    p = &string1;

    while (*p != '\0'){
        string2[i++] = *p;
        p++;
    }
    
    i = 0;
    p = &string3;

    while (*p != '\0'){
        string4[i++] = *p;
        p++;
    }
    
    printf("%s\n", string2);
    printf("%s", string4);

    return 0;
}
