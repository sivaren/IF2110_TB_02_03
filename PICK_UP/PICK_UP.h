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



void PICK_UP();
// prosedur untuk mengambil item dari pickup point

boolean isPickAvailable();
// mengecek apakah ada pesanan pada bangunan tersebut

void pickup_action();
// apabila pesanan tersedia lakukan pickup
// apabila pesanan tidak tersedia print "Pesanan tidak ditemukan"

#endif