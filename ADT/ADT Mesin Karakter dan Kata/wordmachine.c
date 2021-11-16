#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* Algoritma */
    while (currentChar == BLANK || currentChar == MARK_ENGINE) {
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


void readFile(char *namaFile,  int *N, int *M, Point *HQ, ListPoint *Listbangunan, PrioQueuePesanan *QueuePesanan, PrioQueuePesanan *QueuePerishable, Matrix *Adjency) {

    /* KAMUS LOKAL */
    Word kata;
    int i,j,k,jumlahBangunan,jumlahPesanan;
    int X,Y;
    char tempName;
    Pesanan tempPesanan;
    Point tempBangunan;
    
    /* ALGORITMA */
    startFile(namaFile); copyWord();
    //N dan M digunakan pada map
    *N = WordToInt(currentWord);advWord();
    *M = WordToInt(currentWord);advWord();
    
    //Assign posisi HQ
    Absis(*HQ)  = WordToInt(currentWord);advWord();
    Ordinat(*HQ)  = WordToInt(currentWord);advWord();
    Name(*HQ) = '8';

    //Assign jumlah Bangunan dan lokasi
    jumlahBangunan  = WordToInt(currentWord);advWord();
    CreateListPoint(Listbangunan,jumlahBangunan);
    for (i=0; i<jumlahBangunan; i++){
        tempBangunan.name= WordtoSingleChar(currentWord);advWord();
        tempBangunan.X =  WordToInt(currentWord);advWord();
        tempBangunan.Y =  WordToInt(currentWord);advWord();
        insertLastListPoint(Listbangunan,tempBangunan);
    }

    //Untuk Matrix adjacency
    CreateMatrix(jumlahBangunan+1,jumlahBangunan+1,Adjency);
    for (i=0; i<=jumlahBangunan; i++){
        for (j=0; j<=jumlahBangunan; j++){
            ELMT(*Adjency, i, j) = WordToInt(currentWord);advWord();
        }
    }
    
   
    //Untuk Queue Pesanan
    jumlahPesanan = WordToInt(currentWord);
    for (j=0 ; j<jumlahPesanan; j++){
        advWord();
        tempPesanan.waktuMasuk = WordToInt(currentWord);advWord();
        tempPesanan.pickUp = WordtoSingleChar(currentWord);advWord();
        tempPesanan.dropOff = WordtoSingleChar(currentWord);advWord();
        tempPesanan.jenisItem = WordtoSingleChar(currentWord);
        
        if (tempPesanan.jenisItem == 'P'){
            advWord();
            tempPesanan.waktuHangus = WordToInt(currentWord);
            //diEnqueue ke suatu Queue yang nantinya berguna untuk Penggunaan Gadget
            enqueuePRIOQUEUE(QueuePerishable,tempPesanan);
        }    
        
        
        enqueuePRIOQUEUE(QueuePesanan, tempPesanan);
    }

}    

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
    // MARK_ENGINE = "\n" blank =""   MARK_FILE = "."
    while (currentChar != MARK_ENGINE && currentChar != BLANK &&  currentChar != MARK_FILE) {
        // printf("saat ini %c \n", currentChar);
        currentWord.contents[i] = currentChar;
        advForFile();
        i++;
    }
    currentWord.length = i;
    if (currentWord.length > CAPACITY_WORD) {
        currentWord.length = CAPACITY_WORD;
    }
    // if(currentChar == MARK_ENGINE):
}

int WordToInt(Word C){
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

char WordtoSingleChar(Word C){
    return C.contents[0];
}

void printWord (Word C){
//I.S C Terdefinisi
//F.S Kata C tercetak pada layar
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i=0; i<C.length; i++){
        printf("%c", C.contents[i]);
    }
}



int panjangString (char* string){
    /* KAMUS LOKAL */
    int count;
    
    /* ALGORITMA */    
    count =0;
    while (*(string+count) != '\0') count++;

    return count;
}


boolean isKataSama (Word C, char *string){
    /* KAMUS LOKAL */
    int i = 0;
    boolean flag;
    
    /* ALGORITMA */
    flag = panjangString(string) == C.length;
    while (i<C.length && flag){
        
        if (C.contents[i] != *(string +i)) flag = false;
        else i++;
    }

    return flag;
}

int scanINT (){
    startWord();
    return WordToInt(currentWord);
}