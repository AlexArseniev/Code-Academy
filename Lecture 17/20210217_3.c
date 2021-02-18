/*
Задача.3. Направете масив от указатели към функции по
следния начин:
void add(){...}
void fun2(){...}
void fun3(){...}
void (*func_ptr[3])() = {fun1, fun2, fun3};
Направете меню, с което да питате потребителя коя от
горните функции иска да използва – събиране, изваждане,
умножение и деление. След това попитайте за числата, които
да участват в тази операция, и извикайте функцията, която да
извърши желаната операция.
*/


#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int subst(int, int);
int multp(int, int);
int division(int, int);
void menu(int*, int*, int*);

int main(void){ 
    int a, b, choice;

    menu(&a, &b, &choice);

    int (*p[4])(int, int) = {add, subst, multp, division};
 
    printf("%d", (p[choice](a,b)));

}

void menu(int *a, int  *b,int  *choice){
    printf("Plese enter two numbers:\n");
    scanf("%d", a);
    scanf("%d", b);
    printf("Choose what you want to do with the numbers: \n");
    printf("Press 0 for addition\n");
    printf("Press 1 for substraction\n");
    printf("Press 2 for muliplication\n");
    printf("Press 3 for division\n");
    scanf("%d", choice);
}

int add(int a, int b){ return (a+b);}
int subst(int a, int b){ return (a-b);}
int multp(int a, int b){ return (a*b);}
int division(int a, int b){ return (a/b);}
