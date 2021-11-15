#include <stdlib.h>
#include <stdio.h>
#include "DROP_OFF.h"

void DROP_OFF(Point CurrentBangunan, Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, int *heavyitems, int *speedboost, int *currentTasCapacity, int *Money)
// prosedur untuk drop item pada drop point
{
    if (isDropAvailable(CurrentBangunan, *TasNobita, *Todo)) {
        drop_action(TasNobita, DaftarInprog, heavyitems, speedboost, currentTasCapacity, Money);
    }
    else {
        printf("Tidak dapat pesanan yang dapat diantarkan!\n");
    }
}

boolean isDropAvailable(Point CurrentBangunan, Tas TasNobita, ToDoList Todo)
// mengecek apakah ada item yang bisa di-drop di posisi saat ini
{
// cek top dari stack tas

// apakah posisi pesanan top stack === posisi saat ini
if (TOP_TAS(TasNobita).dropOff == CurrentBangunan.name) {
    return true;
}
else {return false;}
}

void drop_action(Tas *TasNobita, InProgList *DaftarInprog, int *heavyitems, int *speedboost, int *currentTasCapacity, int *Money)
// drop item apabila tersedia
{
    int reward;
    ElTypeTas accPesanan = TOP_TAS(*TasNobita);
    // pop pesanan dari tas dan inprog list
    ElmtDelete_DROP_OFF(TasNobita, DaftarInprog);
    // update state heavy item apabila selesai drop heavy item
    // update reward (uang) yang didapat
    // update state speed boost apabila selesai drop heavy item
    if (accPesanan.itemType == 'H') {
        printf("Pesanan Heavy Item berhasil diantarkan\n");
        *heavyitems -= 1;
        if (*heavyitems == 0) {
        *speedboost = 10;
        }
        reward = 400;
    }
    else if (accPesanan.itemType == 'N') {
        printf("Pesanan Normal Item berhasil diantarkan\n");
        reward = 200;

    }
    else if (accPesanan.itemType == 'P') {
        printf("Pesanan Perishable Item berhasil diantarkan\n");
        reward = 400;
        *currentTasCapacity += 1;
        upgradeTasCapacity(TasNobita, *currentTasCapacity);
        
    }

    printf("Uang yang didapatkan: %d", reward);
    // update state uang
    *Money += reward;
}

void ElmtDelete_DROP_OFF(Tas *Tasnobita, InProgList *DaftarInprog)
// menghapus elemen dari tas dan in progress list
{
    ElTypeTas delVal;
    InProgType delVal2;
    popTas(Tasnobita, &delVal);
    deleteFirst_InProgList(DaftarInprog, &delVal2);
}