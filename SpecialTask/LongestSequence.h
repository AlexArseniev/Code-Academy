#include <stdlib.h>
#include <stdio.h>

 typedef struct point {
    int x;
    int y;
}t_point;

 typedef struct pointResult {
    t_point *newPoints;
    int size;
}t_pointsResult;

int visitPoint(int x, int y, int rows, int cols, char matrix[][cols], char color);

t_point *getValidAdjacentPoints(int x, int y, int rows, int cols, char matrix[][cols], char color);

int getPointsSize(t_point *points);

t_pointsResult *appendToPoints(t_point *points, t_point *toAppend, int pointsSize);

int visitPointIterate(int rows, int cols, char matrix[][cols]);
