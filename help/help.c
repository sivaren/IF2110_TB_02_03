/* Implementasi file help.h */

#include "help.h"

/* Display Help */
void displayHelp(){
    printf("1. MOVE         -> Untuk berpindah ke lokasi selanjutnya\n");
    printf("2. PICK_UP      -> Untuk mengambil item di lokasi terkini\n");
    printf("3. DROP_OFF     -> Untuk mengantarkan item ke lokasi terkini\n");
    printf("4. MAP          -> Untuk menampilkan peta permainan\n");
    printf("5. TO_DO        -> Untuk menampilkan pesanan yang masuk ke To Do List\n");
    printf("6. IN_PROGRESS  -> Untuk menampilkan pesanan yang sedang dikerjakan\n");
    // BUY hanya dapat dipanggil di Headquarters
    printf("7. BUY          -> Untuk menampilkan gadget yang dapat dibeli lalu membelinya\n");
    printf("8. INVENTORY    -> Untuk melihat gadget yang dimiliki dan menggunakannya\n");
    printf("9. HELP         -> Untuk mengeluarkan list command dan kegunaannya\n");
}
/*  Menampilkan seluruh command pada permainan
    beserta deskripsi dari command tersebut. */