#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* ALGORITMA */
    BUFFER(*l) = malloc(sizeof(ElType)*capacity);
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}
void dealocate(ListDin *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    /* ALGORITMA */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    /* ALGORITMA */
    if (NEFF(l) > 0) {
        return NEFF(l);
    }
    else {
        return 0;
    }
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    /* ALGORITMA */
    return (NEFF(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* ALGORITMA */
    return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    /* ALGORITMA */
    return (i >= 0 && i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    /* ALGORITMA */
    return (length(l) == 0);
}
boolean isFull(ListDin l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (length(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS LOKAL */
    int i, N;
    /* ALGORITMA */
    scanf("%d", &N);
    while (N<0 || N>CAPACITY(*l)) {
        scanf("%d", &N);
    }
    if (N>0) {
        for (i = 0; i < N; i++) {
            scanf("%d", &ELMT(*l,i));
        }
    }
    NEFF(*l) = N;
}
void displayList(ListDin l) {
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    printf("[");
    for (i = 0; i < NEFF(l); i++) {
        if (i == NEFF(l)-1) {
            printf("%d", ELMT(l,i));
        }
        else {
            printf("%d,", ELMT(l,i));
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    /* KAMUS LOKAL */
    ListDin l3;
    int i;
    /* ALGORITMA */
    CreateListDin(&l3, NEFF(l1));
    for (i = 0; i < length(l1); i++)
    {
        if (plus) {
            insertLast(&l3, ELMT(l1,i)+ELMT(l2,i));
        }
        else {
            insertLast(&l3, ELMT(l1,i)-ELMT(l2,i));
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    /* KAMUS LOKAL */
    int i = 0;
    boolean eq = true;
    /* ALGORITMA */
    if (NEFF(l1) != NEFF(l2)) {
        return false;
    }
    while (i<length(l1) && eq)
    {
        if (ELMT(l1,i) != ELMT(l2,i)) {
            eq = false;
        }
        i++;
    }
    return eq;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    /* KAMUS LOKAL */
    int i; boolean found = false;
    /* ALGORITMA */
    i = 0;
    while ((!found) && (i < length(l))) {
        if (ELMT(l,i) == val) {
            found = true;
        }
        else {
            i += 1;
        }
    }
    if (found) {
        return i;
    }
    else {
        return IDX_UNDEF;
    } 
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min) {
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for (i = 1; i < NEFF(l); i++) {
        if (ELMT(l,i) > *max) {
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min) {
            *min = ELMT(l,i);
        }
    } 
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    CreateListDin(lOut,CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < NEFF(lIn); i++) {
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}

ElType sumList(ListDin l) {
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    /* KAMUS LOKAL */
    int i, sum;
    /* ALGORITMA */
    sum = 0;
    if (NEFF(l) > 0) {
        for (i = 0; i < NEFF(l); i++) {
            sum += ELMT(l,i);
        }
        return sum;
    }
    else {
        return 0;
    }
}
int countVal(ListDin l, ElType val) {
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    /* KAMUS LOKAL */
    int i, count;
    /* ALGORITMA */
    count = 0;
    if (NEFF(l) > 0) {
        for (i = 0; i < NEFF(l); i++) {
            if (ELMT(l,i) == val) {
                count += 1;
            }
        }
        return count;
    }
    else {
        return 0;
    }
}
boolean isAllEven(ListDin l) {
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
    /* ALGORITMA */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while (i < NEFF(l) & ELMT(l,i) % 2 == 0) {
        i += 1;
    }
    if (i == NEFF(l) | isEmpty(l)) {
        return true;
    }
    else {
        return false;
    }
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    /* KAMUS LOKAL */
    int i, j, IMin, IMax, Temp;
    /* ALGORITMA */
    if (asc) {
        for (i=0; i<NEFF(*l)-1; i++) {
            IMin = i;
            for (j = i+1; j < NEFF(*l); j++) {
                if (ELMT(*l,j) < ELMT(*l,IMin)) {
                    IMin = j;
                }
            }
            Temp = ELMT(*l,IMin);
            ELMT(*l,IMin) = ELMT(*l,i);
            ELMT(*l,i) = Temp; 
        }
    }
    else {
        for (i=0; i<NEFF(*l)-1; i++) {
            IMax = i;
            for (j = i+1; j < NEFF(*l); j++) {
                if (ELMT(*l,j) > ELMT(*l,IMax)) {
                    IMax = j;
                }
            }
            Temp = ELMT(*l,IMax);
            ELMT(*l,IMax) = ELMT(*l,i);
            ELMT(*l,i) = Temp; 
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (NEFF(*l) < CAPACITY(*l)) {
        ELMT(*l,NEFF(*l)) = val;
        NEFF(*l) += 1;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    /* ALGORITMA */
    if (NEFF(*l) > 0) {
        *val = ELMT(*l,NEFF(*l)-1);
        NEFF(*l) -= 1;
    }    
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    /* ALGORITMA */
    CAPACITY(*l) += num;
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType)*CAPACITY(*l));
}

void shrinkList(ListDin *l, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    /* ALGORITMA */
    CAPACITY(*l) -= num;
    if (NEFF(*l) > CAPACITY(*l)) {
        NEFF(*l) = CAPACITY(*l);
    }
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType)*CAPACITY(*l));
}

void compactList(ListDin *l) {
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
    /* ALGORITMA */
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType)*CAPACITY(*l));
}