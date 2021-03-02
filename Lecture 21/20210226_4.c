/*
Задача 4 Дефинирайте функция, която събира
две променливи и приема и изпълнява предефиниран
указател, като стойност.
*/


#include <stdio.h>
typedef int * preDefined;
int add(preDefined a, preDefined b){
    return *a+*b;
}
typedef int (*t_fAdd)(preDefined,preDefined);
int main(){
    int a=5,b=6;
    preDefined p=&a;
    preDefined q=&b;
    t_fAdd fPtr=&add;
    printf("%d",fPtr(p,q));
    return 0;
}