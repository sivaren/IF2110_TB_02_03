// pickup & dropoff
#include "PICK_UP/PICK_UP.h"
#include "DROP_OFF/DROP_OFF.h"
#include "toDo/toDo.h"

// move and map
// #include "Move/listpoint.h"
// #include "Move/matrix.h"
#include "Move/move.h"
// #include "Move/point.h"
#include "Map/map.h"


// read config
// #include "ADT/ADT Mesin Karakter dan Kata/charmachine.h"
#include "ADT/ADT Mesin Karakter dan Kata/wordmachine.h"



#include <stdlib.h>
#include <stdio.h>



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
            printf("here\n");
            insert_ToDoList(Todo, tempElmt);
            printf("here2\n");
            
            }
}

void displayAll(Tas TasNobita, InProgList DaftarInprog, ToDoList Todo, int heavyitems, int speedboost, int currentCapacity, Point currentPos, int Money) {
    printf("\n=============\n");
    displaytas(TasNobita);
    printf("=============\n");
    displayInProg(DaftarInprog);
    printf("=============\n");
    displayToDoList(Todo);
    printf("=============\n");
    printf("money: %d\n", Money);
    printf("heavyitems: %d\n", heavyitems);
    printf("speedboost: %d\n", speedboost);
    printf("current capacity: %d\n", currentCapacity);
    printf("currentPos: %c\n", currentPos.name);
    printf("=============\n");
}

int main() {
    // inisialisasi
    int currentCapacity = 3;
    int Money = 3000;
    char opt;
    InProgList DaftarInprog;
    int heavyitems = 0;
    int speedboost = 0;
    Tas TasNobita;
        // baca input tas nobita
        readTas(&TasNobita, &DaftarInprog, &heavyitems, &speedboost);
    ToDoList Todo;
        // baca input todo list
        readTodo(&Todo);

    Matrix dummyPeta;
    Point pointHQ;
    ListPoint DaftarBangunan;
    PrioQueuePesanan DaftarPesanan;
    Matrix Adjacency;
    int Time = 0;
    Point currentPos;
    int rows = 10; // DUMMY
    int cols = 15; //DUMMY


    // pointHQ = CreatePoint('X', 1, 1);
    printf("AbsisHQ sebelum read: %d\n", pointHQ.X);
    CreateMatrix(rows, cols, &dummyPeta);
    CreateListPoint(&DaftarBangunan);
    CreateMatrix(lengthListPoint(DaftarBangunan), lengthListPoint(DaftarBangunan), &Adjacency);

    // readfile kalo udh ada
    // readFile("config.txt", &dummyPeta, &pointHQ, &DaftarBangunan, &DaftarPesanan, &Adjacency);
    // printf("AbsisHQ setelah read: %d\n", pointHQ.X);


    // kalo blm ada read
    printf("input adjacency: \n");
    pointHQ = CreatePoint('8',1,1);
    currentPos = pointHQ;
    Point A = CreatePoint('A',10,1);
    insertLastListPoint(&DaftarBangunan,A);
    Point B = CreatePoint('B',1,15);
    insertLastListPoint(&DaftarBangunan,B);
    Point C = CreatePoint('C',1,9);
    insertLastListPoint(&DaftarBangunan,C);
    Point D = CreatePoint('D',1,13);
    insertLastListPoint(&DaftarBangunan,D);
    Point E = CreatePoint('E',2,3);
    insertLastListPoint(&DaftarBangunan,E);
    Point F = CreatePoint('F',3,1);
    insertLastListPoint(&DaftarBangunan,F);
    Point G = CreatePoint('G',3,8);
    insertLastListPoint(&DaftarBangunan,G);
    Point H = CreatePoint('H',3,14);
    insertLastListPoint(&DaftarBangunan,H);
    Point I = CreatePoint('I',4,5);
    insertLastListPoint(&DaftarBangunan,I);
    Point J = CreatePoint('J',5,12);
    insertLastListPoint(&DaftarBangunan,J);
    Point K = CreatePoint('K',6,3);
    insertLastListPoint(&DaftarBangunan,K);
    Point L = CreatePoint('L',7,10);
    insertLastListPoint(&DaftarBangunan,L);
    Point M = CreatePoint('M',8,2);
    insertLastListPoint(&DaftarBangunan,M);
    Point N = CreatePoint('N',8,6);
    insertLastListPoint(&DaftarBangunan,N);
    Point O = CreatePoint('O',8,15);
    insertLastListPoint(&DaftarBangunan,O);
    Point P = CreatePoint('P',9,13);
    insertLastListPoint(&DaftarBangunan,P);
    Point Q = CreatePoint('Q',10,3);
    insertLastListPoint(&DaftarBangunan,Q);
    CreateMatrix(18,18,&Adjacency);
    readMatrix(&Adjacency,18,18);   






    displayAll(TasNobita, DaftarInprog, Todo, heavyitems, speedboost, currentCapacity, currentPos, Money);

    printf("NAME HQ= %c\n", Name(pointHQ));
    printf("config loaded\n");
   
    do {
        printf("\n=============\n");
        printf("Masukkan command: (M(map), m(move), p(pickup), d(dropoff), q(quit), t(change todo), i(change inprog/tas), D(display all state), c(change tas capacity): ");
        scanf(" %c", &opt);
        printf("\n=============\n");
        if (opt == 'm') {
            //pindah bangunan
            move(DaftarBangunan, Adjacency, &currentPos, pointHQ);
            Time += 1; // regular
            Time += heavyitems; // heavy items

            if ((speedboost%2) == 1) {
                Time -= 1;
                printf("Bonus 1 Unit waktu\n");
            }
            if (speedboost != 0) {
            speedboost -= 1;
            }
        


            // perish controller

            //
            printf("Time = %d\n", Time);
            printf("Speedboost = %d\n", speedboost);
            }
        else if (opt == 'M') {
            // map
            map(DaftarBangunan, pointHQ, rows, cols);
        }
        else if (opt == 'p') {
            //pickup
            PICK_UP(currentPos, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost);
        }
        else if (opt == 'd') {
            //dropoff
            DROP_OFF(currentPos, &TasNobita, &Todo, &DaftarInprog, &heavyitems, &speedboost, &currentCapacity, &Money);
            
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
            displayAll(TasNobita, DaftarInprog, Todo, heavyitems, speedboost, currentCapacity, currentPos, Money);

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
