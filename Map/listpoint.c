#include <stdio.h>
#include "listpoint.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPoint(ListPoint *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    /* KAMUS LOKAL */
    int i;
    Point P;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_LISTPOINT; i++) {
        Name(P) = NAME_UNDEF;
        Absis(P) = VAL_UNDEF;
        Ordinat(P) = VAL_UNDEF;
        ELMTListPoint(*l,i) = P;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPoint(ListPoint l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* KAMUS LOKAL */
    int i, sum = 0;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_LISTPOINT; i++) {
        if (NameELMTListPoint(l,i) != NAME_UNDEF) {
            sum += 1;
        }
    }
    return sum;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListPoint(ListPoint *l, ElTypeListPoint val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (lengthListPoint(*l) < CAPACITY_LISTPOINT) {
        ELMTListPoint(*l,lengthListPoint(*l)) = val;
    }
}