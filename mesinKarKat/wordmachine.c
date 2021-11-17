#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* Algoritma */
    while (currentChar == BLANK || currentChar == MARK_ENGINE) {
        advForFile();
    }
}

void startWord() {
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    /* ALGORITMA */
    start();
    while (currentChar == BLANK || currentChar == MARK_ENGINE) {
        adv();
    }
    if (currentChar == MARK_ENGINE) {
        endWord = true;
    } else {
        endWord = false;
        copyWordKeyboard();
    }
} 

void copyWordKeyboard() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    /* KAMUS LOKAL */
    int i=0;
    /* ALGORITMA */
    // MARK_ENGINE = "\n" blank =""   MARK_FILE = "."
    while (currentChar != MARK_ENGINE && currentChar != BLANK) {
        // printf("saat ini %c \n", currentChar);
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    currentWord.length = i;
    if (currentWord.length > CAPACITY_WORD) {
        currentWord.length = CAPACITY_WORD;
    }
    // if(currentChar == MARK_ENGINE):
}





void advWord(boolean flag) {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
    /* ALGORITMA */
    ignoreBlank();
    if (currentChar == MARK_ENGINE) {
        endWord = true;
    } else {
        copyWord(flag);
        ignoreBlank();
    }
}

void copyWord(boolean flag) {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    /* KAMUS LOKAL */
    int i=0;
    /* ALGORITMA */
    // MARK_ENGINE = "\n" blank =""   MARK_FILE = "."
    if (flag){
        while (currentChar != MARK_ENGINE && currentChar != BLANK &&  currentChar != MARK_FILE) {
            currentWord.contents[i] = currentChar;
            advForFile();
            i++;
        }
        currentWord.length = i;
        if (currentWord.length > CAPACITY_WORD) {
            currentWord.length = CAPACITY_WORD;
        }
    }
    else{
        currentWord.contents[i] = currentChar;
        advForFile();
       
    }
}

int WordToInt(Word C){
// Mengembalikan int dari word
    //KAMUS LOKAL
    int temp;
    int bilangan;
    int i;

    //ALGORITMA
    bilangan = 0;
    for(i=0; i<C.length; i++){
        temp = (C.contents[i]) - '0';
        bilangan = (bilangan *10) + temp;
        
    }
    return bilangan;
}

char WordtoSingleChar(Word C){
    return C.contents[0];
}

void printWord (Word C){
//I.S C Terdefinisi
//F.S Kata C tercetak pada layar
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i=0; i<C.length; i++){
        printf("%c", C.contents[i]);
    }
}

int panjangString (char* string){
    /* KAMUS LOKAL */
    int count;
    
    /* ALGORITMA */    
    count =0;
    while (*(string+count) != '\0') count++;

    return count;
}

boolean isKataSama (Word C, char *string){
    /* KAMUS LOKAL */
    int i = 0;
    boolean flag;
    
    /* ALGORITMA */
    flag = panjangString(string) == C.length;
    while (i<C.length && flag){
        
        if (C.contents[i] != *(string +i)) flag = false;
        else i++;
    }

    return flag;
}

int scanINT (){
    startWord();
    return WordToInt(currentWord);
}


int pangkat (int number, int derajat){
    int i;
    int result;
    result =1;
    for (i=0; i<derajat; i++){
        result *= number;
    }
    return result;
}

void WriteIntToFile(int number){
    char string[10];
    int digit,i,j;
    digit = 1;
    while (number % pangkat(10,digit) != number)
    {
        digit++;
    }
    j=0;
    for (i=digit-1; i>=0; i--){
        *(string+j) = (number /  pangkat(10,i)) + '0';
        number = number % pangkat(10,i);
        j++;
    }
    *(string+digit) = '\0'; 

    for (j = 0; j<panjangString(string); j++){
            advWrite(string[j]);
    }
} 

boolean isFile_inDir(Word kata){
    DIR *d;
    struct dirent *dir;
    boolean found;

    d = opendir(".");
    found = false;
    
    while ((dir = readdir(d)) != NULL && (!found))
    {   
        if(isKataSama(currentWord, dir->d_name)){
            found = true;
        }
    }
    closedir(d);

    return found;
}

void readFile(char *namaFile,  int *N, int *M, Point *HQ, ListPoint *Listbangunan, PrioQueuePesanan *QueuePesanan, PrioQueuePesanan *QueuePerishable, Matrix *Adjency) {



   /* KAMUS LOKAL */
    Word kata;
    int i,j,k,jumlahBangunan,jumlahPesanan;
    int X,Y;
    char tempName;
    Pesanan tempPesanan;
    Point tempBangunan;
    
    /* ALGORITMA */
    startFile(namaFile); copyWord(true);
    //N dan M digunakan pada map
    
    *N = WordToInt(currentWord);advWord(true);
    
    *M = WordToInt(currentWord);advWord(true);
    
    //Assign posisi HQ
    Absis(*HQ)  = WordToInt(currentWord);advWord(true);
    Ordinat(*HQ)  = WordToInt(currentWord);advWord(true);
    Name(*HQ) = '8';
    

    //Assign jumlah Bangunan dan lokasi
    jumlahBangunan  = WordToInt(currentWord);advWord(true);
    CreateListPoint(Listbangunan,jumlahBangunan);
    for (i=0; i<jumlahBangunan; i++){
        
        tempBangunan.name= WordtoSingleChar(currentWord);advWord(true);
        
        tempBangunan.X =  WordToInt(currentWord);advWord(true);
        tempBangunan.Y =  WordToInt(currentWord);advWord(true);
        insertLastListPoint(Listbangunan,tempBangunan);
    }

    //Untuk Matrix adjacency
    CreateMatrix(jumlahBangunan+1,jumlahBangunan+1,Adjency);
    for (i=0; i<=jumlahBangunan; i++){
        for (j=0; j<=jumlahBangunan; j++){
            ELMT(*Adjency, i, j) = WordToInt(currentWord);advWord(true);
        }
    }
    
    //Untuk Queue Pesanan
    
    jumlahPesanan = WordToInt(currentWord);
    if (jumlahPesanan ==0) advWord(false);
    for (j=0 ; j<jumlahPesanan; j++){
        advWord(true);
        
        tempPesanan.waktuMasuk = WordToInt(currentWord);advWord(true);
        tempPesanan.pickUp = WordtoSingleChar(currentWord);advWord(false);
        tempPesanan.dropOff = WordtoSingleChar(currentWord);advWord(false);
        tempPesanan.jenisItem = WordtoSingleChar(currentWord);
        
        
        if (tempPesanan.jenisItem == 'P'){
            advWord(true);
            tempPesanan.waktuHangus = WordToInt(currentWord);
            //diEnqueue ke suatu Queue yang nantinya berguna untuk Penggunaan Gadget
            enqueuePRIOQUEUE(QueuePerishable,tempPesanan);
        }    
        
        
        enqueuePRIOQUEUE(QueuePesanan, tempPesanan);
    }

}

void saveFile(char *namaFile,int N,int M, Point HQ, ListPoint Listbangunan, PrioQueuePesanan QueuePesanan,PrioQueuePesanan staticPerishQueue, Matrix Adjency,int pesananDiantar, Point PosisiMobita, int Money, int time, int speedboost, int heavyitem, Tas tasMobita, InProgList progress, ToDoList Todo, ListInventory inventory){
    
    /* KAMUS LOKAL */
    Point temp;
    int i,j;
    char stringTemp[10];
    Pesanan trashPesanan;
    ElTypeTas trashTas;
    InProgType trashProg;
    ToDoType trashTodo;
    Gadget trashGadget;
    /* ALGORITMA */
    writeFile(namaFile);
    //Ukuran Peta
    WriteIntToFile(N); advWrite(BLANK);
    WriteIntToFile(M);
    advWrite('\n');

    //HQ
    WriteIntToFile(HQ.X); advWrite(BLANK);
    WriteIntToFile(HQ.Y);
    advWrite('\n');

    //Bangunan
    WriteIntToFile(lengthListPoint(Listbangunan)); advWrite('\n');
    for (i = 0 ; i< lengthListPoint(Listbangunan); i++){
        advWrite(NameELMTListPoint(Listbangunan, i)); advWrite(BLANK);
        WriteIntToFile(AbsisELMTListPoint(Listbangunan, i)); advWrite(BLANK);
        WriteIntToFile(OrdinatELMTListPoint(Listbangunan, i)); 
        advWrite('\n');
    }
    
    for (i=0; i<=lengthListPoint(Listbangunan); i++){
        for (j=0; j<=lengthListPoint(Listbangunan); j++){
            WriteIntToFile(ELMT(Adjency,i,j)); 
            if (j!= lengthListPoint(Listbangunan)) advWrite(BLANK);
        }
        advWrite('\n');
    }
   
   // PRIOQUEUE PESANAN (Mungkin kosong)
    WriteIntToFile(lengthPRIOQUEUE(QueuePesanan)); advWrite('\n');
    int len  = lengthPRIOQUEUE(QueuePesanan);
    for (i=0; i<len; i++){

        WriteIntToFile(HEAD_PRIOQUEUE(QueuePesanan).waktuMasuk); advWrite(BLANK);
        advWrite (HEAD_PRIOQUEUE(QueuePesanan).pickUp); advWrite(BLANK);
        advWrite (HEAD_PRIOQUEUE(QueuePesanan).dropOff); advWrite(BLANK);
        advWrite (HEAD_PRIOQUEUE(QueuePesanan).jenisItem);

        if ((HEAD_PRIOQUEUE(QueuePesanan).jenisItem) == 'P'){
            
            advWrite(BLANK);
            WriteIntToFile(HEAD_PRIOQUEUE(QueuePesanan).waktuHangus);
        }
        dequeuePRIOQUEUE(&QueuePesanan, &trashPesanan);
        advWrite('\n');
    }
    // PrioQueue untuk Static perishable
    WriteIntToFile(lengthPRIOQUEUE(staticPerishQueue)); advWrite('\n');
    len  = lengthPRIOQUEUE(staticPerishQueue);
    for (i=0; i<len; i++){

        WriteIntToFile(HEAD_PRIOQUEUE(staticPerishQueue).waktuMasuk); advWrite(BLANK);
        advWrite (HEAD_PRIOQUEUE(staticPerishQueue).pickUp); advWrite(BLANK);
        advWrite (HEAD_PRIOQUEUE(staticPerishQueue).dropOff); advWrite(BLANK);
        advWrite (HEAD_PRIOQUEUE(staticPerishQueue).jenisItem);advWrite(BLANK);
        WriteIntToFile(HEAD_PRIOQUEUE(staticPerishQueue).waktuHangus);
        dequeuePRIOQUEUE(&staticPerishQueue, &trashPesanan);
        advWrite('\n');
    }
    //PESANAN DIANTAR
    WriteIntToFile(pesananDiantar); advWrite('\n');

    //posisi mobita
    advWrite (PosisiMobita.name); advWrite(BLANK);
    WriteIntToFile(PosisiMobita.X); advWrite(BLANK);
    WriteIntToFile(PosisiMobita.Y);
    advWrite('\n');
    
    //Money,time,speedboost,heavyItem
    WriteIntToFile(Money);advWrite('\n');
    WriteIntToFile(time);advWrite('\n');
    WriteIntToFile(speedboost);advWrite('\n');
    WriteIntToFile(heavyitem);advWrite('\n');

    // INPROGRESS LIST DAN TAS
    int count =0;
    while (!isEmpty_InProg(progress)){
        count++;
        deleteFirst_InProgList(&progress, &trashProg);
    }

    //TAS
    WriteIntToFile(count); advWrite(BLANK);
    WriteIntToFile(tasMobita.capacity);advWrite('\n');
   
    while (!isEmptyTas(tasMobita)){
        advWrite(TOP_TAS(tasMobita).pickUp); advWrite(BLANK);
        advWrite(TOP_TAS(tasMobita).dropOff); advWrite(BLANK);
        advWrite(TOP_TAS(tasMobita).itemType); 

        if (TOP_TAS(tasMobita).itemType == 'P'){
            advWrite(BLANK);
            WriteIntToFile(TOP_TAS(tasMobita).perishTime);
        }
        advWrite('\n');
        popTas(&tasMobita, &trashTas);
    }

   
    //todo
    
    WriteIntToFile(length_ToDoList(Todo));advWrite('\n');
    while (!isEmpty_ToDo(Todo)){
        WriteIntToFile(TIMEIN_TODO(Todo)); advWrite(BLANK);
        advWrite(PICKUP_TODO(Todo)); advWrite(BLANK);
        advWrite(DROPOFF_TODO(Todo)); advWrite(BLANK);
        advWrite(ITEMTYPE_TODO(Todo)); 

        if ((ITEMTYPE_TODO(Todo)) == 'P'){
            advWrite(BLANK);
            WriteIntToFile(PERISHTIME_TODO(Todo));
        }
        advWrite('\n');
        delete_ToDoList(&Todo, INFO_TODO(Todo), &trashTodo);
    }
    i =0;
    //inventory
     WriteIntToFile(lengthListInventory(inventory));advWrite('\n');
    while (i < lengthListInventory(inventory)){
        WriteIntToFile(ELMTInventory(inventory, i));
        if ( i != lengthListInventory(inventory)-1) advWrite(BLANK);
        i++;
    }
    closeFile();
}

void LoadFile(PrioQueuePesanan *staticPerishQueue, int *pesananDiantar, Point *PosisiMobita, int *Money, int *time, int *speedboost, int *heavyitem, Tas *tasMobita, InProgList *progress, ToDoList *Todo, ListInventory *inventory){
    
    /* KAMUS LOKAL */
    int lenTas;
    int lenToDo;
    int lenInven;
    int lenPerish;
    ElTypeTas tempELTas;
    InProgType tempElProgList;
    ToDoType tempElToDo;
    Gadget tempGadget;
    Word kata;
    int i,j,k,jumlahBangunan,jumlahPesanan;
    int X,Y;
    char tempName;
    Pesanan tempPesanan;
    Point tempBangunan;
    lenPerish = WordToInt(currentWord);advWord(true);
    for (i = 0; i<lenPerish; i++){
        tempPesanan.waktuMasuk =  WordToInt(currentWord);advWord(true);
        tempPesanan.pickUp =  WordtoSingleChar(currentWord);advWord(true);
        tempPesanan.dropOff =  WordtoSingleChar(currentWord);advWord(true);
        tempPesanan.jenisItem =  WordtoSingleChar(currentWord);advWord(true);
        tempPesanan.waktuHangus =  WordToInt(currentWord);advWord(true);

        if (HEAD_PRIOQUEUE(*staticPerishQueue).waktuMasuk !=tempPesanan.waktuMasuk){
            enqueuePRIOQUEUE(staticPerishQueue,tempPesanan);
        } else{
            if (HEAD_PRIOQUEUE(*staticPerishQueue).pickUp !=tempPesanan.pickUp){
                
            } else{
                if (HEAD_PRIOQUEUE(*staticPerishQueue).dropOff !=tempPesanan.dropOff){
                    enqueuePRIOQUEUE(staticPerishQueue,tempPesanan);
                } else{
                    if (HEAD_PRIOQUEUE(*staticPerishQueue).waktuHangus !=tempPesanan.waktuHangus){
                        enqueuePRIOQUEUE(staticPerishQueue,tempPesanan);
                    }
                }
            }
        }
                
             
          
    }

    //jumlah pesanan terantar;
    *pesananDiantar = WordtoSingleChar(currentWord);advWord(true);
    

    //PosisiMobita
    
   
    Name(*PosisiMobita) = WordtoSingleChar(currentWord);advWord(true);
    
    Absis(*PosisiMobita) = WordToInt(currentWord);advWord(true);
    
    Ordinat(*PosisiMobita) = WordToInt(currentWord);advWord(true);

    //Money, time, speedboost,heavy
    
    *Money = WordToInt(currentWord) -50;advWord(true);
    *time = WordToInt(currentWord);advWord(true);
    *speedboost = WordToInt(currentWord);advWord(true);
    *heavyitem = WordToInt(currentWord);advWord(true);
    
    
    //Tas *tasMobita dan InProgList *progress,
    
    lenTas = WordToInt(currentWord);advWord(true);
    TAS_CAPACITY(*tasMobita) = WordToInt(currentWord);
    for (i = 0; i<lenTas; i++){
        advWord(true);
       
        tempELTas.pickUp = WordtoSingleChar(currentWord); 
        tempElProgList.pickUp =  WordtoSingleChar(currentWord); advWord(true);
        
        tempELTas.dropOff = WordtoSingleChar(currentWord); 
        tempElProgList.dropOff =  WordtoSingleChar(currentWord); advWord(true);
         
        tempELTas.itemType = WordtoSingleChar(currentWord); 
        tempElProgList.itemType =  WordtoSingleChar(currentWord);
        if (WordtoSingleChar(currentWord) == 'P'){
            advWord(true);
            tempELTas.perishTime = WordToInt(currentWord); 
            tempElProgList.perishTime =  WordToInt(currentWord);
        }else{
            tempELTas.perishTime = IDX_TAS_UNDEF; 
            tempElProgList.perishTime =  -1;
        }
       
        insertFirst_InProgList(progress, tempElProgList);
        pushTas(tasMobita,tempELTas);
        
    }
    // ToDoList *Todo, 
    advWord(true);
     
    lenToDo = WordToInt(currentWord);
    
    for (i=0; i<lenToDo; i++){
        advWord(true);
       
        tempElToDo.pickUp = WordtoSingleChar(currentWord); advWord(true);
        tempElToDo.dropOff =  WordtoSingleChar(currentWord); advWord(true);
        tempElToDo.itemType =  WordtoSingleChar(currentWord);

        if (WordtoSingleChar(currentWord) == 'P'){
            advWord(false);
            tempElToDo.perishTime = WordToInt(currentWord); 
        }

        insert_ToDoList(Todo,tempElToDo);
        
    }
    displayToDoList(*Todo);    
    //ListInventory *inventory)
    
    ListGadget kumpulanGadget;
    createListGadget(&kumpulanGadget);
    ELMTListGadget(kumpulanGadget,0) = setGadget(1, 800);
    ELMTListGadget(kumpulanGadget,1) = setGadget(2, 1200);
    ELMTListGadget(kumpulanGadget,2) = setGadget(3, 1500);
    ELMTListGadget(kumpulanGadget,3) = setGadget(4, 3000);
    advWord(true);
    
    lenInven = WordToInt(currentWord);
    
    for (i = 0; i<lenInven; i++){
        
        advWord(false);
        insertGadget(inventory, LISTGADGET_IDNAME(kumpulanGadget,WordToInt(currentWord)-1));
    }
    closeFile();
}