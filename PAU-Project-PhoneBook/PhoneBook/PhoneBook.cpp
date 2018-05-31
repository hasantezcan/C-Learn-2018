#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#define R_SARI "\x1b[33m"
#define R_KRMZ "\x1b[31m"
#define R_REST "\x1b[0m"
#define R_MAVI "\x1b[36m"

void menu();
void kisiEkle();
void goruntule(int sayac);
void goruntulemeEkrani();
void dosyayaYaz();
void arama();
void guncelle();
void sil();
void EpostaEkle();
void telEkle(char TelNo[12]);

int N = 0; //KISI SAYISINI TUTAN DEGISKEN

struct kayit
    {   char ad[100];
        char soyad[100];
        char cepTel[100];
        char evTel[100];
        char isTel[100];
    	char ePosta[100];
        char dogumTarihi[100];
		char il[100];
        char ilce[100];
        char mahalle[100];
        char sokak[100];
		
 	}kisibilgisi[BUFSIZ];

main()
{
	//DOSYA OKUMA KISMI : program ilk acildiginda dosyada kac kisi var, onu tespite calisiyor...
	
	FILE *kayit;//Dosya tanimlama islemi
	kayit = fopen("Kayit.txt","r");//dosya acma islemi
	
	if (kayit == NULL)
		printf("Dosya Bulunamadi...\n"); 
		
	else
	{	int x=0;
		while (!feof(kayit))//dosyanin sonuna gelene kadar 
		{ 
			fscanf(kayit,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n%s",&kisibilgisi[x].ad, &kisibilgisi[x].soyad, &kisibilgisi[x].cepTel, &kisibilgisi[x].evTel, &kisibilgisi[x].isTel, &kisibilgisi[x].ePosta, &kisibilgisi[x].dogumTarihi, &kisibilgisi[x].il, &kisibilgisi[x].ilce, &kisibilgisi[x].mahalle, &kisibilgisi[x].sokak);
			x++;	
		}
		x--;  //BUGFIX: N sayisi 1 fazla sayiliyordu bu hatayi gidermek için N'i 1 azaltim ...
		N=x;
		fclose(kayit);
	}
	
	//MENU MEKANIZMASI.
	
	char cikis = 'h';
	
	while(cikis == 'h')
	{
		system("CLS"); //EKRANI TEMIZLER
		menu(); //menu fonksiyonu cagirildi..
		char secim =0; //hangi menu basamagini istiyorsun ?
		char devamEt = 'e'; //devam et degiskenini olmusuz olarak olusturuyoruz!
			secim = getch();
		
		if(secim == '1')  //KISI EKLE
		{
			while(devamEt == 'e' || devamEt == 'E')
			{
				kisiEkle();
				dosyayaYaz();
				printf("\n"R_MAVI"Kisi eklemeye devam edecek misiniz? [E/H]\n"R_REST);
				devamEt = getch();
			}	
		}
		else if (secim == '2')  //GORUNTULE
		{
			goruntulemeEkrani();
			printf(R_MAVI"\n--=> Menuye donmek icin herhangi bir tusa basiniz!\n"R_REST);
			getch();
		}
		else if (secim == '3') //GUNCELLE
		{
			guncelle();
			dosyayaYaz();
			printf(R_MAVI"\n--=> Menuye donmek icin herhangi bir tusa basiniz!\n"R_REST);
			getch();
		}
		else if (secim == '4')  //SIL
		{
			sil();
			dosyayaYaz();
			printf(R_MAVI"\n\n--=> Menuye donmek icin herhangi bir tusa basiniz!\n"R_REST);
			getch();
		}
		else if (secim == '5')  //ARAMA
		{
			while(1)
			{
				arama();
				printf(R_SARI"\nKisi aramaya devam edecek misiniz? [E/H]\n"R_REST);
				devamEt = getch();
					if(devamEt == 'e' || devamEt == 'E')
						continue;
					
					else
					{
						printf(R_MAVI"\n--=> Menuye donmek icin herhangi bir tusa basiniz!\n"R_REST);
						getch();
						break;
					}
			}		
		}
		else if (secim == '6')  //CIKIS
		{
			printf(R_SARI"\n\n                                                Rehber Kapatiliyor"R_REST);
			Sleep(800); printf("."); Sleep(800); printf("."); Sleep(800); printf(".");
			Sleep(250); printf(R_SARI"\n                                    --=> Cikmak icin herhangi bir tusa basiniz!"R_REST);
			cikis = 'e';
		}
		else //BASKA BIR TUSA BASAMA IHTIMALI 
		{
			printf(R_KRMZ"\n\n                                   lutfen menudeki seceneklerden birini seciniz!"R_REST);Sleep(650);
			
		}
	}
}

void menu()
{
	printf("\n\t\t\t\t\t ==="R_SARI"TELEFON REHBERI UYGULAMASI"R_REST"===\n");
	printf("\n\t\t\t\t\t\t 1- KISI EKLE");
	printf("\n\t\t\t\t\t\t 2- KISI GORUNTULE");
	printf("\n\t\t\t\t\t\t 3- KISI GUNCELLE");
	printf("\n\t\t\t\t\t\t 4- KISI SIL");
	printf("\n\t\t\t\t\t\t 5- KISI ARA");
	printf("\n\t\t\t\t\t\t 6- "R_KRMZ"CIKIS"R_REST);
	
	printf("\n\n\t\t\t\t\t   Lutfen bir secenek giriniz.. ");
}
void kisiEkle()
{
	system("CLS"); 
	printf("                                        ____________________                                               \n");
	printf("                                       |                    |                                              \n");
	printf("=====================================> | "R_SARI"KISI EKLEME EKRANI"R_REST" | <============================================\n");
	printf("                                       |____________________|                                              \n");
	
	printf(R_KRMZ"        DIKKAT!! Program kucuk-buyuk harfe duyarlidir. Lutfen girdileri kucuk harf kullanarak girin...\n"R_REST);
	
	printf("\n"R_SARI" %d."R_REST" Kayit icin bilgileri doldurun....\n",N+1);
	
	printf(R_SARI"\nAD:"R_REST);
	gets(kisibilgisi[N].ad);
	
	printf(R_SARI"\nSOYAD:"R_REST);
	gets(kisibilgisi[N].soyad);
	
	printf(R_SARI"\nCEP TELEFONU:"R_REST);
	telEkle(kisibilgisi[N].cepTel);  //TEL EKLE FONKSIYONUNA GONDERDIM. FONKSIYON ICINDE HEM EKLEME ISLEMI HEMDE KONTROL ISLEMI GERCEKLESICEK
	
	printf(R_SARI"\nEV TELEFONU:"R_REST);
	telEkle(kisibilgisi[N].evTel);
	
	printf(R_SARI"\nIS TELEFONU:"R_REST);
	telEkle(kisibilgisi[N].isTel);
	
	EpostaEkle(); //E POSTA EKLE FONKSIYONUNA GONDERDIM. FONKSIYONUN ICINDE HEM EKLEME HEMDE E POSTA KONTROL ISLEMI GERCEKLESICEK
	
	printf(R_SARI"\nDOGUM TARIHI:"R_REST);
	gets(kisibilgisi[N].dogumTarihi);
	
		printf("\n\n"R_SARI"==>ADRES BILGILERI..."R_REST); //ADRESS KISMI
			
			printf(R_SARI"\n|---> IL:"R_REST);
			gets(kisibilgisi[N].il);
			
			printf(R_SARI"\n|---> ILCE:"R_REST);
			gets(kisibilgisi[N].ilce);
			
			printf(R_SARI"\n|---> MAHALLE:"R_REST);
			gets(kisibilgisi[N].mahalle);
			
			printf(R_SARI"\n\\---> SOKAK:"R_REST);
			gets(kisibilgisi[N].sokak);
	
	N++;
}

void dosyayaYaz()  //TEK FONKSIYONDA DOSYA YAZMA ISLEMI
{
	FILE *kayit;
	kayit = fopen("Kayit.txt","w");
	
	if(kayit==NULL)
    	printf("Dosya Bulunamadi...");
    	
    else
	{
		for (int i = 0; i < N; i++)
		{
			fprintf(kayit,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",kisibilgisi[i].ad,kisibilgisi[i].soyad,kisibilgisi[i].cepTel,kisibilgisi[i].evTel,kisibilgisi[i].isTel,kisibilgisi[i].ePosta,kisibilgisi[i].dogumTarihi,kisibilgisi[i].il,kisibilgisi[i].ilce,kisibilgisi[i].mahalle,kisibilgisi[i].sokak);
		}
	}
	fclose(kayit);
}

void goruntule(int sayac)  //TUM GORUNTULEME ISLEMLERI BU FONK UZERINDEN YURUR.
{
	printf(R_SARI"\n=======>"R_REST" %d.kisi "R_SARI"<=======\n"R_REST,sayac+1);
	printf("ADI : %s\n",kisibilgisi[sayac].ad);
	printf("SOY ADI : %s\n",kisibilgisi[sayac].soyad);
	printf("CEP TEL NO:%s\n",kisibilgisi[sayac].cepTel);
	printf("EV TEL NO  :%s\n",kisibilgisi[sayac].evTel);
	printf("IS TEL NO: %s\n",kisibilgisi[sayac].isTel);
	printf("E-POSTA ADRESI:%s\n",kisibilgisi[sayac].ePosta);
	printf("DOGUM TARIHI:%s\n",kisibilgisi[sayac].dogumTarihi);	
	printf(R_SARI"ADRES BILGILERI;\n"R_REST);
	printf(R_SARI"|--->"R_REST" IL:%s\n",kisibilgisi[sayac].il);
	printf(R_SARI"|--->"R_REST" ILCE:%s\n",kisibilgisi[sayac].ilce);
	printf(R_SARI"|--->"R_REST" MAHALLE:%s\n",kisibilgisi[sayac].mahalle);
	printf(R_SARI"\\--->"R_REST" SOKAK:%s\n",kisibilgisi[sayac].sokak);
	
}

void goruntulemeEkrani()
{	
	int secim;
	system("CLS");
	printf("                                        ____________________                                               \n");
	printf("                                       |                    |                                              \n");
	printf("=====================================> | "R_SARI"GORUNTULEME EKRANI"R_REST" | <============================================\n");
	printf("                                       |____________________|                                                ");

//printf("N===%d",N);	

	if(N == 0)
	{
		printf(R_KRMZ"\n      UYARI! Suan rehberinizde hickimse ekli degil. Ekleme yapmak icin [E/H] tusuna basiniz : "R_REST);//Rehber olusturulamamissa veya daha önce silinmisse bu uyari gösterilir
		secim = getch();
		if(secim == 'e' || secim == 'E')
		{
			printf("\n\n                          ---> Kisi ekleme ekranina yonlendiriliyorsunuz");
			Sleep(750); printf("."); Sleep(500); printf("."); Sleep(500); printf(".");Sleep(750);
			kisiEkle();
		}
	}
	else
	{
		for(int i = 0; i < N; i++)
		goruntule(i);	
	}
}

void arama()  //TEK KELIMELI ARAMALARDA KELIMEDEN SONRA BOSLUK KOYDUGUNUZ ZAMAN ARAMA BASARIZI OLUYOR.... !!!
{	
	system("CLS");
	printf("                                        ____________________                                               \n");
	printf("                                       |                    |                                              \n");
	printf("=====================================> |    "R_SARI"ARAMA EKRANI"R_REST"    | <============================================\n");
	printf("                                       |____________________|                                                ");
	
	int secim,a=0;
	char aramaAnahtari[BUFSIZ];
	
	printf("\n"R_SARI" 1 |"R_REST" AD\n");
	printf(R_SARI" 2 |"R_REST" SOY AD\n");
	printf(R_SARI" 3 |"R_REST" CEP TELEFONU\n");
	printf(R_SARI" 4 |"R_REST" EV  TELEFONU\n");
	printf(R_SARI" 5 |"R_REST" IS  TELEFONU\n");
	printf(R_SARI" 6 |"R_REST" E-POSTA ADRESI\n");
	printf(R_SARI" 7 |"R_REST" DOGUM TARIHI\n");	
	printf(R_SARI" 8 |"R_REST" IL\n");
	printf(R_SARI" 9 |"R_REST" ILCE\n");
	
	
	printf("\n\n" R_SARI"--=>"R_REST "Lutfen bir arama turunu secin..");

	secim = getch();
	
	if(secim == '1')
		{	
			printf("\n\n Aradiginiz kisinin "R_SARI"adini"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].ad,aramaAnahtari) == 0)//strcmp = string compare ;kiyasliyor, eger ikiside ayni ise "0" degerini veriyor...
				{
					goruntule(i);
					a++; // eger islem if icine girerse a degiskenini burda 1 artiriyorum boylelikle bundan sonra gelen a=0 sa bulunamadi hatasi vermesi
				}
			}
			if(a == 0) //eger arama islemi hatali gerceklesirse basta tanimlanan a=0 degeri sayesine islem buraya duser.
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
			
		}
	else if(secim=='2')
		{
			printf("\n\n Aradiginiz kisinin "R_SARI"soyadini"R_REST" Giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].soyad,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
		}
	else if(secim=='3')
		{
			printf("\n\n Aradiginiz kisinin "R_SARI"cep telefonu numarasini"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].cepTel,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
		}
	else if(secim=='4')
		{
			printf("\n\n Aradiginiz kisinin "R_SARI"ev telefonu numarasini"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].evTel,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
		}
	else if(secim=='5')
		{
			printf("\n\n Aradiginiz kisinin "R_SARI"is telefonu numarasini"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].isTel,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
		}
	else if(secim=='6')
		{
				printf("\n\n Aradiginiz kisinin "R_SARI"E posta adresini"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].ePosta,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
		}
	else if(secim =='7')
		{
			printf("\n\n Aradiginiz kisinin "R_SARI"dogum tarihini"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].dogumTarihi,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
		}
	else if(secim =='8')
		{
			
			printf("\n\n Aradiginiz kisinin "R_SARI"ikamet ettigi ili"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].il,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
			
		}
	else if(secim =='9')
		{
			printf("\n\n Aradiginiz kisinin "R_SARI"ikamet ettigi ilceyi"R_REST" giriniz "R_SARI"--=>"R_REST);
			gets(aramaAnahtari);
			
			for (int i = 0; i<=N; i++)
			{
				if (strcmp(kisibilgisi[i].ilce,aramaAnahtari) == 0)
				{
					goruntule(i);
					a++;
				}
			}
			if(a == 0)
			{
				printf(" Aradiginiz kisi bulunamadi!..\n");
			}
		}
}

void guncelle()
{
	system("CLS"); 
	printf("                                        _____________________                                               \n");
	printf("                                       |                     |                                              \n");
	printf("=====================================> | "R_SARI" GUNCELLEME EKRANI "R_REST" | <============================================\n");
	printf("                                       |_____________________|                                              \n");
		
	int noGuncellenen,secenek;  
	for (int i = 0; i < N; i++)
		goruntule(i); // TUM VERILERI EKRANA YAZDIRIR. KULLANICIN KIMI SECECEGINI BULMASINA YARDIMCI OLLURUZ
		
	printf("\n\n"R_SARI"--=>"R_REST"GUNCELLEMEK istediginiz kisinin "R_MAVI"numarasini"R_REST" giriniz: ");
	scanf("%d",&noGuncellenen);
	noGuncellenen=noGuncellenen - 1;
	system("CLS");
	printf(R_MAVI"    GUNCELLENECEK KISI"R_REST);
	goruntule(noGuncellenen);
	
	printf(R_MAVI"\n#===================#"R_REST);
	printf(R_MAVI"\n  1-"R_REST"AD");
	printf(R_MAVI"\n  2-"R_REST"SOYAD");
	printf(R_MAVI"\n  3-"R_REST"CEP TELEFONU");
	printf(R_MAVI"\n  4-"R_REST"EV TELEFONU");
	printf(R_MAVI"\n  5-"R_REST"IS TELEFONU");
	printf(R_MAVI"\n  6-"R_REST"E POSTA ADRESI");
	printf(R_MAVI"\n  7-"R_REST"DOGUM TARIHI");
	printf(R_MAVI"\n  8-"R_REST"IL");
	printf(R_MAVI"\n  9-"R_REST"ILCE");
	printf(R_MAVI"\n 10-"R_REST"MAHALLE");
	printf(R_MAVI"\n 11-"R_REST"SOKAK");

	printf("\n\n"R_SARI"--=>"R_REST"Guncellemek istediginiz girdiyi secin.. ");
	
	scanf("%d",&secenek);//Guncellenecek girdi alinir...
	
	if (secenek == 1)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].ad); // ESKI BILGIYI CAGIRDIK
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].ad);  //YENI BILGI ILE GUNCELLEDIK
	}
	else if (secenek == 2)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].soyad);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].soyad);
	}
	else if (secenek == 3)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].cepTel);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].cepTel);
	}
	else if (secenek == 4)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].evTel);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].evTel);
	}
	else if (secenek == 5)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].isTel);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].isTel);
	}
	else if (secenek == 6)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].ePosta);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].ePosta);
	}
	else if (secenek == 7)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].dogumTarihi);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].dogumTarihi);
	}
	else if (secenek == 8)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].il);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].il);
	}
	else if (secenek == 9)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].ilce);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].ilce);
	}
	else if (secenek == 10)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].mahalle);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].mahalle);
	}
	else if (secenek == 11)
	{
		printf("\n              ESKI BILGI = "R_KRMZ"%s\n"R_REST,kisibilgisi[noGuncellenen].sokak);
		printf("\n            GUNCEL BILGI = ");  
		scanf("%s",kisibilgisi[noGuncellenen].sokak);
	}
}

void sil()
{
	system("CLS");
	printf("                                        ____________________                                               \n");
	printf("                                       |                    |                                              \n");
	printf("=====================================> | "R_SARI"KAYIT SILME EKRANI"R_REST" | <============================================\n");
	printf("                                       |____________________|                                                ");
	
	int noSilinen = 0;
	char kontrol;
	int sec;//Silinellenecek bilginin numarasidir.
	for (int i = 0; i < N; i++)
	{
		goruntule(i);
	}
	printf(R_KRMZ"\n----> Silmek istediginiz kisinin numarasini giriniz lutfen!    --> "R_REST);
	scanf("%d",&noSilinen);
	
	system("CLS");
	
	noSilinen=noSilinen - 1;
	
	printf(R_MAVI"     SILINECEK KISI"R_REST);
	goruntule(noSilinen);
	printf(R_KRMZ"\n---> "R_SARI"%d"R_REST R_KRMZ" numarali kisiyi silmeye emin misiniz? [E/H]"R_REST,noSilinen+1);
	kontrol = getch();
	
	if (kontrol == 'e' || kontrol =='E')
	{
		strcpy(kisibilgisi[noSilinen].ad, 			kisibilgisi[N-1].ad);
		strcpy(kisibilgisi[noSilinen].soyad,		kisibilgisi[N-1].soyad);
		strcpy(kisibilgisi[noSilinen].cepTel,		kisibilgisi[N-1].cepTel);
		strcpy(kisibilgisi[noSilinen].evTel,		kisibilgisi[N-1].evTel);
		strcpy(kisibilgisi[noSilinen].isTel,		kisibilgisi[N-1].isTel);
		strcpy(kisibilgisi[noSilinen].ePosta,		kisibilgisi[N-1].ePosta);
		strcpy(kisibilgisi[noSilinen].dogumTarihi,	kisibilgisi[N-1].dogumTarihi);
		strcpy(kisibilgisi[noSilinen].il,			kisibilgisi[N-1].il);
		strcpy(kisibilgisi[noSilinen].ilce,			kisibilgisi[N-1].ilce);
		strcpy(kisibilgisi[noSilinen].mahalle,		kisibilgisi[N-1].mahalle);
		strcpy(kisibilgisi[noSilinen].sokak,		kisibilgisi[N-1].sokak);
		N--;
		
		printf("\n\n---> Islem basariyla gerceklesti...");
	}
}

void EpostaEkle()
{ 
 	int epostakontrol;
	while(epostakontrol==0){
         printf(R_SARI"\nE POSTA ADRESI:"R_REST);
         gets(kisibilgisi[N].ePosta);
         int i=0;
		 while(i < strlen(kisibilgisi[N].ePosta))
		 {
	        if(kisibilgisi[N].ePosta[i]=='@')
	         	epostakontrol=1;
		 	i++;
		 }
         if(epostakontrol==0)
         printf(R_KRMZ"\tLutfen gecerli bir eposta adresi girniz\n"R_REST);
     }
}

void telEkle(char TelNo[12])
{
int i=0,j=0;	

while(1)
{
	gets(TelNo);
	if(strlen(TelNo)==11)
	{
		//printf("oldu\n"); MANUAL DEBUG ICIN KULLANDIM
		while(i < strlen(TelNo))
		 {
			if(TelNo[i]=='1'|| TelNo[i]=='2'|| TelNo[i]=='3'|| TelNo[i]=='4'|| TelNo[i]=='5'|| TelNo[i]=='6'|| TelNo[i]=='7'|| TelNo[i]=='8'|| TelNo[i]=='9'|| TelNo[i]=='0' )
				j++;
			i++;
		 }
				
		if(j==11)
		{
			//printf("girdi\n"); MANUAL DEBUG ICIN KULLANDIM
			break;	
		}
		else
			printf(R_KRMZ"\t11 haneli telefon numaranizi girin!\n"R_REST);
	}
	else	
		printf(R_KRMZ"\t11 haneli telefon numaranizi girin!\n"R_REST);
}
	i=0;
	j=0;
}



