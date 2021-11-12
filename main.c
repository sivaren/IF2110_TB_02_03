#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// include
// Daftar pesanan
// Todo List
// In Progress list & Tas
// Daftar bangunan
#include "ADT/ADT Matriks/matrix.h"
#include "ADT/ADT Point/point.h"
#include "ADT/ADT List Statis/ListOfBangunan.h"
#include "PICK_UP/PICK_UP.h"
#include "DROP_OFF/DROP_OFF.h"


int isStringEqual(char *a, char *b);

int main(){


int Money = 0;
int Time = 0;
Point Position = {0, 0};
Bangunan currentBangunan; // diupdate setiap selesai move ('-' apabila berada di headquarter)
Matrix Adjacency;
// ListStatPos ListGadget, Inventory;
// Queue DaftarPesanan;
char command[100];
ListOfBangunan DaftarBangunan;




int heavyItems = 0;
boolean speedBoost = false;
int currentTasCapacity = 3;
ToDoList DaftarTodo;
Tas TasNobita;
InProgList DaftarInProg;





Read_Config();

// scan input
int opt;
if(opt == 1) {
    Start();
}
else if (opt == 2) {
    Load_Game();
}
else if (opt == 3) {
    quit();
}


// start game

// input command pake mesin kata / is string equal
if (command == "PICK_UP"){
PICK_UP(currentBangunan, &TasNobita, &DaftarTodo, &DaftarInProg, &heavyItems, &speedBoost);
}
else if (command == "DROP_OFF") {
DROP_OFF(currentBangunan, &TasNobita, &DaftarTodo, &DaftarInProg, &heavyItems, &speedBoost, &currentTasCapacity, &Money);
}
/*
MOVE();
MAP();
TO_DO();
IN_PROGRESS();
BUY();
INVENTORY();
HELP();
SAVE_GAME();
*/

}














