#ifndef MAP_H
#define MAP_H

#include "listpoint.h"
#include "matrix.h"
#include "../toDo/toDo.h"

boolean isDestination(ListPoint destination, Point building);
void map(ListPoint list_building, Matrix adjacency_matrix, Point coordinate_mobita, Point HQ, char drop_off, ToDoList pick_up, int N, int M);

#endif