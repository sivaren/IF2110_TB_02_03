/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTOFBANGUNAN_H
#define LISTOFBANGUNAN_H

#include "boolean.h"
#include "..\ADT Point\Point.h"

/*  Kamus Umum */
#define CAPACITY_LISTSTAT 100
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF_BANGUNAN '-'
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct {
	char nama;
   Point posisi;
} Bangunan;  /* type elemen List */
typedef struct {
   Bangunan contents[CAPACITY_LISTSTAT]; /* memori tempat penyimpan elemen (container) */
} ListOfBangunan;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListOfBangunan, cara deklarasi dan akses: */
/* Deklarasi : l : ListOfBangunan */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai VAL_UNDEF_BANGUNAN
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTListOfBangunan(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatPos(ListOfBangunan *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF_BANGUNAN */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListStat(ListOfBangunan l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void printOneBangunan(Bangunan b);

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListStat(ListOfBangunan l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListStat(ListOfBangunan l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListStat(ListOfBangunan l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullListStat(ListOfBangunan l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListStat(ListOfBangunan *l);
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void displayListStat(ListOfBangunan l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListOfBangunan plusMinusTabListStat(ListOfBangunan l1, ListOfBangunan l2, boolean plus);
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListStatEqual(ListOfBangunan l1, ListOfBangunan l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListStat(ListOfBangunan l, Bangunan val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremesListStat(ListOfBangunan l, Bangunan *max, Bangunan *min);
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** OPERASI LAIN ********** */
boolean isAllEvenListStat(ListOfBangunan l);
/* Menghailkan true jika semua elemen l genap */

/* ********** SORTING ********** */
void sortListStat(ListOfBangunan *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListStat(ListOfBangunan *l, Bangunan val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListStat(ListOfBangunan *l, Bangunan *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

Bangunan PointToBangunan(Point P, ListOfBangunan LB);

Point BangunanToPoint(Bangunan B, ListOfBangunan LB);
Point NamaBangunanToPoint(char x, ListOfBangunan LB);


char PointToNamaBangunan(Point P, ListOfBangunan LB);

void updateCurrentBangunan(Point P, ListOfBangunan LB, Bangunan *CurrentBangunan);

#endif