#include <stdio.h>
#include <stdlib.h>
#include "buy.h"

void Buy(ListGadget gadget, ListInventory *inventory, Point coordinate_mobita, int *Money)
{
    //*coordinate_mobita = posisi Mobita saat ini
    if (Name(coordinate_mobita) != '8')
    {
        printf("Anda hanya dapat membeli Gadget di Headquarters!\n\n");
    }
    else 
    {
        printf("Uang Anda sekarang: %d Yen\n", *Money);

        //Menampilkan list Gadget yang dapat dibeli
        displayGadget(gadget);
        printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n\n");

        int op;
        printf("ENTER COMMAND: ");
        scanf("%d", &op);
        //Meminta inputan yang valid
        while (op < 0 || op > 4)
        {
            printf("Masukkan angka antara 0 - 4!\n\n");
            printf("ENTER COMMAND: ");
            scanf("%d", &op); 
        }

        if (op != 0)
        {
            //Hanya dapat membeli gadget apabila inventory gadget belum penuh
            if(!isFullInventory(*inventory))
            {
                int idx, currMoney;
                idx = op-1;

                currMoney = *Money - LISTGADGET_PRICE(gadget,idx);
                if(currMoney >= 0)
                {
                    //Uang berkurang
                    *Money = currMoney;

                    if(LISTGADGET_IDNAME(gadget,idx) == 1) 
                    {
                        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                    }
                    else if(LISTGADGET_IDNAME(gadget,idx) == 2)
                    {
                        printf("Senter Pembesar berhasil dibeli!\n");
                    }
                    else if(LISTGADGET_IDNAME(gadget,idx) == 3)
                    {
                        printf("Pintu Kemana Saja berhasil dibeli!\n");
                    }
                    else if(LISTGADGET_IDNAME(gadget,idx) == 4)
                    {
                        printf("Mesin Waktu berhasil dibeli!\n");
                    }
                    
                    printf("Uang Anda sekarang: %d Yen. \n\n", *Money);
                    //Memasukkan Gadget yang telah dibeli ke dalam List Inventory
                    insertGadget(inventory, LISTGADGET_IDNAME(gadget,idx));
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!\n\n");
                }
            }
            else
            {
                printf("Inventory Gadget Anda sudah penuh!\n\n");
            }
        } else {
            printf("\n");
        }
    }
    
}

