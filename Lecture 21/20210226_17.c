/*Кое е по добре да купите: А броя дини от сорт мелон с диаметър Х сантиметра
и дебелина на кората D сантиметър или В броя дини с диаметър У сантиметра и
същата дебелина на кората D2? Създайте структура диня с два елемента -
диаметър и дебелина на кората заделете динамично с malloc() за масив от А на
брой дини от сорт мелон и попълнете данните за диаметър между 15 и 140 см с
функцията rand(), за всяка една диня в масива и дебелина на кората между 0.5 и
3.5 см. Създайте структура диня с два елемента - диаметър и дебелина на кората
заделете динамично с malloc() за масив от В на брой дини от сорт пъмпкин и
попълнете данните за диаметър между 35 и 95 см с функцията rand(), за всяка
една диня в масива и дебелина на кората между 0.3 и 0.9 см. Намерете средната
големина на динята и средната дебелина на кората и ги съпоставете с тези от
втория масив. Изведете на екрана купчината от кой сорт е по добре да се купи.
Изход:
По-добре е да се купят ... дини с диаметър ... сантиметра и кора с дебелина D
см вместо ... дини с диаметър ... см и дебелина на кората D1 см.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Melon {
    int d;
    float width;
};
int main(){
    srand((unsigned)time(0));
    int a,b; /*брой на дините от двата сорта */
    printf("How many melon(A) watermelons?");
    scanf("%d",&a);
    printf("How many pumpkin(B) watermelons?");
    scanf("%d",&b);
    struct Melon *A=malloc(a*sizeof(struct Melon));
    struct Melon *B=malloc(b*sizeof(struct Melon));
    float x;
    int avg_d_A, avg_d_B, sum=0;
    float avg_w_A, avg_w_B, sumW=0;

    for(int i=0; i<a; i++){
        x=((float)rand()/(float)(RAND_MAX))+(float)(rand()%4);
        if(x<0.5 || x>3.5){
            i--;
            continue;
        }
        A[i].d=rand()%126+15;
        sum=sum+A[i].d;
        A[i].width=x;
        sumW = sumW + A[i].width;
        printf("A: D=%d W=%f\n",A[i].d,A[i].width);
    }
    avg_d_A=sum/a;
    sum=0;
    avg_w_A=sumW/(float)a;
    sumW=0;
    for(int i=0; i<b; i++){
        x=((float)rand()/(float)(RAND_MAX));
        if(x<0.3 || x>0.9){
            i--;
            continue;
        }
        B[i].d=rand()%96+35;
        sum=sum+B[i].d;
        B[i].width=x;
        sumW = sumW + B[i].width;
        printf("B: D=%d W=%f\n",B[i].d,B[i].width);
    }
    avg_d_B=sum/b;
    avg_w_B=sumW/(float)b;
    float totalA = (float)avg_d_A-avg_w_A;
    float totalB = (float)avg_d_B-avg_w_B;
    if(totalA>totalB){
        printf("Better to buy %d watermelons from type A with diameter %d and width %f, than %d watermelons from type B with diameter %d and width %f ",a,avg_d_A,avg_w_A,b,avg_d_B,avg_w_B);
    } else printf("Better to buy %d watermelons from type B with diameter %d and width %f, than %d watermelons from type A with diameter %d and width %f ",b,avg_d_B,avg_w_B,a,avg_d_A,avg_w_A);
    free(A);
    free(B);
    return 0;
}