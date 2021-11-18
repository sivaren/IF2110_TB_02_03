#include <stdio.h>
#include "daftarPesanan.h"

/* *** Kreator *** */
void CreatePRIOQUEUE(PrioQueuePesanan *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    /* ALGORITMA */
    IDX_HEAD_PRIOQUEUE(*q) = IDX_UNDEF;
    IDX_TAIL_PRIOQUEUE(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyPRIOQUEUE(PrioQueuePesanan q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    /* ALGORITMA */
    return (IDX_HEAD_PRIOQUEUE(q) == IDX_UNDEF && IDX_TAIL_PRIOQUEUE(q) == IDX_UNDEF);
}
boolean isFullPRIOQUEUE(PrioQueuePesanan q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    /* ALGORITMA */
    return (IDX_HEAD_PRIOQUEUE(q) == 0 && IDX_TAIL_PRIOQUEUE(q) == CAPACITY_PRIOQUEUE-1);
}
int lengthPRIOQUEUE(PrioQueuePesanan q) {
/* Mengirimkan banyaknya elemen PRIOQUEUE. Mengirimkan 0 jika q kosong. */
    /* ALGORITMA */
    if (isEmptyPRIOQUEUE(q)) {
        return 0;
    }
    return (IDX_TAIL_PRIOQUEUE(q) - IDX_HEAD_PRIOQUEUE(q) + 1);
}
/* *** Primitif Add/Delete *** */
void enqueuePRIOQUEUE(PrioQueuePesanan *q, Pesanan val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (isEmptyPRIOQUEUE(*q)) {
        IDX_HEAD_PRIOQUEUE(*q)=0;}
    IDX_TAIL_PRIOQUEUE(*q)++;

    boolean found = false;
    int idxFound = 0;

    i = IDX_HEAD_PRIOQUEUE(*q) + 1;
    while (!found && i<=IDX_TAIL_PRIOQUEUE(*q)) {
        if ((*q).buffer[i].waktuMasuk > val.waktuMasuk) {
            found = true;
            idxFound = i;
        }
        else {
            i++;
        }

    }

    if (!found) {
        TAIL_PRIOQUEUE(*q) = val;
    }
    else {
        for ( i=IDX_TAIL_PRIOQUEUE(*q); i>idxFound; i--) {
            (*q).buffer[i] = (*q).buffer[i-1];
        } 
        (*q).buffer[idxFound] = val;

    }
    
}

void dequeuePRIOQUEUE(PrioQueuePesanan *q, Pesanan *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
    /* ALGORITMA */
    *val = HEAD_PRIOQUEUE(*q);
    if (IDX_HEAD_PRIOQUEUE(*q) == IDX_TAIL_PRIOQUEUE(*q)) {
        IDX_HEAD_PRIOQUEUE(*q) = IDX_UNDEF;
        IDX_TAIL_PRIOQUEUE(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD_PRIOQUEUE(*q)++;
    }
}

/* *** Display PRIOQUEUE *** */
void displayPRIOQUEUE(PrioQueuePesanan q) {
/* Proses : Menuliskan isi PRIOQUEUE dengan traversal, PRIOQUEUE ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika PRIOQUEUE kosong : menulis [] */
    /* KAMUS LOKAL */
    int i,j;
    /* ALGORITMA */
    if (!isEmptyPRIOQUEUE(q)) {
        printf("Daftar Pesanan yang masuk :\n");
        j=0;
        for (i = IDX_HEAD_PRIOQUEUE(q); i <= IDX_TAIL_PRIOQUEUE(q); i++) {
            
            printf("%d. waktuMasuk : %d\n", j+1, q.buffer[i].waktuMasuk);
            printf("   pickUp     : %c\n",  q.buffer[i].pickUp);
            printf("   dropOff    : %c\n",  q.buffer[i].dropOff);
            printf("   jenisItem  : %c\n",  q.buffer[i].jenisItem);
            if (q.buffer[i].jenisItem == 'P'){
                printf("   waktuHangus: %d\n",  q.buffer[i].waktuHangus);
            }
            printf("\n");
            j++;
        }
    }
}



void sortQueue(PrioQueuePesanan *Q){

/* KAMUS LOKAL */
    int i,j;
    Pesanan temp;

/* ALGORITMA */
     for (i=0; i<lengthPRIOQUEUE(*Q)-1; i++){
                for(j=IDX_HEAD_PRIOQUEUE(*Q); j<lengthPRIOQUEUE(*Q)-i-1;j++){

                    if((*Q).buffer[j].waktuMasuk > (*Q).buffer[j+1].waktuMasuk){
                        temp = (*Q).buffer[j];

                        (*Q).buffer[j] = (*Q).buffer[j+1];
                        (*Q).buffer[j+1] = temp;
                    }
                }
            }
}

