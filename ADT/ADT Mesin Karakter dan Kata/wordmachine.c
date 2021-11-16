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


//ASUMSI SUDAH ADA TYPESTRUCT BANGUNAN
//ASUMSI SUDAH ADA TYPESTRUCT PESANAN
//ASUMSI SUDAH ADA TYPESTRUCT 
void readFile(char *namaFile,  int *N, int *M, Point *HQ, ListPoint *Listbangunan, PrioQueuePesanan *QueuePesanan, Matrix *Adjency) {

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
    *N = charToInt(currentWord);advWord();
    *M = charToInt(currentWord);advWord();
    
    //Assign posisi HQ
    Absis(*HQ)  = charToInt(currentWord);advWord();
    Ordinat(*HQ)  = charToInt(currentWord);advWord();
    Name(*HQ) = '8';

    //Assign jumlah Bangunan dan lokasi
    jumlahBangunan  = charToInt(currentWord);advWord();
    for (i=0; i<jumlahBangunan; i++){
        tempBangunan.name= WordtoSingleChar(currentWord);advWord();
        tempBangunan.X =  charToInt(currentWord);advWord();
        tempBangunan.Y =  charToInt(currentWord);advWord();
        insertLastListPoint(Listbangunan,tempBangunan);
    }
    
    for (i=0; i<=jumlahBangunan; i++){
        for (j=0; j<=jumlahBangunan; j++){
            ELMT(*Adjency, i, j) = charToInt(currentWord);advWord();
        }
    }
    
    // printf("%d\n", charToInt(currentWord));
    
    jumlahPesanan = charToInt(currentWord);
    // printf("aa%d\n", charToInt(currentWord));
    for (j=0 ; j<jumlahPesanan; j++){
        advWord();
        // printf("waktumasuk :");printWord(currentWord);
      
        // printf("\n");
        tempPesanan.waktuMasuk = charToInt(currentWord);advWord();
        // printf("pickUp :");printWord(currentWord);
        // printf("\n");
        tempPesanan.pickUp = WordtoSingleChar(currentWord);advWord();
        // printf("dropOFF :");printWord(currentWord);
        // printf("\n");
        tempPesanan.dropOff = WordtoSingleChar(currentWord);advWord();
        // printf("kenis :");printWord(currentWord);
        // printf("\n");
        tempPesanan.jenisItem = WordtoSingleChar(currentWord);
        // printf("angka %d\n",tempPesanan.waktuMasuk);
        // printf("pickup %c\n", tempPesanan.pickUp);
        // printf("dropOff %c\n", tempPesanan.dropOff);
        // printf("jenis %c\n", tempPesanan.jenisItem);
        
        if (tempPesanan.jenisItem == 'P'){
            advWord();
            tempPesanan.waktuHangus = charToInt(currentWord);
            // printf("waktuHangus %d\n", tempPesanan.waktuHangus);
            
        }    
        
        
        enqueuePRIOQUEUE(QueuePesanan, tempPesanan);
        // displayPRIOQUEUE(*QueuePesanan);
    }

    // dequeuePRIOQUEUE(QueuePesanan,&tempPesanan);
    // dequeuePRIOQUEUE(QueuePesanan,&tempPesanan);
    // displayPRIOQUEUE(*QueuePesanan);
    
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

char WordtoSingleChar(Word C){
    return C.contents[0];
}

void printWord (Word C){
    int i;
    for (i=0; i<C.length; i++){
        printf("%c", C.contents[i]);
    }
}
void convertWordToString(Word C, char *string){
    int i,j,count;
    count= C.length+4;
    char format[] =".txt";
    // char hasil[10];
    j= 0;
    for (i=0; i<=count; i++){
        if (i < C.length){
            *string = C.contents[i];
        } else if (i<count){
            *string = format[j];
            j++;
        }else{
            *string = '\0';
        }
        
        string++;
    }
    
    
}


int panjangString (char* string){
    int count;
    count =0;
    while (*(string+count) != '\0') count++;

    return count;
}


boolean isKataSama (Word C, char *string){
    int i = 0;
    boolean flag;
    flag = panjangString(string) == C.length;
    while (i<C.length && flag){
        
        if (C.contents[i] != *(string +i)) flag = false;
        else i++;
    }

    return flag;
}