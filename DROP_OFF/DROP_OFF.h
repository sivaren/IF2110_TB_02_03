
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

extern int Money;
extern int Time;
extern Point Position;
extern Matrix Adjacency;
extern ListStatPos ListGadget, Inventory;
extern ListOfBangunan DaftarBangunan;
extern Queue DaftarPesanan;
extern LinkedList TodoList;
extern Stack Tas, InProgressList;
extern char;

extern int heavyItems;
extern int speedBoost;
extern int increaseCapacity;

//asumsi sudah ada struct pesanan
Pesanan accPesanan;

void DROP_OFF();
// prosedur untuk drop item pada drop point

boolean isDropAvailable();
// mengecek apakah ada item yang bisa di-drop di posisi saat ini

void drop_action();
// drop item apabila tersedia

#endif
