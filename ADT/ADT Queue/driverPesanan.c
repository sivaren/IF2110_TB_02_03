#include "daftarPesanan.h"
#include <stdio.h>

int main(){
    /* KAMUS LOKAL */
    Pesanan pesanMasuk;
    PrioQueuePesanan Q;
    int timeIn;
    char pickUpPoint;
    char dropOffPoint;
    char jenisItem;
    int timeOut;  
    int i;
    /* ALGORITMA */
    
    CreatePRIOQUEUE(&Q);

    for (i=0; i<5; i++){
        scanf("%d", &timeIn);
        scanf(" %c", &pickUpPoint);
        scanf(" %c", &dropOffPoint);
        scanf(" %c", &jenisItem);

        if (jenisItem == 'P'){
            scanf("%d", &timeOut);
            // printf("%d", timeOut);
            pesanMasuk.waktuHangus = timeOut;
        }
        pesanMasuk.waktuMasuk = timeIn;
        pesanMasuk.pickUp = pickUpPoint;
        pesanMasuk.dropOff = dropOffPoint;
        pesanMasuk.jenisItem = jenisItem;

        enqueuePRIOQUEUE(&Q, pesanMasuk);
    }

    sortQueue(&Q);
    displayPRIOQUEUE(Q);
}

/* INPUT
5 A B N
3 A C P 17
5 C D P 10
2 A V X
3 X X X */


/* OUTPUT

Daftar Pesanan yang masuk :
1. waktuMasuk : 2
   pickUp     : A
   dropOff    : V
   jenisItem  : X

2. waktuMasuk : 3
   pickUp     : A
   dropOff    : C
   jenisItem  : P
   waktuHangus: 17

3. waktuMasuk : 3
   pickUp     : X
   dropOff    : X
   jenisItem  : X

4. waktuMasuk : 5
   pickUp     : A
   dropOff    : B
   jenisItem  : N

5. waktuMasuk : 5
   pickUp     : C
   dropOff    : D
   jenisItem  : P
   waktuHangus: 10
*/