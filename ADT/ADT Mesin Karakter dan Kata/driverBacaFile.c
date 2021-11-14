#include "wordmachine.h"
#include <stdio.h>

int main(){
    /* KAMUS LOKAL */
    char* filename;
    Matrix map,map1;
    Point HQ;
    ListOfBangunan ListOfBangunan;
    PrioQueuePesanan daftarPesanMasuk;
    
    /* ALGORITMA */
    readFile("a.txt", &map1,&HQ, &ListOfBangunan, &daftarPesanMasuk, &map);

    // displayMatrix(map1);
    // displayPRIOQUEUE(daftarPesanMasuk);
    // displayListStat(ListOfBangunan);

    startFile("a.txt"); copyWord();
    printf("%d ", ROWS(map1));advWord();
    printf("%d\n", COLS(map1));advWord();
    printf("%d ", charToInt(currentWord));advWord();
    printf("%d\n", charToInt(currentWord));advWord();
    printf("%d", charToInt(currentWord));advWord();
}