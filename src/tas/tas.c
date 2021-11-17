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

void adjustPerishTime_inTas(Tas *s){
    Tas temp;
    ElTypeTas popVal;
    CreateTas(&temp, TAS_CAPACITY(*s));

    // mengisi tas temp
    while(!isEmptyTas(*s)){
        popTas(&(*s), &popVal);
        if(popVal.itemType == 'P'){
            popVal.perishTime = popVal.perishTime - 1;
        }
        pushTas(&(temp), popVal);
    }
    // mengisi kembali tas *s dengan perishTime item perishable yang telah di decrement
    while(!isEmptyTas(temp)){
        popTas(&temp, &popVal);
        pushTas(&(*s), popVal);
    }
}
/* Adjust waktu hangus perish item, perishTime - 1 */
/* adjustPerishTime_inTas dipakai dalam prosedur adjustPerishTime_inProg (ADT In Progress List)*/

void deletePerishItem_inTas(Tas *s){
    Tas temp;
    Tas perishContainer;
    ElTypeTas popVal;
    CreateTas(&temp, TAS_CAPACITY(*s));
    CreateTas(&perishContainer, TAS_CAPACITY(*s));

    // mengisi tas temp dan tas perishContainer
    while(!isEmptyTas(*s)){
        popTas(&(*s), &popVal);
        if(popVal.itemType == 'P' && popVal.perishTime <= 0){
            pushTas(&(perishContainer), popVal);
        } else {
            pushTas(&(temp), popVal);
        }
    }
    // mengisi kembali tas *s dengan expired perishable item telah di buang dari tas
    while(!isEmptyTas(temp)){
        popTas(&temp, &popVal);
        pushTas(&(*s), popVal);
    }
}
/* I.S. - Tas sembarang*/
/* F.S. - Expired perishable item di hapus (JIKA ADA YG EXPIRED)*/
/* jika tidak ada maka F.S. = I.S.*/
/* deletePerishItem_inTas dipakai dalam prosedur deletePerishItem_inProg (ADT In Progress List) */

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

void upgradeTasCapacity(Tas *s, int newCapacity){
    if(newCapacity <= MAX_TAS_CAPACITY){
        Tas temp;
        CreateTas(&temp, newCapacity);
        copyTas(*s, &temp);

        CreateTas(&(*s), newCapacity);
        copyTas(temp, &(*s));
    }
}
/* Upgrade tas dengan capacity yang baru */

void displaytas(Tas s){
    int i;
    if(!isEmptyTas(s)){
        printf("Isi Tas:\n");
        for( i = IDX_TOP_TAS(s); i >= 0; i--) {
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

void activated_kainWaktu_inTas(Tas *s, PrioQueuePesanan Q, ElTypeTas *targetPerish, int *waktuSemula){
    Tas temp;
    ElTypeTas popVal;
    int i;
    boolean found;
    
    found = false;
    CreateTas(&temp, TAS_CAPACITY(*s));

    while(!isEmptyTas(*s) && !found){
        if(TOP_TAS(*s).itemType == 'P'){
            popTas(&(*s), &popVal);
            found = true;
        } else {
            popTas(&(*s), &popVal);
            pushTas(&(temp), popVal);
        }
    }
    // perishable item ditemukan
    *targetPerish = popVal;

    // mencari data perishable item yang sama pada PrioQueuePesanan
    for(i = IDX_HEAD_PRIOQUEUE(Q); i <= IDX_TAIL_PRIOQUEUE(Q); i++){
        if(Q.buffer[i].pickUp == popVal.pickUp && Q.buffer[i].dropOff == popVal.dropOff && Q.buffer[i].jenisItem == 'P'){
            *waktuSemula = Q.buffer[i].waktuHangus; 
            popVal.perishTime = *waktuSemula; 
        }
    }
    // sisa waktu perishable item teratas TAS telah di refresh

    // masukkan kembali perishable item yang telah di adjust waktu hangus-nya
    pushTas(&(*s), popVal);

    // mengisi kembali sisa item yang ada di tas sebelumnya
    while(!isEmptyTas(temp)){
        popTas(&temp, &popVal);
        pushTas(&(*s), popVal);
    }
}
/* Mengembalikan sisa waktu hangus perishable item teratas TAS, sudah dijamin terdapat perishable item */