/*За да направи една етажерка, дърводелец се нуждае от следните
компоненти: 4 дълги дъски, 6 къси дъски, 12 малки скоби, 2 големи скоби и 14 винта.
Дърводелецът има на склад А дълги дъски, В къси дъски, С малки скоби, D големи скоби и E
винта. Колко етажерки може да направи дърводелецът?
Изход:
С наличните на склад материали (33 дълги дъски, 55 къси дъски, 88 малки скоби, 22 големи
скоби и 99 винта) дърводелецът може да направи 7 етажерки. */



#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int shortBoard;
    int longBoard;
    int smallBrackets;
    int bigBrackets;
    int screws;
}shelf;

int array[5];

int main(void){


    shelf * availabe = (shelf*) malloc(sizeof(shelf));
    shelf * required = (shelf*) malloc(sizeof(shelf));

    printf("Please, enter how many long boards are on stock: \n");
    scanf("%d", &availabe->longBoard);
    printf("Please, enter how many short boards are on stock:\n");
    scanf("%d", &availabe->shortBoard);
    printf("Please, enter how many small brackets are on stock: \n");
    scanf("%d", &availabe->smallBrackets);
    printf("Please, enter how many big brackets are on stock: \n");
    scanf("%d", &availabe->bigBrackets);
    printf("Please, enter how many screws are on stock: \n");
    scanf("%d", &availabe->screws);

    required->shortBoard = 6;
    required->longBoard = 4;
    required->smallBrackets = 12;
    required->bigBrackets = 2;
    required->screws = 14;

    array[0] = availabe->shortBoard / required->shortBoard;
    array[1] = availabe->longBoard / required->longBoard;
    array[2] = availabe->smallBrackets / required->smallBrackets;
    array[3] = availabe->bigBrackets / required->bigBrackets;
    array[4] = availabe->screws / required->screws;

    int total = array[0];

    for(int i = 0; i < 5; i++){
       if(total > array[i]){
            total = array[i];
        }
    }
    
    printf("You can build %d shelfs", total);

    free(availabe);
    free(required);
    return 0;
}
