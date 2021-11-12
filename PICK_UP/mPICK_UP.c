#include "PICK_UP.h"
#include "../DROP_OFF/DROP_OFF.h"
#include "../toDo/toDo.h"
#include <stdlib.h>
#include <stdio.h>



void readTas(Tas *Tasnobita, InProgList *Inprog, int *heavyitems, boolean *speedboost) {
    int capacity;
    int jumlahPesanan;
    ElTypeTas tempElmt;
    InProgType tempElmt2;
    char tempItemType;
    char tempPickUp;
    char tempDropOff;
    int tempPerishTime;
    printf("\n=============\n");
    printf("INPUT TAS/INPROG\n");
    printf("masukkan capacity Tas: ");
        scanf("%d", &capacity);
        // create tas dan inprog
        CreateTas(Tasnobita, capacity);
        CreateInProgList(Inprog);
    printf("masukkan jumlah pesanan saat ini: ");
        scanf("%d", &jumlahPesanan);
        // iterasi masukkan elem ke tas
        for (int i=jumlahPesanan; i>0; i--) {
            printf("Tas elemen ke-%d\n", i);
            printf("Masukkan item type: ");
            scanf(" %c", &tempItemType);
            if (tempItemType == 'H') {
                *heavyitems += 1;
            }
            printf("Masukkan pick up: ");
            scanf(" %c", &tempPickUp);
            printf("Masukkan drop off: ");
            scanf(" %c", &tempDropOff);
            printf("Masukkan tempPerishTme: ");
            scanf("%d", &tempPerishTime);
            tempElmt.itemType = tempItemType;
            tempElmt.pickUp = tempPickUp;
            tempElmt.dropOff = tempDropOff;
            tempElmt.perishTime = tempPerishTime;
            tempElmt2.itemType = tempItemType;
            tempElmt2.pickUp = tempPickUp;
            tempElmt2.dropOff = tempDropOff;
            tempElmt2.perishTime = tempPerishTime;
            pushTas(Tasnobita, tempElmt);
            insertFirst_InProgList(Inprog, tempElmt2);
        }
    printf("speedboost (0 = false, 1 = true): ");
        int sb;
        scanf("%d", &sb);
        if (sb == 0) {
            *speedboost = false;
        }
        else if (sb == 1) {
            *speedboost = true;
        }
}
void readTodo(ToDoList *Todo) {
    int jumlahPesanan;
    ToDoType tempElmt;
    int tempTimeIn;
    char tempItemType;
    char tempPickUp;
    char tempDropOff;
    int tempPerishTime;
    printf("\n=============\n");
    printf("INPUT TODO\n");
    printf("Masukkan jumlah pesanan: ");
    scanf("%d", &jumlahPesanan);

    // iterasi masukkan elem ke tas
        for (int i=0; i<jumlahPesanan; i++) {
            printf("Todo list elemen ke-%d\n", i+1);
            printf("Masukkan time in: ");
            scanf(" %d", &tempTimeIn);
            printf("Masukkan item type: ");
            scanf(" %c", &tempItemType);
            printf("Masukkan pick up: ");
            scanf(" %c", &tempPickUp);
            printf("Masukkan drop off: ");
            scanf(" %c", &tempDropOff);
            printf("Masukkan tempPerishTme: ");
            scanf("%d", &tempPerishTime);
            tempElmt.timeIn = tempTimeIn;
            tempElmt.itemType = tempItemType;
            tempElmt.pickUp = tempPickUp;
            tempElmt.dropOff = tempDropOff;
            tempElmt.perishTime = tempPerishTime;
            insert_ToDoList(Todo, tempElmt);
            
            }
}

void displayAll(Tas TasNobita, InProgList DaftarInprog, ToDoList Todo, int heavyitems, boolean speedboost, int currentCapacity, Bangunan CurrentBangunan, int Money) {
    printf("\n=============\n");
    displaytas(TasNobita);
    printf("=============\n");
    displayInProg(DaftarInprog);
    printf("=============\n");
    displayToDoList(Todo);
    printf("=============\n");
    printf("money: %d\n", Money);
    printf("heavyitems: %d\n", heavyitems);
    printf("speedboost: ");
    if (speedboost) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    printf("current capacity: %d\n", currentCapacity);
    printf("currentbangunan: %c\n", CurrentBangunan.nama);
    printf("=============\n");
}

int main() {
    // inisialisasi
    int currentCapacity = 3;
    int Money = 3000;
    char opt;
    InProgList DaftarInprog;
    int heavyitems = 0;
    boolean speedboost = false;
    Bangunan CurrentBangunan;
        // baca input current bangunan
        printf("Masukkan currentbangunan: ");
        scanf(" %c", &CurrentBangunan.nama);
    Tas TasNobita;
        // baca input tas nobita
        readTas(&TasNobita, &DaftarInprog, &heavyitems, &speedboost);
    ToDoList Todo;
        // baca input todo list
        readTodo(&Todo);
        displayAll(TasNobita, DaftarInprog, Todo, heavyitems, speedboost, currentCapacity, CurrentBangunan, Money);
   
    do {
        printf("\n=============\n");
        printf("Masukkan command: (m(move), p(pickup), d(dropoff), q(quit), t(change todo), i(change inprog/tas), D(display all state), c(change tas capacity): ");
        scanf(" %c", &opt);
        printf("\n=============\n");
        if (opt == 'm') {
            //pindah bangunan
            printf("Masukkan currentbangunan: ");
            scanf(" %c", &CurrentBangunan.nama);
        }
        else if (opt == 'p') {
            //pickup
            PICK_UP(CurrentBangunan, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost);
        }
        else if (opt == 'd') {
            //dropoff
            DROP_OFF(CurrentBangunan, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost, &currentCapacity, &Money);
            
        }
        else if (opt == 't') {
            //change todo
            readTodo(&Todo);
        }
        else if (opt == 'i') {
            //change inprog and tas
            readTas(&TasNobita, &DaftarInprog, &heavyitems, &speedboost);
        }
        else if (opt == 'D') {
            //print all state
            displayAll(TasNobita, DaftarInprog, Todo, heavyitems, speedboost, currentCapacity, CurrentBangunan, Money);

        }
        else if (opt == 'c') {
            // ganti kapasitas tas
            printf("Masukkan kapasitas baru tas: ");
            scanf(" %d", &currentCapacity);
            upgradeTasCapacity(&TasNobita, currentCapacity);
        }

    }
    while (opt != 'q');




    return 0;
}
