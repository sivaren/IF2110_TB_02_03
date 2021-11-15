#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "tas.c"
#include "../inProg/inProg_rev.c"

/* 
NOTE:
Testing tas.c & inProg_rev.c
 */

int main(){
    InProgList list;
    InProgType inProgVar;
    InProgType delVal;

    Tas tasBusuk; 
    ElTypeTas tasVar;

    char pickUp;
    char dropOff; 
    char itemType;
    int perishTime;
    

    CreateInProgList(&list);
    CreateTas(&tasBusuk, 3); 

    /* 
    Untuk tes perishable item, input [pickup] [dropoff] P 2
     */
    scanf("%c %c %c %d", &pickUp, &dropOff, &itemType, &perishTime);
    inProgVar.pickUp = pickUp;
    inProgVar.dropOff = dropOff;
    inProgVar.itemType = itemType;
    inProgVar.perishTime = perishTime; 
    insertFirst_InProgList(&list, inProgVar);
    // 
    tasVar.pickUp = pickUp;
    tasVar.dropOff = dropOff;
    tasVar.itemType = itemType;
    tasVar.perishTime = perishTime;
    pushTas(&tasBusuk, tasVar);
    
    
    printf("===\n");
    displayInProg(list);
    displaytas(tasBusuk);
    printf("===\n");

    // tes adjust dan delete perish item pada elemen pertama
    printf("apply adjustPerishTime_inProg & deletePerishItem_inProg\n");
    adjustPerishTime_inProg(&list, &tasBusuk);
    deletePerishItem_inProg(&list, &tasBusuk, &delVal);

    printf("===\n");
    displayInProg(list);
    displaytas(tasBusuk);
    printf("===\n");

    if(isHeavyAvail_inProg(list)){
      printf("Berat cuk!\n===\n");
    }
    if(isPerishAvail_inProg(list)){
      printf("Eh keburu hangus cuk!\n===\n");
    }
    if(isPerishExpiredAvail_inProg(list)){
      printf("Eh ada yg angus hangus cuk!\n===\n");
    }

    printf("Insert list (Y X P 1)\n");
    inProgVar.pickUp = 'Y';
    inProgVar.dropOff = 'X';
    inProgVar.itemType = 'P';
    inProgVar.perishTime = 1; 
    insertFirst_InProgList(&list, inProgVar);
    // 
    tasVar.pickUp = 'Y';
    tasVar.dropOff = 'X';
    tasVar.itemType = 'P';
    tasVar.perishTime = 1; 
    pushTas(&tasBusuk, tasVar);

    printf("===\n");
    displayInProg(list);
    displaytas(tasBusuk);
    printf("===\n");

    // tes adjust dan delete perish item pada elemen kedua
    printf("apply adjustPerishTime_inProg & deletePerishItem_inProg\n");
    adjustPerishTime_inProg(&list, &tasBusuk);
    deletePerishItem_inProg(&list, &tasBusuk, &delVal);
    
    printf("===\n");
    displayInProg(list);
    displaytas(tasBusuk);
    printf("===\n");

    printf("Insert list (Q R P 5)\n");
    inProgVar.pickUp = 'Q';
    inProgVar.dropOff = 'R';
    inProgVar.itemType = 'P';
    inProgVar.perishTime = 5; 
    insertFirst_InProgList(&list, inProgVar);
    // 
    tasVar.pickUp = 'Q';
    tasVar.dropOff = 'R';
    tasVar.itemType = 'P';
    tasVar.perishTime = 5;
    pushTas(&tasBusuk, tasVar);
    
    printf("===\n");
    displayInProg(list);
    displaytas(tasBusuk);
    printf("===\n");

    // testing delete elemen in progress list
    
    deleteFirst_InProgList(&list, &delVal);
    popTas(&tasBusuk, &tasVar);
    printf("Isi list setelah delete ke-1\n");
    displayInProg(list);
    displaytas(tasBusuk);
    
    printf("===\n");
    printf("Isi dari elemen yang di delete\n");
    printf("Pickup      : %c\n", delVal.pickUp);
    printf("Dropoff     : %c\n", delVal.dropOff);
    printf("Item type   : %c\n", delVal.itemType);
    printf("Perish time : %d\n", delVal.perishTime);
    printf("===\n");

    return 0;
}