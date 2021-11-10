/* File: inProg_rev.h */

#ifndef INPROGRESS_H
#define INPROGRESS_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef struct {
	char pickUp;
    char dropOff;
    char itemType;
    int perishTime;
} InProgType;

typedef struct node *Address;
typedef struct node { 
	InProgType info;
	Address next;
} ElmtInProgList;

typedef Address InProgList;

#define FIRST_INPROG(P) (P)
#define INFO_INPROG(P) (P)->info
#define NEXT_INPROG(P) (P)->next

#define PICKUP_INPROG(P) (P)->info.pickUp
#define DROPOFF_INPROG(P) (P)->info.dropOff
#define ITEMTYPE_INPROG(P) (P)->info.itemType
#define PERISHTIME_INPROG(P) (P)->info.perishTime

/* 
FIRST_INPROG(L)
INFO_INPROG(P)
NEXT_INPROG(P) 

PICKUP_INPROG(P) 
DROPOFF_INPROG(P) 
ITEMTYPE_INPROG(P) 
PERISHTIME_INPROG(P)
*/

Address allocate_INPROG(char pickUp, char dropOff, char itemType, int perishTime);
/* Alokasi node baru untuk inprogresslist */

void deallocate_INPROG (Address p);
/* Dealokasi suatu node pada inprogresslist */

void CreateInProgList(InProgList *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isEmpty_InProg(InProgList l);
/* Mengirim true jika list kosong */

void insertFirst_InProgList(InProgList *l, InProgType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void deleteFirst_InProgList(InProgList *l, InProgType *delVal);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

void displayInProg(InProgList l);
/* Menampilkan isi inprogresslist */

#endif