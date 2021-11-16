#include <stdlib.h>
#include <stdio.h>

#include "Buy/buy.h"
#include "Buy/ListGadget.h"
#include "DROP_OFF/DROP_OFF.h"
#include "Inventory/Inventory.h"
#include "Inventory/ListInventory.h"
#include "Map/map.h"
#include "Move/move.h"
#include "mesinKarKat/wordmachine.h"
#include "PICK_UP/PICK_UP.h"
#include "toDo/toDo.h"


void readTas(Tas *Tasnobita, InProgList *Inprog, int *heavyitems, int *speedboost) {
    int capacity;
    int jumlahPesanan;
    ElTypeTas tempElmt;
    InProgType tempElmt2;
    char tempItemType;
    char tempPickUp;
    char tempDropOff;
    int tempPerishTime;
    printf("\n=============\n");
    printf("INPUT TAS/INPROG  COPY DARI input todo.txt biar cepet\n");
    printf("masukkan capacity Tas: ");
        scanf("%d", &capacity);
        // create tas dan inprog
        CreateTas(Tasnobita, capacity);
        CreateInProgList(Inprog);
    printf("masukkan jumlah pesanan saat ini: ");
        scanf("%d", &jumlahPesanan);
        // iterasi masukkan elem ke tas
        int i;
        for ( i=jumlahPesanan; i>0; i--) {
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
    printf("speedboost (0 = no sb): ");
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
    CreateToDoList(Todo);
    printf("\n=============\n");
    printf("INPUT TODO\n");
    printf("Masukkan jumlah pesanan: ");
    scanf("%d", &jumlahPesanan);
    int i;
    // iterasi masukkan elem ke tas
        for ( i=0; i<jumlahPesanan; i++) {
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
            printf("here\n");
            insert_ToDoList(Todo, tempElmt);
            printf("here2\n");
            
            }
}

void displayAll(Tas TasNobita, InProgList DaftarInprog, ToDoList Todo, int heavyitems, int speedboost, int currentCapacity, Point currentPos, int Money, int Time) {
    printf("\n=============\n");
    displaytas(TasNobita);
    printf("\n=============\n");
    displayInProg(DaftarInprog);
    printf("\n=============\n");
    displayToDoList(Todo);
    printf("\n=============\n");
    printf("Time = : %d\n", Time);
    printf("Speedboost = : %d\n", speedboost);
    printf("current capacity: %d\n", TAS_CAPACITY(TasNobita));
    printf("currentPos: %c\n", currentPos.name);
    printf("heavyitems: %d\n", heavyitems);
    printf("\n=============\n");
}

int main() {
    // inisialisasi
    int Money = 30000;
    char opt;
    InProgList DaftarInprog;
    int heavyitems = 0;
    int speedboost = 0;
    Tas TasNobita;
        // baca input tas nobita
        // readTas(&TasNobita, &DaftarInprog, &heavyitems, &speedboost);
    ToDoList Todo;
        // baca input todo list
        // readTodo(&Todo);
    char namaFile[50];
    Point pointHQ;
    ListPoint DaftarBangunan;
    PrioQueuePesanan DaftarPesanan;
    Matrix Adjacency;
    int Time = 0;
    Point currentPos;
    int rows = 10; // DUMMY
    int cols = 15; //DUMMY

    // create list gadget
    ListGadget Gadget;
    createListGadget(&Gadget);
    ELMTListGadget(Gadget,0) = setGadget(1, 800);
    ELMTListGadget(Gadget,1) = setGadget(2, 1200);
    ELMTListGadget(Gadget,2) = setGadget(3, 1500);
    ELMTListGadget(Gadget,3) = setGadget(4, 3000);
    // displayGadget(Gadget);
    // printf("\nb4here\n");
    ListInventory Inventory;
    CreateListInventory(&Inventory);
    printf("LENGTH = %d", lengthListInventory(Inventory));
    PrioQueuePesanan staticPesananPerish;

    pointHQ = CreatePoint('X', 1, 1);
    printf("AbsisHQ sebelum read: %d\n", pointHQ.X);
    CreateListPoint(&DaftarBangunan, 17); // GANTI JUMLAH BANGUNAN YG ADA
    CreateMatrix(lengthListPoint(DaftarBangunan), lengthListPoint(DaftarBangunan), &Adjacency);
    CreatePRIOQUEUE(&DaftarPesanan);
    CreatePRIOQUEUE(&staticPesananPerish);
    // readfile kalo udh ada
    CreateMatrix(18, 18, &Adjacency);
    printf("nama FILE : " );
    startWord();
    // printWord(currentWord);
    int ii,jj,count;
    count= currentWord.length+4;
    char format[] =".txt";
    jj= 0;
    
    for (ii=0; ii<=count; ii++){
        // printf("yang keprint %c\n", currentWord.contents[ii]);
        if (ii < currentWord.length){
            
            namaFile[ii] = currentWord.contents[ii];
            
        } else if (ii<count){
            namaFile[ii] = format[jj];
            jj++;
        }else{
            namaFile[ii] = '\0';
        }
    }


    readFile(namaFile, &rows, &cols, &pointHQ, &DaftarBangunan, &DaftarPesanan, &staticPesananPerish, &Adjacency);
    closeFile();
    displayMatrix(Adjacency);
    currentPos = pointHQ;
    
    CreateTas(&TasNobita, 3);
    CreateToDoList(&Todo);
    CreateInProgList(&DaftarInprog);
    

    displayAll(TasNobita, DaftarInprog, Todo, heavyitems, speedboost, TAS_CAPACITY(TasNobita), currentPos, Money, Time);
    displayPRIOQUEUE(DaftarPesanan);
    printf("NAME HQ= %c\n", Name(pointHQ));
    printf("config loaded\n");
   
    do {
        printf("\n=============\n");
        printf("Masukkan command: (M(map), m(move), p(pickup), d(dropoff), q(quit), t(change todo), i(change inprog/tas), D(display all state), c(change tas capacity), b(buy), I(inventory): ");
        startWord();
        printf("\n=============\n");
        if (isKataSama(currentWord, "MOVE"))  {
            //pindah bangunan
            move(DaftarBangunan, Adjacency, &currentPos, pointHQ);
            int addition = 0;
            addition += 1; //regular addition
            addition += heavyitems; // heavy items addition
            if (speedboost != 0) {
                if((speedboost%2) == 0){
                    addition -= 1;
                    printf("Bonus 1 Unit waktu, Waktu tidak kurang\n"); }
                speedboost -= 1;
            }
            // adjust perish
            int x;
            InProgType delValProgType;
            for (x = 0; x<addition; x++) {
                adjustPerishTime_inProg(&DaftarInprog, &TasNobita);
                deletePerishItem_inProg(&DaftarInprog, &TasNobita, &delValProgType);
            }

            // time adjust
            Time += addition;

            /* NOTE: move #1
            
            Time += 1; // regular
            Time += heavyitems; // heavy items

            //speedboost

            if (speedboost != 0) {
                printf("BONUS WAKTU\n");
                if ((speedboost%2) == 0) {
                    Time -= 1;
                }
                speedboost -= 1;
            } 
            */
           
           /* Butuh inisialisasi delValProgType, buat tempat buangan delete value */
           /* MOVE 2
            InProgType delValProgType;
            if(speedboost == 0 && !isHeavyAvail_inProg(DaftarInprog)){
                Time++;
                adjustPerishTime_inProg(&DaftarInprog, &TasNobita);
                deletePerishItem_inProg(&DaftarInprog, &TasNobita, &delValProgType);
            } else if (speedboost != 0 && !isHeavyAvail_inProg(DaftarInprog)){
                speedboost--;
                if((speedboost%2) == 1){
                    printf("Bonus 1 Unit waktu, Waktu tidak kurang\n");
                } 
                else{
                    Time++;
                    adjustPerishTime_inProg(&DaftarInprog, &TasNobita);
                    deletePerishItem_inProg(&DaftarInprog, &TasNobita, &delValProgType);
                }        
            } else if (isHeavyAvail_inProg(DaftarInprog)){
                speedboost = 0;
                Time += heavyitems;
                for(int timePlus = 0; timePlus < heavyitems; timePlus++){
                    adjustPerishTime_inProg(&DaftarInprog, &TasNobita);
                    deletePerishItem_inProg(&DaftarInprog, &TasNobita, &delValProgType);
                }
            }
            */

            // daftar pesanan to todo
            while (!isEmptyPRIOQUEUE(DaftarPesanan) && Time >= HEAD_PRIOQUEUE(DaftarPesanan).waktuMasuk) {
                Pesanan tempPesanan;
                ToDoType tempTodo;
                dequeuePRIOQUEUE(&DaftarPesanan, &tempPesanan);
                tempTodo.timeIn = tempPesanan.waktuMasuk;
                tempTodo.pickUp = tempPesanan.pickUp;
                tempTodo.dropOff = tempPesanan.dropOff;
                tempTodo.perishTime = tempPesanan.waktuHangus;
                tempTodo.itemType = tempPesanan.jenisItem;
                insert_ToDoList(&Todo, tempTodo);

            }

            printf("Time = : %d\n", Time);
            printf("CurrBangunan = : %c\n", currentPos.name);
            printf("Speedboost = : %d\n", speedboost);
            


	


            //
            }
        else if (isKataSama(currentWord, "MAP"))  {
            // map
            map(DaftarBangunan, Adjacency, currentPos, pointHQ, TOP_TAS(TasNobita).dropOff, Todo, rows, cols);
        }
        else if  (isKataSama(currentWord, "PICK_UP")) {
            //pickup
            PICK_UP(currentPos, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost);
        }
        else if (isKataSama(currentWord, "DROP_OFF")) {
            //dropoff
            DROP_OFF(currentPos, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost, &Money);
            
        }
        else if (isKataSama(currentWord, "TO_DO")) {
            //change todo
            readTodo(&Todo);
        }
        else if (isKataSama(currentWord, "IN_PROGRESS"))  {
            //change inprog and tas
            readTas(&TasNobita, &DaftarInprog, &heavyitems, &speedboost);
        }
        else if (isKataSama(currentWord, "DISPLAY")) {
            //print all state
            displayAll(TasNobita, DaftarInprog, Todo, heavyitems, speedboost, TAS_CAPACITY(TasNobita), currentPos, Money, Time);

        }
        else if (opt == 'c') {
            // ganti kapasitas tas
            printf("Masukkan kapasitas baru tas: ");
        }
        else if ((isKataSama(currentWord, "BUY")))  {
            // buy
            Buy(Gadget, &Inventory, currentPos, &Money);
            printf("LENGTH = %d\n", lengthListInventory(Inventory));
            
        }
        else if (isKataSama(currentWord, "INVENTORY")) {
            // inventory
            inventory(&Inventory, &TasNobita, &DaftarInprog, DaftarBangunan, staticPesananPerish, &currentPos, &Time);
        }
        else{
            printf("Input tidak valid\n");
        }
    }
   while (!isKataSama(currentWord, "QUIT"));
    printf("GAME SELESAI");
    closeKata();
    return 0;
}
