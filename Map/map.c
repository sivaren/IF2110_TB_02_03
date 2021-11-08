#include "map.h"

void Map(MatrixPoint map) {
    ROWSP(map) += 2;
    COLSP(map) += 2;
    for (int i = 0; i < ROWSP(map); i++)
    {
        for (int j = 0; j < COLSP(map); j++)
        {
            if (i == 0 || j == 0 || i == ROWSP(map)-1 || j == COLSP(map)-1)
            {
                printf("*");
            }
            else if (NAME(map,i,j) != '#')
            {
                printf("%c", NAME(map,i,j));
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}