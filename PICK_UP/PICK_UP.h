#ifndef PICK_UP_H
#define PICK_UP_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../ADT/ADT List Statis/ListOfBangunan.h"
#include "../toDo/toDo.h"
#include "../tas/tas.h"
#include "../inProg/inProg_rev.h"




void PICK_UP(Bangunan CurrentBangunan, Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, int *heavyitems, boolean *speedboost);
// prosedur untuk mengambil item dari pickup point

boolean isPickAvailable(Bangunan CurrentBangunan, Tas TasNobita, ToDoList Todo, ToDoType *accPesanan);
// mengecek apakah ada pesanan pada bangunan tersebut

void pickup_action(Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, ToDoType accPesanan, int *heavyitems, boolean *speedboost);
// apabila pesanan tersedia lakukan pickup
// apabila pesanan tidak tersedia print "Pesanan tidak ditemukan"


// type converter
ElTypeTas TodoType_to_ElTypeTas(ToDoType Todo);
InProgType TodoType_to_InProgType(ToDoType Todo);
InProgType ElTypeTas_to_InProgType(ElTypeTas elmtTas);
ElTypeTas InProgType_to_ElTypeTas(InProgType elmtInProg);

// proses pemindahan pesanan dari todo ke tas dan inprogress list
void ElmtTransfer_PICK_UP(ToDoType accPesanan, ToDoList *Todo, Tas *Tasnobita, InProgList *DaftarInprog);

#endif