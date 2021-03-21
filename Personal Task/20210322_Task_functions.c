#include <stdlib.h>
#include <stdio.h>


//This function is asking you how big do you want the board to be
int boardSize(void){
    
    int size = 0;
    here:
    printf("How big do you want the board to be? (from 10 - 30)\n");
    scanf("%d", &size);

    if(size < 10 || size > 30 ){
        printf("Please, enter a value between 10 and 30\n");
        goto here;
    }
    return size;
}

//Sets the board for play
void drawBoard(int size, char array[]){

    char *playerOne = array;
    char *playerTwo = &array[size-1];

        for(int i = 0; i < size; i++){
        
            if(i == 0){
                *playerOne = '1';
            } else if(i == size - 1){
                *playerTwo = '2';
            } else{
                array[i] = '*';
            }
        printf("|");
        printf("%c", array[i]); 
        printf("|");
    }
}

//This function is used to determin the max move during the game
int maxMoves(int result){
    
    int moves = 0;

    here2:
    printf("\nWhat do you want to be your max move? (The maximum according to your board size is %d)\n", result);
    scanf("%d", &moves);

    if(moves > result || moves <= 0){
        if(moves == 0){
            printf("You can't have zero as maximum move. You will not be able to move.");
        } else if(moves < 0){
            printf("You can't have a nagative number as maximum move. Please enter a new value");
        } else {
            printf("You have to enter a valid size of the step");
        }

        goto here2;
    }
    return moves;
}

//Printing the board
int print(char array[], int size){
        
    for(int i = 0; i < size; i++){
        printf("|");
        printf("%c", array[i]); 
        printf("|");
    }
}

//The game
void game(int moves, int size, char array[]){

    char* playerOne = array;
    char* playerTwo = &array[size - 1];

    int steps = 0;
    int direction = 0;
    int currentP1 = 0;
    int currentP2 = size - 1;
    int difference = size - 2;
    
    
    while(1){
        printf("\nPlayer one turn\n");
        here3:
        printf("How many steps do you want to make? (max %d)\n", moves);
        scanf("%d", &steps);
        if(steps > moves || steps <= 0){
            if(steps > moves){
                printf("The maximum number of steps you can make is %d.\n", moves);
                goto here3;
            } else if(steps == 0){
                printf("You can't stay on the same possition. You have to make a move\n");
                goto here3;
            } else {
                printf("You can't eneter a negative value for the steps.\n");
                goto here3;
            }
        }
        printf("In what direction do you want to move?\nPress 1 for left\nPress 2 for right\n");
        scanf("%d", &direction);
        

        if(direction == 2){
            if(difference + 1 < steps){
                printf("You can't jump over the opponent.\n");
                continue;
            }else if(difference + 1 == steps){
                printf("========\n");
                printf("YOU WIN!\n");
                printf("========");
                break;
            } else {
                currentP1 += steps;
                *playerOne = '*';
                playerOne += steps;
                *playerOne = '1';
                int i = 0;
                
                print(array, size);

            }
        } else if(direction == 1){
            if((currentP1 - steps) < 0){
                printf("You can't make %d steps to left. You have to make another move\n", steps);
                continue;
            } else {
                currentP1 -= steps;
                *playerOne = '*';
                playerOne -= steps;
                *playerOne = '1';
                int i = 0;
                print(array, size);
            }
        }

        printf("\nPlayer 2\n");
        difference = (currentP2 - currentP1) - 1;

        if(difference > moves){
                *playerTwo = '*';
                int playerMove = difference - moves;
                if(playerMove > moves){
                    playerMove = moves;
                }
                playerTwo -= playerMove;
                currentP2 -= playerMove;
                *playerTwo = '2'; 
                print(array, size);
        } else if(difference < moves){
                *playerTwo = '*';
                playerTwo = playerOne;
                *playerTwo = '2';
                print(array, size);
                printf("\n==============\n");
                printf("PLAYER 2 WINS!\n");
                printf("==============");
                break;
        } else if(difference == moves){
            if(currentP2 < size - 1){
                int maxMove = (size - 1 - currentP2 > moves) ? moves : size - 1 - currentP2;
                *playerTwo = '*';
                playerTwo += maxMove;
                *playerTwo = '2';
                currentP2 += maxMove;
                print(array, size);
            } else if(currentP2 == size - 1){
                *playerTwo = '*';
                playerTwo--;
                *playerTwo = '2';
                currentP2--;
                print(array, size);
            }
        }
        difference = (currentP2 - currentP1) - 1;
    }
}
