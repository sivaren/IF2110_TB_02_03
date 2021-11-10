#include <stdio.h>
#include <stdlib.h>
#include "../Inventory/ListInventory.h"
#include "../ADT/ADT Point/point.h"
#include "ListGadget.h"

int Money = 100;

void Buy(ListGadget gadget, ListInventory *inventory, Point *coordinate_mobita)
{
    //cek apakah mobita sedang di HQ
    //*coordinate_mobita = ELMTListPoint(l, idx);
    if(Name(coordinate_mobita != '8'))
    {
        printf("Anda hanya dapat membeli Gadget di Headquarters!");
    }
    else 
    {
        printf("Uang Anda sekarang: %d Yen\n", Money);
        displayGadget(gadget);
        printf("\n");

        int op;
        scanf("ENTER COMMAND: %d", &op);
        //meminta inputan yang valid
        while (op < 0 || op > 4)
        {
            printf("Masukkan angka antara 0 - 4!\n");
            scanf("ENTER COMMAND: %d", &op); 
        }

        //hanya bisa membeli item jika inventory belum penuh
        if (op != 0)
        {
            //hanya dapat membeli gadget apabila inventory gadget belum penuh
            if(!isFullInventory(*inventory))
            {
                int idx, currMoney;
                idx = op-1;

                currMoney = Money - ELMTListGadget(gadget,idx).price;
                if(currMoney >= 0)
                {
                    //uang berkurang
                    Money = currMoney;
                    printf("%c berhasil dibeli!\n",ELMTListGadget(gadget,idx).name);
                    printf("Uang Anda sekarang: %d Yen", Money);
                    //memasukkan Gadget yang dibeli ke dalam list inventory
                    insertGadget(inventory, ELMTListGadget(gadget,idx).name);
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!");
                }
            }
            else
            {
                printf("Inventory gadget Anda sudah penuh!");
            }
        }
    }
    
}
