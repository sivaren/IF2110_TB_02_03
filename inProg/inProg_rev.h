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

typedef struct nodeInProg *AddressInProg;
typedef struct nodeInProg { 
	InProgType info;
	AddressInProg next;
} ElmtInProgList;

typedef AddressInProg InProgList;

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

AddressInProg allocate_INPROG(char pickUp, char dropOff, char itemType, int perishTime);
/* Alokasi nodeInProg baru untuk inprogresslist */

void deallocate_INPROG (AddressInProg p);
/* Dealokasi suatu nodeInProg pada inprogresslist */

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