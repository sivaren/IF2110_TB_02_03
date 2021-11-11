#include "PICK_UP.h"
#include <stdlib.h>
#include <stdio.h>



void readTas(Tas *Tasnobita, InProgList *Inprog, int *heavyitems) {
    int capacity;
    int jumlahPesanan;
    boolean speedboost;
    ElTypeTas tempElmt;
    InProgType tempElmt2;
    char tempItemType;
    char tempPickUp;
    char tempDropOff;
    int tempPerishTime;
    printf("masukkan capacity Tas: ");
        scanf("%d", &capacity);
        // create tas
        CreateTas(Tasnobita, capacity);
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
        scanf("%d", &speedboost);
}

int main() {
    // inisialisasi
    ToDoList Todo;
    InProgList DaftarInprog;
    int heavyitems;
    boolean speedboost;
    Bangunan CurrentBangunan;
        // baca input current bangunan
        printf("Masukkan currentbangunan: ");
        scanf(" %c", &CurrentBangunan);
    Tas TasNobita;
        // baca input tas nobita
        readTas(&TasNobita, &DaftarInprog, &heavyitems);
    
    displaytas(TasNobita);
    displayInProg(DaftarInprog);
    printf("heavyitems: %d\n", heavyitems);
    printf("speedboost: %d\n", speedboost);
    printf("currentbangunanL %c", CurrentBangunan);




    return 0;
}