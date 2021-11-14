#ifndef LISTINVENTORY_H
#define LISTINVENTORY_H

#include "boolean.h"

/*  Kamus Umum */
#define INVENTORY_CAPACITY 5
/* Kapasitas penyimpanan */
#define INVENTORY_IDXUNDEF -1
/* Indeks tak terdefinisi*/
#define INVENTORY_GADGETUNDEF '-'
/* Nilai elemen tak terdefinisi*/

typedef char Gadget;  
typedef struct {
   Gadget contents[INVENTORY_CAPACITY]; 
} ListInventory;

#define ELMTInventory(l, i) (l).contents[(i)]

void CreateListInventory(ListInventory *l);

int lengthListInventory(ListInventory l);

boolean isFullInventory(ListInventory l);

void displayInventory(ListInventory l);

void insertGadget(ListInventory *l, Gadget val);

void deleteGadget(ListInventory l, Gadget val);


#endif