#include <stdlib.h>
#include <stdio.h>

#include "Buy/buy.h"
#include "Buy/ListGadget.h"
#include "DROP_OFF/DROP_OFF.h"
#include "help/help.h"
#include "Inventory/Inventory.h"
#include "Inventory/ListInventory.h"
#include "Map/map.h"
#include "mesinKarKat/wordmachine.h"
#include "Move/move.h"
#include "PICK_UP/PICK_UP.h"
#include "toDo/toDo.h"
#include "END_GAME/END_GAME.h"

int main() {   
    /* INISIALISASI */
    PrioQueuePesanan DaftarPesanan;
    PrioQueuePesanan staticPesananPerish;
    ToDoList Todo;
    InProgList DaftarInprog;
    Tas TasNobita;

    ListGadget Gadget;
    ListInventory Inventory;
    
    Point pointHQ;
    Point currentPos;
    Point tempcurrentPos;
    ListPoint DaftarBangunan;
    
    Matrix Adjacency;
    int rows;
    int cols;
    
    char namaFile[50];
    int Money = 3000;
    int Time = 0;
    int heavyitems = 0;
    int speedboost = 0;
    int PesananDiantar = 0;
    
    int ii, jj, count;
    char format[] = ".txt";

    /* Controler Main Program */
    boolean run = true;

    /* Set Up List Gadget */
    createListGadget(&Gadget);
    ELMTListGadget(Gadget,0) = setGadget(1, 800);
    ELMTListGadget(Gadget,1) = setGadget(2, 1200);
    ELMTListGadget(Gadget,2) = setGadget(3, 1500);
    ELMTListGadget(Gadget,3) = setGadget(4, 3000);

    /* Create a couple set of data */
    CreatePRIOQUEUE(&DaftarPesanan);
    CreatePRIOQUEUE(&staticPesananPerish);
    CreateToDoList(&Todo);
    CreateInProgList(&DaftarInprog);
    CreateTas(&TasNobita, 3);
    CreateListInventory(&Inventory);
    CreateListPoint(&DaftarBangunan, 26);
    CreateMatrix(27, 27, &Adjacency);
    
    /* ASSIGNMENT HEADQUARTERS */
    pointHQ = CreatePoint('X', 1, 1);
    
    printf("Masukkan nama file konfigurasi (config): " );

    startWord();
    count = currentWord.length + 4;
    jj = 0;
    
    for (ii = 0; ii <= count; ii++){
        if (ii < currentWord.length){
            namaFile[ii] = currentWord.contents[ii];
        } else if (ii < count){
            namaFile[ii] = format[jj];
            jj++;
        } else{
            namaFile[ii] = '\0';
        }
    }

    readFile(namaFile, &rows, &cols, &pointHQ, &DaftarBangunan, &DaftarPesanan, &staticPesananPerish, &Adjacency);
    closeFile();

    // Assignment current position setelah baca file konfigurasi
    currentPos = pointHQ; 

    printf("===================\n");
    printf("Loading...\n");
    printf("Config file loaded.\n");
    printf("===================\n");

    /* LOOP MAIN PROGRAM */
    while (run) {
        printf("ENTER COMMAND: ");
        startWord();
        
        if (isKataSama(currentWord, "MOVE")) {
            tempcurrentPos = currentPos;
            // Pindah Bangunan
            move(DaftarBangunan, Adjacency, &currentPos, pointHQ);
            
            // Jika Mobita Bergerak
            if (currentPos.name != tempcurrentPos.name) {
                int addition = 0;
                
                addition += 1; // regular addition
                addition += heavyitems; // heavy items addition

                if (speedboost != 0) {
                    if((speedboost%2) == 0){
                        addition -= 1;
                        printf("Speedboost activated, waktu tidak bertambah\n"); }
                    speedboost -= 1;
                }
                // Adjust perishable item
                int x;
                InProgType delValProgType;
                
                for (x = 0; x < addition; x++) {
                    adjustPerishTime_inProg(&DaftarInprog, &TasNobita);
                    deletePerishItem_inProg(&DaftarInprog, &TasNobita, &delValProgType);
                }

                // Time adjust
                Time += addition;

                // Daftar pesanan to ToDoList
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

                printf("Time            : %d\n", Time);
                printf("Posisi sekarang : %c\n", currentPos.name);
                printf("Speedboost      : %d\n\n", speedboost);

            } else { // Jika Mobita Diam di tempat
                printf("MOVE dibatalkan!\n\n");
            }

            // cek end game
            END_GAME(Time, PesananDiantar, pointHQ, currentPos, DaftarPesanan, Todo, DaftarInprog, TasNobita, &run);
        }
        else if  (isKataSama(currentWord, "PICK_UP")) {
            // PICK_UP
            PICK_UP(currentPos, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost);
        }
        else if (isKataSama(currentWord, "DROP_OFF")) {
            // DROP_OFF
            DROP_OFF(currentPos, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost, &Money, &PesananDiantar); 
        }
        else if (isKataSama(currentWord, "MAP"))  {
            // MAP
            map(DaftarBangunan, Adjacency, currentPos, pointHQ, TOP_TAS(TasNobita).dropOff, Todo, rows, cols);
        }
        else if (isKataSama(currentWord, "TO_DO")) {
            // TO_DO
            displayToDoList(Todo);
        }
        else if (isKataSama(currentWord, "IN_PROGRESS"))  {
            // IN_PROGRESS
            displayInProg(DaftarInprog);
        }
        else if ((isKataSama(currentWord, "BUY")))  {
            // BUY
            Buy(Gadget, &Inventory, currentPos, &Money);
        }
        else if (isKataSama(currentWord, "INVENTORY")) {
            // INVENTORY
            inventory(&Inventory, &TasNobita, &DaftarInprog, DaftarBangunan, staticPesananPerish, &currentPos, &Time);
        }
        else if (isKataSama(currentWord, "HELP")){
            // HELP
            displayHelp();
        }
        else if (isKataSama(currentWord, "QUIT")) {
            run = false;
            printf("(^///^) Selamat tinggal (^///^)\n\n");
        }
        else{
            printf("Input tidak valid!\n\n");
        }
    }

    return 0;
}