#include <stdlib.h>
#include <stdio.h>
#include "DROP_OFF.h"

void DROP_OFF()
// prosedur untuk drop item pada drop point
{
    if (isDropAvailable()) {
        drop_action();
    }
    else {
        printf("Tidak dapat pesanan yang dapat diantarkan!\n");
    }
}

boolean isDropAvailable()
// mengecek apakah ada item yang bisa di-drop di posisi saat ini
{
// cek top dari stack tas

// apakah posisi pesanan top stack === posisi saat ini
if ((TOP(Tas).posisi.X == Position.X) && (TOP(Tas).posisi.Y == Position.Y)) {
    return true;
}
else false;
}

void drop_action()
// drop item apabila tersedia
{
    // pop pesanan dari stack tas
    int reward;
    pop(&Tas, &accPesanan);
    pop(&InProgressList, &accPesanan);
    // update state heavy item apabila selesai drop heavy item
    // update reward (uang) yang didapat
    // update state speed boost apabila selesai drop heavy item
    if (accPesanan.JenisItem == 'H') {
        printf("Pesanan Heavy Item berhasil diantarkan\n");
        heavyItems-=1;
        speedBoost = true;
        reward = 400;
    }
    else if (accPesanan.JenisItem == 'N') {
        printf("Pesanan Normal Item berhasil diantarkan\n");
        reward = 200;

    }
    else if (accPesanan.JenisItem == 'P') {
        printf("Pesanan Perishable Item berhasil diantarkan\n");
        reward = 400;
        increaseCapacity = 5; // SESUAIKAN DENGAN INCREASE CAPACITY
        
    }

    printf("Uang yang didapatkan: %d", reward);
}