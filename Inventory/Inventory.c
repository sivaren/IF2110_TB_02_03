#include <stdio.h>
#include "Inventory.h"


void inventory(ListInventory *inventory, Tas *tasMobita, ListPoint LP, PrioQueuePesanan Q, Point *coordinate_mobita, int *Time)
{
    //Menampilkan isi List Inventory
    displayInventory(*inventory);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("\n");

    int op;
    scanf("ENTER COMMAND: %d\n", &op);
    //Meminta input yang valid
    while (op < 0 || op > 5)
    {
        printf("Masukkan angka antara 0 - 5!\n");
        scanf("ENTER COMMAND: %d", &op); 
    }

    if (op != 0)
    {
        int idx = op-1;
        //Tidak ada gadget pada opsi yang dipilih (isi list = "-")
        if(ELMTInventory(*inventory,idx) == INVENTORY_IDXUNDEF)
        {
            printf("Tidak ada Gadget yang dapat digunakan!");
        }
        else 
        {
            //Gadget digunakan, hapus dari list inventory
            deleteGadget(inventory, idx, ELMTInventory(*inventory,idx));

            //Efek dari gadget aktif
            if(ELMTInventory(*inventory,idx) == 1)
            {
                printf("Kain Pembungkus Waktu berhasil digunakan!\n");
                KainPembungkusWaktu(*tasMobita, Q);
            }
            else if(ELMTInventory(*inventory,idx) == 2)
            {
                printf("Senter Pembesar berhasil digunakan!\n");
                SenterPembesar(tasMobita);
            }
            else if(ELMTInventory(*inventory,idx) == 3)
            {
                printf("Pintu Kemana Saja berhasil digunakan!\n");
                PintuKemanaSaja(LP, coordinate_mobita);
            }
            else if(ELMTInventory(*inventory,idx) == 4)
            {
                printf("Mesin Waktu berhasil digunakan!\n");
                MesinWaktu(*Time);
            }
        }
    }
}


//Waktu item perishable di TOP tas kembali ke semula
void KainPembungkusWaktu(Tas tasMobita, PrioQueuePesanan Q)
{
    if(TOP_TAS(tasMobita).itemType == 'P')
    {
        int i;
        char pickUpTOP, dropOffTOP, itemTypeTOP;
        pickUpTOP = TOP_TAS(tasMobita).pickUp;
        dropOffTOP = TOP_TAS(tasMobita).dropOff;

        for(i = IDX_HEAD_PRIOQUEUE(Q); i <= IDX_TAIL_PRIOQUEUE(Q); i++)
        {
            if(Q.buffer[i].pickUp == pickUpTOP)
            {
                if(Q.buffer[i].dropOff == dropOffTOP)
                {
                    if(Q.buffer[i].jenisItem == 'P')
                    {
                        TOP_TAS(tasMobita).perishTime = Q.buffer[i].waktuHangus;
                    }
                }
            }
        }
    }
    else
    {
        printf("Item teratas bukan perishable item.");
    }
}

//Kapasitas tas menjadi 2 kali lipat
void SenterPembesar(Tas *tasMobita)
{
    int newCapacity;
    newCapacity = TAS_CAPACITY(*tasMobita)*2;
    if (newCapacity <= 100)
    {
        upgradeTasCapacity(tasMobita, newCapacity);
    }
    else //Melebihi 100
    {
        printf("Kapasitas tas melebihi maksimum!");
    }
}

//Berpindah lokasi tanpa menambah unit waktu
void PintuKemanaSaja(ListPoint LP, Point *coordinate_mobita)
{
    int num, idx;
    //Menampilkan semua bangunan yang ada
    for (num = 1; num <= lengthListPoint(LP); num++)
    {
        printf("%d. ", num);
        idx = num-1;
        printOneBangunan(ELMTListPoint(LP,idx));
        print("\n");
    }
    
    printf("Anda mau pindah ke titik mana?\n");
    int op;
    printf("ENTER COMMAND: ");
    scanf("%d", &op); 
    while (op < 0 || op > lengthListPoint(LP))
    {
        printf("Masukkan angka antara 0-total_point!\n");
        printf("ENTER COMMAND: ");
        scanf("%d\n", &op); 
    }

    if (op != 0)
    {
        idx = op-1;
        //Mobita berpindah ke titik yang dipilih
        *coordinate_mobita = ELMTListPoint(LP, idx);
        printf("Anda telah menggunakan Pintu Kemana Saja! Sekarang Mobita berada di titik ");
        WritePoint(ELMTListPoint(LP, idx));
        printf("!\n");
    }

}

//Mengurangi waktu sebanyak 50 unit
void MesinWaktu(int Time)
{
    int currTime;
    currTime = Time - 50;
    if (currTime < 0)
    {
        Time = 0;
    }
    else
    {
        Time = currTime;
    }
}
