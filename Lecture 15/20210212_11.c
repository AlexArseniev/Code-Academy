/*
Задача 11.
Напишете програма, в която се въвеждат пореден номер,
име, фамилия, възраст на участници в маратон. Изискването
е за името и фамилията да не се използват масиви с
фиксирана дължина. След като въвеждането завърши,
изведете списък с участниците. 

Все още не е готова. Работя над нея.
*/


#include <stdio.h>
#include <stdlib.h>

int main(void){

    printf("************WELCOME TO THE MARATHON************\n");


    char *data = NULL;
    int *counter;
    int i = 0;
    int j = 0;
    int contestants = 0;
    int l = 10;

    data = (char*) malloc(l * sizeof(char));
    counter = (int*) malloc(200 * sizeof(int));

    if(NULL == data){
        printf("Out of memory");
        exit(1);
    }

     
    while (1){
        printf("Please enter first name:");
        char c;
        while ((c = getchar()) != '\n'){
            j++;
            *(data + i++) = c;
            if(i == (l - 1)){
                data = (char*) realloc(data, (l + 10) * sizeof(char));
                    if(NULL == data){
                        printf("Out of memory");
                        exit(1);
                    }

            }
        }

        fflush(stdin);
        printf("Please enter family name: ");
        while ((c = getchar()) != '\n'){
            j++;
            *(data + i++) = c;
            if(i == (l - 1)){
                data = (char*) realloc(data, (l + 10) * sizeof(char));
                if(NULL == data){
                    printf("Out of memory");
                    exit(1);
                }

            }

        }

        fflush(stdin);
        printf("Please enter age: ");
        while ((c = getchar()) != '\n'){
            j++;
            *(data + i++) = c;
            if(i == (l - 1)){
                data = (char*) realloc(data, (l + 10) * sizeof(char));
                if(NULL == data){
                    printf("Out of memory");
                    exit(1);
                }

            }

        }

        fflush(stdin);

        *(counter + contestants++) = j;

        int answer; 

        printf("Do you want to add another contestant (y/n)?\n");
        scanf("%c", &answer);

        if(answer == 'y'){
            continue;
        } else if (answer == 'n'){
            for(int e = 0; e <= contestants; e++){
                for(int a = 0; a < *counter; a++){
                    int b = 0;
                    while (*(data + b++) != 0) {
                        printf("%c", *(data +b));
                    }
                    
                } 
            }
        }

    }
    
    
    free(data);
    free(counter);


    return 0;
}
