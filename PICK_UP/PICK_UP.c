#include <stdio.h>
#include <stdlib.h>
#include "PICK_UP.h"

void PICK_UP(Bangunan CurrentBangunan, Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog){
    ToDoType accPesanan;
    if (isPickAvailable(CurrentBangunan, *TasNobita, *Todo, *DaftarInprog)) {
        if (isFullTas(*TasNobita)) {
            printf("Tas penuh\n");
        }
        else {
        pickup_action(TasNobita, Todo, DaftarInprog, accPesanan);
        }
    }
    else {
        printf("Pesanan tidak ditemukan!\n");
    }
}
// prosedur untuk mengambil item dari pickup point

boolean isPickAvailable(Bangunan CurrentBangunan, Tas TasNobita, ToDoList Todo, ToDoType *accPesanan)
// mengecek apakah ada pesanan pada bangunan tersebut
{
    boolean found = false;
    int i = 0;
    Address p = FIRST_TODO(Todo);
    while (!found && p!= NULL) {
        if (CurrentBangunan.nama = INFO_TODO(p).pickUp) {
            found = true;
        }
        else {
        p = NEXT_TODO(p);
        }
    }
    if (found) {
        *accPesanan = INFO_TODO(p);
    }
    return found;
}

void pickup_action(Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, ToDoType accPesanan)
// I.S pesanan ditemukan
// F.S pesanan telah berhasil diambil
{
    // push semua pesanan ke stack tas dan in progress list
    pushTas(TasNobita, accPesanan);


    
    // update state heavyItems apabila pickup heavy item serta remove ability speedup
    if (accPesanan.JenisItem == 'H') {
        heavyItems+=1;
        speedBoost = false;
        printf("Heavy item berhasil diambil!\n");
        printf("Tujuan pesanan: %c", PointToNamaBangunan(Position, DaftarBangunan));
    }
    else if (accPesanan.JenisItem == 'N') {
        printf("Normal item berhasil diambil!\n");
        printf("Tujuan pesanan: %c", PointToNamaBangunan(Position, DaftarBangunan));

    }
    else if (accPesanan.JenisItem == 'P') {
        printf("Perishable item berhasil diambil!\n");
        printf("Tujuan pesanan: %c", PointToNamaBangunan(Position, DaftarBangunan));
        // print sisa waktu hangus
    }
}