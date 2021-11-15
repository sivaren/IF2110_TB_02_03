#ifndef GADGET_H
#define GADGET_H

/* Kamus Umum */
#define CAPACITY_LISTGADGET 4
/* Kapasitas penyimpanan */
#define GADGET_IDNAMEUNDEF -999
#define GADGET_PRICEUNDEF -999

typedef struct {
    int idname;
    int price;
} DataGadget;

typedef struct { 
    DataGadget contents [CAPACITY_LISTGADGET];
} ListGadget;

/* *** Notasi Akses: Selektor Point *** */
#define GADGETNAME(g) (g).idname
#define GADGETPRICE(g) (g).price

#define ELMTListGadget(l,i) (l).contents[(i)]
#define LISTGADGET_IDNAME(l,i) (l).contents[(i)].idname
#define LISTGADGET_PRICE(l,i) (l).contents[(i)].price

void createListGadget(ListGadget *l);

void createGadget(DataGadget *G);

DataGadget setGadget(int idname, int price);

void displayGadget(ListGadget l);

#endif