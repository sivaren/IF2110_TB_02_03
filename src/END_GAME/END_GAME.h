
#ifndef END_GAME_H
#define END_GAME_H
#include <stdlib.h>
#include <stdio.h>
#include "../daftarPesanan/daftarPesanan.h"
#include "../toDo/toDo.h"
#include "../inProg/inProg_rev.h"
#include "../tas/tas.h"
#include "../Map/listpoint.h"
#include "../Map/boolean.h"

void END_GAME(int Time, int PesananDiantar, Point pointHQ, Point currentPos, PrioQueuePesanan DaftarPesanan,ToDoList Todo, InProgList DaftarInprog, Tas TasNobita, boolean *run);

#endif