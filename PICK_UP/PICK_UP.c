#include <stdio.h>
#include <stdlib.h>
#include "PICK_UP.h"

void PICK_UP(Point CurrentBangunan, Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, int *heavyitems, int *speedboost){
    ToDoType accPesanan;
    if (isPickAvailable(CurrentBangunan, *TasNobita, *Todo, &accPesanan)) {
    while (isPickAvailable(CurrentBangunan, *TasNobita, *Todo, &accPesanan)) {
        if (isFullTas(*TasNobita)) {
            printf("Tas penuh\n");
        }
        else {
        pickup_action(TasNobita, Todo, DaftarInprog, accPesanan, heavyitems, speedboost);
        }
    }
    }
    else {
        printf("Pesanan tidak ditemukan!\n");
    }
}
// prosedur untuk mengambil item dari pickup point

boolean isPickAvailable(Point CurrentBangunan, Tas TasNobita, ToDoList Todo, ToDoType *accPesanan)
// mengecek apakah ada pesanan pada bangunan tersebut
{
    boolean found = false;
    int i = 0;
    AddressTodo p = FIRST_TODO(Todo);
    while (!found && p!= NULL) {
        if (CurrentBangunan.name == INFO_TODO(p).pickUp) {
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

void pickup_action(Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, ToDoType accPesanan, int *heavyitems, int *speedboost)
// I.S pesanan ditemukan
// F.S pesanan telah berhasil diambil
{
    // transfer elemen tadi todo list ke inprogress list dan tas
    ElmtTransfer_PICK_UP(accPesanan, Todo, TasNobita, DaftarInprog);
    


    // update state heavyItems apabila pickup heavy item serta remove ability speedup
    if (accPesanan.itemType == 'H') {
        *heavyitems+=1;
        *speedboost = 0;
        printf("Heavy item berhasil diambil!\n");
        printf("Tujuan pesanan: %c\n", accPesanan.dropOff);
    }
    else if (accPesanan.itemType == 'N') {
        printf("Normal item berhasil diambil!\n");
        printf("Tujuan pesanan: %c\n", accPesanan.dropOff);

    }
    else if (accPesanan.itemType == 'P') {
        printf("Perishable item berhasil diambil!\n");
        printf("Tujuan pesanan: %c\n", accPesanan.dropOff);
        printf("Sisa waktu hangus: %d\n", accPesanan.perishTime);
    }
}

// type converter
ElTypeTas TodoType_to_ElTypeTas(ToDoType Todo) {
    ElTypeTas elmtTas;
    elmtTas.pickUp = Todo.pickUp;
    elmtTas.dropOff = Todo.dropOff;
    elmtTas.itemType = Todo.itemType;
    elmtTas.perishTime = Todo.perishTime;
    return elmtTas;
}
InProgType TodoType_to_InProgType(ToDoType Todo) {
    InProgType elmtInprog;
    elmtInprog.pickUp = Todo.pickUp;
    elmtInprog.dropOff = Todo.dropOff;
    elmtInprog.itemType = Todo.itemType;
    elmtInprog.perishTime = Todo.perishTime;
    return elmtInprog;
}
InProgType ElTypeTas_to_InProgType(ElTypeTas elmtTas) {
    InProgType elmtInprog;
    elmtInprog.pickUp = elmtTas.pickUp;
    elmtInprog.dropOff = elmtTas.dropOff;
    elmtInprog.itemType = elmtTas.itemType;
    elmtInprog.perishTime = elmtTas.perishTime;
    return elmtInprog;
}
ElTypeTas InProgType_to_ElTypeTas(InProgType elmtInProg) {
    ElTypeTas elmtTas;
    elmtTas.pickUp = elmtInProg.pickUp;
    elmtTas.dropOff = elmtInProg.dropOff;
    elmtTas.itemType = elmtInProg.itemType;
    elmtTas.perishTime = elmtInProg.perishTime;
    return elmtTas;
}

// proses pemindahan pesanan dari todo ke tas dan inprogress list
void ElmtTransfer_PICK_UP(ToDoType accPesanan, ToDoList *Todo, Tas *Tasnobita, InProgList *DaftarInprog) {
    // I.S. sembarang
    // F.S. elemen dalam todo list dihapus dan dipindahkan ke dalma tas dan in progress list
    ElTypeTas elmtTas = TodoType_to_ElTypeTas(accPesanan);
    InProgType elmtInprog = TodoType_to_InProgType(accPesanan);
    ToDoType delval;
    // delete dari todo
    delete_ToDoList(Todo, accPesanan, &delval);

    // push ke tas
    pushTas(Tasnobita, elmtTas);

    // insertfirst ke in progress list
    insertFirst_InProgList(DaftarInprog, elmtInprog);
}