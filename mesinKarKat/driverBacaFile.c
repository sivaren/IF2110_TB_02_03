#include "wordmachine.h"
#include <stdio.h>

int main(){
    /* KAMUS LOKAL */
    char *namaFile;
    int N,M;
    Matrix map,map1;
    Point HQ;
    ListPoint ListOfBangunan;
    PrioQueuePesanan daftarPesanMasuk,daftarP;
    
    /* ALGORITMA */
    printf("input Nama file\n");
    CreateListPoint(&ListOfBangunan,1); 
    CreateMatrix(1,1,&map);
    CreatePRIOQUEUE(&daftarPesanMasuk);
    CreatePRIOQUEUE(&daftarP);


    /* */
    printf("\n");
    printf("hello");
    readFile("config.txt",&N, &M,&HQ, &ListOfBangunan, &daftarPesanMasuk, &daftarP, &map);
    closeFile();
    displayMatrix(map);
    displayPRIOQUEUE(daftarPesanMasuk);
    

    /*UJI KEYBOARD*/
    int X,Y;
    printf("Input nilai int X : "); X = scanINT();
    printf("Input nilai int Y : ");  Y = scanINT();
    printf("Hasil dari X + Y = %d\n", X+Y);

    int len;
    printf("Ketikkan suata kata dengan huruf kapital : ");  startWord();
    printf("Kata yang anda masukkan adalah : "); printWord(currentWord);
    printf("\n Kata yang ingin diuji adalah : COBA \n");
    if (isKataSama(currentWord, "COBA")){
        printf("isKataSama == True");
    } else{
        printf("isKataSama == False");
    }

}