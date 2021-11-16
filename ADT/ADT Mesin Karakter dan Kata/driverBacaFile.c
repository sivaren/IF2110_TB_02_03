#include "wordmachine.h"
#include <stdio.h>

int main(){
    /* KAMUS LOKAL */
    char *filename;
    int N,M;
    Matrix map,map1;
    Point HQ;
    ListPoint ListOfBangunan;
    PrioQueuePesanan daftarPesanMasuk;
    
    /* ALGORITMA */
    printf("input Nama file\n");
    CreateListPoint(&ListOfBangunan); 
    CreateMatrix(18,18,&map);
    CreatePRIOQUEUE(&daftarPesanMasuk);

    startWord();
    // printWord(currentWord);
    convertWordToString(currentWord, filename);
    
    int i =0;
    while (*(filename+i) != '\0'){
        printf("%c", *(filename+i));
        i++;
    }
    printf("\n");
    // filename= "a.txt";

    // int i;
   
    // for (i=0; i<currentWord.length; i++){
    //     *(filename+i) = currentWord.contents[i];
    // }

    readFile(filename,&N, &M,&HQ, &ListOfBangunan, &daftarPesanMasuk, &map);
    
    // displayMatrix(map);
    displayPRIOQUEUE(daftarPesanMasuk);
    // displayListStat(ListOfBangunan);
    
    // printWord(currentWord);

    // if (isKataSama(currentWord, "MOVE")) printf("BENAR");
    // else printf("SALAH");

    // if (currentWord == 'HELLO') printf("yey");
    // startFile("a.txt"); copyWord();
    // printf("%d ", ROWS(map1));advWord();
    // printf("%d\n", COLS(map1));advWord();
    // printf("%d ", charToInt(currentWord));advWord();
    // printf("%d\n", charToInt(currentWord));advWord();
    // printf("%d", charToInt(currentWord));advWord();
}