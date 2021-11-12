/* Implementasi file tas.h */

#include "tas.h"
/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s, int capacity){
    BUFFER_TAS(*s) = malloc(sizeof(ElTypeTas)*capacity);
    TAS_CAPACITY(*s) = capacity;
    IDX_TOP_TAS(*s) = IDX_TAS_UNDEF;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tas S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyTas(Tas s){
    return IDX_TOP_TAS(s) == IDX_TAS_UNDEF;
}
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullTas(Tas s){
    return IDX_TOP_TAS(s) == TAS_CAPACITY(s) - 1;
}
/* Mengirim true jika tabel penampung nilai s Tas penuh */

/* ************ Menambahkan sebuah elemen ke Tas ************ */
void pushTas(Tas *s, ElTypeTas val){
    if(!isFullTas(*s)){
        IDX_TOP_TAS(*s)++;
        (*s).buffer[(*s).idxTop].pickUp = val.pickUp;
        (*s).buffer[(*s).idxTop].dropOff = val.dropOff;
        (*s).buffer[(*s).idxTop].itemType = val.itemType;
        (*s).buffer[(*s).idxTop].perishTime = val.perishTime;
    }
}
/* Menambahkan val sebagai elemen Tas s */
/* I.S. s mungkin kosong, tabel penampung elemen Tas TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Tas ************ */
void popTas(Tas *s, ElTypeTas *val){
    *val = TOP_TAS(*s);
    IDX_TOP_TAS(*s)--;
}
/* Menghapus val dari Tas s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

void copyTas(Tas t1, Tas *t2){
    Tas temp;
    ElTypeTas popVal;
    CreateTas(&temp, TAS_CAPACITY(t1));
    
    while(!isEmptyTas(t1)){
        popTas(&t1, &popVal);
        pushTas(&(temp), popVal);
    }
    while(!isEmptyTas(temp)){
        popTas(&temp, &popVal);
        pushTas(&(*t2), popVal);
    }
}
/* Tas t2 berisi copy dari Tas t1 */

void upgradeTasCapacity(Tas *s, int capacity){
    Tas temp;
    CreateTas(&temp, capacity);
    copyTas(*s, &temp);

    CreateTas(&(*s), capacity);
    copyTas(temp, &(*s));
}
/* Upgrade tas dengan capacity yang baru */

void displaytas(Tas s){
    if(!isEmptyTas(s)){
        printf("Isi Tas:\n");
        for(int i = IDX_TOP_TAS(s); i >= 0; i--) {
            printf("%c ", s.buffer[i].pickUp);
            printf("%c ", s.buffer[i].dropOff);
            printf("%c ", s.buffer[i].itemType);
            printf("%d\n", s.buffer[i].perishTime);
        }
    } else{
        printf("Tas Kosong!\n");
    }
}
/* Display isi tas (hanya untuk debugging) */