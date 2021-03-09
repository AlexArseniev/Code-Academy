/*
Направете сериализация и десериализация на структурата
typedef struct Person{
char name[20];
int age;
char gender;
}t_person;
 в XML формат по показания в лекцията начин.
 */

#include <stdio.h>

static const char *FORMAT_IN = "(%[^,], %[^,], %d)\n";
static const char *FORMAT_OUT = "(%s, %s, %d)\n";

typedef struct Person{
    char name[20];
    char surname[20];
    int age;
}t_person;

int main(void){
    t_person firstPerson ={
        .name = "Alex",
        .surname = "Georguiev",
        .age = 33
    };

    t_person deserPerson;
    FILE *fp;
    fp = fopen("people.xml", "w+" );
    if(NULL == fp)
    return 1;
    fprintf(fp, FORMAT_OUT, firstPerson.name, firstPerson.surname, firstPerson.age);
    fseek(fp, 0, SEEK_SET);

    fscanf(fp, FORMAT_IN, &deserPerson.name, &deserPerson.surname, &deserPerson.age);

    printf(FORMAT_OUT, deserPerson.name, deserPerson.surname, deserPerson.age);
    fclose(fp);

    return 0;
}