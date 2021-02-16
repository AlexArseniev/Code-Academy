/*
Задача 13.
Напишете програма, която намира дължината на стринг с
пойнтер! (без да използва length());
*/

#include <stdio.h>

int main(void){

    char array[] = "Papaya and Maracuja";
    char* p = &array;
    int i = 0;

    while (*p != '\0'){
        p++;
        i++;
    }

    printf("The length of the string is %d symbols", i);
    

    return 0;
}
