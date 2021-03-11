/*Задача 1.
Напишете програма, която сравнява два файла, като отпечатва
първият ред на който се различават и на двата файла.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(FILE *p1, FILE *p2);

int main(){
    FILE *fp1=NULL;
    if(fp1==NULL){
        perror("Error: ");
    }
    FILE *fp2=NULL;
    if(fp2==NULL){
        perror("Error: ");
    }
    fp1=fopen("test1.txt","r");
    fp2=fopen("test2.txt","r");
    printf("\nline %d is different\n",compare(fp1,fp2));
    fclose(fp1);
    fclose(fp2);
    return 0;
}
int compare(FILE *p1, FILE *p2){
    int line=1;
    char c1,c2;
    while(((c1=getc(p1))!=EOF)&&((c2=getc(p2))!=EOF)){
        if(c1=='\n'){
            line++;
        }
        if(c1!=c2){
            return line;
        }
    }
    return 0;
}
