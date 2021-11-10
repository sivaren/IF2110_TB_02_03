#ifndef GADGET_H
#define GADGET_H

/* Kamus Umum */
#define CAPACITY_LISTGADGET 4
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

typedef struct {
    char name;
    int price;
} DataGadget;
typedef struct { 
    DataGadget contents [CAPACITY_LISTGADGET];
} ListGadget;

/* *** Notasi Akses: Selektor Point *** */
#define ELMTListGadget(l,i) (l).contents[(i)]

void displayGadget(ListGadget l);
/* Menampilkan daftar List Gadget yang dapat dibeli */

#endif