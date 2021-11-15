#include <stdio.h>
#include "map.h"

void map(ListPoint map, Point HQ, int N, int M) {
    Matrix m;int i,j;
    CreateMatrix(N,M,&m);
    int row = ROWS(m)+2;
    int col = COLS(m)+2;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            if (i == 0 || j == 0 || i == row-1 || j == col-1)
            {
                printf("*");
            }
            else if (Absis(HQ) == i && Ordinat(HQ) == j)
            {
                printf("8");
            }          
            else
            {
                boolean found = false;
                int k = 0;
                while (k < lengthListPoint(map) && !found)
                {
                    if (i == AbsisELMTListPoint(map,k) && j == OrdinatELMTListPoint(map,k))
                    {
                        found = true;
                    }
                    else
                    {
                        k++;
                    }                    
                }   
                if (found)
                {
                    printf("%c", NameELMTListPoint(map,k));
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}