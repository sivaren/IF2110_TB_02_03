/* Nama: Farnas Rozaan Iraqee */
/* NIM: 13520067 */
/* Tanggal: 8 September 2021 */
/* Topik: ADT List */
/* Deskripsi: Realisasi ADT List */

#include <stdio.h>
#include "ListPos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatPos(ListStatPos *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_LISTSTAT; i++) {
        ELMTListStat(*l,i) = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListStat(ListStatPos l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* KAMUS LOKAL */
    int i, sum = 0;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_LISTSTAT; i++) {
        if (ELMTListStat(l,i) != VAL_UNDEF) {
            sum += 1;
        }
    }
    return sum;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListStat(ListStatPos l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* ALGORITMA */
    return (i >= 0 && i < CAPACITY_LISTSTAT);
}
boolean isIdxEffListStat(ListStatPos l, int i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    /* ALGORITMA */
    return (i >= 0 && i < lengthListStat(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListStat(ListStatPos l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (lengthListStat(l) == 0); 
}
/* *** Test List penuh *** */
boolean isFullListStat(ListStatPos l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (lengthListStat(l) == CAPACITY_LISTSTAT);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListStat(ListStatPos *l) {
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    /* KAMUS LOKAL */
    int n, i, temp, j;
    /* ALGORITMA */
    CreateListStatPos(l);
    i = 0;
    scanf("%d", &n);
    while (n < 0 | n > CAPACITY_LISTSTAT) {
        scanf("%d", &n);
        i += 1;
    }
    if (n > 0) {
        for (i = 0; i < n; i++) {
            scanf("%d", &temp);
            j = 0;
            while (temp <= 0) {
                scanf("%d", &temp);
            }
            ELMTListStat(*l,i) = temp;
        }
    }
}
void displayListStat(ListStatPos l) {
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    printf("[");
    for (i = 0; i < lengthListStat(l); i++) {
        if (i == lengthListStat(l)-1) {
            printf("%d", ELMTListStat(l,i));
        }
        else {
            printf("%d,", ELMTListStat(l,i));
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatPos plusMinusTabListStat(ListStatPos l1, ListStatPos l2, boolean plus) {
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    /* KAMUS LOKAL */
    int i;
    ListStatPos l3;
    /* ALGORITMA */
    CreateListStatPos(&l3);
    if (plus) {
        for (i = 0; i < lengthListStat(l1); i++) {
            ELMTListStat(l3,i) = ELMTListStat(l1,i) + ELMTListStat(l2,i);
        }
    }
    else {
        for (i = 0; i < lengthListStat(l1); i++) {
            ELMTListStat(l3,i) = ELMTListStat(l1,i) - ELMTListStat(l2,i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListStatEqual(ListStatPos l1, ListStatPos l2) {
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (lengthListStat(l1) == lengthListStat(l2)) {
        for (i=0; i < lengthListStat(l1); i++) {
            if (ELMTListStat(l1,i) != ELMTListStat(l2,i)) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListStat(ListStatPos l, ElTypeListStat val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while ((ELMTListStat(l,i) != val) & (i < lengthListStat(l))) {
        i += 1;
    }
    if (i == lengthListStat(l) | isEmptyListStat(l)) {
        return IDX_UNDEF;
    }
    else {
        return i;
    } 
}

/* ********** NILAI EKSTREM ********** */
void extremesListStat(ListStatPos l, ElTypeListStat *max, ElTypeListStat *min) {
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    *max = ELMTListStat(l,0);
    *min = ELMTListStat(l,0);
    for (i = 1; i < lengthListStat(l); i++) {
        if (ELMTListStat(l,i) > *max) {
            *max = ELMTListStat(l,i);
        }
        if (ELMTListStat(l,i) < *min) {
            *min = ELMTListStat(l,i);
        }
    } 
}

/* ********** OPERASI LAIN ********** */
boolean isAllEvenListStat(ListStatPos l) {
/* Menghailkan true jika semua elemen l genap */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < lengthListStat(l); i++) {
        if (ELMTListStat(l,i) % 2 != 0) {
            return false;
        }
    }
    return true;
    
}

/* ********** SORTING ********** */
void sortListStat(ListStatPos *l, boolean asc) {
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    /* KAMUS LOKAL */
    int i, j, IMin, IMax, Temp;
    /* ALGORITMA */
    if (asc) {
        for (i=0; i<lengthListStat(*l)-1; i++) {
            IMin = i;
            for (j = i+1; j < lengthListStat(*l); j++) {
                if (ELMTListStat(*l,j) < ELMTListStat(*l,IMin)) {
                    IMin = j;
                }
            }
            Temp = ELMTListStat(*l,IMin);
            ELMTListStat(*l,IMin) = ELMTListStat(*l,i);
            ELMTListStat(*l,i) = Temp; 
        }
    }
    else {
        for (i=0; i<lengthListStat(*l)-1; i++) {
            IMax = i;
            for (j = i+1; j < lengthListStat(*l); j++) {
                if (ELMTListStat(*l,j) > ELMTListStat(*l,IMax)) {
                    IMax = j;
                }
            }
            Temp = ELMTListStat(*l,IMax);
            ELMTListStat(*l,IMax) = ELMTListStat(*l,i);
            ELMTListStat(*l,i) = Temp; 
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListStat(ListStatPos *l, ElTypeListStat val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (lengthListStat(*l) < CAPACITY_LISTSTAT) {
        ELMTListStat(*l,lengthListStat(*l)) = val;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListStat(ListStatPos *l, ElTypeListStat *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    /* ALGORITMA */
    if (lengthListStat(*l) > 0) {
        *val = ELMTListStat(*l,lengthListStat(*l)-1);
        ELMTListStat(*l,lengthListStat(*l)-1) = VAL_UNDEF;
    }
}