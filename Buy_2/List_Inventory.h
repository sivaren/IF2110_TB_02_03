#ifndef LIST_INVENTORY.H
#define LIST_INVENTORY.H

#include "boolean.h"

#define INVENTORY_CAPACITY 4
#define GADGET_IDUNDEF -1
#define GADGET_PRICEUNDEF -999

typedef struct {
    int id;
    int price;
} DataGadget;

typedef struct {
    DataGadget contents[INVENTORY_CAPACITY];
} ListInventory;

#define GADGETID(g) (g).id
#define GADGETPRICE(g) (g).price
#define ELMTListInventory(l,i) (l).contents[(i)]
#define INVENTORY_GADGETID(l,i) (l).contents[(i)].id
#define INVENTORY_GADGETPRICE(l,i) (l).contents[(i)].price

void createListInventory(ListInventory *l);

DataGadget createGadget(int id, int price);

void createDataGadget(DataGadget g);

void insertGadget(ListInventory *l, DataGadget g);

void displayListInventory(ListInventory l);

int lengthListInventory(ListInventory l);

boolean isListInventoryFull(ListInventory l);

void deleteGadget(ListInventory *l, int i, DataGadget *val);


#endif