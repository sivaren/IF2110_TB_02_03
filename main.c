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
void START(int *Money, int *Time, int *heavyItems, boolean *speedBoost, int *currentTasCapaicty, boolean *started) {
    *Money = 0;
    *Time = 0;
    *heavyItems = 0;
    *speedBoost = false;
    *currentTasCapaicty = 3;
    *started = true;
}

int main(){

boolean started;
int Money;
int Time;
Point Position;
Bangunan currentBangunan; // diupdate setiap selesai move ('8' apabila berada di headquarter)
Matrix Adjacency;
// 
char command[100];
ListOfBangunan DaftarBangunan;
int heavyItems;
boolean speedBoost;
int currentTasCapacity;
ToDoList DaftarTodo;
Tas TasNobita;
InProgList DaftarInProg;





started = false;

// scan input
printf("Selamat datang di MOBILITA\n");

int opt;
while (!started) {
    printf("1) START\n2) LOAD\n3) QUIT\n");
    printf("Masukkan command: ");
    scanf("%d", &opt); // GANTI MESIN KARAKTER
if(opt == 1) {
    START(&Money, &Time, &heavyItems, &speedBoost, &currentTasCapacity, &started);
}
else if (opt == 2) {
    Load_Game();
}
else if (opt == 3) {
    quit();
}
else {
    printf("command salah\n");
}

}


// start game
while (!isStringEqual(&command, "QUIT")) {

// input command pake mesin kata / is string equal
if (isStringEqual(&command, "PICK_UP")){
PICK_UP(currentBangunan, &TasNobita, &DaftarTodo, &DaftarInProg, &heavyItems, &speedBoost);
}
else if (&command, "DROP_OFF") {
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
else {
    printf("Command salah\n");
}
}
}














