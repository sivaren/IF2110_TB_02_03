#include <stdio.h>
#include "ListInventory.h"

#include "../Move/matrixpoint.h"
#include "../Move/matrix.h"
#include "../Move/point.h"
#include "../ADT/ADT Stack/stack.h"

//dari awal udah createlist inventory
//ListStatPos inventory
//CreateListStatPos(&inventory)
int Time;

void inventory(ListInventory inventory)
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
        if(ELMTInventory(inventory,idx) == VAL_UNDEF)
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
                KainPembungkusWaktu();
            }
            else if(ELMTInventory(inventory,idx) == 'Senter Pembesar')
            {
                SenterPembesar();
            }
            else if(ELMTInventory(inventory,idx) == 'Pintu Kemana Saja')
            {
                PintuKemanaSaja();
            }
            else if(ELMTInventory(inventory,idx) == 'Mesin Waktu')
            {
                MesinWaktu();
            }
        }
    }
}

void KainPembungkusWaktu()
{
    if(TOP(Tas).JenisItem == 'P')
    {
        //Baca konfigurasi awal
    }
    else
    {
        printf('Item teratas bukan perishable item.');
    }
}

//Meningkatkan kapasitas tas 2 kali lipat
void SenterPembesar()
{
    //sesuain sama file tas
    int newCapacity, CAPACITY_TAS;
    newCapacity = CAPACITY_TAS*2;
    if (newCapacity <= 100)
    {
        CAPACITY_TAS = newCapacity;
    }
    else //Melebihi 100
    {
        printf('Kapasitas tas melebihi maksimum!');
    }
}

//Berpindah lokasi tanpa menambah unit waktu
void PintuKemanaSaja(MatrixPoint *map, Matrix adjacency_matrix, Point *coordinate_mobita)
{
    //panggil fungsi move
    //move(MatrixPoint *map, Matrix adjacency_matrix, Point *coordinate_mobita);
}

//Mengurangi waktu sebanyak 50 unit
void MesinWaktu()
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
