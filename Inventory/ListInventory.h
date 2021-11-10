/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTINVENTORY_H
#define LISTINVENTORY_H

#include "boolean.h"

/*  Kamus Umum */
#define CAPACITY_INVENTORY 5
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF '-'
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef char Gadget;  /* type elemen List */
typedef struct {
   Gadget contents[CAPACITY_INVENTORY]; /* memori tempat penyimpan elemen (container) */
} ListInventory;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatPos */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai VAL_UNDEF
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTInventory(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatPos(ListInventory *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListStat(ListInventory l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** TEST KOSONG/PENUH ********** */
boolean isFullListStat(ListInventory l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void displayInventory(ListInventory l);
/* Menampilkan list gadget yang ada di dalam Inventory */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertGadget(ListInventory *l, Gadget val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void deleteGadget(ListInventory l, Gadget val);
/* Menghapus elemen list pada index tertentu */

#endif