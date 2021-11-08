#ifndef MatrixPoint_H
#define MatrixPoint_H

#include "point.h"

#define ROW_CAP 100
#define COL_CAP 100

typedef struct
{
    Point contents[ROW_CAP][COL_CAP];
    int rowEffPoint; /* banyaknya/ukuran baris yg terdefinisi */
    int colEffPoint; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixPoint;
};

#define ROWSP(M) (M).rowEffPoint
#define COLSP(M) (M).colEffPoint
#define POINT(M, i, j) (M).contents[(i)][(j)]
#define NAME(M, i, j) (M).contents[(i)][(j)].name
#define ABSIS(M, i, j) (M).contents[(i)][(j)].X
#define ORDINAT(M, i, j) (M).contents[(i)][(j)].Y