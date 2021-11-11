#include <stdio.h>
#include <stdlib.h>
#include "PICK_UP.h"

void PICK_UP(Bangunan CurrentBangunan, Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, int *heavyitems, boolean *speedboost){
    ToDoType accPesanan;
    if (isPickAvailable(CurrentBangunan, *TasNobita, *Todo, *DaftarInprog)) {
        if (isFullTas(*TasNobita)) {
            printf("Tas penuh\n");
        }
        else {
        pickup_action(TasNobita, Todo, DaftarInprog, accPesanan, heavyitems, speedboost);
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

void pickup_action(Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, ToDoType accPesanan, int *heavyitems, boolean *speedboost)
// I.S pesanan ditemukan
// F.S pesanan telah berhasil diambil
{
    // transfer elemen tadi todo list ke inprogress list dan tas
    ElmtTransfer(accPesanan, Todo, TasNobita, DaftarInprog);
    


    // update state heavyItems apabila pickup heavy item serta remove ability speedup
    if (accPesanan.itemType == 'H') {
        *heavyitems+=1;
        *speedboost = false;
        printf("Heavy item berhasil diambil!\n");
        printf("Tujuan pesanan: %c", accPesanan.dropOff);
    }
    else if (accPesanan.itemType == 'N') {
        printf("Normal item berhasil diambil!\n");
        printf("Tujuan pesanan: %c", accPesanan.dropOff);

    }
    else if (accPesanan.itemType == 'P') {
        printf("Perishable item berhasil diambil!\n");
        printf("Tujuan pesanan: %c", accPesanan.dropOff);
        printf("Sisa waktu hangus: %d", accPesanan.perishTime);
    }
}

// type converter
ElTypeTas TodoType_to_EltypeTas(ToDoType Todo) {
    ElTypeTas elmtTas;
    elmtTas.pickUp = Todo.pickUp;
    elmtTas.dropOff = Todo.dropOff;
    elmtTas.itemType = Todo.itemType;
    elmtTas.perishTime = Todo.perishTime;
    return elmtTas;
}
InProgType TodoType_toInProgType(ToDoType Todo) {
    InProgType elmtInprog;
    elmtInprog.pickUp = Todo.pickUp;
    elmtInprog.dropOff = Todo.dropOff;
    elmtInprog.itemType = Todo.itemType;
    elmtInprog.perishTime = Todo.perishTime;
    return elmtInprog;
}

// proses pemindahan pesanan dari todo ke tas dan inprogress list
void ElmtTransfer(ToDoType accPesanan, ToDoList *Todo, Tas *Tasnobita, InProgList *DaftarInprog) {
    // I.S. sembarang
    // F.S. elemen dalam todo list dihapus dan dipindahkan ke dalma tas dan in progress list
    ElTypeTas elmtTas = TodoType_to_EltypeTas(accPesanan);
    InProgType elmtInprog = TodoType_toInProgType(accPesanan);

    // delete dari todo
    delete_ToDoList(Todo, accPesanan, &accPesanan);

    // push ke tas
    pushTas(Tasnobita, elmtTas);

    // insertfirst ke in progress list
    insertFirst_InProgList(DaftarInprog, elmtInprog);
}