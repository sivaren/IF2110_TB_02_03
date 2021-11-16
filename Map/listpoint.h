#ifndef LISTPOINT_H
#define LISTPOINT_H

#include "boolean.h"
#include "point.h"

/* Definisi elemen dan koleksi objek */
typedef Point ElTypeListPoint;  /* type elemen List */
typedef struct {
   ElTypeListPoint *buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;
   int capacity;
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
#define BufferListPoint(l) (l).buffer
#define ELMTListPoint(l, i) (l).buffer[(i)]
#define NameELMTListPoint(l, i) (l).buffer[(i)].name
#define AbsisELMTListPoint(l, i) (l).buffer[(i)].X
#define OrdinatELMTListPoint(l, i) (l).buffer[(i)].Y
#define NEFFListPoint(l) (l).nEff
#define CAPListPoint(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPoint(ListPoint *l, int capacity);
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

void printOneBangunan(Point b);

#endif