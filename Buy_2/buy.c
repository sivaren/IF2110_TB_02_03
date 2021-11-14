#include <stdio.h>
#include "List_Inventory.h"

#include "../ADT/ADT List Statis/ListOfBangunan.h"
#include "../ADT/ADT Point/point.h"
#include "../Move/move.h"

void Buy(ListInventory *inventory, ListOfBangunan LB, Point *coordinate_mobita, int *Money)
{
    if(PointToNamaBangunan(*coordinate_mobita, LB) != '8')
    {
        printf("Anda hanya dapat membeli Gadget di Headquarters!");
    }
    else 
    {
        int i;
        printf("Uang Anda sekarang: %d Yen\n", Money);
        printf("Gadget yang tersedia: \n");
        for(i = 0; i < 4; i++)
        {
            prinf("%d. ", (i+1));
            //bingung ngeprintnya karna pake ID
            //atau print manual?
        }
        printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
        printf("\n");

        int op;
        scanf("ENTER COMMAND: %d", &op);

        //meminta inputan yang valid
        while (op < 0 || op > 4)
        {
            printf("Masukkan angka antara 0 - 4!\n");
            scanf("ENTER COMMAND: %d", &op); 
        }

        if (op != 0)
        {
            //hanya dapat membeli gadget apabila inventory gadget belum penuh
            if(!isFullListInventory(inventory))
            {
                int idx, currMoney;
                idx = op-1;
                
                //bingung juga set harganya gimana
                currMoney = *Money - INVENTORY_GADGETPRICE(*inventory,idx);
                if(currMoney >= 0)
                {
                    //uang berkurang
                    *Money = currMoney;

                    //bingung ngeprint nama barangnya karna pake ID
                    printf("%c berhasil dibeli!\n",ELMTListInventory(*inventory,idx).id);
                    printf("Uang Anda sekarang: %d Yen", *Money);

                    //memasukkan Gadget yang dibeli ke dalam list inventory
                    insertGadget(inventory, createGadget(idx,INVENTORY_GADGETPRICE(*inventory,idx)));
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
