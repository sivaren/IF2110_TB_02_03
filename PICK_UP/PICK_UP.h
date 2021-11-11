#ifndef PICK_UP_H
#define PICK_UP_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// include
// Daftar pesanan
// Todo List
// In Progress list & Tas
// Daftar bangunan
#include "../ADT/ADT Matriks/matrix.h"
#include "../ADT/ADT Point/point.h"
#include "../ADT/ADT List Statis/listpos.h"
#include "../ADT/ADT Linked List/list_linked.h"
#include "../ADT/ADT Queue/queue.h" // modif prioqueue
#include "../ADT/ADT Stack/stack.h"
#include "../ADT/ADT List Statis/ListOfBangunan.h"
#include "../toDo/toDo.h"
#include "../tas/tas.h"
#include "../inProg/inProg_rev.h"




//asumsi sudah ada struct pesanan
ToDoType accPesanan;



void PICK_UP(Bangunan CurrentBangunan, Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog);
// prosedur untuk mengambil item dari pickup point

boolean isPickAvailable(Bangunan CurrentBangunan, Tas TasNobita, ToDoList Todo, ToDoType *accPesanan);
// mengecek apakah ada pesanan pada bangunan tersebut

void pickup_action(Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, ToDoType accPesanan);
// apabila pesanan tersedia lakukan pickup
// apabila pesanan tidak tersedia print "Pesanan tidak ditemukan"


// type converter
ElTypeTas TodoType_to_EltypeTas(ToDoType Todo);
InProgType TodoType_toInProgType(ToDoType InProg);

// proses pemindahan pesanan dari todo ke tas dan inprogress list
void ElmtTransfer(ToDoType accPesanan, ToDoList *Todo, Tas *Tasnobita, InProgList *DaftarInprog);

#endif