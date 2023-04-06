#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // bool fonksiyonunu kullanabilmek için bu kütüphaneyi açtým.

// AMAÇ: Tek baðlý bir listenin palindromik olup olmadýðýný kontrol eden program. Eðer palindromik ise true deðise false döndürmali.

struct node { // tek baðlý listenin düðüm yapýsýný oluþturdum.
    int data;
    struct node* next;
};

typedef struct node list; //struct node tipinden oluþan list yapýsý tanýmladým.

 list* olustur(int data) { // tek baðlý listenin düðümleri oluþturmasýný saðlayan fonksiyonu tanýmladým.
    list* newNode = (list*)malloc(sizeof(struct node)); // yeni düðüm oluþturarak bellekten yeterli miktarda yer ayýrmasýný saðladým.
    newNode->data = data; // veriyi yeni düðüme atadým.
    newNode->next = NULL; //listenin yeni verilerini null olarak ayarladým.
    return newNode;  //listenin yeni verileri döndürülüyor.
}

bool palindrom(list* head) { //tek baðlý listenin palindromik olup olmadýðýný kontrol eden fonksiyonu oluþturdum.
    if (head == NULL) { // eðer head NULL ise liste boþ olduðundan palindromik deðil.
        return false;
    }

    // listenin uzunluðunu hesaplayan kýsmý oluþturdum.
    int uzunluk = 0;
    list* yeniVeri = head;
    while(yeniVeri != NULL){
        uzunluk++;
        yeniVeri = yeniVeri->next;
    }

    if (uzunluk == 1) { // listenin uzunluðu 1 ise liste zaten palindromik.
        return true;
    }

    // ikinci yarýnýn baþlangýcýný bulmasýný saðladým.
    int orta = uzunluk/2;
    list* ikinciYari = head;
    int i;
    for (i=0;i<orta;i++) {
        ikinciYari = ikinciYari->next;
    }

    // ikinci yarýsýný ters çevirdim.
    list* previous = NULL;
    list* next = NULL;
    while(ikinciYari != NULL){
        next = ikinciYari->next;
        ikinciYari->next = previous;
        previous = ikinciYari;
        ikinciYari = next;
    }

    // ilk yarýsý ile ters çevrilmiþ ikinci yarýsýný karþýlaþtýrarak palindromik olup olmadýklarýný kontrol ettim.
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
     // tek baðlý palindromik listeyi oluþturdum.
    list* head = olustur(1); // ilk düðümü oluþturup head iþaretçisine atadým.
    head->next = olustur(2); // diðer düðümleri head iþaretçisine ekleyerek ilerledim.
    head->next->next = olustur(3);
    head->next->next->next = olustur(2);
    head->next->next->next->next = olustur(1);

     // eðer liste palindrom ise if bloðu deðilse else bloðu çalýþacak.
    if (palindrom(head)) {
        printf("Verilen liste palindromik!\n\n");
    } else {
        printf("Verilen liste palindromik degil!\n\n");
    }

    // kodun doðru çalýþtýðýndan emin olabilmek için palindromik olmayan baþka bir baðlý liste daha oluþturdum.
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
