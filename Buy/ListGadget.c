#include <stdio.h>
#include "ListGadget.h"

//create listgadget kosong
void createListGadget(ListGadget *l)
{
    int i;
    for (i = 0; i < 5 ; i++) 
    {
        ELMTListGadget(*l,i).name = GADGET_NAMEUNDEF;
        ELMTListGadget(*l,i).price = GADGET_PRICEUNDEF;
    }
}

//bikin gadget
void createGadget(DataGadget *G)
{
    GADGETNAME(*G) = GADGET_NAMEUNDEF;
    GADGETPRICE(*G) = GADGET_PRICEUNDEF;
}

//input data gadget
DataGadget setGadget(char name[], int price)
{
    DataGadget G;
    createGadget(&G);
    GADGETNAME(G) = name;
    GADGETPRICE(G) = price;
    return G;
}


//menampilkan list gadget yang dapat dibeli
void displayGadget(ListGadget l) {
    int i;
    int num;

    ELMTListGadget(l,0) = setGadget("Kain Pembungkus Waktu", 800);
    ELMTListGadget(l,1) = setGadget("Senter Pembesar", 1200);
    ELMTListGadget(l,2) = setGadget("Pintu Kemana Saja", 1500);
    ELMTListGadget(l,3) = setGadget("Mesin Waktu", 3000);

    printf("Gadget yang tersedia:\n");
    for (num = 1; num <= 4; num++)
    {
        printf("%d. ", num);
        i = num-1;

        //problemnya nanti disini dia malah ngeprint simbol gini
        // Gadget yang tersedia:
        // 1. ♀ (800 Yen)
        // 2. " (1200 Yen)
        // 3. 2 (1500 Yen)
        // 4. D (3000 Yen)
        //yg di list inventory blm dites tapi kayaknya bakal gini juga

        printf("%c ", NAME(l,i));
        printf("(%d Yen)\n", PRICE(l,i));
    }
    i++;
}
