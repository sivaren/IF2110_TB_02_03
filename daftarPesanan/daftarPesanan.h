/* File : daftarPesanan.h */
/* Memanfaatkan ADT Queue yang dimodifikasi menjadi prioQueue */

#ifndef DAFTARPESANAN_H
#define DAFTARPESANAN_H

#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY_PRIOQUEUE 100

/* Definisi elemen dan address */
typedef int ElType;

typedef struct {
   int waktuMasuk;
   char pickUp;
   char dropOff;
   char jenisItem;
   int waktuHangus;     //untuk perishable
} Pesanan;

typedef struct {
	Pesanan buffer[CAPACITY_PRIOQUEUE]; 
	int idxHead;
	int idxTail;
} PrioQueuePesanan;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD_PRIOQUEUE(q) (q).idxHead
#define IDX_TAIL_PRIOQUEUE(q) (q).idxTail
#define     HEAD_PRIOQUEUE(q) (q).buffer[(q).idxHead]
#define     TAIL_PRIOQUEUE(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreatePRIOQUEUE(PrioQueuePesanan *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyPRIOQUEUE(PrioQueuePesanan q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullPRIOQUEUE(PrioQueuePesanan q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
int lengthPRIOQUEUE(PrioQueuePesanan q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueuePRIOQUEUE(PrioQueuePesanan *q, Pesanan val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeuePRIOQUEUE(PrioQueuePesanan *q, Pesanan *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

/* *** Display Queue *** */
void displayPRIOQUEUE(PrioQueuePesanan q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
void sortQueue(PrioQueuePesanan *Q);

#endif
