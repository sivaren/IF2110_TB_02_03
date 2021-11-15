#include "wordmachine.h"
#include <stdio.h>

int main(){
    /* KAMUS LOKAL */
    char* filename;
    Matrix map,map1;
    Point HQ;
    ListPoint ListOfBangunan;
    PrioQueuePesanan daftarPesanMasuk;
    
    /* ALGORITMA */
    CreateListPoint(&ListOfBangunan); 
    CreateMatrix(18,18,&map);
    CreatePRIOQUEUE(&daftarPesanMasuk);
    readFile("a.txt", &HQ, &ListOfBangunan, &daftarPesanMasuk, &map);
    
    // displayMatrix(map);
    displayPRIOQUEUE(daftarPesanMasuk);
    // displayListStat(ListOfBangunan);
    startWord();
    printWord(currentWord);

    // if (currentWord == 'HELLO') printf("yey");
    // startFile("a.txt"); copyWord();
    // printf("%d ", ROWS(map1));advWord();
    // printf("%d\n", COLS(map1));advWord();
    // printf("%d ", charToInt(currentWord));advWord();
    // printf("%d\n", charToInt(currentWord));advWord();
    // printf("%d", charToInt(currentWord));advWord();
}