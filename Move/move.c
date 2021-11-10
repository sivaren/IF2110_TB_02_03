#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "listpoint.h"
#include "matrix.h"
#include "matrixpoint.h"

void move(MatrixPoint *map, Matrix adjacency_matrix, Point *coordinate_mobita) {
    printf("Posisi yang dapat dicapai:\n");
    int num = 1;
    ListPoint l;
    CreateListPoint(&l);
    int row_mobita = (int) Name(*coordinate_mobita) - 64;
    for (int j = 0; j < COLS(adjacency_matrix); j++)
    {
        if (ELMT(adjacency_matrix, row_mobita, j) == 1)
        {
            if (j == 0)
            {
                printf("%d. Headquarters\n");
                int row = 0;
                int col = 0;
                boolean found = false;
                while (row < ROWSP(*map) && !found)
                {
                    while (col < COLSP(*map) && !found)
                    {
                        if (NAME(*map,row,col) == '8')
                        {
                            WritePoint(POINT(*map,row,col));
                            insertLastListPoint(&l,POINT(*map,row,col));
                            found = true;
                        }
                        if (!found)
                        {
                            col++;
                        }
                    }
                    if (!found)
                    {
                        row++;
                    }
                }               
            }
            else
            {
                printf("%d. ", num);
                int row = 0;
                int col = 0;
                boolean found = false;
                while (row < ROWSP(*map) && !found)
                {
                    while (col < COLSP(*map) && !found)
                    {
                        char name = (char) (j + 64);
                        if (name == NAME(*map,row,col))
                        {
                            WritePoint(POINT(*map,row,col));
                            insertLastListPoint(&l,POINT(*map,row,col));
                            found = true;
                        }
                        if (!found)
                        {
                            col++;
                        }
                    }
                    if (!found)
                    {
                        row++;
                    }
                }
            num++;
        }        
    }
    int total_point = lengthListPoint(l);
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    printf("\n");
    int option;
    scanf("ENTER COMMAND: %d", &option); // Pilih angka antara 0-total_point
    while (option < 0 || option > total_point)
    {
        printf("Masukkan angka antara 0-total_point!\n");
        scanf("ENTER COMMAND: %d", &option); // Pilih angka antara 0-total_point
    }
    printf("\n");
    if (option != 0)
    {
        int idx = option-1;
        *coordinate_mobita = ELMTListPoint(l, idx);
        printf("Mobita sekarang berada di titik ");
        WritePoint(ELMTListPoint(l, idx));
        printf("!\n");
    }
}