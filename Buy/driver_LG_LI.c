#include <stdio.h>
#include "ListGadget.h"
#include "../Map/point.h"
#include "../Inventory/ListInventory.h"
#include "../Inventory/Inventory.h"
#include "buy.h"

int main()
{
    int Money = 10000;
    ListGadget gadget;
    createListGadget(&gadget);
    ELMTListGadget(gadget,0) = setGadget(1, 800);
    ELMTListGadget(gadget,1) = setGadget(2, 1200);
    ELMTListGadget(gadget,2) = setGadget(3, 1500);
    ELMTListGadget(gadget,3) = setGadget(4, 3000);

    displayGadget(gadget);
    printf("\n");

    ListInventory inventory;
    CreateListInventory(&inventory);
    printf("Isi List Inventory sebelum di insert Gadget : \n");
    displayInventory(inventory);

    printf("\n");
    printf("Setelah di-insert 5 Gadget : \n");
    //Insert Kain Pembungkus Waktu, Senter Pembesar, Pintu Kemana Saja, Mesin Waktu, Kain Pembungkus Waktu
    insertGadget(&inventory, LISTGADGET_IDNAME(gadget,0));
    insertGadget(&inventory, LISTGADGET_IDNAME(gadget,1));
    insertGadget(&inventory, LISTGADGET_IDNAME(gadget,2));
    insertGadget(&inventory, LISTGADGET_IDNAME(gadget,3));
    insertGadget(&inventory, LISTGADGET_IDNAME(gadget,1));
    displayInventory(inventory);

    printf("\n");
    printf("Apakah List Inventory sudah penuh? ");
    printf("%d \n", isFullInventory(inventory));

    printf("\n");

    printf("Isi List Inventory setelah Pintu Kemana Saja dan Kain Pembungkus Waktu dihapus : \n");
    deleteGadget(&inventory, 0, LISTGADGET_IDNAME(gadget,0));
    deleteGadget(&inventory, 2, LISTGADGET_IDNAME(gadget,2));
    displayInventory(inventory);
    printf("\n");

    printf("Isi List Inventory setelah insert Pintu Kemana Saja : \n");
    insertGadget(&inventory, LISTGADGET_IDNAME(gadget,2));
    displayInventory(inventory);
    printf("Jumlah gadget dalam list adalah %d\n", lengthListInventory(inventory));
}
