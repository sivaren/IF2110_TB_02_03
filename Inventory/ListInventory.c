#include <stdio.h>
#include "ListInventory.h"
#include "../Buy/ListGadget.h"

/* Konstruktor : create List kosong  */
void CreateListInventory(ListInventory *l) 
{
    int i;
    for (i = 0; i < INVENTORY_CAPACITY; i++) 
    {
        ELMTInventory(*l,i) = INVENTORY_GADGETUNDEF;
    }
}

int lengthListInventory(ListInventory l) 
/* Mengirimkan banyaknya elemen efektif List */
{
    int i, sum = 0;
    /* ALGORITMA */
    for (i = 0; i < INVENTORY_CAPACITY; i++) {
        if (ELMTInventory(l,i) != INVENTORY_GADGETUNDEF) {
            sum += 1;
        }
    }
    return sum;
}

boolean isFullInventory(ListInventory l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return (lengthListInventory(l) == INVENTORY_CAPACITY);
}

void displayInventory(ListInventory l) 
/* Menampilkan list gadget yang ada di dalam Inventory */
{
    /* KAMUS LOKAL */
    int i;
    int num;
    /* ALGORITMA */
    for (num = 1; num <= 5; num++)
    {
        printf("%d.", num);
        i = num-1;
        printf("%c\n", ELMTInventory(l,i));
    }
    i++;
}    

void insertGadget(ListInventory *l, Gadget val) 
/* Memasukkan Gadget yang telah dibeli ke dalam inventory*/
{
    if (lengthListInventory(*l) < INVENTORY_CAPACITY) 
    {
        ELMTInventory(*l,lengthListInventory(*l)) = val;
    }
}

void deleteGadget(ListInventory l, Gadget val) 
/* Menghapus Gadget yang telah digunakan dari inventory */
{
    val = INVENTORY_GADGETUNDEF;
}