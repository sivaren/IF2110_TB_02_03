#include <stdio.h>
#include <stdlib.h>
#include "listpoint.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPoint(ListPoint *l, int capacity) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    /* ALGORITMA */
    BufferListPoint(*l) = malloc(sizeof(ElTypeListPoint)*capacity);
    CAPListPoint(*l) = capacity;
    NEFFListPoint(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPoint(ListPoint l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* ALGORITMA */
    if (NEFFListPoint(l) > 0)
    {
        return NEFFListPoint(l);
    }
    else
    {
        return 0;
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListPoint(ListPoint *l, ElTypeListPoint val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (lengthListPoint(*l) < CAPListPoint(*l)) {
        ELMTListPoint(*l, lengthListPoint(*l)) = val;
        NEFFListPoint(*l) += 1;
    }
}

void printOneBangunan(Point b) {
    printf("%c ", b.name);
    printf("(");
    printf("%d,", Absis(b));
    printf("%d", Ordinat(b));
    printf(")");
}