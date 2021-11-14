#ifndef GADGET_H
#define GADGET_H

/* Kamus Umum */
#define CAPACITY_LISTGADGET 4
/* Kapasitas penyimpanan */
#define GADGET_NAMEUNDEF "GADGETUNDEF"
#define GADGET_PRICEUNDEF -999
/* Indeks tak terdefinisi*/
/* #define VAL_UNDEF -999 */
/* Nilai elemen tak terdefinisi*/

typedef struct {
    char *name;
    int price;
} DataGadget;

typedef struct { 
    DataGadget contents [CAPACITY_LISTGADGET];
} ListGadget;

/* *** Notasi Akses: Selektor Point *** */
#define GADGETNAME(g) (g).name
#define GADGETPRICE(g) (g).price

#define ELMTListGadget(l,i) (l).contents[(i)]
#define NAME(l,i) (l).contents[(i)].name
#define PRICE(l,i) (l).contents[(i)].price

void createListGadget(ListGadget *l);

void createGadget(DataGadget *G);

DataGadget setGadget(char name[], int price);

void displayGadget(ListGadget l);

#endif