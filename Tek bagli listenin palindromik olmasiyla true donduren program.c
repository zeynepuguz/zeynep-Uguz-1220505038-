#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool fonksiyonunu kullanabilmek i�in bu k�t�phaneyi a�t�m.

// AMA�: Tek ba�l� bir listenin palindromik olup olmad���n� kontrol eden program. E�er palindromik ise true de�ise false d�nd�rmali.

struct node { // tek ba�l� listenin d���m yap�s�n� olu�turdum.
    int data;
    struct node* next;
};

typedef struct node list; //struct node tipinden olu�an list yap�s� tan�mlad�m.

 list* olustur(int data) { // tek ba�l� listenin d���mleri olu�turmas�n� sa�layan fonksiyonu tan�mlad�m.
    list* newNode = (list*)malloc(sizeof(struct node)); // yeni d���m olu�turarak bellekten yeterli miktarda yer ay�rmas�n� sa�lad�m.
    newNode->data = data; // veriyi yeni d���me atad�m.
    newNode->next = NULL; //listenin yeni verilerini null olarak ayarlad�m.
    return newNode;  //listenin yeni verileri d�nd�r�l�yor.
}

bool palindrom(list* head) { //tek ba�l� listenin palindromik olup olmad���n� kontrol eden fonksiyonu olu�turdum.
    if (head == NULL) { // e�er head NULL ise liste bo� oldu�undan palindromik de�il.
        return false;
    }

    // listenin uzunlu�unu hesaplayan k�sm� olu�turdum.
    int uzunluk = 0;
    list* yeniVeri = head;
    while(yeniVeri != NULL){
        uzunluk++;
        yeniVeri = yeniVeri->next;
    }

    if (uzunluk == 1) { // listenin uzunlu�u 1 ise liste zaten palindromik.
        return true;
    }

    // ikinci yar�n�n ba�lang�c�n� bulmas�n� sa�lad�m.
    int orta = uzunluk/2;
    list* ikinciYari = head;
    int i;
    for (i=0;i<orta;i++) {
        ikinciYari = ikinciYari->next;
    }

    // ikinci yar�s�n� ters �evirdim.
    list* previous = NULL;
    list* next = NULL;
    while(ikinciYari != NULL){
        next = ikinciYari->next;
        ikinciYari->next = previous;
        previous = ikinciYari;
        ikinciYari = next;
    }

    // ilk yar�s� ile ters �evrilmi� ikinci yar�s�n� kar��la�t�rarak palindromik olup olmad�klar�n� kontrol ettim.
    list* ilkYari = head;
    for (i=0;i<orta;i++) {
        if (ilkYari->data != previous->data) {
            return false;
        }
        ilkYari = ilkYari->next;
        previous = previous->next;
    }
    return true;
}

 int main() {
     // tek ba�l� palindromik listeyi olu�turdum.
    list* head = olustur(1); // ilk d���m� olu�turup head i�aret�isine atad�m.
    head->next = olustur(2); // di�er d���mleri head i�aret�isine ekleyerek ilerledim.
    head->next->next = olustur(3);
    head->next->next->next = olustur(2);
    head->next->next->next->next = olustur(1);

     // e�er liste palindrom ise if blo�u de�ilse else blo�u �al��acak.
    if (palindrom(head)) {
        printf("Verilen liste palindromik!\n\n");
    } else {
        printf("Verilen liste palindromik degil!\n\n");
    }

    // kodun do�ru �al��t���ndan emin olabilmek i�in palindromik olmayan ba�ka bir ba�l� liste daha olu�turdum.
    head = olustur(1);
    head->next = olustur(2);
    head->next->next = olustur(3);
    head->next->next->next = olustur(5);
    head->next->next->next->next = olustur(1);

    if (palindrom(head)) {
        printf("Verilen liste palindromik!\n");
    } else {
        printf("Verilen liste palindromik degil!\n");
    }


    return 0;
}
