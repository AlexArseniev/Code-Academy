/*Задача 14 Напишете програма, в която се въвеждат пореден
номер, име, фамилия, възраст на участници в маратон.
Изискването е, за името и фамилията, да не се използват
масиви с фиксирана дължина. След като въвеждането завърши,
изведете списък с участниците.
Задача 15 Използвайки предишното упражнение, изведете
участниците подредени по азбучен ред.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    char *surname;
    int age;
} Participant;
void inputNames(Participant *p){
    char buf[10];
    printf("Enter name: ");
    scanf("%s", &buf);
    p->name=(char *)malloc(strlen(buf)+1);
    strcpy(p->name,buf);
    printf("Enter surname: ");
    scanf("%s", &buf);
    p->surname=(char *)malloc(strlen(buf)+1);
    strcpy(p->surname,buf);
    printf("Enter age: ");
    scanf("%d",&p->age);
}
void sort(Participant *p, int participants){
    char *buf=NULL;
    int temp;
    for(int i=0; i<participants+1; i++){
        for(int j=i+1; j<participants; j++){
            if (strncmp(p[i].name, p[j].name, 1) > 0){
                buf=p[j].name;
                p[j].name=p[i].name;
                p[i].name=buf;

                buf=p[j].surname;
                p[j].surname=p[i].surname;
                p[i].surname=buf;

                temp=p[j].id;
                p[j].id=p[i].id;
                p[j].id=temp;

                temp=p[j].age;
                p[j].age=p[i].age;
                p[j].age=temp;
                
            }
        }
    }
}
int main(){
    int participants;
    printf("How many participants: ");
    scanf("%d",&participants);
    Participant *p;
    p = (Participant*)malloc(participants*sizeof(Participant));
    for(int i=0; i<participants; i++){
        (p+i)->id=i+1;
        inputNames(p+i);
        
    }
    sort(p,participants);
    for(int i=0; i<participants; i++){
        printf("%d %s %s %d\n", (p+i)->id,(p+i)->name,(p+i)->surname,(p+i)->age);
        
    }
    free(p);
    return 0;
}