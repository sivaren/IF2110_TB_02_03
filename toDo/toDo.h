/* File: toDo.h */

#ifndef TODO_h
#define TODO_h

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../ADT/ADT Queue/daftarPesanan.h"

typedef struct {
    int timeIn;
    char pickUp;
    char dropOff;
    char itemType;
    int perishTime;
} ToDoType;

/* 
diganti kalo udah fix
typedef pesanan ToDoType;
 */

typedef struct nodeToDo *AddressTodo;
typedef struct nodeToDo { 
	ToDoType info;
	AddressTodo next;
} ElmtToDoList;

typedef AddressTodo ToDoList;

#define PERISH_TIME_UNDEF  (-1)
#define FIRST_TODO(td)  (td)
#define INFO_TODO(td)   (td)->info
#define NEXT_TODO(td)   (td)->next

#define TIMEIN_TODO(td)   (td)->info.timeIn
#define PICKUP_TODO(td)   (td)->info.pickUp
#define DROPOFF_TODO(td)   (td)->info.dropOff
#define ITEMTYPE_TODO(td)   (td)->info.itemType
#define PERISHTIME_TODO(td)   (td)->info.perishTime

/* 
TIMEIN_TODO(td)
PICKUP_TODO(td)
DROPOFF_TODO(td)   
ITEMTYPE_TODO(td)  
PERISHTIME_TODO(td)
*/

/* alokasi new nodeToDo untuk TO DO LIST */
AddressTodo newToDoNode(int timeIn, char pickUp, char dropOff, char itemType, int perishTime);

void CreateToDoList(ToDoList *td);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isEmpty_ToDo(ToDoList td);
/* Mengirim true jika list kosong */

int length_ToDoList(ToDoList td);
/* Mengirim banyaknya elemen list jika ada, jika tidak mengirimkan nol */

void insert_ToDoList(ToDoList *td, ToDoType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void delete_ToDoList(ToDoList *td, ToDoType delTarget, ToDoType *delVal);
/* Menghapus elemen toDoList tertentu */

void displayToDoList(ToDoList td);
/* Menampilkan isi To Do List */

boolean isBangunanInTodo (char namaBangunan, ToDoList DaftarTodo);
/* Mengirimkan true apabila namaBangunan terdapat pada To Do List */

void daftarPesanan_to_toDo(Pesanan valPesan, ToDoType *todoVal);
/* CONVERT DAFTAR PESANAN -> TO DO LIST */

#endif