#include <stdio.h>
#include <stdlib.h>
#include "toDo.c"

/* Pastikan input timeIn terurut atau sama, karena 
inisial state dari ToDoList sudah terurut
 */

int main(){
    ToDoList td;
    CreateToDoList(&td);
    
    /* test = isEmpty(td);
    if(test){
        printf("bener cuk\n");
    } */

    int timeIn;
    char pickUp;
    char dropOff; 
    char itemType;
    int perishTime;
    ToDoType todoType;

    scanf("%d %c %c %c %d" ,&timeIn, &pickUp,&dropOff, &itemType, &perishTime);
    todoType.timeIn = timeIn;
    todoType.pickUp = pickUp;
    todoType.dropOff = dropOff;
    todoType.itemType = itemType;
    todoType.perishTime = perishTime; 
    insert_ToDoList(&td, todoType);
    printf("===\n");

    /* NOTE: testing isTodoTypeSama
    todoType.timeIn = 3;
    if(isTodoTypeSama(todoType, INFO_TODO(td))){
        printf("sama cuk\n");
    } else {
        printf("beda cuk\n");
    } 
    */
    
    displayToDoList(td);

    printf("===\n");
    scanf("%d %c %c %c %d" ,&timeIn, &pickUp,&dropOff, &itemType, &perishTime);
    todoType.timeIn = timeIn;
    todoType.pickUp = pickUp;
    todoType.dropOff = dropOff;
    todoType.itemType = itemType;
    todoType.perishTime = perishTime; 
    insert_ToDoList(&td, todoType);
    printf("===\n");

    displayToDoList(td);

    printf("===\n");
    scanf("%d %c %c %c %d" ,&timeIn, &pickUp,&dropOff, &itemType, &perishTime);
    todoType.timeIn = timeIn;
    todoType.pickUp = pickUp;
    todoType.dropOff = dropOff;
    todoType.itemType = itemType;
    todoType.perishTime = perishTime; 
    insert_ToDoList(&td, todoType);
    printf("===\n");

    displayToDoList(td);

    // contoh case 
    ToDoType delVal;
    ToDoType target;
    target.timeIn = 2;
    target.pickUp = 'B';
    target.dropOff = 'B';
    target.itemType = 'H';
    target.perishTime = -1;
    delete_ToDoList(&td, target, &delVal);

    printf("===\n");
    displayToDoList(td);
    printf("===\n");
    printf("%d\n", delVal.timeIn);
    printf("%c\n", delVal.pickUp);
    printf("%c\n", delVal.dropOff);
    printf("%c\n", delVal.itemType);
    printf("%d\n", delVal.perishTime);

    return 0;
}