# Zeynep Uğuz 1220505038 


 ## Palindromik Liste


**Programın Amacı**

Bu program, verilen bir tek bağlı listenin palindromik olup olmadığını kontrol eder ve palindromik olmasıyla true döndürürerek "Verilen liste palindromik!" mesajını verir. Aksi takdirde, "Verilen liste palindromik değil!" mesajı verilir.


**Kullanılan Dil ve Araçlar**

Bu program C dilinde yazılmıştır. Ayrıca, programın doğru çalışması için stdio.h, stdlib.h ve stdbool.h kütüphaneleri kullanılmıştır.


**Nasıl Kullanılır**

Programı çalıştırmak için, kodun main dosyasını derleyin ve oluşan programı çalıştırın. Program çalıştığında, bir tek bağlı liste oluşturulacak ve bu listenin palindromik olup olmadığı kontrol edilecektir.


**Nasıl Çalışır**

Program, verilen tek bağlı listenin palindromik olup olmadığını kontrol eder. Verilen bağlı listede, önceki bir düğümden başlayarak aynı sırayla okunan karakterlerin, son düğümden başlayarak aynı sırayla okunması durumunda palindromik olduğu kabul edilir.

Program, "stdio.h", "stdlib.h" ve "stdbool.h" kütüphanelerini içerir. Ayrıca, "struct" yapısı ile tanımlanmış "node" adlı bir yapı vardır. Bu yapı, "data" ve "next" olmak üzere iki veri üyesi içerir. "data", düğümün veri kısmını temsil ederken, "next", düğümün bir sonraki düğümüne işaret eden bir işaretçidir.

Programın içinde, "olustur" adlı bir fonksiyon vardır. Bu fonksiyon, bağlı listeye yeni bir düğüm eklemek için kullanılır. "palindrom" adlı bir başka fonksiyon ise, verilen bağlı listenin palindromik olup olmadığını kontrol eder.

Program, önceki bir düğümden başlayarak aynı sırayla okunan karakterlerin, son düğümden başlayarak aynı sırayla okunması durumunda bağlı listenin palindromik olduğu kabul edildiği için, bağlı listenin ikinci yarısını ters çevirir ve ilk yarısı ile karşılaştırır. Eğer karşılaştırma başarılı olursa, bağlı liste palindromik olarak kabul edilir.


**Örnekler**

    `list* head = olustur(1);
    head->next = olustur(2);
    head->next->next = olustur(3);
    head->next->next->next = olustur(2);
    head->next->next->next->next = olustur(1);

    if (palindrom(head)) {
        printf("Verilen liste palindromik!\n");
    } else {
        printf("Verilen liste palindromik degil!\n");
    }`

![image](https://user-images.githubusercontent.com/122873468/230357785-176df602-2b64-4569-a0b5-a7b5de46e722.png)

  Program bu kısımda bir palindromik liste oluşturur ve bu listenin palindromik olduğunu doğrular.

    `list* head = olustur(1);
    head->next = olustur(2);
    head->next->next = olustur(5);
    head->next->next->next = olustur(2);
    head->next->next->next->next = olustur(1);

    if (palindrom(head)) {
        printf("Verilen liste palindromik!\n");
    } else {
        printf("Verilen liste palindromik degil!\n");
    }`
    
  ![image](https://user-images.githubusercontent.com/122873468/230356560-c5fe2889-49e1-4dfd-abdf-043b79dc2e91.png)

    Bu kısımda ise program palindromik olmayan bir liste oluşturur ve kodun doğru çalıştığını doğrular.
