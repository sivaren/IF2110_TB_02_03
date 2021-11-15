#include <stdio.h>
#include <stdlib.h>
#include "tas.c"

/* 
NOTE: CARA PAKAI
- input pertama: [pickup] [dropoff] [itemType] [perish time]
- input berikutnya bawaan dari source code (karena dicoba input user ada bug, 
  tapi jika ditentukan di source code, code berjalan lancar)   
 */

int main(){
    Tas t;
    ElTypeTas el;
    char a;
    char b; 
    char c;
    int d;
    int capacity = 3;
    
    CreateTas(&t, capacity);

    scanf("%c %c %c %d", &a, &b, &c, &d);
    el.pickUp = a;
    el.dropOff = b;
    el.itemType = c;
    el.perishTime = d;

    printf("===\n");
    pushTas(&t, el);
    
    /* PRINT ISI TAS */
    displaytas(t);
    printf("===\n");

    el.pickUp = 'B';
    el.dropOff = 'C';
    el.itemType = 'P';
    el.perishTime = 5;

    printf("===\n");
    pushTas(&t, el);
    
    /* PRINT ISI TAS */
    displaytas(t);
    printf("===\n");

    el.pickUp = 'Q';
    el.dropOff = 'R';
    el.itemType = 'H';
    el.perishTime = -1;

    printf("===\n");
    pushTas(&t, el);
    
    /* PRINT ISI TAS */
    displaytas(t);

    el.pickUp = 'Q';
    el.dropOff = 'R';
    el.itemType = 'H';
    el.perishTime = -1;

    printf("===\n");
    pushTas(&t, el);
    printf("Tas sudah full, capacity = 3\n");
    // tas sudah 4 > 3, full
    displaytas(t);
    printf("===\n");

    // popping tas
    printf("Setelah dipop\n");
    ElTypeTas target;
    popTas(&t,&target);
    /* PRINT ISI TAS */
    displaytas(t);
    printf("===\n");

    printf("isi Pop\n");
    printf("%c %c %c %d\n", target.pickUp,target.dropOff,target.itemType,target.perishTime);
    printf("===\n");

    printf("ini tas copy\n");
    Tas tascopy;
    CreateTas(&tascopy, capacity);
    copyTas(t, &tascopy);
    displaytas(tascopy);
    printf("===\n");

    // printf("%d\n", IDX_TOP_TAS(tascopy));
    // printf("%d\n", IDX_TOP_TAS(t));

    // tes upgrade capacity
    printf("Setelah diupgrade dan push menjadi max capacity baru\n");
    capacity++;
    upgradeTasCapacity(&t, capacity);
    // push agar menjadi 4 elemen (capacity stelah di upgrade)
    pushTas(&t, el);
    pushTas(&t, el);
    displaytas(t);
    printf("===\n");

    // coba push walau sudah max kapasitas
    printf("Tas sudah full kapasitas = 4\n");
    pushTas(&t, el);
    displaytas(t);

    return 0;
}