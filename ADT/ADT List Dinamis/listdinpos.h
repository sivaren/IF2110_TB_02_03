/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori list dinamik */

#ifndef LISTDINPOS_H
#define LISTDINPOS_H

#include "boolean.h"

/*  Kamus Umum */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeListDinPos; /* type indeks */
typedef int ElTypeListDinPos;  /* type elemen list */
typedef struct
{
  ElTypeListDinPos *buffer; /* memori tempat penyimpan elemen (container) */
  int capacity;  /* ukuran elemen */
} ListDinPos;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah ListDinPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinPos */
/* Maka cara akses:
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  List kosong: semua elemen bernilai VAL_UNDEF
  Definisi elemen pertama : l.buffer[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i terbesar
                                             sehingga l.buffer[i] != VAL_UNDEF
  Definisi nEff: jumlah elemen efektif, di mana l.buffer[nEff] == VAL_UNDEF
                                             dan l.buffer[nEff-1] != VAL_UNDEF */

/* ********** SELEKTOR ********** */
#define BUFFER_ListDinPos(l) (l).buffer
#define ELMT_ListDinPos(l, i) (l).buffer[i]
#define CAPACITY_ListDinPos(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinPos(ListDinPos *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocate_ListDinPos(ListDinPos *l);
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length_ListDinPos(ListDinPos l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxTypeListDinPos getLastIdx_ListDinPos(ListDinPos l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListDinPos(ListDinPos l, IdxTypeListDinPos i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff_ListDinPos(ListDinPos l, IdxTypeListDinPos i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty_ListDinPos(ListDinPos l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull_ListDinPos(ListDinPos l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList_ListDinPos(ListDinPos *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList_ListDinPos(ListDinPos l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDinPos plusMinusList_ListDinPos(ListDinPos l1, ListDinPos l2, boolean plus);
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual_ListDinPos(ListDinPos l1, ListDinPos l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxTypeListDinPos indexOf_ListDinPos(ListDinPos l, ElTypeListDinPos val);
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan indeks tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes_ListDinPos(ListDinPos l, ElTypeListDinPos *max, ElTypeListDinPos *min);
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList_ListDinPos(ListDinPos lIn, ListDinPos *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElTypeListDinPos sumList_ListDinPos(ListDinPos l);
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal_ListDinPos(ListDinPos l, ElTypeListDinPos val);
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEven_ListDinPos(ListDinPos l);
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sort_ListDinPos(ListDinPos *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListDinPos(ListDinPos *l, ElTypeListDinPos val);
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast_ListDinPos(ListDinPos *l, ElTypeListDinPos *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList_ListDinPos(ListDinPos *l, int num);
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList_ListDinPos(ListDinPos *l, int num);
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList_ListDinPos(ListDinPos *l);
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */

#endif
