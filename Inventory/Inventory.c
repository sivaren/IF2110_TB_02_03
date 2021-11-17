#include <stdio.h>
#include "Inventory.h"

void inventory(ListInventory *inventory, Tas *tasMobita, InProgList *DaftarInprog, ListPoint LP, PrioQueuePesanan Q, Point *coordinate_mobita, int *Time)
{
    //Menampilkan isi List Inventory
    displayInventory(*inventory);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");

    int op;
    printf("ENTER COMMAND: ");
    scanf("%d", &op);
    //Meminta input yang valid
    while (op < 0 || op > 5)
    {
        printf("Masukkan angka antara 0 - 5!\n\n");
        printf("ENTER COMMAND: ");
        scanf("%d", &op); 
    }

    if (op != 0)
    {
        int idx = op-1;
        //Tidak ada gadget pada opsi yang dipilih (isi list = "-")
        if(ELMTInventory(*inventory,idx) == INVENTORY_IDXUNDEF)
        {
            printf("Tidak ada Gadget yang dapat digunakan!\n\n");
        }
        else 
        {
            //Gadget digunakan, hapus dari list inventory
            //Efek dari gadget aktif
            if(ELMTInventory(*inventory,idx) == 1)
            {
                KainPembungkusWaktu(tasMobita, DaftarInprog, Q);
            }
            else if(ELMTInventory(*inventory,idx) == 2)
            {
                printf("Senter Pembesar berhasil digunakan!\n\n");
                SenterPembesar(tasMobita);
            }
            else if(ELMTInventory(*inventory,idx) == 3)
            {
                printf("Pintu Kemana Saja berhasil digunakan!\n\n");
                PintuKemanaSaja(LP, coordinate_mobita);
            }
            else if(ELMTInventory(*inventory,idx) == 4)
            {
                printf("Mesin Waktu berhasil digunakan!\n\n");
                MesinWaktu(&(*Time));
            }
            deleteGadget(inventory, idx, ELMTInventory(*inventory,idx));
        }
    } else {
        printf("\n");
    }
}


//Waktu item perishable di TOP tas kembali ke semula
void KainPembungkusWaktu(Tas *tasMobita, InProgList *DaftarInprog, PrioQueuePesanan Q)
{   
    // jika terdapat perishable item pada tas
    if(isPerishAvail_inProg(*DaftarInprog)){
        printf("Kain Pembungkus Waktu berhasil digunakan!\n\n");
        int waktuSemula;
        ElTypeTas targetPerish;

        activated_kainWaktu_inTas(&(*tasMobita), Q, &targetPerish, &waktuSemula);
        activated_kainWaktu_inProg(&(*DaftarInprog), waktuSemula);
    } 
    // jika tidak ada perishable item pada tas
    else {
        printf("Tidak terdapat perishable item pada tas!\n\n");
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
        printf("Kapasitas tas melebihi maksimum!\n\n");
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
        WritePoint(ELMTListPoint(LP,idx));
        printf("\n");
    }
    
    printf("Anda mau pindah ke titik mana?\n");
    int op;
    printf("ENTER COMMAND: ");
    scanf("%d", &op); 
    while (op < 0 || op > lengthListPoint(LP))
    {
        printf("Masukkan angka antara 0 - %d!\n", lengthListPoint(LP));
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
void MesinWaktu(int *Time)
{
    int currTime;
    currTime = *Time - 50;
    if (currTime < 0)
    {
        *Time = 0;
    }
    else
    {
        *Time = currTime;
    }
}
