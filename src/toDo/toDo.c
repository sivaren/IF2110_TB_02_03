/* Implementasi file toDo.h */

#include "toDo.h"

/* alokasi new nodeToDo untuk TO DO LIST */
AddressTodo newToDoNode(int timeIn,char pickUp, char dropOff, char itemType, int perishTime){
    AddressTodo p = (AddressTodo)malloc(sizeof(ElmtToDoList));
    if(p != NULL){
        TIMEIN_TODO(p) = timeIn;
        PICKUP_TODO(p) = pickUp;
        DROPOFF_TODO(p) = dropOff;
        ITEMTYPE_TODO(p) = itemType;
        PERISHTIME_TODO(p) = perishTime;
        NEXT_TODO(p) = NULL;
    }
    return p;
}

void CreateToDoList(ToDoList *td){
    FIRST_TODO(*td) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isEmpty_ToDo(ToDoList td){
    return(FIRST_TODO(td) == NULL);
}
/* Mengirim true jika list kosong */

int length_ToDoList(ToDoList td){
    AddressTodo p = FIRST_TODO(td);
    int count = 0;

    if(!isEmpty_ToDo(td)){
        do{
            count++;
            p = NEXT_TODO(p);
        } while(p != NULL);
    }
    return count;
}
/* Mengirim banyaknya elemen list jika ada, jika tidak mengirimkan nol */

void insert_ToDoList(ToDoList *td, ToDoType val){
    AddressTodo p = newToDoNode(val.timeIn, val.pickUp, val.dropOff, val.itemType, val.perishTime);
    if(p != NULL){
        if(isEmpty_ToDo(*td)){
            NEXT_TODO(p) = FIRST_TODO(*td);
            FIRST_TODO(*td) = p;
        } else {
            AddressTodo last = FIRST_TODO(*td);

            while(NEXT_TODO(last) != NULL){
                last = NEXT_TODO(last);
            }
            // berada di akhir nodeToDo
            NEXT_TODO(p) = NEXT_TODO(last);
            NEXT_TODO(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void delete_ToDoList(ToDoList *td, ToDoType delTarget, ToDoType *delVal){
    AddressTodo p = FIRST_TODO(*td);
    AddressTodo prev = NULL;

    while(!isTodoTypeSama(delTarget, INFO_TODO(p))){
        prev = p;
        p = NEXT_TODO(p);
    }
    // p == elemen yang dicari
    if(prev == NULL){
        if(NEXT_TODO(p) == NULL){
            FIRST_TODO(*td) = NULL; 
        } else {
            FIRST_TODO(*td) = NEXT_TODO(p); 
        }
    } else {
        NEXT_TODO(prev) = NEXT_TODO(p);
    }
    *delVal = INFO_TODO(p);
    free(p);
}
/* Menghapus elemen toDoList tertentu */

void displayToDoList(ToDoList td){
    if(!isEmpty_ToDo(td)){
        AddressTodo loc;
        loc = FIRST_TODO(td);

        int count = 0;
        printf("Pesanan pada To Do List:\n");

        do{
            printf("%d. ", count+1);
            printf("%c -> %c ", PICKUP_TODO(loc), DROPOFF_TODO(loc));
            if(ITEMTYPE_TODO(loc) == 'N'){
                printf("(Normal Item)\n");
            }
            else if(ITEMTYPE_TODO(loc) == 'H'){
                printf("(Heavy Item)\n");
            }
            else if(ITEMTYPE_TODO(loc) == 'P'){
                printf("(Perishable Item, Waktu hangus: %d)\n", PERISHTIME_TODO(loc));
            }

            loc = NEXT_TODO(loc);
            count++;
        } while (loc != NULL);
        printf("\n");
    } else {
        printf("To Do List Kosong!\n\n");
    }
}
/* Menampilkan isi To Do List */

boolean isBangunanInTodo (char namaBangunan, ToDoList DaftarTodo) {
    boolean found = false;
    AddressTodo p;
    p = FIRST_TODO(DaftarTodo);
    while (p != NULL && !found) {
        if (PICKUP_TODO(p) == namaBangunan) {
            found = true;
        }
        else {
            p = NEXT_TODO(p);
        }
    }
    return found;
}
/* Mengirimkan true apabila namaBangunan terdapat pada To Do List */

void daftarPesanan_to_toDo(Pesanan valPesan, ToDoType *todoVal){
    (*todoVal).timeIn = valPesan.waktuMasuk;
    (*todoVal).pickUp = valPesan.pickUp;
    (*todoVal).dropOff = valPesan.dropOff;
    (*todoVal).itemType = valPesan.jenisItem;
    (*todoVal).perishTime = valPesan.waktuHangus;
}
/* CONVERT DAFTAR PESANAN -> TO DO LIST */

boolean isTodoTypeSama(ToDoType td1, ToDoType td2) {
    return (td1.dropOff == td2.dropOff) && (td1.itemType == td2.itemType) && (td1.pickUp == td2.pickUp) && (td1.timeIn == td2.timeIn);
}
/* Mengembalikan true bila ToDoType sama */