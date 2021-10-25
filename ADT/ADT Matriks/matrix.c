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
boolean isIdxValid(int i, int j) {
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    /* ALGORITMA */
    return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m) {
/* Mengirimkan Index baris terbesar m */
    /* ALGORITMA */
    return (ROWS(m)-1);
}
Index getLastIdxCol(Matrix m) {
/* Mengirimkan Index kolom terbesar m */
    /* ALGORITMA */
    return (COLS(m)-1);
}
boolean isIdxEff(Matrix m, Index i, Index j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    /* ALGORITMA */
    return ((i >= 0 && i < ROWS(m)) && (j >= 0 && j < COLS(m)));
}
ElType getElmtDiagonal(Matrix m, Index i) {
/* Mengirimkan elemen m(i,i) */
    /* ALGORITMA */
    return (ELMT(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
/* Melakukan assignment MRes = MIn */
    /* KAMUS LOKAL */
    Index i,j;
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
    Index i,j;
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
    Index i,j;
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
    Index i,j;
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
    Index i,j;
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
    Index i,j,k;
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
Matrix multiplyConst(Matrix m, ElType x) {
/* Mengirim hasil perkalian setiap elemen m dengan x */
    /* KAMUS LOKAL */
    Index i,j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) *= x;
        }
    }
    return m;  
}
void pMultiplyConst(Matrix *m, ElType k) {
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    /* KAMUS LOKAL */
    Index i,j;
    /* ALGORITMA */
    for (i = 0; i < ROWS(*m); i++) {
        for (j = 0; j < COLS(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    } 
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    /* KAMUS LOKAL */
    Index i,j;
    boolean isIdentic = true;
    /* ALGORITMA */
    if (getLastIdxCol(m1) == getLastIdxCol(m2)) {
        if (count(m1) == count(m2)) {
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
boolean isNotEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    /* ALGORITMA */
    return (!isEqual(m1,m2));
}
boolean isSizeEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* ALGORITMA */
    return ((ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2)));
}

/* ********** Operasi lain ********** */
int count(Matrix m) {
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
    Index i,j;
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
    Index i,j;
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
    Index i,j;
    int countJarang = 0;
    /* ALGORITMA */
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            if (ELMT(m, i, j) != 0) {
                countJarang += 1;
            }        
        }       
    }
    if (countJarang <= count(m)/20) {
        return true;
    } else {
        return false;
    }
}
Matrix inverse1(Matrix m) {
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    /* KAMUS LOKAL */
    Matrix m1;
    Index i,j;
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
    Index i,j;
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
    Index i,j,k,col,row;
    float det = 0;
    int sign = 1;
    /* ALGORITMA */
    CreateMatrix(ROWS(m)-1, COLS(m)-1, &temp);
    if (count(m)==1) {
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
    Index i,j;
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