/* File : tas.h */
#ifndef TAS_H
#define TAS_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define IDX_TAS_UNDEF -1

typedef struct {
	char pickUp;
    char dropOff;
    char itemType;
    int perishTime;
} ElTypeTas;

typedef struct {
    ElTypeTas *buffer;                  /* tabel penyimpan elemen */
    int idxTop;                         /* alamat TOP: elemen puncak */
    int capacity;                       /* kapasitas tas */
} Tas;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Tas, maka akses elemen : */
#define IDX_TOP_TAS(s) (s).idxTop
#define     BUFFER_TAS(s) (s).buffer
#define     TOP_TAS(s) (s).buffer[(s).idxTop]
#define     TAS_CAPACITY(s) (s).capacity

/* 
NOTE:
prosedur adjustPerishTime_inTas dan deletePerishItem_inTas dipakai di dalam
prosedur adjustPerishTime_inProg dan deletePerishItem_inProg yang berada 
di ADT In Progress List
*/

/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s, int capacity);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tas S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyTas(Tas s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullTas(Tas s);
/* Mengirim true jika tabel penampung nilai s Tas penuh */

/* ************ Menambahkan sebuah elemen ke Tas ************ */
void pushTas(Tas *s, ElTypeTas val);
/* Menambahkan val sebagai elemen Tas s */
/* I.S. s mungkin kosong, tabel penampung elemen Tas TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Tas ************ */
void popTas(Tas *s, ElTypeTas *val);
/* Menghapus val dari Tas s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

void adjustPerishTime_inTas(Tas *s);
/* Adjust waktu hangus perish item, perishTime - 1 */
/* adjustPerishTime_inTas dipakai dalam prosedur adjustPerishTime_inProg (ADT In Progress List)*/

void deletePerishItem_inTas(Tas *s);
/* I.S. - Tas sembarang*/
/* F.S. - Expired perishable item di hapus (JIKA ADA YG EXPIRED)*/
/* jika tidak ada maka F.S. = I.S.*/
/* deletePerishItem_inTas dipakai dalam prosedur deletePerishItem_inProg (ADT In Progress List) */

void copyTas(Tas t1, Tas *t2);
/* Tas t2 berisi copy dari Tas t1 */

void upgradeTasCapacity(Tas *s, int capacity);
/* Upgrade tas dengan capacity yang baru */

void displaytas(Tas s);
/* Display isi tas (hanya untuk debugging) */

#endif
