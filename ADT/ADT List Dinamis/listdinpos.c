#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    BUFFER(*l) = malloc(sizeof(ElType)*capacity);
    CAPACITY(*l) = capacity;
    for (i = 0; i < CAPACITY(*l); i++) {
        ELMT(*l,i) = VAL_UNDEF;
    }
}

void dealocate(ListDin *l) {
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */
    /* ALGORITMA */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
    /* KAMUS LOKAL */
    int i, sum=0;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY(l); i++) {
        if (ELMT(l,i) != VAL_UNDEF) {
            sum += 1;
        }
    }
    return sum;
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (length(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* ALGORITMA */
    return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */
    /* ALGORITMA */
    return (i >= 0 && i < length(l));
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
      IdxMin satu per satu diakhiri enter */
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
    for (i = 0; i < length(l); i++) {
        if (i == length(l)-1) {
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
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    /* KAMUS LOKAL */
    ListDin l;
    int i;
    /* ALGORITMA */
    CreateListDin(&l, length(l1));
    if (plus) {
        for (i = 0; i < length(l1); i++) {
            ELMT(l,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    }
    else {
        for (i = 0; i < length(l1); i++) {
            ELMT(l,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    /* ALGORITMA */
        /* KAMUS LOKAL */
    int i=0;
    boolean eq=true;
    /* ALGORITMA */
    if (length(l1) != length(l2)) {
        return false;
    }
    while (i<length(l1) && eq) {
        if (ELMT(l1,i) != ELMT(l2,i)) {
            eq = false;
        }
        else {
            i++;
        }
    }
    return eq;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan indeks tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */
        /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while ((ELMT(l,i) != val) && (i < length(l))) {
        i += 1;
    }
    if (i == length(l) || isEmpty(l)) {
        return IDX_UNDEF;
    }
    else {
        return i;
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
    for (i = 1; i < length(l); i++) {
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
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    CreateListDin(lOut,CAPACITY(lIn));
    for (i = 0; i < length(lIn); i++) {
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
    if (length(l) > 0) {
        for (i = 0; i < length(l); i++) {
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
    if (!isEmpty(l)) {
        for (i = 0; i < length(l); i++) {
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
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while (i < length(l) && ELMT(l,i) % 2 == 0) {
        i += 1;
    }
    if (i == length(l) || isEmpty(l)) {
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
        for (i=0; i<length(*l)-1; i++) {
            IMin = i;
            for (j = i+1; j < length(*l); j++) {
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
        for (i=0; i<length(*l)-1; i++) {
            IMax = i;
            for (j = i+1; j < length(*l); j++) {
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
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (length(*l) < CAPACITY(*l)) {
        ELMT(*l,length(*l)) = val;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    /* ALGORITMA */
    if (length(*l) > 0) {
        *val = ELMT(*l,length(*l)-1);
        ELMT(*l,length(*l)-1) = VAL_UNDEF;
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num) {
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    /* ALGORITMA */
    CAPACITY(*l) += num;
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType)*CAPACITY(*l));
}

void shrinkList(ListDin *l, int num) {
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    /* ALGORITMA */
    CAPACITY(*l) -= num;
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType)*CAPACITY(*l));
}

void compactList(ListDin *l) {
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
    /* ALGORITMA */
    CAPACITY(*l) = length(*l);
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType)*CAPACITY(*l));
}