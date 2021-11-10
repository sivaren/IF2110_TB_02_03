/* Implementasi inProg_rev.h */

#include "inProg_rev.h"

/* Masih bug di insert atau display */

Address allocate_INPROG(char pickUp, char dropOff, char itemType, int perishTime){
    Address p = (Address)malloc(sizeof(ElmtInProgList));
    if(p != NULL){
        PICKUP_INPROG(p)  = pickUp;
        DROPOFF_INPROG(p)  = dropOff;
        ITEMTYPE_INPROG(p) = itemType;
        PERISHTIME_INPROG(p) = perishTime;
        NEXT_INPROG(p)  = NULL;
    }
    return p;
}

void deallocate_INPROG (Address p){
    free(p);
}

boolean isEmpty_InProg(InProgList l){
    return(FIRST_INPROG(l) == NULL);
}

void CreateInProgList(InProgList *l){
    FIRST_INPROG(*l) = NULL;
}

void insertFirst_InProgList(InProgList *l, InProgType val){
    Address p;
    p = allocate_INPROG(val.pickUp, val.dropOff, val.itemType, val.perishTime);
    if(p != NULL){
        NEXT_INPROG(p) = FIRST_INPROG(*l);
        FIRST_INPROG(*l) = p;
    }
}

void deleteFirst_InProgList(InProgList *l, InProgType *delVal){
    Address p = FIRST_INPROG(*l);
    *delVal = INFO_INPROG(p);
    FIRST_INPROG(*l) =  NEXT_INPROG(p);
    deallocate_INPROG(p);
}

void displayInProg(InProgList l){
    printf("Pesanan yang sedang diantarkan:\n");

    if(isEmpty_InProg(l)){
        printf("Tidak ada pesanan yang sedang diantar\n");
    } else {
        Address p = FIRST_INPROG(l);
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