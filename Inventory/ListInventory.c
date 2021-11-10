/* Nama: Farnas Rozaan Iraqee */
/* NIM: 13520067 */
/* Tanggal: 8 September 2021 */
/* Topik: ADT List */
/* Deskripsi: Realisasi ADT List */

#include <stdio.h>
#include "ListInventory.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatPos(ListInventory *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_INVENTORY; i++) {
        ELMTInventory(*l,i) = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListStat(ListInventory l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* KAMUS LOKAL */
    int i, sum = 0;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_INVENTORY; i++) {
        if (ELMTInventory(l,i) != VAL_UNDEF) {
            sum += 1;
        }
    }
    return sum;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List penuh *** */
boolean isFullInventory(ListInventory l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (lengthListStat(l) == CAPACITY_INVENTORY);
}

void displayInventory(ListInventory l) {
/* Menampilkan list gadget yang ada di dalam Inventory */
    /* KAMUS LOKAL */
    int i;
    int num;
    /* ALGORITMA */
    for (num = 1; num <= 5; num++)
    {
        printf("%d.", num);
        for (i = 0; i < 5; i++) 
        {
            printf("%c\n", ELMTInventory(l,i));
        }
    }
}    

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN LIST INVENTORY ********** */
/* *** Menambahkan elemen terakhir *** */
void insertGadget(ListInventory *l, Gadget val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (lengthListStat(*l) < CAPACITY_INVENTORY) {
        ELMTInventory(*l,lengthListStat(*l)) = val;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteGadget(ListInventory l, Gadget val) {
/* Menghapus elemen list pada index tertentu */

    val = VAL_UNDEF;

}