#include <stdio.h>
#include "map.h"
#include "../Move/move.h"
#include "../pcolor/pcolor.h"

boolean isDestination(ListPoint destination, Point building) {
    boolean found = false;
    int i = 0;
    while (i < lengthListPoint(destination) && !found)
    {
        if (Name(building) == NameELMTListPoint(destination,i))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

void map(ListPoint list_building, Matrix adjacency_matrix, Point coordinate_mobita, Point HQ, char drop_off, char pick_up, int N, int M) {
    ListPoint destination = adjacent(list_building,adjacency_matrix,coordinate_mobita,HQ);
    Matrix m;
    CreateMatrix(N+2,M+2,&m);
    for (int i = 0; i < ROWS(m); i++)
    {
        for (int j = 0; j < COLS(m); j++)
        {
            if (i == 0 || j == 0 || i == ROWS(m)-1 || j == COLS(m)-1)
            {
                printf("*");
            }
            else if (Absis(HQ) == i && Ordinat(HQ) == j)
            {
                if (Name(coordinate_mobita) = Name(HQ))
                {
                    print_yellow('8');
                }
                else if (isDestination(destination,HQ))
                {
                    print_green('8');
                }
                else
                {
                    printf("8");
                }
            }          
            else
            {
                boolean found = false;
                int k = 0;
                while (k < lengthListPoint(list_building) && !found)
                {
                    if (i == AbsisELMTListPoint(list_building,k) && j == OrdinatELMTListPoint(list_building,k))
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
                    if (NameELMTListPoint(list_building,k) == Name(coordinate_mobita))
                    {
                        print_yellow(NameELMTListPoint(list_building,k));
                    }
                    else if (NameELMTListPoint(list_building,k) == drop_off)
                    {
                        print_blue(NameELMTListPoint(list_building,k));
                    }
                    else if (NameELMTListPoint(list_building,k) == pick_up)
                    {
                        print_red(NameELMTListPoint(list_building,k));
                    }
                    else
                    {
                        if (isDestination(destination, ELMTListPoint(list_building,k)))
                        {
                            print_green(NameELMTListPoint(list_building,k));
                        }
                        else
                        {
                            printf("%c", NameELMTListPoint(list_building,k));
                        }
                    }
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