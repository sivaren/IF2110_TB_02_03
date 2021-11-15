#include <stdio.h>
#include "ListGadget.h"

//Create listgadget kosong
void createListGadget(ListGadget *l)
{
    int i;
    for (i = 0; i < 5 ; i++) 
    {
        LISTGADGET_IDNAME(*l,i) = GADGET_IDNAMEUNDEF;
        LISTGADGET_PRICE(*l,i) = GADGET_PRICEUNDEF;
    }
}

//Create Gadget
void createGadget(DataGadget *G)
{
    GADGETNAME(*G) = GADGET_IDNAMEUNDEF;
    GADGETPRICE(*G) = GADGET_PRICEUNDEF;
}

//Input data Gadget
DataGadget setGadget(int idname, int price)
{
    DataGadget G;
    createGadget(&G);
    GADGETNAME(G) = idname;
    GADGETPRICE(G) = price;
    return G;
}

//Menampilkan list gadget yang dapat dibeli
void displayGadget(ListGadget l) {
    int i;
    int num;

    // ELMTListGadget(l,0) = setGadget(1, 800);
    // ELMTListGadget(l,1) = setGadget(2, 1200);
    // ELMTListGadget(l,2) = setGadget(3, 1500);
    // ELMTListGadget(l,3) = setGadget(4, 3000);

    printf("Gadget yang tersedia:\n");
    for (num = 1; num <= 4; num++)
    {
        printf("%d. ", num);
        i = num-1;

        if(LISTGADGET_IDNAME(l,i) == 1) 
        {
            printf("Kain Pembungkus Waktu (%d Yen)\n", LISTGADGET_PRICE(l,i));
        }
        else if(LISTGADGET_IDNAME(l,i) == 2)
        {
            printf("Senter Pembesar (%d Yen)\n", LISTGADGET_PRICE(l,i));
        }
        else if(LISTGADGET_IDNAME(l,i) == 3)
        {
            printf("Pintu Kemana Saja (%d Yen)\n", LISTGADGET_PRICE(l,i));
        }
        else if(LISTGADGET_IDNAME(l,i) == 4)
        {
            printf("Mesin Waktu (%d Yen)\n", LISTGADGET_PRICE(l,i));
        }
    }
    i++;
}
