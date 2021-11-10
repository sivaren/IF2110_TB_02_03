#include <stdio.h>
#include "ListGadget.h"

void displayGadget(ListGadget l) {
/* Menampilkan daftar List Gadget yang dapat dibeli */
    /* KAMUS LOKAL */
    int i;
    int num;
    /* ALGORITMA */
    ELMTListGadget(l,0).name = 'Kain Pembungkus Waktu';
    ELMTListGadget(l,0).price = 800;
    ELMTListGadget(l,1).name = 'Senter Pembesar';
    ELMTListGadget(l,1).price = 1200;
    ELMTListGadget(l,2).name = 'Pintu Kemana Saja';
    ELMTListGadget(l,2).price = 1500;
    ELMTListGadget(l,3).name = 'Mesin Waktu';
    ELMTListGadget(l,3).price = 3000;

    printf("Gadget yang tersedia:\n");
    for (num = 1; num <= 4; num++)
    {
        printf("%d. ", num);
        for (i = 0; i < 4; i++) 
        {
            printf("%c ", ELMTListGadget(l,i).name);
            printf("(%d Yen)\n", ELMTListGadget(l,i).price);
        }
    }
}    
