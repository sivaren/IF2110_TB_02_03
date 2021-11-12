/* Implementasi inProg_rev.h */

#include "inProg_rev.h"

/* Masih bug di insert atau display */

AddressInProg allocate_INPROG(char pickUp, char dropOff, char itemType, int perishTime){
    AddressInProg p = (AddressInProg)malloc(sizeof(ElmtInProgList));
    if(p != NULL){
        PICKUP_INPROG(p)  = pickUp;
        DROPOFF_INPROG(p)  = dropOff;
        ITEMTYPE_INPROG(p) = itemType;
        PERISHTIME_INPROG(p) = perishTime;
        NEXT_INPROG(p) = NULL;
    }
    return p;
}
/* Alokasi nodeInProg baru untuk inprogresslist */

void deallocate_INPROG (AddressInProg p){
    free(p);
}
/* Dealokasi suatu nodeInProg pada inprogresslist */

boolean isEmpty_InProg(InProgList l){
    return(FIRST_INPROG(l) == NULL);
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isHeavyAvail(InProgList l){
    if(isEmpty_InProg(l)){
        return false;
    } else {
        AddressInProg p;
        boolean found = false;
        p = FIRST_INPROG(l);
        do{
            if(ITEMTYPE_INPROG(p) == 'H'){
                found = true;
            }
            p = NEXT_INPROG(p);
        } while(p != NULL && !found);
        return found;
    }
}
/* Mengirim true jika terdapat heavy item pada list  */

boolean isPerishAvail(InProgList l){
    if(isEmpty_InProg(l)){
        return false;
    } else {
        AddressInProg p;
        boolean found = false;
        p = FIRST_INPROG(l);
        do{
            if(ITEMTYPE_INPROG(p) == 'P'){
                found = true;
            }
            p = NEXT_INPROG(p);
        } while(p != NULL && !found);
        return found;
    }
}
/* Mengirim true jika terdapat perish item pada list  */

boolean isPerishExpiredAvail(InProgList l){
    if(!isPerishAvail(l)){
        return false;
    } else {
        AddressInProg p;
        boolean found = false;
        p = FIRST_INPROG(l);

        do{
            if(ITEMTYPE_INPROG(p) == 'P' && PERISHTIME_INPROG(p) <= 0){
                found = true;
            }
            p = NEXT_INPROG(p);
        } while(p != NULL && !found);
        return found;
    }
}
/* Mengirim true jika terdapat perishable item yang telah expired pada list  */

void CreateInProgList(InProgList *l){
    FIRST_INPROG(*l) = NULL;
}
/* Mengirim true jika list kosong */

void insertFirst_InProgList(InProgList *l, InProgType val){
    AddressInProg p;
    p = allocate_INPROG(val.pickUp, val.dropOff, val.itemType, val.perishTime);
    if(p != NULL){
        NEXT_INPROG(p) = FIRST_INPROG(*l);
        FIRST_INPROG(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void deleteFirst_InProgList(InProgList *l, InProgType *delVal){
    AddressInProg p = FIRST_INPROG(*l);
    *delVal = INFO_INPROG(p);
    FIRST_INPROG(*l) =  NEXT_INPROG(p);
    deallocate_INPROG(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

void adjustPerishTime(InProgList *l){
    if(isPerishAvail(*l)){
        AddressInProg p;
        p = FIRST_INPROG(*l);
        
        do{
            if(ITEMTYPE_INPROG(p) == 'P'){
                PERISHTIME_INPROG(p) = PERISHTIME_INPROG(p) - 1;
                printf("waktu perish tujuan %c = %d\n", DROPOFF_INPROG(p), PERISHTIME_INPROG(p));
            }
            p = NEXT_INPROG(p);
        } while(p != NULL);
    };
}
/* Adjust waktu hangus perish item */
/* Apabila waktu habis, maka perish item akan dihapus darii list */
/* Jika waktu != 0, maka perishTime akan dikurang 1 */

void deletePerishItem(InProgList *l, InProgType *delVal){

    while(isPerishExpiredAvail(*l)){
        AddressInProg p;
        AddressInProg prev;
        
        p = FIRST_INPROG(*l);
        prev = NULL;

        while(p != NULL && ITEMTYPE_INPROG(p) != 'P' && PERISHTIME_INPROG(p) > 0){
            prev = p;
            p = NEXT_INPROG(p);
        };
        // ITEMTYPE_INPROG(p) == 'P' && PERISHTIME_INPROG(p) <= 0

        if(prev == NULL){
            FIRST_INPROG(*l) =  NEXT_INPROG(p);    
        } else {
            NEXT_INPROG(prev) = NEXT_INPROG(p);
        }
        *delVal = INFO_INPROG(p);
        deallocate_INPROG(p);
    };
}

void displayInProg(InProgList l){
    printf("Pesanan yang sedang diantarkan:\n");

    if(isEmpty_InProg(l)){
        printf("Tidak ada pesanan yang sedang diantar\n");
    } else {
        AddressInProg p = FIRST_INPROG(l);
        int count = 0;

        do{
            printf("%d. ", count+1);
            if(ITEMTYPE_INPROG(p) == 'N'){
                printf("Normal Item ");
            }
            else if(ITEMTYPE_INPROG(p) == 'H'){
                printf("Heavy Item ");
            }
            else if(ITEMTYPE_INPROG(p) == 'P'){
                printf("Perishable Item ");
            }

            printf("(Tujuan: %c)\n", DROPOFF_INPROG(p));
            p = NEXT_INPROG(p);
            count++;
        } while(p != NULL);
    }
}
/* Menampilkan isi inprogresslist */