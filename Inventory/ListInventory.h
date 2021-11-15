#ifndef LISTINVENTORY_H
#define LISTINVENTORY_H

#include "boolean.h"

/*  Kamus Umum */
#define INVENTORY_CAPACITY 5
#define INVENTORY_IDXUNDEF -999

typedef int Gadget;  
typedef struct {
   Gadget contents[INVENTORY_CAPACITY]; 
} ListInventory;

#define ELMTInventory(l, i) (l).contents[(i)]

void CreateListInventory(ListInventory *l);

int lengthListInventory(ListInventory l);

boolean isFullInventory(ListInventory l);

void displayInventory(ListInventory l);

void insertGadget(ListInventory *l, Gadget id);

void deleteGadget(ListInventory *l, int i, Gadget id);


#endif