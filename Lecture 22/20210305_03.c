/*Задача 3. С увеличаване на надморската височина температурата намалява с
около 0,5ºC на всеки 100м. Нека приемем, че атмосферното налягане е нормално.
Ако се знае температурата (ХºC) на хижа Вихрен (1950 метра над морското
равнище), да се изчисли каква е температурата на връх Вихрен (2918 метра над
морското равнище). Ако се знае температурата (УºC) на връх Вихрен, да се изчисли
каква е температурата на хижа Вихрен.
Изход 1:
Ако атмосферното налягане е нормално и температурата на хижа Вихрен (1950м
н.м.р.) е ... ºC , то температурата на връх Вихрен (2918м н.м.р.) е ... ºC.
Изход 2:
Ако атмосферното налягане е нормално и температурата на връх Вихрен (2918м
н.м.р.) е ... ºC , то температурата на хижа Вихрен (1950м н.м.р.) е ... ºC.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int altitude;
    float temperature;
}conditions;


int main(void){

    float result = 0;
    int choice = 0;
    int temperature = 0;
    conditions * peack = (conditions*) malloc(sizeof(conditions));
    conditions * hut = (conditions*) malloc(sizeof(conditions));

    peack->altitude = 2915;
    hut->altitude = 1950;

    int differenceInAltitude = peack->altitude - hut->altitude;

    here: 

    printf("Hello! Which temperature value do you know?\nFor the peack press 1\nFor the hut press 2\n");
    scanf("%d", &choice);
    
    if(choice != 1 && choice != 2){
        
        printf("Please enter a valid digit.\n\n");
        goto here;
    }
    
    printf("What is the temperature at your position?\n");
    
    if(choice == 1){

        scanf("%f", &peack->temperature);

        result = peack->temperature + ((differenceInAltitude / 100) * 0.5);

    } else if(choice == 2){

        scanf("%f", &hut->temperature);

         result = hut->temperature - ((differenceInAltitude / 100) * 0.5);
    }

    if (choice == 1){

        printf("If the atmospheric pressure is normal and the temperature at peack Vihren (%d m) is %.1f C the temperature at Vihren hut is: %.1f C", peack->altitude, peack->temperature, result);
    } else {
         printf("If the atmospheric pressure is normal and the temperature at hut Vihren (%d m) is %.1f C the temperature at peack Vihren is: %.1f C", hut->altitude, hut->temperature, result);
    }

    free(peack);
    free(hut);
    
    return 0;
}
