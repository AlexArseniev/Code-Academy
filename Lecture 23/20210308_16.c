/*
Напишете програма, която премахва от файл номер на ред и
премахва този ред от файла. (Hint: Не трийте от оригиналния файл, а
запишете съдържанието на файла без конкретния ред в друг файл).
*/

#include <stdlib.h>
#include <stdio.h>

int main(void){
    
    int count = 1;
    int lineToRemove = 0;
    int c;

    FILE *original, *cpy;

    original = fopen("16.txt", "w+");

    if(original == NULL){
        perror("File not found");
        exit(1);
    }

    cpy = fopen("16copy.txt", "w+");

    if(cpy == NULL){
        perror("File not found");
        exit(1);
    }


    fputs("Green\nBlue\nRed\nWhite",original);

    rewind(original);

    printf("Which line do you want to remove? Press from 1 to 4: ");
    scanf("%d", &lineToRemove);
    
    while ((c = fgetc(original)) != EOF){
        if(count == lineToRemove){
            if(c == '\n'){
                count++;
            }
            continue;
        } else if(c == '\n'){
            fputc(c, cpy);
            count++;
        } else{
            fputc(c, cpy);
        }
    }

    fclose(original);
    fclose(cpy);
    return 0;
}