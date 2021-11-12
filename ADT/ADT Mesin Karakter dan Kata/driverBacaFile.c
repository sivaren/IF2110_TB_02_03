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

    displayMatrix(map);
    
}