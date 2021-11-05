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
#include "ADT/ADT List Statis/listpos.h"
#include "ADT/ADT Linked List/list_linked.h"
#include "ADT/ADT Queue/queue.h" // modif prioqueue
#include "ADT/ADT Stack/stack.h"

int main(){
int Money = 0;
int Time = 0;
Point Position = {0, 0};
Matrix Adjacency;
ListStatPos DaftarBangunan, ListGadget, Inventory;
Queue DaftarPesanan;
LinkedList TodoList;
Stack Tas, InProgressList;
char command[100];

int heavyItems = 0;
int speedBoost;
int increaseCapacity;


int isStringEqual(char *a, char *b);




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

}

// start game

// input command pake mesin kata
MOVE();
PICK_UP();
DROP_OFF();
MAP();
TO_DO();
IN_PROGRESS();
BUY();
INVENTORY();
HELP();
SAVE_GAME();















