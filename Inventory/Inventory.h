#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include "../tas/tas.h"
#include "../Move/matrix.h"
#include "../Move/point.h"
#include "../ADT/ADT Stack/stack.h"
#include "../Move/listpoint.h"
#include "ListInventory.h"

void inventory(ListInventory *inventory, Tas *tasMobita, ListPoint LP, Point *coordinate_mobita, int *Time);

//Waktu item perishable di TOP tas kembali ke semula
void KainPembungkusWaktu(Tas tasMobita);

//Kapasitas tas menjadi 2 kali lipat
void SenterPembesar(Tas *tasMobita);

//Berpindah lokasi tanpa menambah unit waktu
void PintuKemanaSaja(ListPoint LP, Point *coordinate_mobita);

//Mengurangi waktu sebanyak 50 unit
void MesinWaktu(int Time);

#endif