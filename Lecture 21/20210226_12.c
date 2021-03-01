/*Задача 12. Представете служителите във фирма в структура с
членове: пореден номер, име, презиме, фамилия, позиция, трудов стаж в
години, заплата в лева, указател към структурата, описващ неговия
началник. Напишете програма, която въвежда 10 служителя, които се
съхраняват в масив от описаните структури. Въвеждането на служителите
може да стане на два паса, първо въвеждане на всички данни без
указателя към началника и на втори пас, указване на всеки служител кой е
неговият началник. В решението трябва да се използва динамично
заделяне на памет и typedef.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct employee{
    int id;
    char *name;
    char *middleName;
    char *lastName;
    char *job;
    int years;
    double salary;
    struct employee *boss;
}worker;
void inputNames(worker *p){
    char buf[10];
    int n;
    double s;
    printf("Enter id: ");
    scanf("%d",&n);
    p->id=n;
    printf("Enter name: ");
    scanf("%s", &buf);
    p->name=(char *)malloc(strlen(buf)+1);
    strcpy(p->name,buf);
    printf("Enter middleName: ");
    scanf("%s", &buf);
    p->middleName=(char *)malloc(strlen(buf)+1);
    strcpy(p->middleName,buf);
    printf("Enter last name: ");
    scanf("%s", &buf);
    p->lastName=(char *)malloc(strlen(buf)+1);
    strcpy(p->lastName,buf);
    printf("Enter job: ");
    scanf("%s", &buf);
    p->job=(char *)malloc(strlen(buf)+1);
    strcpy(p->job,buf);
    printf("Enter years in company: ");
    scanf("%d",&n);
    p->years=n;
    printf("Enter salary: ");
    scanf("%lf",&s);
    p->salary=s;
}
int main(){
    worker *company=(worker*)malloc(3*sizeof(worker));
    for(int i=0; i<3; i++){
        inputNames(company+i);
    }
    for(int i=0; i<3; i++){
        printf("%d %s %s %s %s %d %lf\n",(company+i)->id,(company+i)->name,(company+i)->middleName,(company+i)->lastName,(company+i)->job,
        (company+i)->years,(company+i)->salary);
    }
    int choice=0;
    for(int i=0;i<3;i++){
        printf("Enter boss's id for worker %s %s",(company+i)->name,(company+i)->lastName);
        scanf("%d",&choice);
        for(int j=0; j<3; j++){
            if(choice!=0 && choice==(company+j)->id){
                (company+i)->boss=(company+j);
            }
        }
    }
    
    for(int i=0; i<3; i++){
        printf("Worker No.%d %s %s %s %d %lf BOSS: %s %s \n",(company+i)->id,(company+i)->name,
        (company+i)->middleName,(company+i)->lastName,(company+i)->years,(company+i)->salary,
        (company+i)->boss->name,(company+i)->boss->lastName);
    }
    free(company);
    return 0;
}
