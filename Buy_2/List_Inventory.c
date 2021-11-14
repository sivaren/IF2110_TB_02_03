#include <stdio.h>
#include "List_Inventory.h"

//membuat list inventory, elemennya diisi dengan UNDEF
void createListInventory(ListInventory *l)
{  
    int i;
    for (i = 0; i < INVENTORY_CAPACITY; i++)
    {
        INVENTORY_GADGETID(*l,i) = GADGET_IDUNDEF;
        INVENTORY_GADGETPRICE(*l,i) = GADGET_PRICEUNDEF;
    }
}

//membuat gagdet (misalnye createGadget(1, 800))
DataGadget createGadget(int id, int price)
{
    DataGadget G;
    GADGETID(G) = id;
    GADGETPRICE(G) = price;
    return G;
}

void createDataGadget(DataGadget g)
{
    ListInventory l;
    createListInventory(&l);
    ELMTListInventory(l,0) = createGadget(1, 800);
    ELMTListInventory(l,1) = createGadget(2, 1200);
    ELMTListInventory(l,2) = createGadget(3, 1500);
    ELMTListInventory(l,3) = createGadget(4, 3000);
}

//insert gadget yang sudah dibeli ke dalam inventory
void insertGadget(ListInventory *l, DataGadget g)
{

    int i;
    for(i = 0; i < INVENTORY_CAPACITY; i++)
    {
        if(INVENTORY_GADGETID(*l,i) == GADGET_IDUNDEF)
        {
            INVENTORY_GADGETID(*l,i) = GADGETID(g);
            INVENTORY_GADGETPRICE(*l,i)= GADGETPRICE(g);
           }
    }

}

//menampilkan daftar gadget yang ada di inventory
void displayListInventory(ListInventory l)
{
    int i, num;
    for(num = 1; num <= INVENTORY_CAPACITY; num++)
    {
        i = num-1;
        if(INVENTORY_GADGETID(l,i) == 1)
        {
            printf("Kain Pembungkus Waktu\n");
        }
        else if(INVENTORY_GADGETID(l,i) == 2)
        {
            printf("Senter Pembesar\n");
        }
        else if(INVENTORY_GADGETID(l,i) == 3)
        {
            printf("Pintu Kemana Saja\n");
        }
        else if(INVENTORY_GADGETID(l,i) == 4)
        {
            printf("Mesin Waktu\n");
        }
        else 
        {
            printf("-\n");
        }
    }
}

//mengembalikan panjang list inventory
int lengthListInventory(ListInventory l) 
{
    int i, sum = 0;

    for (i = 0; i < INVENTORY_CAPACITY; i++) {
        if (INVENTORY_GADGETID(l,i) != GADGET_IDUNDEF) 
        {
            sum += 1;
        }
    }
    return sum;
}

//memeriksa apakah inventory gadget sudah penuh atau belum
boolean isListInventoryFull(ListInventory l)
{
    return (lengthListInventory(l) == INVENTORY_CAPACITY);
}

//menghapus gadget dari inventory
void deleteGadget(ListInventory *l, int i, DataGadget *val)
{
    GADGETID(*val) = INVENTORY_GADGETID(*l,i);
    GADGETID(*val) = GADGET_IDUNDEF;
    GADGETPRICE(*val) = INVENTORY_GADGETPRICE(*l,i);
    GADGETPRICE(*val) = GADGET_PRICEUNDEF;
}