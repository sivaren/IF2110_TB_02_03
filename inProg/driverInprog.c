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
    InProgType delVal;

    CreateInProgList(&list);

    /* 
    Untuk tes perishable item, input -> [pickup] [dropoff] P 2
     */
    scanf("%c %c %c %d", &pickUp, &dropOff, &itemType, &perishTime);
    inProgVar.pickUp = pickUp;
    inProgVar.dropOff = dropOff;
    inProgVar.itemType = itemType;
    inProgVar.perishTime = perishTime; 
    insertFirst_InProgList(&list, inProgVar);
    
    printf("===\n");
    displayInProg(list);
    printf("===\n");

    // tes adjust dan delet perish item pada elemen pertama
    printf("apply adjustPerishTime & deletePerishItem\n");
    adjustPerishTime(&list);
    deletePerishItem(&list, &delVal);

    printf("===\n");
    displayInProg(list);
    printf("===\n");

    if(isHeavyAvail(list)){
      printf("Berat cuk!\n===\n");
    }
    if(isPerishAvail(list)){
      printf("Eh keburu hangus cuk!\n===\n");
    }
    if(isPerishExpiredAvail(list)){
      printf("Eh ada yg angus hangus cuk!\n===\n");
    }

    printf("Insert list (Y X P 1)\n");
    inProgVar.pickUp = 'Y';
    inProgVar.dropOff = 'X';
    inProgVar.itemType = 'P';
    inProgVar.perishTime = 1; 
    insertFirst_InProgList(&list, inProgVar);

    printf("===\n");
    displayInProg(list);
    printf("===\n");

    // tes adjust dan delet perish item pada elemen kedua
    printf("apply adjustPerishTime & deletePerishItem\n");
    adjustPerishTime(&list);
    deletePerishItem(&list, &delVal);
    
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

    // deleteFirst_InProgList(&list, &delVal);
    // printf("Isi list setelah delete ke-2\n");
    // displayInProg(list);
    
    // printf("===\n");
    // printf("Isi dari elemen yang di delete\n");
    // printf("Pickup      : %c\n", delVal.pickUp);
    // printf("Dropoff     : %c\n", delVal.dropOff);
    // printf("Item type   : %c\n", delVal.itemType);
    // printf("Perish time : %d\n", delVal.perishTime);

    return 0;
}