#ifndef MOVE_H
#define MOVE_H

#include "listpoint.h"
#include "matrix.h"

ListPoint adjacent(ListPoint map, Matrix adjacency_matrix, Point coordinate_mobita, Point HQ);
void move(ListPoint map, Matrix adjacency_matrix, Point *coordinate_mobita, Point HQ);

#endif