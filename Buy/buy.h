#ifndef BUY_H
#define BUY_H

#include <stdio.h>
#include "../Inventory/ListInventory.h"
#include "../Move/move.h"
#include "../ADT/ADT Point/point.h"
#include "ListGadget.h"

void Buy(ListGadget gadget, ListInventory *inventory, Point coordinate_mobita, int *Money);

#endif