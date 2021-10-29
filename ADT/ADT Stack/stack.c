#include <stdio.h>
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
    /* ALGORITMA */
    IDX_TOP(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s) {
/* Mengirim true jika s kosong: lihat definisi di atas */
    /* ALGORITMA */
    return IDX_TOP(s) == IDX_UNDEF;
}
boolean isFullStack(Stack s) {
/* Mengirim true jika tabel penampung nilai s stack penuh */
    /* ALGORITMA */
    return IDX_TOP(s) == CAPACITY_STACK-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, ElTypeStack val) {
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
    /* ALGORITMA */
    IDX_TOP(*s)++;
    TOP(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, ElTypeStack *val) {
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
    /* ALGORITMA */
    *val = TOP(*s);
    IDX_TOP(*s)--; 
}