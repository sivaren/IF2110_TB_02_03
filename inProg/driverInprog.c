#include <stdio.h>
#include <stdlib.h>
#include "inProg_rev.c"

/* 
NOTE: CARA PAKAI
- input pertama: [pickup] [dropoff] [itemType] [perish time]
- input kedua/ketiga bawaan dari source code (karena dicoba input user ada bug, 
  tapi jika ditentukan di source code, code berjalan lancar)   
 */

int main(){
    InProgList list;
    char pickUp;
    char dropOff; 
    char itemType;
    int perishTime;
    InProgType inProgVar;

    CreateInProgList(&list);

    scanf("%c %c %c %d", &pickUp, &dropOff, &itemType, &perishTime);
    inProgVar.pickUp = pickUp;
    inProgVar.dropOff = dropOff;
    inProgVar.itemType = itemType;
    inProgVar.perishTime = perishTime; 
    insertFirst_InProgList(&list, inProgVar);
    
    printf("===\n");
    displayInProg(list);
    printf("===\n");

    printf("Insert list (Y X H -1)\n");
    inProgVar.pickUp = 'Y';
    inProgVar.dropOff = 'X';
    inProgVar.itemType = 'H';
    inProgVar.perishTime = -1; 
    insertFirst_InProgList(&list, inProgVar);
    
    printf("===\n");
    displayInProg(list);
    printf("===\n");

    printf("Insert list (Q R P 5)\n");
    inProgVar.pickUp = 'Q';
    inProgVar.dropOff = 'R';
    inProgVar.itemType = 'P';
    inProgVar.perishTime = 5; 
    insertFirst_InProgList(&list, inProgVar);
    
    printf("===\n");
    displayInProg(list);
    printf("===\n");

    // testing delete elemen in progress list
    InProgType delVal;
    deleteFirst_InProgList(&list, &delVal);
    printf("Isi list setelah delete ke-1\n");
    displayInProg(list);
    
    printf("===\n");
    printf("Isi dari elemen yang di delete\n");
    printf("Pickup      : %c\n", delVal.pickUp);
    printf("Dropoff     : %c\n", delVal.dropOff);
    printf("Item type   : %c\n", delVal.itemType);
    printf("Perish time : %d\n", delVal.perishTime);
    printf("===\n");

    deleteFirst_InProgList(&list, &delVal);
    printf("Isi list setelah delete ke-2\n");
    displayInProg(list);
    
    printf("===\n");
    printf("Isi dari elemen yang di delete\n");
    printf("Pickup      : %c\n", delVal.pickUp);
    printf("Dropoff     : %c\n", delVal.dropOff);
    printf("Item type   : %c\n", delVal.itemType);
    printf("Perish time : %d\n", delVal.perishTime);

    return 0;
}