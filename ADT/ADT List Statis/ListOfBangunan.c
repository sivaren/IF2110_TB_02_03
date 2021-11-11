/* Nama: Farnas Rozaan Iraqee */
/* NIM: 13520067 */
/* Tanggal: 8 September 2021 */
/* Topik: ADT List */
/* Deskripsi: Realisasi ADT List */

#include <stdio.h>
#include "ListOfBangunan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatPos(ListOfBangunan *l) {
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_LISTSTAT; i++) {
        ELMTListOfBangunan(*l,i).nama = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListStat(ListOfBangunan l) {
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    /* KAMUS LOKAL */
    int i, sum = 0;
    /* ALGORITMA */
    for (i = 0; i < CAPACITY_LISTSTAT; i++) {
        if (ELMTListOfBangunan(l,i).nama != VAL_UNDEF) {
            sum += 1;
        }
    }
    return sum;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListStat(ListOfBangunan l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    /* ALGORITMA */
    return (i >= 0 && i < CAPACITY_LISTSTAT);
}
boolean isIdxEffListStat(ListOfBangunan l, int i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    /* ALGORITMA */
    return (i >= 0 && i < lengthListStat(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListStat(ListOfBangunan l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (lengthListStat(l) == 0); 
}
/* *** Test List penuh *** */
boolean isFullListStat(ListOfBangunan l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (lengthListStat(l) == CAPACITY_LISTSTAT);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */

void displayListStat(ListOfBangunan l) {
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
            printOneBangunan(ELMTListOfBangunan(l,i));
        }
        else {
            printOneBangunan(ELMTListOfBangunan(l,i));
            printf(",");
        }
    }
    printf("]");
}
void printOneBangunan(Bangunan b) {
    printf("(");
    printf("%c:", b.nama);
    printf("%d,", Absis(b.posisi));
    printf("%d", Ordinat(b.posisi));
    printf(")");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListStat(ListOfBangunan l, Bangunan val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 0;
    while ((ELMTListOfBangunan(l,i).nama != val.nama) & (i < lengthListStat(l))) {
        i += 1;
    }
    if (i == lengthListStat(l) | isEmptyListStat(l)) {
        return IDX_UNDEF;
    }
    else {
        return i;
    } 
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListStat(ListOfBangunan *l, Bangunan val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    /* ALGORITMA */
    if (lengthListStat(*l) < CAPACITY_LISTSTAT) {
        ELMTListOfBangunan(*l,lengthListStat(*l)) = val;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListStat(ListOfBangunan *l, Bangunan *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    /* ALGORITMA */
    if (lengthListStat(*l) > 0) {
        *val = ELMTListOfBangunan(*l,lengthListStat(*l)-1);
        ELMTListOfBangunan(*l,lengthListStat(*l)-1).nama = VAL_UNDEF;
    }
}

Bangunan PointToBangunan(Point P, ListOfBangunan LB) {
    boolean found = false;
    int i = 0;
    while (!found && i<lengthListStat(LB)) {
        if ((ELMTListOfBangunan(LB, i).posisi.X == P.X) && (ELMTListOfBangunan(LB, i).posisi.Y == P.Y) ) {
            
            found = true;
        }
        else {
            i++;
        }
    }
    return ELMTListOfBangunan(LB, i);
}

Point BangunanToPoint(Bangunan B, ListOfBangunan LB) {
    char nama = B.nama;
    Point P = NamaBangunanToPoint(nama, LB);
    return P;
}

Point NamaBangunanToPoint(char x, ListOfBangunan LB) {
    boolean found = false;
    int i = 0;
    Point pnt;
    while (!found && i<lengthListStat) {
        if (ELMTListOfBangunan(LB, i).nama == x) {
            pnt = ELMTListOfBangunan(LB, i).posisi;
        }
        else {
            i++;
        }
}
    return pnt;
}


char PointToNamaBangunan(Point P, ListOfBangunan LB){

    Bangunan temp = PointToBangunan(P, LB);
    return temp.nama;

}

void updateCurrentBangunan(Point P, ListOfBangunan LB, Bangunan *CurrentBangunan) {
    *CurrentBangunan = PointToBangunan(P, LB);

}