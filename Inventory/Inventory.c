#include <stdio.h>
#include "Inventory.h"


void inventory(ListInventory inventory, Tas *tasMobita, ListOfBangunan LB, Point *coordinate_mobita, int *Time)
{
    //menampilkan isi inventory
    displayInventory(inventory);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("\n");

    int op;
    scanf("ENTER COMMAND: %d\n", &op);
    //meminta input yang valid
    while (op < 0 || op > 5)
    {
        printf("Masukkan angka antara 0 - 5!\n");
        scanf("ENTER COMMAND: %d", &op); 
    }

    if (op != 0)
    {
        int idx = op-1;
        //tidak ada gadget pada opsi yang dipilih
        if(ELMTInventory(inventory,idx) == INVENTORY_GADGETUNDEF)
        {
            printf("Tidak ada Gadget yang dapat digunakan!");
        }
        else 
        {
            //gadget digunakan, hapus dari list inventory
            deleteGadget(inventory, ELMTInventory(inventory,idx));
            printf("%c berhasil digunakan!", ELMTInventory(inventory,idx));

            //efek dari gadget aktif
            if(ELMTInventory(inventory,idx) == 'Kain Pembungkus Waktu')
            {
                KainPembungkusWaktu(*tasMobita);
            }
            else if(ELMTInventory(inventory,idx) == 'Senter Pembesar')
            {
                SenterPembesar(tasMobita);
            }
            else if(ELMTInventory(inventory,idx) == 'Pintu Kemana Saja')
            {
                PintuKemanaSaja(LB, coordinate_mobita);
            }
            else if(ELMTInventory(inventory,idx) == 'Mesin Waktu')
            {
                MesinWaktu(*Time);
            }
        }
    }
}


//Waktu item perishable di TOP tas kembali ke semula
void KainPembungkusWaktu(Tas tasMobita)
{
    if(TOP_TAS(tasMobita).itemType == 'P')
    {
        //TOP_TAS(tasMobita).perishTime == waktu hangus di awal daftar pesanan;
    }
    else
    {
        printf('Item teratas bukan perishable item.');
    }
}

//kapasitas tas menjadi 2 kali lipat
void SenterPembesar(Tas *tasMobita)
{
    //sesuain sama file tas
    int newCapacity;
    newCapacity = TAS_CAPACITY(*tasMobita)*2;
    if (newCapacity <= 100)
    {
        upgradeTasCapacity(tasMobita, newCapacity);
    }
    else //Melebihi 100
    {
        printf('Kapasitas tas melebihi maksimum!');
    }
}

//Berpindah lokasi tanpa menambah unit waktu
void PintuKemanaSaja(ListOfBangunan LB, Point *coordinate_mobita)
{
    int num;
    for (num = 1; num <= lengthListStat(LB); num++)
    {
        printf("%d. ", num);
        //tampilin list semua bangunan yang ada
    }
    
    printf("Anda mau pindah ke titik mana?\n");
    int op;
    printf("ENTER COMMAND: ");
    scanf("%d", &op); 
    while (op < 0 || op > lengthListStat(LB))
    {
        printf("Masukkan angka antara 0-total_point!\n");
        printf("ENTER COMMAND: ");
        scanf("%d", &op); 
    }
    printf("\n");
    if (op != 0)
    {
        ListPoint l;
        int idx = op-1;
        //set koordinat mobita = yg dipilih
        *coordinate_mobita = ELMTListPoint(l, idx);
        printf("Anda telah menggunakan Pintu Kemana Saja! Sekarang Mobita berada di titik ");
        WritePoint(ELMTListPoint(l, idx));
        printf("!\n");
    }

}

//Mengurangi waktu sebanyak 50 unit
void MesinWaktu(Time)
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
