/*
Задача 13.
Напишете програма, която да прочете низ от потребителя и да го обърне
в обратен ред.
Например: 'xyz' да стане 'zyx'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*, char*);

int main(void){
    char array[100];
    char arrayRev[100]; 
    void (*pReverse)(char *, char *) = reverse;

    printf("Please enter a string: ");
    fgets(array, sizeof array, stdin);
    
    pReverse(array, arrayRev);

    printf("Ths string you entered: %s\n", array);
    printf("Reversed string: %s\n", arrayRev);

    return 0; 
}


void reverse(char *str, char *rev)
{
    int size = strlen(str);
    for (int i = size - 1, j = 0; i >= 0, j <= size - 1; i--, j++)
    {
        rev[j] = str[i];
    }
}
