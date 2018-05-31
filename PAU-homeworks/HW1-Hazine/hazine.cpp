#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int e[10],jeton,toplam=0,Z[10];	/*"e" her jeton için rastgele atanan yön deðerlerin tutulduðu dizi*/   /*"Z" yön belirteclerinin toplamýnýn yazýldýðý dize*/ /* Z haznedeki jeton sayisini tutuyor*/
	srand(time(NULL));
	printf("Jeton Sayisi: ");
	scanf("%d",&jeton);
	
	
	for(int i=0;i<10;i++)   /*Z dizesisi için ayrýlan kýsmý sýfýrladým */
	{
		Z[i]=0;
	}
	
	for(int i=0; i<jeton; i++)
	{
		printf("%3d. jetonu atmak icin herhangi bir tusa basiniz ->",i+1);
		getch();
		
			for(int i=1; i<10; i++)
			{
				e[i]=(rand()%2);   /* jetonlarin civilere carptiginda yönelecegi yönü rastgele atar. */
			//		printf("e[%d] = %d\n" ,i,e[i]);       /* jetonun düsmesi için gereken rastgele deðerleri görmek için yazdirdim*/
			}
		
			for(int i=1; i<10; i++)			/* e dizisinin içindeki "1" leri okutmak için sayýlarý toplattým*/
			{
				toplam += e[i];   /* e dizesinde toplanan deðerleri toplam deðiþkenine yazdýrdým*/
			}	
			
			Z[toplam]++;    /*döngü döndükce sýrasý gelen haznedeki jeton sayýsýný Z dizesine yazdým*/
			printf(" %2d. hazneye dustu..\n", toplam+1);  /*jetonlar toplamýn 1 fazlasý hazneye düþüyor*/
			toplam=0;    /*toplam deðiþkenini sýfýrladým çünkü iþlem tüm jetonlar için uygulanacak..*/
	}	
		
		printf("\n");
	
	for(int i=0;i<10;i++)
	{
		printf("%2d Haznedeki jeton sayisi = %d\n",i+1,Z[i]);
	}
/* ------------------------ histogram kismi ---------------------------*/

	printf("\n");
	printf("Jetonlarin histogram seklinde dagilimlari:\n");
	
	int max=0;
	for(int i=0;i<10;i++)
	{
		if(max<Z[i]) /*histogramda baþý ceken jeton haznesini buldurdum*/
		{
			max=Z[i];
		}
	}

	while(1)
	{
		printf(" %2d|",max);
		for(int i=0;i<10;i++)
		{
			if(Z[i]>=max)   /*En üst satýrdan baþlayýp max a eþit yada büyük varsa (en üst saatýrda zaten en büyük max) |o| koyuyor [ yoksa  |  | koyar ]sonra saða doðru devam ediyor. Sonra maxý bir düþürüp alt satýra iniyoruz.*/
			{
				printf(" o |");
			}
			else
			{
				printf("   |");
			}	
		}
		printf("\n");
		max--;
		if(max==0) /*max sýfýrlandýðýnda döngüden çýkýyoruz.*/
		{
			break;
		}
	}
	
	
	printf("---+---+---+---+---+---+---+---+---+---+---+\n");
	printf("   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n\n");
	
	
	
	

/*--------------------------son-----------------------*/
	printf("Hasan TEZCAN tarafindan hazirlanmistir.\n");
	printf("e mail: htezcan17@posta.pau.edu.tr\n");
	printf("Ogrenci No: 17253046\n");
 getch();
}


