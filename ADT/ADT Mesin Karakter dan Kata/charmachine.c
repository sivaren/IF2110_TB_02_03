/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean eot;

static FILE * tape;
static int retval;

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
  tape = fopen(fileName,"r");
  advForFile();
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(tape,"%c",&currentChar);
	eot = (currentChar == MARK_ENGINE);
	if (eot) {
              fclose(tape);
 	}
}

void advForFile(){
   retval = fscanf(tape,"%c",&currentChar);
   // if (currentChar == '\n') fscanf(tape,"%c",&currentChar);
	eot = (currentChar == MARK_FILE);
	if (eot) {
              fclose(tape);
 	}

}


// void advNewline(){
//    retval = fscanf(tape,"\n",&currentChar)
// }