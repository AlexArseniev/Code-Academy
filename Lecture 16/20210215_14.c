/* 
Задача 14
Решете задачата за генериране на 6 буквена парола с
пойнтери.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 7

int main(void){


    char password[MAX];
    char *p = password;
    srand(time(0));
    char answer;

    while (answer != 'y'){

        while(p != &password[6]){
            *p = ((rand()%26) + 97);
            p++;
        }
        
        printf("This could be your new password: %s\n", password);
        printf("If you like it press 'y'.\nIf you want to change it press any other key.\n");
        fflush(stdin);
        scanf("%c", &answer);
        if(answer != 'y'){
            p = password;
        }
    }

    printf("Your new password is: %s", password);

    return 0;
}
