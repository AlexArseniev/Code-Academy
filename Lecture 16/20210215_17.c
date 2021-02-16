#include <stdio.h>
#include <string.h>

int main(){
    char string1[]= "A string to be copied.\0";
    char string3[]= "I am very good in strings coping!\0";
    char string2[50];
    char string4[50];

    strcpy(string2, string1);
    strcpy(string4, string3);
    printf("%s\n", string2);
    printf("%s\n", string4);
 
    return 0;
}
