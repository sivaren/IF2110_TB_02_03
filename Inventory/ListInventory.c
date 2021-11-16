#include <stdio.h>
#include "ListInventory.h"
#include "../Buy/ListGadget.h"

//create list kosong
void CreateListInventory(ListInventory *l) 
{
    int i;
    for (i = 0; i < INVENTORY_CAPACITY; i++) 
    {
        ELMTInventory(*l,i) = INVENTORY_IDXUNDEF;
    }
}

//Mengirimkan banyaknya elemen efektif list
int lengthListInventory(ListInventory l) 
{
    int i, sum = 0;
    /* ALGORITMA */
    for (i = 0; i < INVENTORY_CAPACITY; i++) {
        if (ELMTInventory(l,i) != INVENTORY_IDXUNDEF) {
            sum += 1;
        }
    }
    return sum;
}

//mengirimkan true jika list inventory sudah penuh
boolean isFullInventory(ListInventory l)
{
    return (lengthListInventory(l) == INVENTORY_CAPACITY);
}

//menampilkan list gadget yang ada di inventory
void displayInventory(ListInventory l) 
{
    int i, num;
    for(num = 1; num <= INVENTORY_CAPACITY; num++)
    {
        printf("%d. ", num);
        i = num-1;
        if(ELMTInventory(l,i) == 1)
        {
            printf("Kain Pembungkus Waktu\n");
        }
        else if(ELMTInventory(l,i) == 2)
        {
            printf("Senter Pembesar\n");
        }
        else if(ELMTInventory(l,i) == 3)
        {
            printf("Pintu Kemana Saja\n");
        }
        else if(ELMTInventory(l,i) == 4)
        {
            printf("Mesin Waktu\n");
        }
        else 
        {
            printf("-\n");
        }
    }
}    


//insert gadget yang sudah dibeli ke dalam inventory
void insertGadget(ListInventory *l, Gadget id)
{

    int i = 0;
    boolean flag = true;
    while(i < INVENTORY_CAPACITY && flag)
    {
        if (ELMTInventory(*l,i) == INVENTORY_IDXUNDEF)
        {
            ELMTInventory(*l,i) = id;
            flag = false;
        }
        i += 1;
    }
}


//menghapus gadget dari list inventory
void deleteGadget(ListInventory *l, int i, Gadget id)
{
    id = ELMTInventory(*l,i);
    ELMTInventory(*l,i) = INVENTORY_IDXUNDEF;
}