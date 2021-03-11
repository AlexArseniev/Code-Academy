/*Пренапишете Задача 2 от 05.03.2021г за Пощенските такси на дадена
куриерска фирма се определят според тежестта на пратките (с точност до цял грам) и обема,
както е показано в таблицата.
При влизане в някоя функция отваряте файл за писане и при успешно излизане от функцията
записвате във файла function_name() success . Това го правим за всички функции. Ако има
някаква грешка записваме грешката във файла и името на функцията.*/
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
FILE *fp=NULL;
typedef struct{
    int weight;
    float w_price;
    int size;
    float s_price;
}order;
const int c_weight[2][9]={{20,50,100,200,350,500,1000,2000,3000},{46,69,102,175,213,244,320,427,503}};
const int c_size[2][9]={{10,50,100,150,250,400,500,600,-1},{1,11,22,33,56,150,311,489,579}};
order makeOrder(int weight, int size);
float getPrice(order* orders,int size);
void menu();
void toFile(FILE *fp);
int main(void){
    fp=fopen("functions.txt","wt");
    menu();
    fclose(fp);
    return 0;
}
void menu(){
    printf("How many orders would you like?");
    fflush(stdin);
    int order_count;
    int total_weight=0,total_size=0;
    scanf("%d",&order_count);
    order* orders;
    orders=(order*)malloc(order_count*sizeof(order));
    for(int i=0;i<order_count;i++){
        int weight,size;
        printf("Enter %d order weight: ",i+1);
        fflush(stdin);
        scanf("%d",&weight);
        printf("Enter %d order size: ",i+1);
        fflush(stdin);
        scanf("%d",&size);
        orders[i]=makeOrder(weight,size);
        total_size+=size;
        total_weight+=weight;
    }
    order bigOrder=makeOrder(total_weight,total_size);
    float total_price = getPrice(orders,order_count);
    if((bigOrder.s_price+bigOrder.w_price)>=total_price){
        printf("For orders with weigt %d and size %d it's better to send them separate, and it will cost: %.2f",total_weight,total_size,total_price);
    }else{
        printf("For orders with weigt %d and size %d it's better to send them together, and it will cost: %.2f",total_weight,total_size,(bigOrder.s_price+bigOrder.w_price));
    }
    free(orders);
    if (errno == 0)
    {
        fprintf(fp, "%s -> %d : %s\n", __func__, errno, "Succsessfull");
    }
    else
    {
        fprintf(fp, "%s -> %d : ", __func__, errno);
        perror("Error ");
    }
}
float getPrice(order* orders,int size){
    float price=0;
    for(int i=0;i<size;i++){
        price+=orders[i].w_price;
        price+=orders[i].s_price;
    }
    if (errno == 0)
    {
        fprintf(fp, "%s -> %d : %s\n", __func__, errno, "Succsessfull");
    }
    else
    {
        fprintf(fp, "%s -> %d : ", __func__, errno);
        perror("Error ");
    }
    return price;
}
order makeOrder(int weight, int size){
    float w_price=0;
    float s_price=0;
    if(weight<c_weight[0][0]){
        w_price=c_weight[1][0];
    }
    if(size<c_size[0][0]){
        s_price=c_size[1][0];
    }
    for(int i=0;i<8;i++){
        if(weight>c_weight[0][i]&&weight<=c_weight[0][i+1]){
            w_price=c_weight[1][i+1];
            break;
        }
    }
    if(w_price==0){
        w_price=c_weight[1][8];
    }
    for(int i=0;i<8;i++){
        if(size>c_size[0][i]&&size<=c_size[0][i+1]){
            s_price=c_size[1][i+1];
            break;
        }
    }
    if(s_price==0){
        s_price=c_size[1][8];
    }
    w_price/=100;
    s_price/=100;
    order order={weight,w_price,size,s_price};
    if (errno == 0)
    {
        fprintf(fp, "%s -> %d : %s\n", __func__, errno, "Succsessfull");
    }
    else
    {
        fprintf(fp, "%s -> %d : ", __func__, errno);
        perror("Error ");
    }
    return order;
}