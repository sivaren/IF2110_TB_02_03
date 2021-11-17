/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
char currentCharForSave;
boolean eot;

static FILE * tape;
static FILE * tapeFile;
static int retval;
static int retvalFile;

void start() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	tape = stdin;
	adv();
}

void startFile(char *fileName){
/* start baca dari file,mirip start()*/
  /* Algoritma */
  tapeFile = fopen(fileName,"r");
  advForFile();
}

void writeFile(char *fileName){
   tapeFile = fopen(fileName,"w");
   // advWrite(fileName);
}

void advWrite(char anything){
   retval = fputc(anything,tapeFile);
//   retval = fprintf(tapeFile,"%c",&currentCharForSave);
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(tape,"%c",&currentChar);
}




void advForFile(){
   retvalFile = fscanf(tapeFile,"%c",&currentChar);
}


void closeFile(){
   fclose(tapeFile);
}

void closeKata(){
    fclose(tape);
}