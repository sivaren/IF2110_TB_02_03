/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include <dirent.h>
#include "boolean.h"
#include "charmachine.h"
// #include "../ADT Matriks/matrix.h"
// #include "../ADT Point/point.h"
// #include "../ADT List Statis/listpos.h"
#include "../daftarPesanan/daftarPesanan.h"
#include "../Map/map.h"
#include "../toDo/toDo.h"
#include "../inProg/inProg_rev.h"
#include "../Inventory/ListInventory.h"
#include "../tas/tas.h"
#include "../Buy/ListGadget.h"


#define CAPACITY_WORD 50
#define BLANK ' '

typedef struct {
   char contents[CAPACITY_WORD]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

// typedef struct {
//    int waktuMasuk;
//    Point pickUp;
//    Point dropOff;
//    char jenisItem;
//    int waktuHangus;     //untuk perishable
// } Pesanan;



/* Word Engine State */
extern boolean endWord;
extern Word currentWord;

void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startWord();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void copyWordKeyboard();



void advWord(boolean flag);
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord(boolean flag);
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
int WordToInt(Word C);
char WordtoSingleChar(Word C);
void printWord(Word C);

// void convertWordToString(Word C,  char *string);
int panjangString (char* string);
boolean isKataSama (Word C, char* string);
int scanINT ();
int pangkat (int number, int derajat);
void WriteIntToFile(int number);
boolean isFile_inDir(Word kata);
void readFile(char *namaFile,  int *N, int *M, Point *HQ, ListPoint *bangunan, PrioQueuePesanan *Queuepesanan,PrioQueuePesanan *QueuePerishable ,Matrix *Adjency);
void saveFile(char *namaFile,int N,int M, Point HQ, ListPoint Listbangunan, PrioQueuePesanan QueuePesanan,PrioQueuePesanan staticPerishQueue, Matrix Adjency, int pesananDiantar, Point PosisiMobita, int Money, int time, int speedboost, int heavyitem, Tas tasMobita, InProgList progress, ToDoList Todo, ListInventory inventory);
void LoadFile(PrioQueuePesanan *staticPerishQueue, int *pesananDiantar, Point *PosisiMobita, int *Money, int *time, int *speedboost, int *heavyitem, Tas *tasMobita, InProgList *progress, ToDoList *Todo, ListInventory *inventory);

#endif

