/*
Задача 2 Пощенските такси на дадена куриерска фирма се определят според
тежестта на пратките (с точност до цял грам) и обема, както е показано в таблицата.
Тегло (с точност до 1 грам) Такса до 20 г 0,46 лева; 21-50 г 0,69 лева; 51-100 г
1,02 лева; 101-200 г 1,75 лева; 201-350 г 2,13 лева; 351-500 г 2,44 лева; 501-
1000 г 3,20 лева; 1001-2000 г 4,27 лева; 2001-3000 г 5,03 лева;
Обем: до 10см + 0,01лв; 10- 50 см + 0,11 лева, 50-100 см + 0,22лв, 100-150см + 0,33лв, 150-
250см +0,56лв, 250-400см+1.50лв, 400-500см+3,11лв, 500-600см+4,89лв, над 600см+ 5.79лв
Потребителя се пита за броя на пратките пратки след което теглото на всяка пратка и обема и.
Определете според пощенските такси в тази куриерска фирма как по-евтино да изпрати своите
пратки като една или да ги изпрати като отделни пратки.
Изход 1:
За пратки с тегло ... грама обем ... и ... грама ...обем е по-добре да бъдат изпратени заедно. В
този случай изпращането ще струва ... лева.
Изход 2:
За пратки с тегло ... грама обем ... и ... грама ...обем е по-добре да бъдат изпратени заедно. В
този случай изпращането ще струва ... лева.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int size;
}package;

void print(float, float);

int main(void){

    int totalPackages = 0, totalWeight = 0, totalSize = 0;
    float price = 0, totalPrice = 0; 
    printf("How many packages do you want to send?\n");
    scanf("%d", &totalPackages);

    package* packageList = (package*) malloc(totalPackages * sizeof(package));
    
    for(int i = 0; i < totalPackages; i++){
        printf("Plese, enter the weight of package number %d\n", i + 1);
        scanf("%d", &packageList[i].weight);
        here:
        printf("Please, enter the size of package number %d\n", i + 1);
        scanf("%d", &packageList[i].size);
        if(packageList[i].size > 3000){
            printf("You can't send package over 3000 cm. Please enter new dimentions\n");
            goto here;
        }
    }

    for(int i = 0; i < totalPackages; i++){
        if(packageList[i].weight <= 20){
            price += 0.46;
        }else if(packageList[i].weight <= 50){
            price += 0.69;
        }else if(packageList[i].weight <= 100){
            price += 1.02;
        }else if(packageList[i].weight <= 200){
            price += 1.75;
        }else if(packageList[i].weight <= 350){
            price += 2.13;
        }else if(packageList[i].weight <= 500){
            price += 2.44;
        }else if(packageList[i].weight <= 1000){
            price += 3.20;
        }else if(packageList[i].weight <= 2000){
            price += 4.27;
        }else if(packageList[i].weight <= 3000){
            price += 5.03;
        } 
    }

    for(int i = 0; i < totalPackages; i++){
        if(packageList[i].size <= 10){
            price += 0.01;
        } else if(packageList[i].size <= 50){
            price += 0.11;
        } else if(packageList[i].size <= 100){
            price += 0.22;
        } else if (packageList[i].size <= 150){
            price += 0.33;
        } else if (packageList[i].size <= 250){
            price += 0.56;
        } else if(packageList[i].size <= 400){
            price += 1.5;
        } else if(packageList[i].size <= 500){
            price += 3.11;
        } else if(packageList[i].size <= 600){
            price += 4.89;
        } else if(packageList[i].size > 600){
            price += 5.79;
        }
    }

    for(int i = 0; i < totalPackages; i++){
        totalWeight += packageList[i].weight;
        totalSize += packageList[i].size;
    }
    
    
    for(int i = 0; i < totalPackages; i++){
        if(totalWeight <= 20){
            totalPrice += 0.46;
        }else if(totalWeight <= 50){
            totalPrice += 0.69;
        }else if(totalWeight <= 100){
            totalPrice += 1.02;
        }else if(totalWeight <= 200){
            totalPrice += 1.75;
        }else if(totalWeight <= 350){
            totalPrice += 2.13;
        }else if(totalWeight <= 500){
            totalPrice += 2.44;
        }else if(totalWeight <= 1000){
            totalPrice += 3.20;
        }else if(totalWeight <= 2000){
            totalPrice += 4.27;
        }else if(totalWeight <= 3000){
            totalPrice += 5.03;
        } 
    }

    for(int i = 0; i < totalPackages; i++){
        if(totalSize <= 10){
            totalPrice += 0.01;
        } else if(totalSize <= 50){
            totalPrice += 0.11;
        } else if(totalSize <= 100){
            totalPrice += 0.22;
        } else if (totalSize <= 150){
            totalPrice += 0.33;
        } else if (totalSize <= 250){
            totalPrice += 0.56;
        } else if(totalSize <= 400){
            totalPrice += 1.5;
        } else if(totalSize <= 500){
            totalPrice += 3.11;
        } else if(totalSize <= 600){
            totalPrice += 4.89;
        } else if(totalSize > 600){
            totalPrice += 5.79;
        }
    }

    print(price, totalPrice);

    return 0;
}

void print(float price, float totalPrice){

    printf("If you send the packages separetly you will have to pay: %.3f\n", price);
    printf("If you send the packages together you will have to pay: %.3f\n", totalPrice);

    if(price > totalPrice){
        printf("It is better to send the packages together.");
    } else if(totalPrice > price){
        printf("It is better to send the packages seperatly");
    } else{
        printf("It doesn't make any difference how you are going to send the packages");
    }

}
