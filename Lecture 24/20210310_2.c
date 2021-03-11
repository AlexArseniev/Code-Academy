/*Задача 2.
Напишете програма, която проверява дали всички отворени къдрави скоби {, (, [ за затворени ] ),},
Хвърлете грешка при липса на затварящи скоби и реда на който са.
*/
#include <stdio.h>
char br[6]={'{','[','(',')',']','}'};
int main(){
    FILE *fp=NULL;
    fp=fopen("test2.txt","rt");
    if(fp==NULL){
        perror("Error: ");
    }
    char c;
    int line=1,count=0;
    while((c=getc(fp)) != EOF){
        for(int i=0;i<6;i++){
            if(c==br[i]){
            count++;
            }
        }         
        if(c=='\n'){
            if((count%2)!=0){
            printf("line %d",line);
            count=0;
            }
        line++;
        }
    }    
    fclose(fp);
    return 0;
}