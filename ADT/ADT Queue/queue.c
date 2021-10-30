#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    /* ALGORITMA */
    IDX_HEAD_QUEUE(*q) = IDX_UNDEF;
    IDX_TAIL_QUEUE(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    /* ALGORITMA */
    return (IDX_HEAD_QUEUE(q) == IDX_UNDEF && IDX_TAIL_QUEUE(q) == IDX_UNDEF);
}
boolean isFullQueue(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    /* ALGORITMA */
    return (IDX_HEAD_QUEUE(q) == 0 && IDX_TAIL_QUEUE(q) == CAPACITY_QUEUE-1);
}
int lengthQueue(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* ALGORITMA */
    if (isEmptyQueue(q)) {
        return 0;
    }
    return (IDX_TAIL_QUEUE(q) - IDX_HEAD_QUEUE(q) + 1);
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypeQueue val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    if (isEmptyQueue(*q)) {
        IDX_HEAD_QUEUE(*q)=0;
    } else if (IDX_TAIL_QUEUE(*q) == CAPACITY_QUEUE-1) {
        i = IDX_HEAD_QUEUE(*q); j = 0;
        do {
            (*q).buffer[j] = (*q).buffer[i];
            i++; j++;
        } while (i <= IDX_TAIL_QUEUE(*q));
        IDX_TAIL_QUEUE(*q) = lengthQueue(*q)-1; IDX_HEAD_QUEUE(*q) = 0; 
    }
    IDX_TAIL_QUEUE(*q)++;
    TAIL_QUEUE(*q) = val;
}

void dequeue(Queue *q, ElTypeQueue *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
    /* ALGORITMA */
    *val = HEAD_QUEUE(*q);
    if (IDX_HEAD_QUEUE(*q) == IDX_TAIL_QUEUE(*q)) {
        IDX_HEAD_QUEUE(*q) = IDX_UNDEF;
        IDX_TAIL_QUEUE(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD_QUEUE(*q)++;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    printf("[");
    if (!isEmptyQueue(q)) {
        for (i = IDX_HEAD_QUEUE(q); i <= IDX_TAIL_QUEUE(q); i++) {
            if (i == IDX_TAIL_QUEUE(q)) {
                printf("%d", q.buffer[i]);
            } else {
                printf("%d,", q.buffer[i]);
            }
        }
    }
    printf("]");
}