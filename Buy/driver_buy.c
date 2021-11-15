#include <stdio.h>
#include "ListGadget.h"
#include "../Inventory/ListInventory.h"
#include "buy.h"

//Belum jadi
int main()
{
    int *Money;
    ListInventory *inventory;
    CreateListInventory(inventory);    

    //menentukan titik mobita saat ini
    Point *coordinate_mobita;
    ReadPoint(coordinate_mobita);

    //isi list gadget dengan gadget
    ListGadget gadget;
    createListGadget(&gadget);
    ELMTListGadget(gadget,0) = setGadget(1, 800);
    ELMTListGadget(gadget,1) = setGadget(2, 1200);
    ELMTListGadget(gadget,2) = setGadget(3, 1500);
    ELMTListGadget(gadget,3) = setGadget(4, 3000);

    Buy(gadget, inventory, *coordinate_mobita, Money);
}
