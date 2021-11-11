
#ifndef DROP_OFF_H
#define DROP_OFF_H

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
#include "../PICK_UP/PICK_UP.h"

void DROP_OFF(Bangunan CurrentBangunan, Tas *TasNobita, ToDoList *Todo, InProgList *DaftarInprog, int *heavyitems, boolean *speedboost, int currentTasCapacity, int *Money);
// prosedur untuk drop item pada drop point

boolean isDropAvailable(Bangunan CurrentBangunan, Tas TasNobita, ToDoList Todo);
// mengecek apakah ada item yang bisa di-drop di posisi saat ini

void drop_action(Tas *TasNobita, InProgList *DaftarInprog, int *heavyitems, boolean *speedboost, int currentTasCapacity, int *Money);
// drop item apabila tersedia

void ElmtDelete_DROP_OFF(Tas *Tasnobita, InProgList *DaftarInprog);
// menghapus elemen dari tas dan in progress list

#endif
