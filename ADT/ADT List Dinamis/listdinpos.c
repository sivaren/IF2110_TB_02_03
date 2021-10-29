#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDinPos *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    BUFFER_ListDinPos(*l) = malloc(sizeof(ElTypeListDinPos)*capacity);
    CAPACITY_ListDinPos(*l) = capacity;
    for (i = 0; i < CAPACITY_ListDinPos(*l); i++) {
        ELMT_ListDinPos(*l,i) = VAL_UNDEF;
    }
}

void dealocate_ListDinPos(ListDinPos *l) {
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY_ListDinPos(l)=0; nEff(l)=0 */
    /* ALGORITMA */
    free(BUFFER_ListDinPos(*l));
    CAPACITY_ListDinPos(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length_ListDinPos(ListDinPos l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
    /* KAMUS LOKAL */
    int i, sum=0;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_ListDinPos(l); i++) {
        if (ELMT_ListDinPos(l,i) != VAL_UNDEF) {
            sum += 1;
        }
    }
    return sum;
}

/* *** Selektor INDEKS *** */
IdxTypeListDinPos getLastIdx_ListDinPos(ListDinPos l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (length(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListDinPos(ListDinPos l, IdxTypeListDinPos i) {
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* ALGORITMA */
    return (i >= 0 && i < CAPACITY_ListDinPos(l));
}
boolean isIdxEff_ListDinPos(ListDinPos l, IdxTypeListDinPos i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */
    /* ALGORITMA */
    return (i >= 0 && i < length(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty_ListDinPos(ListDinPos l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    /* ALGORITMA */
    return (length(l) == 0);
}
boolean isFull_ListDinPos(ListDinPos l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (length(l) == CAPACITY_ListDinPos(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList_ListDinPos(ListDinPos *l) {
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY_ListDinPos(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY_ListDinPos(l); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS LOKAL */
    int i, N;
    /* ALGORITMA */
    scanf("%d", &N);
    while (N<0 || N>CAPACITY_ListDinPos(*l)) {
        scanf("%d", &N);
    }
    if (N>0) {
        for (i = 0; i < N; i++) {
            scanf("%d", &ELMT_ListDinPos(*l,i));
        }
    }
}
void displayList_ListDinPos(ListDinPos l) {
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
            printf("%d", ELMT_ListDinPos(l,i));
        }
        else {
            printf("%d,", ELMT_ListDinPos(l,i));
        }
    }
    printf("]");    
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDinPos plusMinusList_ListDinPos(ListDinPos l1, ListDinPos l2, boolean plus) {
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    /* KAMUS LOKAL */
    ListDinPos l;
    int i;
    /* ALGORITMA */
    CreateListDin(&l, length(l1));
    if (plus) {
        for (i = 0; i < length(l1); i++) {
            ELMT_ListDinPos(l,i) = ELMT_ListDinPos(l1,i) + ELMT_ListDinPos(l2,i);
        }
    }
    else {
        for (i = 0; i < length(l1); i++) {
            ELMT_ListDinPos(l,i) = ELMT_ListDinPos(l1,i) - ELMT_ListDinPos(l2,i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual_ListDinPos(ListDinPos l1, ListDinPos l2) {
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
        if (ELMT_ListDinPos(l1,i) != ELMT_ListDinPos(l2,i)) {
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
IdxTypeListDinPos indexOf_ListDinPos(ListDinPos l, ElTypeListDinPos val) {
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan indeks tak terdefinisi (VAL_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */
        /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while ((ELMT_ListDinPos(l,i) != val) && (i < length(l))) {
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
void extremes_ListDinPos(ListDinPos l, ElTypeListDinPos *max, ElTypeListDinPos *min) {
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    *max = ELMT_ListDinPos(l,0);
    *min = ELMT_ListDinPos(l,0);
    for (i = 1; i < length(l); i++) {
        if (ELMT_ListDinPos(l,i) > *max) {
            *max = ELMT_ListDinPos(l,i);
        }
        if (ELMT_ListDinPos(l,i) < *min) {
            *min = ELMT_ListDinPos(l,i);
        }
    } 
}

/* ********** OPERASI LAIN ********** */
void copyList_ListDinPos(ListDinPos lIn, ListDinPos *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    CreateListDin(lOut,CAPACITY_ListDinPos(lIn));
    for (i = 0; i < length(lIn); i++) {
        ELMT_ListDinPos(*lOut,i) = ELMT_ListDinPos(lIn,i);
    }    
}
ElTypeListDinPos sumList_ListDinPos(ListDinPos l) {
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    /* KAMUS LOKAL */
    int i, sum;
    /* ALGORITMA */
    sum = 0;
    if (length(l) > 0) {
        for (i = 0; i < length(l); i++) {
            sum += ELMT_ListDinPos(l,i);
        }
        return sum;
    }
    else {
        return 0;
    }
}
int countVal_ListDinPos(ListDinPos l, ElTypeListDinPos val) {
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    /* KAMUS LOKAL */
    int i, count;
    /* ALGORITMA */
    count = 0;
    if (!isEmpty(l)) {
        for (i = 0; i < length(l); i++) {
            if (ELMT_ListDinPos(l,i) == val) {
                count += 1;
            }
        }
        return count;
    }
    else {
        return 0;
    }    
}
boolean isAllEven_ListDinPos(ListDinPos l) {
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while (i < length(l) && ELMT_ListDinPos(l,i) % 2 == 0) {
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
void sort_ListDinPos(ListDinPos *l, boolean asc) {
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
                if (ELMT_ListDinPos(*l,j) < ELMT_ListDinPos(*l,IMin)) {
                    IMin = j;
                }
            }
            Temp = ELMT_ListDinPos(*l,IMin);
            ELMT_ListDinPos(*l,IMin) = ELMT_ListDinPos(*l,i);
            ELMT_ListDinPos(*l,i) = Temp; 
        }
    }
    else {
        for (i=0; i<length(*l)-1; i++) {
            IMax = i;
            for (j = i+1; j < length(*l); j++) {
                if (ELMT_ListDinPos(*l,j) > ELMT_ListDinPos(*l,IMax)) {
                    IMax = j;
                }
            }
            Temp = ELMT_ListDinPos(*l,IMax);
            ELMT_ListDinPos(*l,IMax) = ELMT_ListDinPos(*l,i);
            ELMT_ListDinPos(*l,i) = Temp; 
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListDinPos(ListDinPos *l, ElTypeListDinPos val) {
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (length(*l) < CAPACITY_ListDinPos(*l)) {
        ELMT_ListDinPos(*l,length(*l)) = val;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast_ListDinPos(ListDinPos *l, ElTypeListDinPos *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    /* ALGORITMA */
    if (length(*l) > 0) {
        *val = ELMT_ListDinPos(*l,length(*l)-1);
        ELMT_ListDinPos(*l,length(*l)-1) = VAL_UNDEF;
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList_ListDinPos(ListDinPos *l, int num) {
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    /* ALGORITMA */
    CAPACITY_ListDinPos(*l) += num;
    BUFFER_ListDinPos(*l) = realloc(BUFFER_ListDinPos(*l), sizeof(ElTypeListDinPos)*CAPACITY_ListDinPos(*l));
}

void shrinkList_ListDinPos(ListDinPos *l, int num) {
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    /* ALGORITMA */
    CAPACITY_ListDinPos(*l) -= num;
    BUFFER_ListDinPos(*l) = realloc(BUFFER_ListDinPos(*l), sizeof(ElTypeListDinPos)*CAPACITY_ListDinPos(*l));
}

void compactList_ListDinPos(ListDinPos *l) {
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
    /* ALGORITMA */
    CAPACITY_ListDinPos(*l) = length(*l);
    BUFFER_ListDinPos(*l) = realloc(BUFFER_ListDinPos(*l), sizeof(ElTypeListDinPos)*CAPACITY_ListDinPos(*l));
}