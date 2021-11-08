#ifndef LISTPOINT_H
#define LISTPOINT_H

#include "boolean.h"
#include "point.h"

/*  Kamus Umum */
#define CAPACITY_LISTPOINT 100
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/
#define NAME_UNDEF '#'
/* Nama elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Point ElTypeListPoint;  /* type elemen List */
typedef struct {
   ElTypeListPoint contents[CAPACITY_LISTPOINT]; /* memori tempat penyimpan elemen (container) */
} ListPoint;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatPos */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai VAL_UNDEF
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTListPoint(l, i) (l).contents[(i)]
#define NameELMTListPoint(l, i) (l).contents[(i)].name
#define AbsisELMTListPoint(l, i) (l).contents[(i)].X
#define OrdinatELMTListPoint(l, i) (l).contents[(i)].Y

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPoint(ListPoint *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPoint(ListPoint l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListPoint(ListPoint *l, ElTypeListPoint val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

#endif