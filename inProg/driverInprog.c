#include <stdio.h>
#include <stdlib.h>
#include "inProg_rev.c"

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

    char pickUp1;
    char dropOff1; 
    char itemType1;
    int perishTime1;
    InProgType inProgVar1;

    scanf("%c %c %c %d", &pickUp1, &dropOff1, &itemType1, &perishTime1);
    inProgVar1.pickUp = pickUp1;
    inProgVar1.dropOff = dropOff1;
    inProgVar1.itemType = itemType1;
    inProgVar1.perishTime = perishTime1; 
    insertFirst_InProgList(&list, inProgVar1);
    
    printf("===\n");
    displayInProg(list);
    printf("===\n");

    InProgType delVal;
    deleteFirst_InProgList(&list, &delVal);

    printf("===\n");
    displayInProg(list);
    printf("===\n");
    printf("Pickup      : %c\n", delVal.pickUp);
    printf("Dropoff     : %c\n", delVal.dropOff);
    printf("Item type   : %c\n", delVal.itemType);
    printf("Perish time : %d\n", delVal.perishTime);

    return 0;
}