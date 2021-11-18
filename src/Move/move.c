#include <stdio.h>
#include "boolean.h"
#include "move.h"
#include "../mesinKarKat/wordmachine.h"

ListPoint adjacent(ListPoint map, Matrix adjacency_matrix, Point coordinate_mobita, Point HQ) {
    int num = 1, row_mobita; int j;
    ListPoint l;
    CreateListPoint(&l,100);
    if (EQ(coordinate_mobita,HQ))
    {
        row_mobita = 0;
    }
    else
    {
        row_mobita = (int) Name(coordinate_mobita) - 64;
    }
    for (j = 0; j < COLS(adjacency_matrix); j++)
    {
        if (ELMT(adjacency_matrix, row_mobita, j) == 1)
        {
            if (j == 0)
            {
                insertLastListPoint(&l,HQ);             
            }
            else
            {
                int ctr = 0;
                boolean found = false;
                while (!found)
                {
                    char name = (char) (j+64);
                    if (name == NameELMTListPoint(map,ctr))
                    {
                        insertLastListPoint(&l,ELMTListPoint(map,ctr));
                        found = true;
                    }
                    else
                    {
                        ctr++;
                    }
                }
            }   
            num++;
        }        
    }
    return l;
}

void move(ListPoint map, Matrix adjacency_matrix, Point *coordinate_mobita, Point HQ) {
    printf("Posisi yang dapat dicapai:\n");
    ListPoint list_adjacent = adjacent(map,adjacency_matrix,*coordinate_mobita,HQ);
    int i;
    for ( i = 0; i < lengthListPoint(list_adjacent); i++)
    {
        if (NameELMTListPoint(list_adjacent,i) == Name(HQ))
        {
            printf("%d. Headquarters", i+1);
        }
        else
        {
            printf("%d. ", i+1);
            WritePoint(ELMTListPoint(list_adjacent,i));
        }
        printf("\n");
    }
    int total_point = lengthListPoint(list_adjacent);
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    printf("\n");
    int option;
    printf("ENTER NUMBER: ");
    option = scanINT();
    while (option < 0 || option > total_point)
    {
        printf("Masukkan angka antara 0-%d\n", total_point);
        printf("ENTER NUMBER: ");
        option = scanINT();
    }
    printf("\n");
    if (option != 0)
    {
        int idx = option-1;
        *coordinate_mobita = ELMTListPoint(list_adjacent, idx);
        printf("Mobita sekarang berada di titik ");
        WritePoint(ELMTListPoint(list_adjacent, idx));
        printf("!\n");
    }
}
