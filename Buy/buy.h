#ifndef BUY_H
#define BUY_H

#include <stdio.h>
#include "ListGadget.h"
#include "../Inventory/ListInventory.h"
#include "../Move/move.h"
#include "../Map/point.h"

void Buy(ListGadget gadget, ListInventory *inventory, Point coordinate_mobita, int *Money);

#endif