#include "list_linked.h"
#include "node.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinked(List *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    /* ALGORITMA */
    *l = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_ListLinked(List l) {
/* Mengirim true jika list kosong */
    /* ALGORITMA */
    return l==NULL; 
}

/****************** GETTER SETTER ******************/
ElTypeLinked getElmt_ListLinked(List l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS LOKAL */
    int ctr = 0;
    Address p;
    /* ALGORITMA */
    p = l;
    while (ctr<idx)
    {
        ctr++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt_ListLinked(List *l, int idx, ElTypeLinked val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS LOKAL */
    int ctr = 0;
    Address p;
    /* ALGORITMA */
    p = *l;
    while (ctr<idx)
    {
        ctr++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf_ListLinked(List l, ElTypeLinked val) {
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    /* KAMUS LOKAL */
    int idx = 0;
    Address p;
    boolean found = false;
    /* ALGORITMA */
    p = l;
    while (p != NULL & !found)
    {
        if (INFO(p)==val)
        {
            found = true;
        }
        else
        {
            idx++;
            p = NEXT(p);
        }
    }
    if (found)
    {
        return idx;
    }
    else
    {
        return IDX_UNDEF;
    }
}   

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst_ListLinked(List *l, ElTypeLinked val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL)
    {
        NEXT(p) = *l;
        FIRST(*l) = p;
    }
}

void insertLast_ListLinked(List *l, ElTypeLinked val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p, last;
    /* ALGORITMA */
    if (isEmpty_ListLinked(*l))
    {
        insertFirst_ListLinked(l, val);
    }
    else
    {
        p = newNode(val);
        if (p != NULL)
        {
            last = *l;
            while (NEXT(last) != NULL)
            {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }       
    }
}

void insertAt_ListLinked(List *l, ElTypeLinked val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    int ctr;
    Address p, loc;
    /* ALGORITMA */
    if (idx==0)
    {
        insertFirst_ListLinked(l, val);
    }
    else
    {
        p = newNode(val);
        if (p != NULL)
        {
            ctr = 0;
            loc = *l;
            while (ctr<idx-1)
            {
                ctr++;
                loc = NEXT(loc); 
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst_ListLinked(List *l, ElTypeLinked *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = *l;
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
void deleteLast_ListLinked(List *l, ElTypeLinked *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS LOKAL */
    Address p,loc;
    /* ALGORITMA */
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL)
    {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL)
    {
        *l = NULL;
    }
    else
    {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt_ListLinked(List *l, int idx, ElTypeLinked *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS LOKAL */
    int ctr;
    Address p,loc;
    /* ALGORITMA */
    if (idx==0)
    {
        deleteFirst_ListLinked(l, val);
    }
    else
    {
        ctr = 0;
        loc = *l;
        while (ctr<idx-1)
        {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p); 
    }
}   

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList_ListLinked(List l) {
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    printf("[");
    p = l;
    while (p != NULL)
    {
        if (NEXT(p)==NULL)
        {
            printf("%d", INFO(p));
        }
        else
        {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

int length_ListLinked(List l) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* KAMUS LOKAL */
    int ctr=0;
    Address p;
    /* ALGORITMA */
    p = l;
    while (p != NULL)
    {
        ctr++;
        p = NEXT(p);
    }
    return ctr;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch_ListLinked(List L, Address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

    //KAMUS LOKAL
    Address temp;
    boolean found;

    //ALGORITMA
    found = false;
    if (!isEmpty_ListLinked(L)) {
        temp = FIRST(L);
        while (temp != NULL && !found){
            if (temp == P) found = true;
            else temp = NEXT(temp);
        }
    }
    return found;

}

Address searchPrec_ListLinked(List L, ElTypeLinked X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    
    //KAMUS LOKAL
    Address P,temp;
    boolean found;

    //ALGORITMA
    P = NULL;
    temp = FIRST(L);
    found = false;

    if (length_ListLinked(L) > 1){
        while ((NEXT(temp) != NULL) && !found){
            if (INFO(NEXT(temp)) == X){
                P = temp;
                found = true;
            }
            else{
                temp = NEXT(temp);
            }
        }
    }
    return P;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElTypeLinked max_ListLinked(List l){
/* Mengirimkan nilai info(P) yang maksimum */

    //KAMUS LOKAL
    Address P;
    ElTypeLinked max_value;
    int i;

    //ALGORITMA
    max_value = INFO(FIRST(l));
    P = NEXT(FIRST(l));
    for (i = 0; i <length_ListLinked(l)-1; i++){
        if (INFO(P) > max_value) max_value = INFO(P);
        P = NEXT(P);
    }
    
    return max_value;
}

Address adrMax_ListLinked(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    //ALGORITMA
    if (length_ListLinked(l)==1) return FIRST(l);
    else return NEXT(searchPrec_ListLinked(l,max_ListLinked(l)));
}

ElTypeLinked min_ListLinked(List l){
/* Mengirimkan nilai info(P) yang minimum */

    //KAMUS LOKAL
    Address P;
    ElTypeLinked min_value;
    int i;

    //ALGORITMA
    min_value = INFO(FIRST(l));
    P = NEXT(FIRST(l));
    for (i = 0; i <length_ListLinked(l)-1; i++){
        if (INFO(P) < min_value) min_value = INFO(P);
        P = NEXT(P);
    }
    
    return min_value;
}

Address adrMin_ListLinked(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    //ALGORITMA
    if (length_ListLinked(l)==1) return FIRST(l);
    else return NEXT(searchPrec_ListLinked(l,min_ListLinked(l)));
}

float average_ListLinked(List l){
/* Mengirimkan nilai rata-rata info(P) */
    //KAMUS LOKAL
    float sum;
    Address P;
    int i;
    
    //ALGORITMA
    P = FIRST(l);
    sum = 0;

    for (i=0; i<length_ListLinked(l); i++){
        
        sum += INFO(P);
        P = NEXT(P);
    }
    
    return (sum/length_ListLinked(l));
}

/****************** PROSES TERHADAP LIST ******************/
List concat_ListLinked(List l1, List l2) {
    /* I.S. l1 dan l2 sembarang */
    /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
    /* Konkatenasi dua buah list : l1 dan l2    */
    /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
    /* Tidak ada alokasi/dealokasi pada prosedur ini */

    //KAMUS
    int i;
    Address P;
    List l3;

    //ALGORITMA
    CreateListLinked(&l3);

    //isi l3 dengan l1
    P = FIRST(l1);
    for (i = 0;  i<length_ListLinked(l1) ; i++){
        insertLast_ListLinked(&l3, INFO(P));
        P = NEXT(P);
    }

    //isi l3 dengan l2
    P = FIRST(l2);
    for (i = 0;  i<length_ListLinked(l2) ; i++){
        insertLast_ListLinked(&l3, INFO(P));
        P = NEXT(P);
    }
    
    return l3;
}


void delAll_ListLinked(List *l){
/* Delete semua elemen list dan alamat elemen di-dealokasi */

    //KAMUS LOKAL
    ElTypeLinked val;

    //ALGORITMA
    while (!isEmpty_ListLinked(*l)){
        deleteFirst_ListLinked(l, &val);
    }
   
}

void inverseList_ListLinked(List *l){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

    //KAMUS LOKAL
    Address P;
    ElTypeLinked temp[length_ListLinked(*l)];
    int i;

    //ALGORITMA
    P = FIRST(*l);
    for (i=length_ListLinked(*l)-1; i>=0; i--){
        temp[i] = INFO(P);
        P=NEXT(P);
    }

    for (i=0; i< length_ListLinked(*l); i++){
        setElmt_ListLinked(l,i,temp[i]);
    }
}


List fInverseList_ListLinked(List l){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

    //KAMUS LOKAL
    List l2;
    CreateListLinked(&l2);
    //ALGORITMA
    l2 = fCopyList_ListLinked(l);
    inverseList_ListLinked(&l2);

    return l2;
}


void copyList_ListLinked(List *l1, List *l2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    FIRST(*l2) = FIRST(*l1);
}


List fCopyList_ListLinked(List l){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

    //KAMUS LOKAL
    List l2;
    Address P;
    boolean flag;
    int i;

    //ALGORITMA
    CreateListLinked(&l2);
    i =0;
    flag = true;

    while (i< length_ListLinked(l) && flag){
        P = newNode(getElmt_ListLinked(l,i));
        if (P==NULL){
            delAll_ListLinked(&l2);
            flag = false;
        }

        else{
            insertLast_ListLinked(&l2, INFO(P));
        }
        i++;
    }
    return l2;
}


void cpAllocList_ListLinked(List lIn, List *lOut){
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */

    //KAMUS LOKAL
    CreateList_ListLinked(lOut);
    //ALGORITMA
    *lOut = fCopyList_ListLinked(lIn);

}


void splitList_ListLinked(List *l1, List *l2, List l){
    /* I.S. l mungkin kosong */
    /* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
    /* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
    /* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
    /* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */

    //KANUS LOKAL
    int i,tempLen;
    Address P;

    //ALGORITMA
    CreateListLinked(l1);
    CreateListLinked(l2);
    i = 0;
    P = FIRST(l);
    
    tempLen = (length_ListLinked(l) /2);
   

    for (i = 0; i<length_ListLinked(l); i++){
        if (i<tempLen) insertLast_ListLinked(l1, INFO(P));
        else insertLast_ListLinked(l2, INFO(P));
        P = NEXT(P);
    }
}
