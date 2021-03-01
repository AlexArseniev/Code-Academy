/*16.Да се състави програма, с помощта на която играч може да
играе (с право на връщане на ходовете) следната игра СОЛИТЕР:
На игралното поле са поставени 16 номерирани пулове и три реда
с по осем позиции. Целта е да се извадят от игра всички пулове с
изключение на номер 1. Може да се прескача през някой пул на
свободна клетка, но не се разрешава движение по диагонал.
Например възможни са ходове 1-9; 2-10; 1-2 и т.н. По тази схема 1
прескача 9 и 9х излиза от игра – отстранява се от полето, след
това 2 прескача 10 и 10 отпада от играта; по-нататък 1 прескача 2 и
2 излиза от игра.*/
#include <stdio.h>
int sumArr(int arr[3][8])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
int main()
{
    int board[3][8] = {0, 0, 0, 0, 0, 0, 0, 0}; /*0 -свободни клетки */
    int a = 9;
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            board[i][j] = a++;
        }
        a = 1;
    }

    int start, i, j;
    int d, temp;
    while (sumArr(board) > 1)
    {

        for (int l = 0; l < 3; l++)
        {
            for (int k = 0; k < 8; k++)
            {
                printf("%d\t", board[l][k]);
            }
            printf("\n");
        }
        printf("Choose which element to move, if you want to go back press 0\n");
        scanf("%d", &start);
        if (start == 0)
        {
            if (d == 3)
            {
                board[i][j] = board[i - 2][j];
                board[i - 1][j] = temp;
                board[i - 2][j] = 0;
            }
            else if (d == 2)
            {
                board[i][j] = board[i][j + 2];
                board[i][j + 1] = temp;
                board[i][j + 2] = 0;
            }
            else if (d == 1)
            {
                board[i][j] = board[i][j - 2];
                board[i][j - 1] = temp;
                board[i][j - 2] = 0;
            }
            else if (d == 4)
            {
                board[i][j] = board[i + 2][j];
                board[i + 1][j] = temp;
                board[i + 2][j] = 0;
            }
            continue;
        }
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 8; l++)
            {
                if (board[k][l] == start)
                {
                    i = k;
                    j = l;
                }
            }
        }
        printf("Enter a direction 1 for left, 2for right, 3 for up, 4 for down\n");
        scanf("%d", &d);

        if (d == 3 && board[i - 2][j] == 0)
        { /*нагоре */
            board[i - 2][j] = board[i][j];
            temp = board[i - 1][j];
            board[i - 1][j] = 0;
            board[i][j] = 0;
        }
        else if (d == 2 && board[i][j + 2] == 0)
        { /*надясно*/
            board[i][j + 2] = board[i][j];
            temp = board[i][j + 1];
            board[i][j + 1] = 0;
            board[i][j] = 0;
        }
        else if (d == 4 && board[i + 2][j] == 0)
        { /* надолу */
            board[i + 2][j] = board[i][j];
            temp = board[i + 1][j];
            board[i + 1][j] = 0;
            board[i][j] = 0;
        }
        else if (d == 1 && board[i][j - 2] == 0)
        { /*наляво*/
            board[i][j - 2] = board[i][j];
            temp = board[i][j - 1];
            board[i][j - 1] = 0;
            board[i][j] = 0;
        }
    }
    printf("You won the game!");
    return 0;
}