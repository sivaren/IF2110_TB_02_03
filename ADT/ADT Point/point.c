/* File: point.c */
/* Tanggal: 1 September 2021 */
/* Realisasi ADT POINT */

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
Point MakePOINT (float X, float Y) {
/* Membentuk sebuah Point dari komponen-komponennya */
    /* KAMUS */
    Point P;
    /* ALGORITMA */
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPoint (Point *P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    /* KAMUS */
    float X, Y;
    /* ALGORITMA */
    scanf("%f %f", &X, &Y);
    *P = CreatePoint(X, Y);
}
void TulisPoint (Point P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
    /* KAMUS */
    /* ALGORITMA */
    printf("(%.2f, %.2f)\n", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean EQ (Point P1, Point P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    /* ALGORITMA */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
boolean NEQ (Point P1, Point P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    /* ALGORITMA */
    return ((Absis(P1) != Absis(P2)) && (Ordinat(P1) != Ordinat(P2)));
}
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (Point P) {
/* Menghasilkan true jika P adalah titik origin */
    /* ALGORITMA */
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean IsOnSbX (Point P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    /* ALGORITMA */
    return (Ordinat(P) == 0);    
}
boolean IsOnSbY (Point P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    /* ALGORITMA */
    return (Absis(P) == 0);    
}
int Kuadran (Point P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    /* ALGORITMA */
    if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
        return 1;
    }
    else if ((Absis(P) < 0) && Ordinat(P) > 0) {
        return 2;
    }
    else if ((Absis(P) < 0) && Ordinat(P) < 0) {
        return 3;
    }
    else {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
Point NextX (Point P) {
/* Mengirim salinan P dengan absis ditambah satu */             
    /* ALGORITMA */
    return (CreatePoint(Absis(P)+1, Ordinat(P)));
}
Point NextY (Point P) {
/* Mengirim salinan P dengan ordinat ditambah satu */      
    /* ALGORITMA */
    return (CreatePoint(Absis(P), Ordinat(P)+1));
}
Point PlusDelta (Point P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */           
    /* ALGORITMA */
    return (CreatePoint(Absis(P)+deltaX, Ordinat(P)+deltaY));
}
Point MirrorOf (Point P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */           
    /* ALGORITMA */
    if (SbX) {
        return (CreatePoint(Absis(P), -Ordinat(P)));
    }
    else {
        return (CreatePoint(-Absis(P), Ordinat(P)));
    }
}
float Jarak0 (Point P) {
/* Menghitung jarak P ke (0,0) */
    /* ALGORITMA */
    return (sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}
float Panjang (Point P1, Point P2) {
/* Menghitung jarak antara P1 dan P2 */
    /* KAMUS */
    float x, y;
    /* ALGORITMA */
    x = fabs(Absis(P1) - Absis(P2));
    y = fabs(Ordinat(P1) - Ordinat(P2));
    return (sqrt(pow(x, 2) + pow(y, 2)));
}
void Geser (Point *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    /* ALGORITMA */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY; 
}
void GeserKeSbX (Point *P) {    
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    /* ALGORITMA */
    Ordinat(*P) = 0;
}
void GeserKeSbY (Point *P) {
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    /* ALGORITMA */
    Absis(*P) = 0;   
}
void Mirror (Point *P, boolean SbX) {
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    /* ALGORITMA */
    if (SbX) {
        Ordinat(*P) = -Ordinat(*P);
    }
    else {
        Absis(*P) = -Absis(*P);
    }
}
void Putar (Point *P, float Sudut) {
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    /* ALGORITMA */
    Absis(*P) = (Absis(*P)*cos(Sudut)) + (Ordinat(*P)*sin(Sudut));
    Ordinat(*P) = -(Absis(*P)*sin(Sudut)) + (Ordinat(*P)*cos(Sudut));
}