#include <stdio.h>
#include <stdlib.h>
#include "PICK_UP.h"

void PICK_UP(){
    if (isPickAvailable()) {
        pickup_action();
    }
    else {
        printf("Pesanan tidak ditemukan!\n");
    }
}
// prosedur untuk mengambil item dari pickup point

boolean isPickAvailable()
// mengecek apakah ada pesanan pada bangunan tersebut
{
    boolean found = false;
    int i = 0;
    while (!found && i<length_ListLinked(TodoList)) {
        accPesanan = getElmt_ListLinked(TodoList, i);
        if ((accPesanan.PickupPoint.X == Position.X) && (accPesanan.PickupPoint.Y == Position.Y) ) {
            
            found = true;
        }
        else {
            i++;
        }
    }
    return found;
}

void pickup_action()
// I.S pesanan ditemukan
// F.S pesanan telah berhasil diambil
{
    // push semua pesanan ke stack tas dan in progress list
    push(&Tas, getElmt_ListLinked(TodoList, accPesanan));
    push(&InProgressList, getElmt_ListLinked(TodoList, accPesanan));
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