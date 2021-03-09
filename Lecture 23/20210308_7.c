/*
Напишете символ в текстов файл.
Int fputc(int ch, FILE *pfile);
Първият параметър е символът, който искаме да отпечатаме (изразен като
int, т.е. номер в ASCII таблицата), вторият е самия файл, в който ще пишем.
Ако е успешно, функцията връща това, което искаме да изпише.
При грешка функцията връща EOF.
putc () работи със същите аргументи, но е дефинирана като макрос в
стандартната библиотека.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char string[30] = "This is a test message";

    FILE *pf = NULL;

    pf = fopen("7.txt", "w+");

    if(pf == NULL){
        perror("File not found");
        exit(1);
    }

    for(int i = 0; i < strlen(string); i++){
        fputc(string[i], pf);
    }

    fclose(pf);
    return 0;
}