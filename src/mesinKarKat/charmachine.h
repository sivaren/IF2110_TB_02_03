/* File: charmachine.h */
/* Definisi Character Engine */

#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "boolean.h"

#define MARK_ENGINE '\n'
#define MARK_FILE EOF
// #define MARK_FILE '\0'
/* Char Engine State */
extern char currentChar;
extern char currentCharForSave;
extern boolean eot;

void start();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void startFile(char *fileName);
void writeFile(char *fileName);
// void advWrite();
void advWrite(char anything);

void adv();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
void advForFile();

void closeFile();

void closeKata();


#endif
