#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m) {
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    /* ALGORITMA */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValidMatrix(int i, int j) {
/* Mengirimkan true jika i, j adalah IndexMatrix yang valid untuk matriks apa pun */
    /* ALGORITMA */
    return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IndexMatrix getLastIdxRow(Matrix m) {
/* Mengirimkan IndexMatrix baris terbesar m */
    /* ALGORITMA */
    return (ROWS(m)-1);
}
IndexMatrix getLastIdxCol(Matrix m) {
/* Mengirimkan IndexMatrix kolom terbesar m */
    /* ALGORITMA */
    return (COLS(m)-1);
}
boolean isIdxEffMatrix(Matrix m, IndexMatrix i, IndexMatrix j) {
/* Mengirimkan true jika i, j adalah IndexMatrix efektif bagi m */
    /* ALGORITMA */
    return ((i >= 0 && i < ROWS(m)) && (j >= 0 && j < COLS(m)));
}
ElTypeMatrix getElmtDiagonal(Matrix m, IndexMatrix i) {
/* Mengirimkan elemen m(i,i) */
    /* ALGORITMA */
    return (ELMT(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
/* Melakukan assignment MRes = MIn */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    /* ALGORITMA */
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for (i = 0; i < ROWS(mIn); i++) {
        for (j = 0; j < COLS(mIn); j++) {
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    /* ALGORITMA */
    CreateMatrix(nRow, nCol, m);
    for (i = 0; i < ROWS(*m); i++) {
        for (j = 0; j < COLS(*m); j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }  
}
void displayMatrix(Matrix m) {
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            if (j == COLS(m)-1) {
                printf("%d", ELMT(m, i, j));
            } else {
                printf("%d ", ELMT(m, i, j));
            }
        }
        if (i != ROWS(m)-1) {
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    /* KAMUS LOKAL */
    Matrix m;
    IndexMatrix i,j;
    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for (i = 0; i < ROWS(m1); i++) {
        for (j = 0; j < COLS(m1); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m;  
}
Matrix subtractMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    /* KAMUS LOKAL */
    Matrix m;
    IndexMatrix i,j;
    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for (i = 0; i < ROWS(m1); i++) {
        for (j = 0; j < COLS(m1); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m;  
}
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    /* KAMUS LOKAL */
    Matrix mRes;
    IndexMatrix i,j,k;
    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m2), &mRes);
    for (i = 0; i < ROWS(mRes); i++) {
        for (j = 0; j < COLS(mRes); j++) {
            ELMT(mRes, i, j) = 0;
            for (k = 0; k < COLS(m1); k++) {
                ELMT(mRes, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return mRes;  
}
Matrix multiplyConst(Matrix m, ElTypeMatrix x) {
/* Mengirim hasil perkalian setiap elemen m dengan x */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) *= x;
        }
    }
    return m;  
}
void pMultiplyConst(Matrix *m, ElTypeMatrix k) {
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(*m); i++) {
        for (j = 0; j < COLS(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    } 
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqualMatrix(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan IndexMatrix baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    boolean isIdentic = true;
    /* ALGORITMA */
    if (getLastIdxCol(m1) == getLastIdxCol(m2)) {
        if (countMatrix(m1) == countMatrix(m2)) {
            for (i = 0; i < ROWS(m1); i++) {
                for (j = 0; j < COLS(m1); j++) {
                    if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                        isIdentic = false;
                        break;
                    }       
                }
            }
        } else {
            isIdentic = false;
        }
    } else {
        isIdentic = false;
    }
    return isIdentic;
}
boolean isNotEqualMatrix(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    /* ALGORITMA */
    return (!isEqualMatrix(m1,m2));
}
boolean isSizeEqualMatrix(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* ALGORITMA */
    return ((ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2)));
}

/* ********** Operasi lain ********** */
int countMatrix(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    /* ALGORITMA */
    return (ROWS(m) * COLS(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    /* ALGORITMA */
    return (ROWS(m) == COLS(m));
}
boolean isSymmetric(Matrix m) {
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    boolean isIdentic = true;
    /* ALGORITMA */
    if (isSquare(m)) {
        for (i = 0; i < ROWS(m); i++) {
            for (j = 0; j < COLS(m); j++) {
                if (ELMT(m, i, j) != ELMT(m, j, i)) {
                    isIdentic = false;
                    break;
                }       
            }
        }
    } else {
        isIdentic = false;
    }
    return isIdentic;
}
boolean isIdentity(Matrix m) {
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    boolean id=true;
    /* ALGORITMA */
    if (isSquare(m)) {
        for (i = 0; i < ROWS(m); i++) {
            if (ELMT(m, i, i) != 1) {
                id = false;
                break;
            } 
            for (j = 0; j < COLS(m); j++) {
                if (i != j) {
                    if (ELMT(m, i, j) != 0) {
                        id = false;
                        break;
                    }
                }
            }       
        }
    } else {
        id = false;
    }
    return id;
}
boolean isSparse(Matrix m) {
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    int countJarang = 0;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            if (ELMT(m, i, j) != 0) {
                countJarang += 1;
            }        
        }       
    }
    if (countJarang <= countMatrix(m)/20) {
        return true;
    } else {
        return false;
    }
}
Matrix inverse1(Matrix m) {
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    /* KAMUS LOKAL */
    Matrix m1;
    IndexMatrix i,j;
    /* ALGORITMA */
    copyMatrix(m, &m1);
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m1, i, j) *= -1;
        }
    } 
    return m1;
}
void pInverse1(Matrix *m) {
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    /* KAMUS LOKAL */
    IndexMatrix i,j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(*m); i++) {
        for (j = 0; j < COLS(*m); j++) {
            ELMT(*m, i, j) *= -1;
        }
    } 
}
float determinant(Matrix m) {
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    /* KAMUS LOKAL */
    Matrix temp;
    IndexMatrix i,j,k,col,row;
    float det = 0;
    int sign = 1;
    /* ALGORITMA */
    CreateMatrix(ROWS(m)-1, COLS(m)-1, &temp);
    if (countMatrix(m)==1) {
        return ELMT(m, 0, 0);
    }
    for (k = 0; k < COLS(m); k++) {
        row = 0; col = 0;
        for (i = 0; i < ROWS(m); i++) {
            for (j = 0; j < COLS(m); j++) {
                if (i != 0 && j != k) {
                    ELMT(temp, row, col) = ELMT(m, i, j);
                    col++;
                    if (col == COLS(m)-1) {
                        col = 0;
                        row++;
                    }
                }
            }
        }
        det += sign * ELMT(m, 0, k) * determinant(temp);
        sign = -sign;
    }

    return det;
}
void transpose(Matrix *m) {
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /* KAMUS LOKAL */
    Matrix temp;
    IndexMatrix i,j;
    /* ALGORITMA */
    CreateMatrix(ROWS(*m), COLS(*m), &temp);
    for (i = 0; i < ROWS(*m); i++) {
        for (j = 0; j < COLS(*m); j++) {
            ELMT(temp, i, j) = ELMT(*m, j, i);
        }
    } 
    for (i = 0; i < ROWS(*m); i++) {
        for (j = 0; j < COLS(*m); j++) {
            ELMT(*m, i, j) = ELMT(temp, i, j);
        }
    } 
}


float rowMean (Matrix m, IndexMatrix i){
    /* Menghasilkan rata-rata dari elemen pada baris ke-i */
    /* Prekondisi: i adalah indeks baris efektif dari M */
    
    /* KAMUS LOKAL */
    float sum;
    IndexMatrix j;

   /* ALGORITMA */
    sum = 0;
    for (j=0 ; j<COLS(m); j++){
        sum += ELMT(m,i,j);
    }

    return (sum/COLS(m));
}

float colMean (Matrix m, IndexMatrix j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
    /* KAMUS LOKAL */
    float sum;
    IndexMatrix i;

    /* ALGORITMA */
    sum = 0;
    for (i=0 ; i<ROWS(m); i++){
        sum += ELMT(m,i,j);
    }

    return (sum/ROWS(m));
}

void rowExtremes (Matrix m, IndexMatrix i, ElTypeMatrix * max, ElTypeMatrix * min){
    /* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada baris i dari M
        min berisi elemen minimum pada baris i dari M */
    /* KAMUS LOKAL */
    IndexMatrix j;

    /* ALGORITMA */
    *max = ELMT(m,i,0);
    *min = ELMT(m,i,0);


    for (j=0 ; j<COLS(m); j++){
        if (ELMT(m,i,j) >= *max) *max = ELMT(m,i,j);
        if (ELMT(m,i,j) <= *min) *min = ELMT(m,i,j);
    
    }
}

void colExtremes (Matrix m, IndexMatrix j, ElTypeMatrix * max, ElTypeMatrix * min){
    /* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada kolom j dari M
            min berisi elemen minimum pada kolom j dari M */
    /* KAMUS LOKAL */
    IndexMatrix i;

    /* ALGORITMA */
    *max = ELMT(m,0,j);
    *min = ELMT(m,0,j);


    for (i=0 ; i<ROWS(m); i++){
        if (ELMT(m,i,j) >= *max) *max = ELMT(m,i,j);
        if (ELMT(m,i,j) <= *min) *min = ELMT(m,i,j);
    
    }

}

int countValOnRow (Matrix m, IndexMatrix i, ElTypeMatrix val){
    /* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    /* KAMUS LOKAL */
    IndexMatrix j;
    int count;

    /* ALGORITMA */
    count=0;

    for (j=0 ; j<COLS(m) ; j++){
        if (ELMT(m,i,j) == val) count++;
    }
    return count;
}


int countValOnCol (Matrix m, IndexMatrix j, ElTypeMatrix val){
    /* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    IndexMatrix i;
    int count=0;
    for (i=0; i<ROWS(m); i++){
        if (ELMT(m,i,j) == val) count++;
    }

    return count;
}
