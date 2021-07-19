#include "LongestSequence.h"

int main(int argc, char const *argv[]) {

    char matrix1[][3] = {{'R', 'R', 'B'},
                        {'G', 'G', 'R'},
                        {'R', 'B', 'G'}};

    printf("%d\n", visitPointIterate(3, 3, matrix1));

    char matrix2[][4] = {{'R', 'R', 'R', 'G'},
                        {'G', 'B', 'R', 'G'},
                        {'R', 'G', 'G', 'G'},
                        {'G', 'G', 'B', 'B'}};

    printf("%d\n", visitPointIterate(4, 4, matrix2));

    char matrix3[][6] = {{'R', 'R', 'B', 'B', 'B', 'B'},
                        {'B', 'R', 'B', 'B', 'G', 'B'},
                        {'B', 'G', 'G', 'B', 'R', 'B'},
                        {'B', 'B', 'R', 'B', 'G', 'B'},
                        {'R', 'B', 'R', 'B', 'R', 'B'},
                        {'R', 'B', 'B', 'B', 'G', 'B'}};
                        
    printf("%d\n", visitPointIterate(6, 6, matrix3));

    char matrix4[1000][1000];
    int i,j;
    for(i = 0; i < 1000; i++){
        for(j = 0; j < 1000; j++){
            matrix4[i][j] = 'R';
        }
    }
    printf("%d\n", visitPointIterate(1000, 1000, matrix4));

    return 0;
}

int visitPointIterate(int rows, int cols, char matrix[][cols]){    
    int maxElements = 0;
    int element = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 'v')
                continue;

            int currMax = 1;
            int pointsSize = 0; // adjacent uncovered points
            char color = matrix[i][j];
            t_point *points = getValidAdjacentPoints(i, j, rows, cols, matrix, color);
            pointsSize = getPointsSize(points);
            matrix[i][j] = 'v';
            int currentPosition = pointsSize - 1;
            t_pointsResult *pRez;

            while(pointsSize > 0){
                int pX = points[currentPosition].x;
                int pY = points[currentPosition].y;
                currMax++;
                pointsSize--;
                t_point *newPoints = getValidAdjacentPoints(pX, pY, rows, cols, matrix, color);
                pRez = appendToPoints(points, newPoints, pointsSize);
                points = pRez->newPoints;
                pointsSize = pRez->size;
                currentPosition = pRez->size - 1;
                free(pRez);
            }
            free(points);
            maxElements = currMax > maxElements ? currMax : maxElements;
        }
    }
    return maxElements;    
}

t_pointsResult *appendToPoints(t_point *points, t_point *toAppend, int pointsSize){
    int toAppendSize = getPointsSize(toAppend);
    points = realloc(points, (pointsSize + toAppendSize) * sizeof(t_point));    
    for(int i = 0; i < toAppendSize; i++) {
        points[pointsSize++] = toAppend[i];
    }

    free(toAppend);
    t_pointsResult *returnValue = malloc(sizeof(t_pointsResult));
    returnValue->newPoints = points;
    returnValue->size = pointsSize;
    return returnValue;
}

int getPointsSize(t_point *points){
    int size = 0;
    while(points->x != -1){
        points++;
        size++;
    }
    return size;
}

t_point *getValidAdjacentPoints(int x, int y, int rows, int cols, char matrix[][cols], char color) {
    t_point *points = (t_point*) malloc(5 * sizeof(t_point));
    int validPoints = 0; // valid adjacent points count

    if(((y-1) >= 0) && ((y-1)< cols) && matrix[x][y-1] == color){ //left
        points[validPoints].x = x;
        points[validPoints].y = y-1;
        matrix[x][y-1] = 'v';
        validPoints++;
    }

    if(((x-1) >= 0) && ((x-1) < rows) && matrix[x-1][y] == color ){ //up
        points[validPoints].x = x-1;
        points[validPoints].y = y;
        matrix[x-1][y] = 'v';
        validPoints++;
    }

    if(((y+1) >= 0) && ((y+1) < cols) && matrix[x][y+1] == color){ //right
        points[validPoints].x = x;
        points[validPoints].y = y+1;
        matrix[x][y+1] = 'v';
        validPoints++;
    }

    if(((x+1) >= 0) && ((x+1) < rows) && matrix[x+1][y] == color){ //down
        points[validPoints].x = x+1;
        points[validPoints].y = y;
        matrix[x+1][y] = 'v';
        validPoints++;
    }

    points[validPoints].x = -1;
    points[validPoints].y = -1;
    return points;
}
