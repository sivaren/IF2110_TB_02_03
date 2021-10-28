// Nama    : Suryanto
// NIM     : 13520059  

/* File : list_linked.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi Address dengan pointer */
/* ElType adalah integer */


#include "boolean.h"
#include "node.h"
#include "list_linked.h"
#include <stdio.h>


/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}


/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    /* Mengirim true jika list kosong */
    return FIRST(l) == NULL;
}


/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan nilai elemen l pada indeks idx */

    //KAMUS 
    int i;
    Address P;

    //ALGORITMA
    i=0;
    P = FIRST(l);

    while (i<idx){
        i++;
        P = NEXT(P);
    }

    return INFO(P);

}


void setElmt(List *l, int idx, ElType val){
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

    //KAMUS 
    int i;
    Address P;

    //ALGORITMA
    i=0;
    P = FIRST(*l);

    while (i<idx){
        i++;
        P = NEXT(P);
    }

    INFO(P) = val;
}

int indexOf(List l, ElType val){
    /* I.S. l, val terdefinisi */
    /* F.S. Mencari apakah ada elemen list l yang bernilai val */
    /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
    /* Mengembalikan IDX_UNDEF jika tidak ditemukan */

    //KAMUS
    int i = 0;
    Address P;
    boolean found;

    //ALGORITMA
    i=0;
    P = FIRST(l);
    found =false;

    while (!found && P !=NULL){
        if (INFO(P) == val) found=true;
        else{
            i++;
            P = NEXT(P);
        }    
    }

    if (!found){
        i = IDX_UNDEF;
    }

    return i;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S.= F.S. */

    //KAMUS
    Address P;
    
    //ALGORITMA
    P = newNode(val);

    if (isEmpty(*l)) NEXT(P) = NULL;
    else            NEXT(P) = FIRST(*l);
    
    FIRST(*l) = P; 
}

void insertLast(List *l, ElType val){
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    //KAMUS
    Address P,last;
    
    //ALGORITMA
    if (isEmpty(*l)) insertFirst(l, val);
    else{
        P = newNode(val);
        last = FIRST(*l);

        while (NEXT(last) != NULL){
            last = NEXT(last);
        }
        NEXT(last) = P; 
    }
}


void insertAt(List *l, ElType val, int idx){
    /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
    /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    //KAMUS
    Address P,temp;
    int i;
    
    //ALGORITMA
    if (idx==0) insertFirst(l, val);
    else{
        int i = 0;
        P = newNode(val);
        temp = FIRST(*l);

        if (idx<=length(*l)){
             //cari node sebelum node[idx]
            while (i< idx-1){
                i++;
                temp = NEXT(temp);
            }

            NEXT(P) = NEXT(temp);
            NEXT(temp) = P;
            }
       
    }

}


/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    /* I.S. List l tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen pertama di-dealokasi */

    //KAMUS LOKAL
    Address P;
    
    //ALGORITMA
    P = FIRST(*l);
    *val = INFO(P);

    if (length(*l)==1) FIRST(*l) = NULL;
    else    FIRST(*l) = NEXT(P);
    
    free(P);
}

void deleteLast(List *l, ElType *val){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen terakhir di-dealokasi */

    //KAMUS
    Address P,temp;

    //ALGORITMA

    if (length(*l) == 1) deleteFirst(l,val);
    else{
        temp = FIRST(*l);
        P = NULL;
        while (NEXT(temp) != NULL){
            P = temp;
            temp = NEXT(temp);
        }

        NEXT(P) = NULL;
        *val = INFO(temp);
        free(temp);
    }
    
}


void deleteAt(List *l, int idx, ElType *val){
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. val diset dengan elemen l pada indeks ke-idx. */
    /*      Elemen l pada indeks ke-idx dihapus dari l */

    //KAMUS
    Address P,temp;
    int i;

    //ALGORITMA
    if (idx == 0 ) deleteFirst(l,val);
    else{
        temp = FIRST(*l);
        i = 0;

        while (i<idx-1){
            temp = NEXT(temp);
            i++;
        }

        P = NEXT(temp);
        *val = INFO(P);
        NEXT(temp) = NEXT(P);
        free(P);
    }
}



/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    // void printInfo(List l);
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

    //KAMUS
    int i;
    Address P;

    //ALGORITMA
    P = FIRST(l);
    i=0;
    // printf("%d", length(l));
   
    printf("[");
    while (i<length(l)){
        if (NEXT(P)!= NULL)  printf("%d," , INFO(P));
        else printf("%d" , INFO(P));
        P = NEXT(P);
        i++;
    }
    printf("]");


}


int length(List l){
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

    //KAMUS
    int len;
    Address P;

    //ALGORITMA
    if (isEmpty(l)) len = 0;
    else{
        P = FIRST(l);
        len = 1;
        while(NEXT(P)!=NULL){
            len++;
            P = NEXT(P);
        }
    }
    return len;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

    //KAMUS LOKAL
    Address temp;
    boolean found;

    //ALGORITMA
    found = false;
    if (!isEmpty(L)) {
        temp = FIRST(L);
        while (temp != NULL && !found){
            if (temp == P) found = true;
            else temp = NEXT(temp);
        }
    }
    return found;

}

Address searchPrec(List L, ElType X){
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

    if (length(L) > 1){
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
ElType max(List l){
/* Mengirimkan nilai info(P) yang maksimum */

    //KAMUS LOKAL
    Address P;
    ElType max_value;
    int i;

    //ALGORITMA
    max_value = INFO(FIRST(l));
    P = NEXT(FIRST(l));
    for (i = 0; i <length(l)-1; i++){
        if (INFO(P) > max_value) max_value = INFO(P);
        P = NEXT(P);
    }
    
    return max_value;
}

Address adrMax(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    //ALGORITMA
    if (length(l)==1) return FIRST(l);
    else return NEXT(searchPrec(l,max(l)));
}

ElType min(List l){
/* Mengirimkan nilai info(P) yang minimum */

    //KAMUS LOKAL
    Address P;
    ElType min_value;
    int i;

    //ALGORITMA
    min_value = INFO(FIRST(l));
    P = NEXT(FIRST(l));
    for (i = 0; i <length(l)-1; i++){
        if (INFO(P) < min_value) min_value = INFO(P);
        P = NEXT(P);
    }
    
    return min_value;
}

Address adrMin(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    //ALGORITMA
    if (length(l)==1) return FIRST(l);
    else return NEXT(searchPrec(l,min(l)));
}

float average(List l){
/* Mengirimkan nilai rata-rata info(P) */
    //KAMUS LOKAL
    float sum;
    Address P;
    int i;
    
    //ALGORITMA
    P = FIRST(l);
    sum = 0;

    for (i=0; i<length(l); i++){
        
        sum += INFO(P);
        P = NEXT(P);
    }
    
    return (sum/length(l));
}


/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
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
    CreateList(&l3);

    //isi l3 dengan l1
    P = FIRST(l1);
    for (i = 0;  i<length(l1) ; i++){
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }

    //isi l3 dengan l2
    P = FIRST(l2);
    for (i = 0;  i<length(l2) ; i++){
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    
    return l3;
}


void delAll(List *l){
/* Delete semua elemen list dan alamat elemen di-dealokasi */

    //KAMUS LOKAL
    ElType val;

    //ALGORITMA
    while (!isEmpty(*l)){
        deleteFirst(l, &val);
    }
   
}




void inverseList(List *l){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

    //KAMUS LOKAL
    Address P;
    ElType temp[length(*l)];
    int i;

    //ALGORITMA
    P = FIRST(*l);
    for (i=length(*l)-1; i>=0; i--){
        temp[i] = INFO(P);
        P=NEXT(P);
    }

    for (i=0; i< length(*l); i++){
        setElmt(l,i,temp[i]);
    }
}


List fInverseList(List l){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

    //KAMUS LOKAL
    List l2;
    CreateList(&l2);
    //ALGORITMA
    l2 = fCopyList(l);
    inverseList(&l2);

    return l2;
}


void copyList(List *l1, List *l2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    FIRST(*l2) = FIRST(*l1);
}


List fCopyList(List l){
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
    CreateList(&l2);
    i =0;
    flag = true;

    while (i< length(l) && flag){
        P = newNode(getElmt(l,i));
        if (P==NULL){
            delAll(&l2);
            flag = false;
        }

        else{
            insertLast(&l2, INFO(P));
        }
        i++;
    }
    return l2;
}


void cpAllocList(List lIn, List *lOut){
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */

    //KAMUS LOKAL
    CreateList(lOut);
    //ALGORITMA
    *lOut = fCopyList(lIn);

}


void splitList(List *l1, List *l2, List l){
    /* I.S. l mungkin kosong */
    /* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
    /* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
    /* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
    /* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */

    //KANUS LOKAL
    int i,tempLen;
    Address P;

    //ALGORITMA
    CreateList(l1);
    CreateList(l2);
    i = 0;
    P = FIRST(l);
    
    tempLen = (length(l) /2);
   

    for (i = 0; i<length(l); i++){
        if (i<tempLen) insertLast(l1, INFO(P));
        else insertLast(l2, INFO(P));
        P = NEXT(P);
    }
}

