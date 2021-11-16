#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include "ListInventory.h"
#include "../tas/tas.h"
#include "../daftarPesanan/daftarPesanan.h"
#include "../inProg/inProg_rev.h"
#include "../Map/matrix.h"
#include "../Map/point.h"
#include "../Map/listpoint.h"

void inventory(ListInventory *inventory, Tas *tasMobita, InProgList *DaftarInprog, ListPoint LP, PrioQueuePesanan Q, Point *coordinate_mobita, int *Time);

//Waktu item perishable di TOP tas kembali ke semula
void KainPembungkusWaktu(Tas *tasMobita, InProgList *DaftarInprog ,PrioQueuePesanan Q);

//Kapasitas tas menjadi 2 kali lipat
void SenterPembesar(Tas *tasMobita);

//Berpindah lokasi tanpa menambah unit waktu
void PintuKemanaSaja(ListPoint LP, Point *coordinate_mobita);

//Mengurangi waktu sebanyak 50 unit
void MesinWaktu(int *Time);

#endif