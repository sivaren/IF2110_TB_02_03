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

int main() {   
    // inisialisasi
    int Money = 3000;
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
    int rows;
    int cols;
    boolean run = true;

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
    PrioQueuePesanan staticPesananPerish;

    pointHQ = CreatePoint('X', 1, 1);
    CreateListPoint(&DaftarBangunan, 26);
    CreateMatrix(27, 27, &Adjacency);
    CreatePRIOQUEUE(&DaftarPesanan);
    CreatePRIOQUEUE(&staticPesananPerish);
    CreateTas(&TasNobita, 3);
    CreateToDoList(&Todo);
    CreateInProgList(&DaftarInprog);
    printf("nama FILE : " );

    startWord();
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

    currentPos = pointHQ;
    Point tempcurrentPos;


    printf("Config loaded\n");

    while (run) {
        printf("ENTER COMMAND: ");
        startWord();
        
        if (isKataSama(currentWord, "MOVE"))  {
            //pindah bangunan
            tempcurrentPos = currentPos;
            move(DaftarBangunan, Adjacency, &currentPos, pointHQ);
            if (currentPos.name != tempcurrentPos.name) {
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
            }
            else {
                printf("MOVE batal\n");
            }
            


	


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
            displayToDoList(Todo);
        }
        else if (isKataSama(currentWord, "IN_PROGRESS"))  {
            //change inprog and tas
            displayInProg(DaftarInprog);
        }
        else if ((isKataSama(currentWord, "BUY")))  {
            // buy
            Buy(Gadget, &Inventory, currentPos, &Money);
            
        }
        else if (isKataSama(currentWord, "INVENTORY")) {
            // inventory
            inventory(&Inventory, &TasNobita, &DaftarInprog, DaftarBangunan, staticPesananPerish, &currentPos, &Time);
        }
        else if (isKataSama(currentWord, "QUIT")) {
            run = false;
        }
        else{
            printf("Input tidak valid");
        }
    }








    return 0;
}