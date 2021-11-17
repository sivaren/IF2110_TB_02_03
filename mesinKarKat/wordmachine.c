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
    while (currentChar == BLANK || currentChar == MARK_ENGINE) {
        adv();
    }
    if (currentChar == MARK_ENGINE) {
        endWord = true;
    } else {
        endWord = false;
        copyWordKeyboard();
    }
} 

void copyWordKeyboard() {
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
    while (currentChar != MARK_ENGINE && currentChar != BLANK) {
        // printf("saat ini %c \n", currentChar);
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    currentWord.length = i;
    if (currentWord.length > CAPACITY_WORD) {
        currentWord.length = CAPACITY_WORD;
    }
    // if(currentChar == MARK_ENGINE):
}





void advWord(boolean flag) {
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
        copyWord(flag);
        ignoreBlank();
    }
}

void copyWord(boolean flag) {
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
    if (flag){
        while (currentChar != MARK_ENGINE && currentChar != BLANK &&  currentChar != MARK_FILE) {
            // printf("saat ini %c \n", currentChar);
            // printf(" %c", currentChar);
            currentWord.contents[i] = currentChar;
            advForFile();
            i++;
        }
        currentWord.length = i;
        if (currentWord.length > CAPACITY_WORD) {
            currentWord.length = CAPACITY_WORD;
        }
    }
    else{
        currentWord.contents[i] = currentChar;
        advForFile();
        // printf(" %c", currentChar);
    }
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

void readFile(char *namaFile,  int *N, int *M, Point *HQ, ListPoint *Listbangunan, PrioQueuePesanan *QueuePesanan, PrioQueuePesanan *QueuePerishable, Matrix *Adjency) {

   /* KAMUS LOKAL */
    Word kata;
    int i,j,k,jumlahBangunan,jumlahPesanan;
    int X,Y;
    char tempName;
    Pesanan tempPesanan;
    Point tempBangunan;
    
    /* ALGORITMA */
    startFile(namaFile); copyWord(true);
    //N dan M digunakan pada map
    
    *N = WordToInt(currentWord);advWord(true);
    
    *M = WordToInt(currentWord);advWord(true);
    
    //Assign posisi HQ
    Absis(*HQ)  = WordToInt(currentWord);advWord(true);
    Ordinat(*HQ)  = WordToInt(currentWord);advWord(true);
    Name(*HQ) = '8';
    

    //Assign jumlah Bangunan dan lokasi
    jumlahBangunan  = WordToInt(currentWord);advWord(true);
    CreateListPoint(Listbangunan,jumlahBangunan);
    for (i=0; i<jumlahBangunan; i++){
        
        tempBangunan.name= WordtoSingleChar(currentWord);advWord(true);
        
        tempBangunan.X =  WordToInt(currentWord);advWord(true);
        tempBangunan.Y =  WordToInt(currentWord);advWord(true);
        insertLastListPoint(Listbangunan,tempBangunan);
    }

    //Untuk Matrix adjacency
    CreateMatrix(jumlahBangunan+1,jumlahBangunan+1,Adjency);
    for (i=0; i<=jumlahBangunan; i++){
        for (j=0; j<=jumlahBangunan; j++){
            ELMT(*Adjency, i, j) = WordToInt(currentWord);advWord(true);
        }
    }
    
    //Untuk Queue Pesanan
    
    jumlahPesanan = WordToInt(currentWord);
    for (j=0 ; j<jumlahPesanan; j++){
        advWord(true);
        
        tempPesanan.waktuMasuk = WordToInt(currentWord);advWord(true);
        tempPesanan.pickUp = WordtoSingleChar(currentWord);advWord(false);
        tempPesanan.dropOff = WordtoSingleChar(currentWord);advWord(false);
        // if (j!= jumlahPesanan-1){
        //     printf("\n");
        //     advWord();
        // }
        // else{
        //     advWord();
        // }
        
        // printWord(currentWord);printf("\n");
        tempPesanan.jenisItem = WordtoSingleChar(currentWord);
        
        
        if (tempPesanan.jenisItem == 'P'){
            advWord(true);
            tempPesanan.waktuHangus = WordToInt(currentWord);
            //diEnqueue ke suatu Queue yang nantinya berguna untuk Penggunaan Gadget
            enqueuePRIOQUEUE(QueuePerishable,tempPesanan);
        }    
        
        
        enqueuePRIOQUEUE(QueuePesanan, tempPesanan);
    }

}    

boolean isFile_inDir(Word kata){
    DIR *d;
    struct dirent *dir;
    boolean found;

    d = opendir(".");
    found = false;
    
    while ((dir = readdir(d)) != NULL && (!found))
    {   
        if(isKataSama(currentWord, dir->d_name)){
            found = true;
        }
    }
    closedir(d);

    return found;
}
/* cek apakah ada nama file di dalam directory */