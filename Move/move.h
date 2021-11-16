#ifndef MOVE_H
#define MOVE_H

#include "../Map/listpoint.h"
#include "../Map/map.h"

ListPoint adjacent(ListPoint map, Matrix adjacency_matrix, Point coordinate_mobita, Point HQ);
void move(ListPoint map, Matrix adjacency_matrix, Point *coordinate_mobita, Point HQ);

#endif