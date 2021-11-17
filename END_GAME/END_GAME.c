#include "END_GAME.h"

void END_GAME(int Time, int PesananDiantar, Point pointHQ, Point currentPos, PrioQueuePesanan DaftarPesanan,ToDoList Todo, InProgList DaftarInprog, Tas TasNobita, boolean *run) {
    // check all list
    if (isEmptyPRIOQUEUE(DaftarPesanan) && isEmpty_ToDo(Todo) && isEmptyTas(TasNobita) && isEmpty_InProg(DaftarInprog) && (currentPos.name == pointHQ.name)) {
        // tampilkan pesan
        printf("Permainan selesai\n");
        printf("Semua pesanan telah diantarkan\n");

        // tampilkan score
        printf("Jumlah pesanan diantar   : %d\n", PesananDiantar);
        printf("Waktu                    : %d\n", Time);

        // ubah state run
        *run = false;
    }
}