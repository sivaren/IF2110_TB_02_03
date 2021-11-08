#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* Algoritma */
    while (currentChar == BLANK) {
        advForFile();
    }
}

void startWord() {
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    /* ALGORITMA */
    start();
    ignoreBlank();
    if (currentChar == MARK_ENGINE) {
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
}


//ASUMSI SUDAH ADA TYPESTRUCT BANGUNAN
//ASUMSI SUDAH ADA TYPESTRUCT PESANAN
//ASUMSI SUDAH ADA TYPESTRUCT 
void readFile(char *namaFile, Matrix *peta, Point *HQ, ListOfBangunan *bangunan, ListOfPesanan *pesanan) {
// void readFile(char *namaFile) {
    Word kata;
    int i,j,k,n,m;
    ;
    startFile(namaFile); copyWord();
    ROWS(*peta) = charToInt(currentWord);advWord();
    COLS(*peta) = charToInt(currentWord);advWord();
    Absis(*HQ)  = charToInt(currentWord);advWord();
    Ordinat(*HQ)  = charToInt(currentWord);advWord();
    *bangunan.length  = charToInt(currentWord);advWord();

    for (i=0; i<*bangunan.length; i++){
        *bangunan[i].nama = currentChar;advWord();
        *bangunan[i].absis = charToInt(currentWord);advWord();
        *bangunan[i].ordinat = charToInt(currentWord);advWord();
    }

    for (n = 0; n<ROWS(*peta); n++){
        for (m = 0; m<COLS(*peta); m++){
            ELMT(*peta, n, m) = charToInt(currentWord);advWord();
        }
    }

    *pesanan.length = charToInt(currentWord);advWord();
    for (j=0 ; j<*pesanan.length; j++){
        *pesanan[j].waktuMasuk = charToInt(currentWord);advWord();
        //Kalau pickUp dan dropOff direpresentasikan dengan char (lokasi)
        // *pesanan[i].pickUP = currentChar;advWord();
        // *pesanan[i].dropOff = currentChar;advWord();

        //Tetap make point
        //Cari absis ordinat bangunan
        char namaBangunan = currentChar;advWord();
        k=0;
        while (namaBangunan != *bangunan[k].nama){
            k++;
        }
        *pesanan[j].pickUp.absis = *bangunan[k].absis;
        *pesanan[j].pickUp.ordinat = *bangunan[k].ordinat;


        //Cari absis ordinat bangunan
        char namaBangunan = currentChar;advWord();
        k=0;
        while (namaBangunan != *bangunan[k].nama){
            k++;
        }
        *pesanan[j].dropOff.absis = *bangunan[k].absis;
        *pesanan[j].dropOff.ordinat = *bangunan[k].ordinat;

        *pesanan[j].jenisItem = currentChar;advWord();
        if (*pesanan[j].jenisItem == 'P') *pesanan[j].waktuHangus = charToInt(currentWord);advWord();
    }

     
    
    
}    
    // bil = charToInt(currentWord);advWord();
    // printf("%d\n", bil);
    // bil2 = charToInt(currentWord);advWord();
    // printf("%d\n", bil2);
    // resu = bil+bil2;
    // printf("%d", resu);
    //koordinat HQ = charToInt(currentWord);advWord();
    //  printf("%d\n",ROWS(*Peta));
    // while (currentChar != MARK_FILE ){
        

    //     if (currentChar == MARK_ENGINE) printf("\n");
    //     printf("%c", currentChar);
        
    //     advForFile();

    //     bil++;






void advWord() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
    /* ALGORITMA */
    ignoreBlank();
    if (currentChar == MARK_ENGINE) {
        endWord = true;
    } else {
        copyWord();
        ignoreBlank();
    }
}

void copyWord() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    /* KAMUS LOKAL */
    int i=0;
    /* ALGORITMA */
    while (currentChar != MARK_ENGINE && currentChar != BLANK) {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    currentWord.length = i;
    if (currentWord.length > CAPACITY_WORD) {
        currentWord.length = CAPACITY_WORD;
    } 
}

int charToInt(Word C){
// Mengembalikan int dari word
    //KAMUS LOKAL
    int temp;
    int bilangan;
    int i;

    //ALGORITMA
    bilangan = 0;
    for(i=0; i<C.length; i++){
        temp = (C.contents[i]) - '0';
        bilangan = (bilangan *10) + temp;
        
    }
    return bilangan;
}
