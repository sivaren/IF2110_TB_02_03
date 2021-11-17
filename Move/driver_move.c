#include <stdio.h>
#include "move.h"

int main() {
    ListPoint l;
    CreateListPoint(&l);
    Point HQ = CreatePoint('8',1,1);
    Point mobita = HQ;
    Point A = CreatePoint('A',10,1);
    insertLastListPoint(&l,A);
    Point B = CreatePoint('B',1,15);
    insertLastListPoint(&l,B);
    Point C = CreatePoint('C',1,9);
    insertLastListPoint(&l,C);
    Point D = CreatePoint('D',1,13);
    insertLastListPoint(&l,D);
    Point E = CreatePoint('E',2,3);
    insertLastListPoint(&l,E);
    Point F = CreatePoint('F',3,1);
    insertLastListPoint(&l,F);
    Point G = CreatePoint('G',3,8);
    insertLastListPoint(&l,G);
    Point H = CreatePoint('H',3,14);
    insertLastListPoint(&l,H);
    Point I = CreatePoint('I',4,5);
    insertLastListPoint(&l,I);
    Point J = CreatePoint('J',5,12);
    insertLastListPoint(&l,J);
    Point K = CreatePoint('K',6,3);
    insertLastListPoint(&l,K);
    Point L = CreatePoint('L',7,10);
    insertLastListPoint(&l,L);
    Point M = CreatePoint('M',8,2);
    insertLastListPoint(&l,M);
    Point N = CreatePoint('N',8,6);
    insertLastListPoint(&l,N);
    Point O = CreatePoint('O',8,15);
    insertLastListPoint(&l,O);
    Point P = CreatePoint('P',9,13);
    insertLastListPoint(&l,P);
    Point Q = CreatePoint('Q',10,3);
    insertLastListPoint(&l,Q);
    Matrix adjacency;
    CreateMatrix(18,18,&adjacency);
    // Hanya membaca baris pertama adjacency matrix karena posisi mobita berada di HQ
    readMatrix(&adjacency,1,18);                             
    move(l,adjacency,&mobita,HQ);
    return 0;
}
